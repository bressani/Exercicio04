// Arquivos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void leitura(char b[150]);
void Inverso(FILE *file, char n[1000]);
void binario(FILE *a);




int _tmain(int argc, _TCHAR* argv[])
{
	
	//Criando e escrevendo
	FILE *fP;
	fP = fopen("Not�cias.txt","w");
	fprintf(fP, "This is a terrifying news, be careful... \nOne day, there was a chicken, it was trying to cross the road, and then came a car and killed it.\nHorrible death.");
	fclose(fP);
	//fim

	printf("Lendo o Not�cias.txt: \n");
	leitura("Not�cias.txt");
	


	FILE *abcd;
	abcd = fopen("Not�cias.txt", "r");
	binario(abcd);

	printf("Lendo o Not�cias.bin:\n");
	leitura("Not�cias.bin");

	
	FILE *a = NULL;
	char name[1000];
	Inverso(a, name);


	
	

	
	return 0;
}

void leitura(char b[150]){
	char linhas[150];
	FILE *a;
	a = fopen(b, "r");

	while (!feof(a)){
		fgets(linhas, 150, a);
		puts(linhas);
	}
	printf("\n\n\n");
}



void binario(FILE *a){

	char b[150];
	FILE *fP3;
	fP3 = fopen("Not�cias.bin", "w");

	FILE *fP4;
	fP4 = fopen("Not�cias.txt", "r");

	while (!feof(fP4)){
		fgets(b, 150, fP4);
		fputs(b, fP3);

	}
	
	
	fclose(fP4);

	fclose(fP3);


}






void Inverso(FILE *file, char n[1000]){
	FILE *a = NULL;
	if ((file = fopen("Not�cias.txt", "wb+")) == NULL){
		printf("Arquivo n�o pode ser aberto.\n");
	}
	if ((a = fopen("Not�cias.bin", "r")) == NULL){
		printf("Arquivo n�o pode ser aberto.\n");
	}
	else {


		while (!feof(a)){
			fseek(a, 1000, SEEK_END);
			a -= sizeof(n);
			fputs(n, file);
			printf("%s", n);
		}

	}

	fclose(file);
}

