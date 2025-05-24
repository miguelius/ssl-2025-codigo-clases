# Volumen 2 Capitulo 1 Ejercicio 14

En este ejercicio implementamos un autómata finito en C para el lenguaje regular de los números enteros en base 10 precedidos opcionalmente por un signo.

## Qué necesito?

- compilador de c más o menos moderno
- un IDE

## Cómo lo compilo?

Son programas de un solo archivo.

1. *algo1.c*: Algoritmo 1 para implementar un autómata usando estructuras de control de flujo.
2. *algo1-con-tt.c*: Algoritmo 1 usando una tabla de transición.
3. *algo2.c*: Algoritmo 2 usando la tabla de transición y el corte del recorrido ante el primer fallo.

Se compila así:

```
gcc algo1.c -o algo1
```

## Cómo lo corro

En linux

./algo1 6 1234 47822 +9876543210 000 123A "*66" 14.23

En windows con PwSh
\.algo1.exe 6 1234 47822 +9876543210 000 123A "*66" 14.23

Los números que quiero validar se pasan como argumentos del programa.

## Temas

- LR
- ER
- Autómatas finitos
- Tabla de transición
- Funciones de librería
- Agrupar caracteres.
- Vector de argumento
