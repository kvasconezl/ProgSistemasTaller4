#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/codificacion.h"

void claveMorse(char *p){
	int tamanio, i, j, validacion;
	char abecedario[60] = "abcdefghijklmnopqrstuvwxyz 0123456789";
	char ABECEDARIO[60] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
	char morse[60][40]={".-","—···","-·-·","-··",".","··-·","--·","····","··","·---","-·-","·-··","--","-·","---","·--·",
			    "--·-","·-·","···","-","··-","···-","·--","-··-","-·--","--··","/","·----","··---","···--","····-","·····",
	  		    "-····","--···","---··","----·","-----"};

	tamanio = strlen(p);
	for (i = 0; i < tamanio; i++){
		validacion = 0;
		for(j = 0; j < strlen(abecedario); j++){
			if(p[i] == abecedario[j] || p[i] == ABECEDARIO[j]){
				printf("%s ",morse[j]);
				validacion = 1;
			}
		}
		if (validacion == 0){
			printf("%s ",p[i]);
		}
	}
}

