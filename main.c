#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numerical.h"

double funcx(double x){
    return x*x + x - 6;
}

double funcy(double x){
    return pow(x+1, 2)*pow(2.718281828, (pow(x, 2)-2))-1;
}

double funcz(double x){
    return x+1;
}

int main(void){

    printf("Bisection: \n");
    bisection(funcx, 1.5, 1.7);
    printf("Secant: \n");
    secant(funcx, 1.5, 1.7, 0.003);
    // trunc_graphic(funcz, -100, 100, -50, 50);
    return EXIT_SUCCESS;
}