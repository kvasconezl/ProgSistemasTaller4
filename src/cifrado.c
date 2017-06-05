#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cifrado.h"

char encriptado[1024]= {0};
char *cifradoCiclico(char *p, int c){
	
	char abecedario[60]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int tamanioAbc, tamanioP, i, j, validacion;
	tamanioAbc = strlen(abecedario);
	tamanioP = strlen(p);
	for (i = 0; i < tamanioP; i++){		
		validacion = 0;
		for (j = 0; j < tamanioAbc; j++){
			if(p[i] == abecedario[j]){
				if(j > 25- c && j < 26 || j > 51-c){
					encriptado[i] = abecedario[j+c-26];
				}
				else{
					encriptado[i] = abecedario[j+c];
				}
				validacion = 1;
			}
		}
		if (validacion == 0){encriptado[i] = p[i];}
	}
	return encriptado;


}

char encriptado1[100] = {0};
char *cifradoContrasenia(char *mensaje, char *llave){
	char ABECEDARIO[60] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, j, k, l,tamaniop;
	int validacion;
	int abc = 26;
	char nuevo[100] = {0};
	tamaniop = strlen(llave);
	for (i=0; i < abc; i++){
		if (i >= tamaniop){
			j = i - tamaniop;
			nuevo[i] = ABECEDARIO[j];		
		}
		else{nuevo[i] = toupper(llave[i]);}
	}
	for(k = 0; k < strlen(mensaje); k++){
		validacion = 0;
		for(l = 0; l < abc; l++){
			if(toupper(mensaje[k]) == ABECEDARIO[l]){
				encriptado[k] = nuevo[l];
				validacion = 1;
			}
			if (validacion == 0){
				encriptado[k] = mensaje[k];
			}
		}	
		
			
	}
	return encriptado1;
	
}

char encriptado2[1024]= {0};
char *cifradoAutollave(char *mensaje, char *llave){
	char palabra[1024];
	int i,j,k;
	int tamanioL = strlen(llave);
	int tamanioM = strlen(mensaje);
	int resta = tamanioM - tamanioL;
	int matriz[30][30] = {
{'-','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
{'A','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
{'B','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A'},
{'C','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B'},
{'D','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'},
{'E','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D'},
{'F','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E'},
{'G','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F'},
{'H','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G'},
{'I','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H'},
{'J','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I'},
{'K','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J'},
{'L','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K'},
{'M','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L'},
{'N','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'},
{'O','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N'},
{'P','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'},
{'Q','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'},
{'R','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q'},
{'S','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'},
{'T','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'},
{'U','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'},
{'V','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'},
{'W','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'},
{'X','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'},
{'Y','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'},
{'Z','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'}
}; 
	
	for(i = 0; i < tamanioL; i++){
		encriptado2[i] = toupper(llave[i]);
		if (llave[i] == ' ') {
			encriptado2[i] = ' ';
		}
	}
	for(j = 0; j < resta; j++){
		encriptado2[j+tamanioL] = toupper(mensaje[j]);
		if (mensaje[i] == ' ') {
			encriptado2[i] = ' ';
		}
		
	}
	return encriptado2;
}






