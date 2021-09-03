# Actividad-1.6-Multiprocesadores

## Instrucciones
Desarrollar 2 programas que resuelvan las siguientes ecuaciones diferenciales de forma numérica usando el método de Runge-Kutta de orden 4:
- y' = te^(3t) - 2y
- y' = 1 + (t - y)^2
- y' = 1 + y / t
- y' = cos(2ty) + sen(3ty)

En el intervalo [0, PI] (con 50,000 puntos en el intervalo de evaluación). Para todas las ecuaciones la condición inicial es y(0) = PI / 4. Se debe de entregar un archivo por cada una de las soluciones determinadas en el programa.

Uno de los programas a desarrollar deberá hacerlo de forma secuencial y el otro en forma paralela usando task level parallelism (TLP).
