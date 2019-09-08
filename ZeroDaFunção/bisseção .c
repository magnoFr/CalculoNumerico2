#include <stdio.h>
#include <math.h>

typedef struct{
    double (*f)(double);
}Calculum;

double exSin(double x){
    return 0.5 + sin(x);
}

double *bissecao(double particoes, double min, double max, double (*f)(double));

int main(void) {
    double *res = bissecao(0.001, -1, 0, exSin);
    printf("Intervalo: %lf e %lf", res[0], res[1]);
    return 0;
}

double *bissecao(double particoes, double min, double max, double (*f)(double)){
    
    double a = min, b = max, fx = 0.0, x = 0.0;
    int stop = (log(b - a) - log(particoes))/log(2), i = 0;
    
    for(i; i <= stop; i++){
        x = (a + b)/2;
        fx = f(x);
        
        if(fx == 0){
            break;
        }
        
        if(f(a) * f(x) < 0){
            printf("min: %lf, max: %lf, media: %lf, fx: %lf\n", a, b, x, fx);
            b = x;
        }else{
            printf("min: %lf, max: %lf, media: %lf, fx: %lf\n", a, b, x, fx);
            a = x;
        }
    }
    
    if (f(a) * f(x) < 0){
        static double array[2];
        array[0] = a;
        array[1] = x;
        return array;
    }
    else{
        static double array[2];
        array[0] = b;
        array[1] = x;
        return array;
    }
}


