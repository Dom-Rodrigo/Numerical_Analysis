#include <math.h>
#define MAX_ITERATIONS 100


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