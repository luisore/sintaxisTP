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
		int i,j;
		for (i = 0; i < ROWS; ++i) {
			for (j = 0; j < COLS; ++j) {
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
		int var;
		for (var = 0; var < COLS; ++var) {
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

	char ** lista_palabras = NULL;
	int cantidad_palabras = 0;
	void agregar_palabra(char *palabra, char **lista_palabras){
		printf("palabra: %s \n",palabra);
		//lista_palabras = (char**)realloc(lista_palabras, cantidad_palabras * sizeof(char*));
		//lista_palabras[cantidad_palabras++] = strdup(palabra);

/*
		while(*lista_palabras != NULL){
			cantidad_palabras++;
			lista_palabras++;
		}
		printf("%d",cantidad_palabras);
*/
		//lista_palabras = (char**)realloc(lista_palabras, cantidad_palabras * sizeof(char*));

		//lista_palabras[cantidad_palabras] = strdup(palabra);


	}

	void mostrar_palabras_reconocidas(){
		puts("Palabras Encontradas:");
		int i = 0;
		puts("ljhdjldda");
		printf("saada %s",lista_palabras[0]);
		while(*lista_palabras != NULL){
			printf("palabra: %s \n",lista_palabras[i++]);
			lista_palabras++;
		}
	}

	char buffer_palabra[15];
	int contador_caracter_palabra = 0;
	while(--argc>0){
		printf("Entrada %s\n\n",*++argv);
		char estado_actual = '0';
		char caracter = '\0';
		int iteracion;
		for (iteracion = 0; iteracion < strlen(*argv); ++iteracion) {
			caracter = (*argv)[iteracion];
			buffer_palabra[contador_caracter_palabra]=caracter;
			estado_actual = buscar_nuevo_estado(estado_actual,caracter);
			imprimir_caracter_y_estado(iteracion, caracter,estado_actual);
			contador_caracter_palabra++;
			contador_caracter_palabra = (estado_actual=='0') ? 0 : contador_caracter_palabra;
			if(estado_actual=='6'){
				buffer_palabra[--contador_caracter_palabra]='\0';
				agregar_palabra(buffer_palabra,lista_palabras);
				contador_caracter_palabra = 0;
			}
		}
		//mostrar_palabras_reconocidas();
	}

	return EXIT_SUCCESS;
}
