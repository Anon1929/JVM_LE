#include <stdio.h>
#include "src/classfile.h"
#include "src/leitor.h"
#include "src/exibidor.h"
#include "src/jvm.h"
#include "src/instructions.h"
#include <string.h>
#include <stdlib.h>
int main(int argc,char * argv[]){
	Classfile cf;
	char * filename;
	if (argc == 3){
		readFile(&cf,argv[1]);


		printf("Leitura Ok\n");

		if(strcmp(argv[2],"1")==0){
			printf("Execução iniciando\n");
			// jvmexec(&cf);
			
			
			method_area area_metodos;

			area_metodos.tamanho_total = 100;
			area_metodos.classes = (method_area_item*)malloc(sizeof(method_area_item)*area_metodos.tamanho_total);
			area_metodos.qtd_atual = 0;
			carregamento(&cf, &area_metodos);
			

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
