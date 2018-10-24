/*
 ============================================================================
	 Algoritmo 3
	- Intenta leer primer carácter del texto (porque el texto puede estar
	vacío)
	- Mientras no sea fdt, repetir:
	(1) Estado actual del autómata: estado inicial
	(2) Mientras no sea un estado final y no sea el estado FDT, repetir:
	(2.1) Determinar el nuevo estado actual
	(2.2) Actualizar el carácter a analizar
	(3) Si el estado es final, la cadena procesada es una constante entera;
	caso contrario, la cadena no pertenece al lenguaje.

	ER [0-9]+F|[0-9]\.[01]? Centinela: #
	(VALIDAS)			   |	(NO VALIDAS)
	0123F#0.1#1.#99F#5F#9.0#99999#FFFFF#9.1F
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ROWS 10
#define COLS 15

char tabla_transiciones[10][15] = {
	{'-','0','1','2','3','4','5','6','7','8','9','.','F','#','f'},
	{'0','1','1','1','1','1','1','1','1','1','1','5','5','0','7'},
	{'1','2','2','2','2','2','2','2','2','2','2','3','4','0','7'},
	{'2','2','2','2','2','2','2','2','2','2','2','5','4','0','7'},
	{'3','4','4','5','5','5','5','5','5','5','5','5','5','6','8'},
	{'4','5','5','5','5','5','5','5','5','5','5','5','5','6','8'},
	{'5','5','5','5','5','5','5','5','5','5','5','5','5','0','7'},
	{'6','1','1','1','1','1','1','1','1','1','1','5','5','0','7'},
	{'7','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'8','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
};
//Estados de aceptacion 6, Aceptacion y fin de texto 8
//Estado fin de texto 7

int main(int argc, char *argv[]) {

	void imprimir(char tabla[ROWS][COLS]){
		puts("/////TABLA TRANSICIONES/////");
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				printf("%c ",tabla[i][j]);
			}
			puts("");
		}
		puts("///FIN TABLA TRANSICIONES///\n");
	}
	imprimir(tabla_transiciones);

	void imprimir_caracter_y_estado(char contador,char caracter, char estado){
		printf("Caracter %d: %c Estado Actual: %c\n", contador, caracter,estado);
	}
	
	int obtener_row(char estado_actual){
		return (estado_actual - '0') + 1;
	}

	int obtener_col(char caracter_leido){
		for (int var = 0; var < COLS; ++var) {
			if(tabla_transiciones[0][var] == caracter_leido){
				return var;
			}
			//return "other character";
		}
	}

	char buscar_nuevo_estado(char estado_actual,char caracter_leido){
		int row_number = obtener_row(estado_actual);
		int col_number = obtener_col(caracter_leido);
		return tabla_transiciones[row_number][col_number];
	}

	while(--argc>0){
		printf("Entrada %s\n\n",*++argv);
		char estado_actual = '0';
		char caracter = '\0';
		for (int var = 0; var < strlen(*argv); ++var) {
			caracter = (*argv)[var];
			estado_actual = buscar_nuevo_estado(estado_actual,caracter);
			imprimir_caracter_y_estado(var, caracter,estado_actual);
			if(estado_actual=='6'){
				puts("encontre palabra perroohh!!!");
			}
		}
	}

	return EXIT_SUCCESS;
}
