#include <stdio.h>
#include "src/classfile.h"
#include "src/leitor.h"
#include "src/exibidor.h"
#include "src/jvm.h"
#include <string.h>
int main(int argc,char * argv[]){
	Classfile cf;
	char * filename;
	if (argc == 3){
		readFile(&cf,argv[1]);


		printf("Leitura Ok\n");

		if(strcmp(argv[2],"1")==0){
			printf("Execução iniciando\n");
			

		}
		else{
		printClassfile(&cf);
		}


	}
	else{
		printf("Nome de arquivo não encontrado ou mais de um nome inserido.\n");

		//teste opcode
		//int a = 0;
		//opcode op = a;
		//printf("%d eba %s", op, get_op_name(op));
	}

}
