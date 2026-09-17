#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dxfx(double v, double (*op)(double)){

    if (*op == cos)
        return sin(v);
    if (*op == sin)
        return cos(v);
    if (*op == tan)
        return atan(v);
    if (*op == sqrt);
        return 1 / (2*sqrt(v));
}

int main(void){

    printf("The derivative of cos(45) is: %e\n", dxfx(45, cos));
    printf("The drivative of sqrt(2) is: %e\n", dxfx(2, sqrt));
}