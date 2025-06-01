#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define FDT        -1

void vaciar_buffer(char buffer[]) {
  buffer[0] = '\0';
}

void agregar_al_final_del_buffer(char buffer[], char c) {
  int pos_buffer = 0;
  for ( ; buffer[pos_buffer] != 0 ; ++pos_buffer)
    ;
  buffer[pos_buffer] = c;
  buffer[pos_buffer+1] = '\0';
}

int reconocer(const char cadena[]);
int determinar_estado_para(int estado, char simbolo);
void manejar_estado(char buffer[], int estado, char caracter);

int main(int argc, const char *argv[]) {
    char buffer[4096] = "";
    int caracter_a_analizar;
    int estado = 0;
    
    while ((caracter_a_analizar = getchar())) {
      estado = determinar_estado_para(estado, caracter_a_analizar);
    
      manejar_estado(buffer, estado, caracter_a_analizar);
      
      if (estado == 4 || estado == 6) {
        break;
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
    } else if ('#' == simbolo ) {
        return 2;
    } else if (FDT == simbolo) {
        return 4;
    }
    return 3;
}

int determinar_estado_para(int estado, char simbolo) {
    static int TT[7][5] = {
    /*  TT    S  D  C  O fdt */
    /*  0-*/{ 1, 2, 0, 5, 6 },
    /*  1 */{ 5, 2, 0, 5, 6 },
    /*. 2 */{ 5, 2, 3, 5, 4 },
    /*  3+*/{ 1, 2, 0, 5, 6 },
    /*  4+*/{ 6, 6, 6, 6, 6 },
    /*  5 */{ 5, 5, 0, 5, 6 },  
    /*  6 */{ 6, 6, 6, 6, 6 }
    };
    return TT[estado][determinar_columna(simbolo)];
}

void manejar_estado(char buffer[], int estado, char caracter) {
      if (estado == 1) {
        vaciar_buffer(buffer);
        agregar_al_final_del_buffer(buffer, caracter);
      }
      if (estado == 2) {
        agregar_al_final_del_buffer(buffer, caracter);
      }
      
      if (estado == 3 || estado == 4) {
        puts(buffer);
        vaciar_buffer(buffer);
      }
      if (estado == 5) {
        vaciar_buffer(buffer);
      }
}
