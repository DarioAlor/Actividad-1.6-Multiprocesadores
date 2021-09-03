#include <stdio.h>
#include <math.h>
#include <time.h>

FILE *fptr1;
FILE *fptr2;
FILE *fptr3;
FILE *fptr4;

int main() {
    clock_t tiempo_inicio, tiempo_final;
    double segundos;
    tiempo_inicio = clock();

    long N = 50000;
    double h, t, w, ab, k1, k2, k3, k4;
    double w0=0.7854,a=0,b=3.1416;
    int i;
    w=w0;

    fptr1=fopen("Kutta01.txt","w");
 	fprintf(fptr1, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
    fprintf(fptr1, "%f\t %f\n", a, w);
    for(i=0;i<N;i++) {
        h=(b-a)/N;
        t=a+(h*i);
        k1=h*(t*exp(3*t)-2*w);
        k2=h*((t+(h/2.0))*exp(3*(t+(h/2.0)))-2*(w+(0.5*k1)));
        k3=h*((t+(h/2.0))*exp(3*(t+(h/2.0)))-2*(w+(0.5*k2)));
        k4=h*((t+h)*exp(3*(t+h))-2*(w+k3));
        w=w+(1.0/6.0)*(k1+(2*k2)+(2*k3)+k4);
        fprintf(fptr1, "%f\t %f\n", t+h, w);
    }
    fclose(fptr1);

    w=w0;
    fptr2=fopen("Kutta02.txt","w");
    fprintf(fptr2, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
    fprintf(fptr2, "%f\t %f\n", a, w);
    for(i=0;i<N;i++) {
        h=(b-a)/N;
        t=a+(h*i);
        k1=h*(1+pow(t-w,2));
        k2=h*(1+pow((t+(h/2)-(w+(0.5*k1))),2));
        k3=h*(1+pow((t+(h/2)-(w+(0.5*k2))),2));
        k4=h*(1+pow((t+h)-(w+k3),2));
        w=w+(1.0/6.0)*(k1+(2*k2)+(2*k3)+k4);
        fprintf(fptr1, "%f\t %f\n", t+h, w);
    }
    fclose(fptr2);

    w=w0;
    fptr3=fopen("Kutta03.txt","w");
    fprintf(fptr3, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
    fprintf(fptr3, "%f\t %f\n", a, w);
    for(i=0;i<N;i++) {
        h=(b-a)/N;
        t=a+(h*i);
        k1=h*(1+(w/t));
        k2=h*(1+((w+(0.5*k1))/(t+(h/2))));
        k3=h*(1+((w+(0.5*k2))/(t+(h/2))));
        k4=h*(1+((w+k3)/(t+h)));
        w=w+(1.0/6.0)*(k1+(2*k2)+(2*k3)+k4);
        fprintf(fptr3, "%f\t %f\n", t+h, w);
    }
    fclose(fptr3);
    
    w=w0;
    fptr4=fopen("Kutta04.txt","w");
    fprintf(fptr4, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
    fprintf(fptr4, "%f\t %f\n", a, w);
    for(i=0;i<N;i++) {
        h=(b-a)/N;
        t=a+(h*i);
        k1=h*(cos(2*t*w)+sin(3*t*w));
        k2=h*(cos(2*(t+(h/2)*(w+(0.5*k1))))+sin(3*(t+(h/2)*(w+(0.5*k1)))));
        k3=h*(cos(2*(t+(h/2)*(w+(0.5*k2))))+sin(3*(t+(h/2)*(w+(0.5*k2)))));
        k4=h*(cos(2*(t+h)*(w+k3))+sin(3*(t+h)*(w+k3)));
        w=w+(1.0/6.0)*(k1+(2*k2)+(2*k3)+k4);
        fprintf(fptr4, "%f\t %f\n", t+h, w);
    }
    fclose(fptr4);

    tiempo_final = clock();
    segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
    printf("Runge-Kutta secuencial\n");
    printf("Tomo (%f) segundos",segundos);
}