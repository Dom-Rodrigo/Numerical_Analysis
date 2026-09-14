#define MAX_ITERATIONS 100

int bisection(double (*op)(double), double x0, double x1){

    double x;
    double f;
    for (size_t i = 0; i < MAX_ITERATIONS; ++i){
        x = (x0 + x1)/2;
        f = op(x0)*op(x);
        if (f < 0 ){
            x1 = x;
        }
        else if (f > 0){
            x0 = x;
        }
    }
    printf("x0: %.5e\t x1: %.5e\t, func(x0): %.15f\t, func(x1) %.15f\t\n", x0, x1, op(x0), op(x1));

    return EXIT_SUCCESS;

}

int secant(double (*op)(double), double x0, double x1, double stop_er){
    double x = op(x1);
    double er = x1-x0;
    for (size_t i = 0; i < MAX_ITERATIONS; ++i){
        printf("x0: %.5e\t x1: %.5e\t, func(x0): %.15f\t, func(x1) %.15f\t, error= %.15f\n", x0, x1, op(x0), op(x1), er);
        x = (x0*op(x1) - x1*op(x0))/(op(x1)-op(x0));
        er = (x-x1);
        x0 = x1;
        x1 = x;
        if (er < stop_er){
            printf("x0: %.5e\t x1: %.5e\t, func(x0): %.15f\t, func(x1) %.15f\t, error= %.15f\n", x0, x1, op(x0), op(x1), er);
            break;
        }
    }
    return EXIT_SUCCESS;
}

int trunc_graphic(double (*op)(double), int x0, int x1, int y0, int y1){

    int lines = abs(y0)+abs(y1)+1;
    int columns = abs(x0)+abs(x1)+1;
    int xy[lines][columns] = {};

    //Plots the axes
    for (size_t i = 0; i < lines; ++i){
        xy[i][abs(x0)] = 7; // y ax
    }

    for (size_t j = 0; j < columns; ++j){
        xy[abs(y1)][j] = 7; // x ax
    }


    // Plots the truncted avalue points
    for (int x = x0; x <= x1; ++x){
        int y = op(x);
        if (y <= y1 && y >= y0){
            xy[abs(y1) - y][abs(x0) + x] = 1;
        }
    }

    for (size_t i = 0; i < lines; ++i){
        for (size_t j = 0; j < columns; ++j){
            if (xy[i][j] > 0){
                printf("%d", xy[i][j]);
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}