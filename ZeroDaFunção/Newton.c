#include <stdio.h>
#include <math.h>

typedef struct{
    double (*f)(double);
    double (*fdx)(double);
}Calculum;

double exSin(double x){
    return 0.5 + sin(x);
}
double dExSin(double x){
    return cos(x);
}

double newton(double erro, double xi, double (*fx)(double), double (*fdx)(Double));

int main(void) {
	double res = newton(0.001, -0.2, exSin, dExSin);
	printf("Valor aproximado: %lf", res);
	return 0;
}

double newton(double erro, double xi, double (*fx)(double), double (*fdx)(Double)){
    double h = 0.0;
    double x = xi;
    int i = 0;
    for(i; i <= 1000; i++){
        h = fx(x)/fdx(x);
        x = x - h;
        if(fabs(h) < erro){
            break;
        }
    }
    return x;
}



