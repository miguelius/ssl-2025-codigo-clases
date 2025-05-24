#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
- Carácter a analizar: primer carácter de la cadena
- Estado actual del autómata: estado inicial
- Mientras haya caracteres en la cadena, repetir:
(1) Determinar el nuevo estado actual (estado de llegada de la
transición)
(2) Actualizar el carácter a analizar
- Si el último estado actual es un estado final, entonces la cadena
procesada es una palabra del lenguaje; caso contrario, la cadena no
pertenece al lenguaje.
*/
int reconocer(const char cadena[]);

int main(int argc, const char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (reconocer(argv[i])) {
            puts(argv[i]);
        }
    }
    return 0;
}

#define SIMBOLOS "+-"

/**
 * Si existe el elemento en la cadena de caracteres devuelve 1
 * Si no existe devuelve 0
 */
int existe_en(char simbolo, const char *cadena_de_simbolos) {
    for (int i=0; cadena_de_simbolos[i]; ++i) {
        if ( simbolo ==  cadena_de_simbolos[i] )
            return 1;
    }
    return 0;
}

int determinar_estado_para(int estado, char simbolo) {
    switch (estado) {
        case 0:
        if (isdigit(simbolo)) {
            return 2;
        }
        if (existe_en(simbolo, SIMBOLOS)) {
            return 1;
        }
        break;
        case 1:
        if (isdigit(simbolo)) {
            return 2;
        }
        break;
        case 2:
        if (isdigit(simbolo)) {
            return 2;
        }
        break;
    }
    return 3;
}

#define CENTINELA         '\0'
#define ESTADO_ACEPTACION   2

int reconocer(const char cadena[]) {
    int pos = 0;
    char caracter_a_analizar = cadena[pos];
    int estado = 0;
    while (caracter_a_analizar != CENTINELA) {
        estado = determinar_estado_para(estado, caracter_a_analizar);
        ++pos;
        caracter_a_analizar = cadena[pos];
    }

    // verificar estado es final
    if (estado == ESTADO_ACEPTACION)
        return 1;
    return 0;
}

