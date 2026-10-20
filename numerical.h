#include <math.h>
#define MAX_ITERATIONS 20

int bisection(double (*op)(double), double x0, double x1){

    if ((op(x0) * op(x1)) > 0){
        return EXIT_FAILURE;
    }

    double x;
    double f;
    for (size_t i = 0; i < MAX_ITERATIONS; ++i){
        printf("x0: %.5e\t x1: %.5e\t, func(x0): %.15f\t, func(x1) %.15f\t\n", x0, x1, op(x0), op(x1));
        x = (x0 + x1)/2;
        f = op(x0)*op(x);
        if (f < 0 ){
            x1 = x;
        }
        else if (f > 0){
            x0 = x;
        }
    }

    return EXIT_SUCCESS;

}

int fixed_point(double (*f1)(double), double (*f2)(double), double x0, double x1, double err){

    double step_size = 0.00001;
    double x = x0;
    double difference;
    for (int i = 0; i < 1000000; i++){
        x = x+step_size;
        difference = fabs(f1(x) - f2(x));
        printf("%.14f, %.14f\n", x, difference);
        if (difference < err)
            break;
    }

}

double differenciation(double (*f)(double), double x0, double x1){
    double h = 0.01;
    (f(x0+h)-f(x0))/h;
}
int secant(double (*op)(double), double x0, double x1, double stop_er){
    double x = op(x1);
    double er = x1-x0;
    for (size_t i = 0; i < MAX_ITERATIONS; ++i){
        printf("x0: %.15f\t x1: %.15f\t, func(x0): %.15f\t, func(x1) %.15f\t, error= %.15f\n", x0, x1, op(x0), op(x1), er);
        x = (x0*op(x1) - x1*op(x0))/(op(x1)-op(x0));
        er = fabs(x-x1);
        x0 = x1;
        x1 = x;
        if (er < stop_er){
            printf("x0: %.15f\t x1: %.15f\t, func(x0): %.15f\t, func(x1) %.15f\t, error= %.15f\n", x0, x1, op(x0), op(x1), er);
            break;
        }
    }
    return EXIT_SUCCESS;
}

// // Basically the same as secant, but guarantees that the root is between the interval
// int secant(double (*op)(double), double x0, double x1, double stop_er){


//     if (op(x0) * op(x1)){
//         return EXIT_FAILURE;
//     }
    
//     double x2 = (x0*op(x1) - x1*op(x0))/(op(x1)-op(x0));
//     double er_x0 = (x2-x0)/2;
//     double er_x1 = (x2-x1)/2;
    
//     if (er_x0 < stop_er || er_x1 < stop_er){
//         printf("x0: %.15f\t x1: %.15f\t, func(x0): %.15f\t, func(x1) %.15f\t, errorx0= %.15f\n, errorx1=%.15f", x0, x1, op(x0), op(x1), er_x0, er_x1);
//     }
//     else{
//     for (size_t i = 0; i < MAX_ITERATIONS; ++i){
//         printf("x0: %.15f\t x1: %.15f\t, func(x0): %.15f\t, func(x1) %.15f\t, error= %.15f\n", x0, x1, op(x0), op(x1), er);
//         x = (x0*op(x1) - x1*op(x0))/(op(x1)-op(x0));
//         er = fabs(x-x1);
//         x0 = x1;
//         x1 = x;
//         if (er < stop_er){
//             printf("x0: %.15f\t x1: %.15f\t, func(x0): %.15f\t, func(x1) %.15f\t, error= %.15f\n", x0, x1, op(x0), op(x1), er);
//             break;
//         }
//     }
//     }

//     return EXIT_SUCCESS;
// }

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