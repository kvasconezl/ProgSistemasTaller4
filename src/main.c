#include <stdio.h>
#include "../include/cifrado.h"
#include "../include/codificacion.h"

main(){
	char valor[1];
	int clave;
	char palabra[1024], llave[1024];
	printf("Ingrese el tipo de cifrado por favor, (C), (A), (P)\n");
	gets(valor);
	if(valor == "C" || valor == "c"){
		printf("Cidrafo Ciclico\n")
		printf("Ingrese la clave: \n");
		gets(clave);
		printf("Ingrese el mensaje: \n");
		gets(palabra);
		printf("Mensaje cifrado: %s", cifradoCilico(palabra, clave));
		printf("Codigo Morse: ");
		claveMorse(cifradoCilico(palabra, clave));
	}
	if(valor == "P" || valor == "p"){
		printf("Cidrafo Ciclico\n")
		printf("Ingrese el mensaje: \n");
		gets(palabra);
		printf("Ingrese la llave: \n");
		gets(llave);
		printf("Mensaje cifrado: %s", cifradoContrasenia(palabra))
	}
}
