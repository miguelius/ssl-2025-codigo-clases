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

int determinar_columna(int simbolo) {
    if (existe_en(simbolo, SIMBOLOS)) {
        return 0;
    } else if (isdigit(simbolo)) {
        return 1;
    }
    return 2;
}

/*
     0 1 2
TT | S D O
---+-------
0- | 1 2 3
1  | 3 2 3
2+ | 3 2 3
3  | 3 3 3
*/
int determinar_estado_para(int estado, char simbolo) {
    static int TT[4][3] = {
    /*            S  D  O */
    /* 0- */    { 1, 2, 3},
    /* 1  */    { 3, 2, 3},
    /* 2+ */    { 3, 2, 3},
    /* 3  */    { 3, 3, 3}
    };
    return TT[estado][determinar_columna(simbolo)];
}

#define CENTINELA         '\0'
#define ESTADO_ACEPTACION   2

/* ALGO 1 */
int reconocer(const char cadena[]) {
    int pos = 0;
    char caracter_a_analizar = cadena[pos];
    int estado = 0;
    while (
        caracter_a_analizar != CENTINELA
        
    ) {
        estado = determinar_estado_para(estado, caracter_a_analizar);
        ++pos;
        caracter_a_analizar = cadena[pos];
    }

    // verificar estado es final
    if (estado == ESTADO_ACEPTACION)
        return 1;
    return 0;
}

