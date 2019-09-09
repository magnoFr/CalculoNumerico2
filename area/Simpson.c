#include <stdio.h>
#include <math.h>

typedef struct{
    double (*f)(double);
}Calculum;

double exSin(double x){
    return sin(x);
}

double simpson(double particoes, double min, double max, double (*f)(double));

int main(void) {
	
	Calculum ex;
	ex.f = exSin;
	
	double resultado = simpson(20.0, 0.0, 2.0, ex.f);
	printf("%lf", resultado);
	
	return 0;
}

double simpson(double particoes, double min, double max, double (*f)(double)){
    double b = (max - min)/(2*particoes);
    double xn = min + b;
    double resultado = 0.0;
    int i = 1;
    for(i; i <= ((int)(particoes * 2) - 1); i++){
        if(i % 2 == 1){
            resultado += 4*f(xn);
        }else{
            resultado += 2*f(xn);
        }
        xn += b;
    }
    return (b/3)*(f(min) + resultado + f(max));
}
