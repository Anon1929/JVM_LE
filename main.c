#include <stdio.h>
#include "src/classfile.h"
#include "src/leitor.h"
#include "src/exibidor.h"
#include "src/jvm.h"
#include "src/instructions.h"
#include <string.h>
#include <stdlib.h>
extern void (*vetorfuncs[256])(Jvm *, frame*, classcode*);


int main(int argc,char * argv[]){
		
	
	Classfile cf;
	char * filename;
	
	if (argc == 3){
		readFile(&cf,argv[1]);

		printf("Leitura Ok\n");
		

		if(strcmp(argv[2],"1")==0){
			
			printf("Execução iniciando\n");
			
			load_instructions(vetorfuncs);

			Jvm *Javamaquina;
			Javamaquina = (Jvm *) malloc(sizeof(Jvm));
			
			method_area area_metodos;
			
			area_metodos.tamanho_total = 100;
			area_metodos.classes = (method_area_item*)malloc(sizeof(method_area_item)*area_metodos.tamanho_total);
						
			area_metodos.qtd_atual = 0;
									
			Javamaquina->area_de_metodos = area_metodos;
						
			carregamento(&cf, &Javamaquina->area_de_metodos, Javamaquina);


			jvm_exec(&Javamaquina->area_de_metodos, Javamaquina);


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
