#include <math.h>
#define MAX_ITERATIONS 100

int bisection(double (*op)(double), double x0, double x1){

    if ((op(x0) * op(x1)) > 0){
        return EXIT_FAILURE;
    }

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

int fixed_point(double (*f1)(double), double (*f2)(double), double x0, double x1, double err){

    double step_size = 0.00001;
    double x = x0;
    double difference;
    for (int i = 0; i < 1000000; i++){
        x = x+step_size;
        difference = fabs(f1(x) - f2(x));
        if (difference < err){
            printf("x: %.14f, abs_err: %.14f\n", x, difference);
            break;
        }
    }

}
