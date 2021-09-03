#include <stdio.h>
#include <omp.h>
#include <math.h>

#define NUM_THREADS 4

FILE *fptr1;
FILE *fptr2;
FILE *fptr3;
FILE *fptr4;

void main() {
    double t1, t2, tiempo;
    omp_set_num_threads(NUM_THREADS);
    const double startTime = omp_get_wtime();

    # pragma omp parallel 
    {
        # pragma omp sections
        {
            # pragma omp section
            {
                long N = 50000;
                double h, t, w, ab, k1, k2, k3, k4;
                double w0=0.7854,a=0,b=3.1416;
                int i;
                w=w0;
                printf("Runge-Kutta, numero de pasos:%d Atendido por thread:%d\n", N, omp_get_thread_num());
                fptr1=fopen("Kutta01.txt","w");
                fprintf(fptr1, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
                for(i=0;i<N;i++) {
                    h=(b-a)/N;
                    t=a+(h*i);
                    k1=h*(t*exp(3.0*t)-2.0*w);
                    k2=h*((t+(h/2.0))*exp(3.0*(t+(h/2.0)))-2*(w+(0.5*k1)));
                    k3=h*((t+(h/2.0))*exp(3.0*(t+(h/2.0)))-2*(w+(0.5*k2)));
                    k4=h*((t+h)*exp(3.0*(t+h))-2.0*(w+k3));
                    w=w+(1.0/6.0)*(k1+(2.0*k2)+(2.0*k3)+k4);
                    fprintf(fptr1, "%f\t %f \t numero de thread:%d\n", t+h, w, omp_get_thread_num());
                }
                fclose(fptr1);
            }
            #pragma omp section
            {
                long N = 50000;
                double h, t, w, ab, k1, k2, k3, k4;
                double w0=0.7854,a=0,b=3.1416;
                int i;
                w=w0;
                printf("Runge-Kutta, numero de pasos:%d Atendido por thread:%d\n", N, omp_get_thread_num());
                fptr2=fopen("Kutta02.txt","w");
                fprintf(fptr2, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
                for(i=0;i<N;i++) {
                    h=(b-a)/N;
                    t=a+(h*i);
                    k1=h*(1+pow(t-w,2));
                    k2=h*(1+pow((t+(h/2.0)-(w+(0.5*k1))),2));
                    k3=h*(1+pow((t+(h/2.0)-(w+(0.5*k2))),2));
                    k4=h*(1+pow((t+h)-(w+k3),2));
                    w=w+(1.0/6.0)*(k1+(2.0*k2)+(2.0*k3)+k4);
                    fprintf(fptr2, "%f\t %f \t numero de thread:%d\n", t+h, w, omp_get_thread_num());
                }
                fclose(fptr2);
            }
            #pragma omp section
            {
                long N = 50000;
                double h, t, w, ab, k1, k2, k3, k4;
                double w0=0.7854,a=0,b=3.1416;
                int i;
                w=w0;
                printf("Runge-Kutta, numero de pasos:%d Atendido por thread:%d\n", N, omp_get_thread_num());
                fptr3=fopen("Kutta03.txt","w");
                fprintf(fptr3, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
                for(i=0;i<N;i++) {
                    h=(b-a)/N;
                    t=a+(h*i);
                    k1=h*(1+(w/t));
                    k2=h*(1+((w+(0.5*k1))/(t+(h/2.0))));
                    k3=h*(1+((w+(0.5*k2))/(t+(h/2.0))));
                    k4=h*(1+((w+k3)/(t+h)));
                    w=w+(1.0/6.0)*(k1+(2.0*k2)+(2.0*k3)+k4);
                    fprintf(fptr3, "%f\t %f \t numero de thread:%d\n", t+h, w, omp_get_thread_num());
                }
                fclose(fptr3);
            }
            #pragma omp section
            {
                long N = 50000;
                double h, t, w, ab, k1, k2, k3, k4;
                double w0=0.7854,a=0,b=3.1416;
                int i;
                w=w0;
                printf("Runge-Kutta, numero de pasos:%d Atendido por thread:%d\n", N, omp_get_thread_num());
                fptr4=fopen("Kutta04.txt","w");
                fprintf(fptr4, "Datos que encuentra el metodo de Runge-Kutta(variable ind.\t variable dep.\t numero de thread)\n");
                for(i=0;i<N;i++) {
                    h=(b-a)/N;
                    t=a+(h*i);
                    k1=h*(cos(2.0*t*w)+sin(3.0*t*w));
                    k2=h*(cos(2.0*(t+(h/2.0)*(w+(0.5*k1))))+sin(3.0*(t+(h/2.0)*(w+(0.5*k1)))));
                    k3=h*(cos(2.0*(t+(h/2.0)*(w+(0.5*k2))))+sin(3.0*(t+(h/2.0)*(w+(0.5*k2)))));
                    k4=h*(cos(2.0*(t+h)*(w+k3))+sin(3.0*(t+h)*(w+k3)));
                    w=w+(1.0/6.0)*(k1+(2.0*k2)+(2.0*k3)+k4);
                    fprintf(fptr4, "%f\t %f \t numero de thread:%d\n", t+h, w, omp_get_thread_num());
                }
                fclose(fptr4);
            }
        }
    }
    const double endTime = omp_get_wtime();
    tiempo = t2-t1;
    printf("Tomo (%lf) segundos\n", (endTime-startTime));
}