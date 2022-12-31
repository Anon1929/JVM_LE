#include <stdio.h>
#include "src/classfile.h"
#include "src/leitor.h"

int main(int argc,char * argv[]){
	Classfile cf;
	char * filename;
	if (argc == 2){
		readFile(&cf,argv[1]);

	}
	else{
		printf("Nome de arquivo não encontrado ou mais de um nome inserido.\n");
	}
	printf("Ok\n");
}
