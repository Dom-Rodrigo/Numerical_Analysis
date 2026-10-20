
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numerical.h"

#define M_E 2.71828182845904523536028747135266250

double funcx(double x){
    return x*x + x - 6;
}

double funcy(double x){
    return pow(x+1, 2)*pow(2.718281828, (pow(x, 2)-2))-1;
}

double funcz(double x){
    return x+1;
}
double func_bissection(double x){
    return pow(M_E, x)-pow(x, 2)-3*x;
}

double func_pf1(double x){
    return (pow(-x, 3)/3)+(3*x)-1;
}

double func_pf2(double x){
    return (pow(x, 3)/9) + (0.3333333333);
}

int main(void){

    printf("Bisection: \n");
    bisection(func_bissection, -4, -3);
    fixed_point(func_pf1, func_pf2, 0, 1, 0.00001);

    return EXIT_SUCCESS;
}