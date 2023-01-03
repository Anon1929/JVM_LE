#include <stdio.h>
#include "src/classfile.h"
#include "src/leitor.h"
#include "src/exibidor.h"
int main(int argc,char * argv[]){
	Classfile cf;
	char * filename;
	if (argc == 2){
		readFile(&cf,argv[1]);


		printf("Leitura Ok\n");
		printClassfile(&cf);


	}
	else{
		printf("Nome de arquivo não encontrado ou mais de um nome inserido.\n");

		//teste opcode
		//int a = 0;
		//opcode op = a;
		//printf("%d eba %s", op, get_op_name(op));
	}

}
