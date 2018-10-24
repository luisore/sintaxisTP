# sintaxisTP
TP Anual Sintaxis
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
  
  ejecutar en consola con el parametro: 0123F#0.1#1.#99F#5F#9.0#99999#FFFFF#9.1F
 ============================================================================
