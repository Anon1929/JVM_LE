#include "exibidor.h"
#include "classfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jvm.h>
#include "leitor.h"
#include "exibidor.h"

void readmethod_area(method_area * method_area, Classfile *classfile){
    method_area->classfile = (Classfile **)malloc(sizeof(Classfile *));
    method_area->classfile[0] = classfile;
    //falta o caso em que a super classe não é object, ou seja, será necessário carregar todos os classfiles
    //em diante até chegar na object
    while(classfile->super_class != 0){
        char *nome_da_super_classe = getUtf8(classfile->constant_pool, classfile->super_class);
        Classfile *super_class = (Classfile *)malloc(sizeof(Classfile));
        readFile(super_class, nome_da_super_classe); //lendo o classfile da super classe
        method_area->classfile = (Classfile **)realloc(method_area->classfile, sizeof(Classfile *) * (method_area->tamanho + 1));
        method_area->classfile[method_area->tamanho] = super_class;
        method_area->tamanho++;
    }
}

void readframe(frame *frame, Classfile *classfile){
    frame->pc = NULL;
    readlocal_variable_vector(&frame->vetor_de_variaveis_locais, classfile);
    frame->pilha_de_operandos.topo = NULL;
    frame->pilha_de_operandos.tamanho = 0;
    frame->constant_pool = classfile->constant_pool;
}
void readlocal_variable_vector(local_variable_vector *local_variable_vector, Classfile *classfile){
    
}

void carregamento(Classfile * classfile){
    method_area area_de_metodos;
    readmethod_area(&area_de_metodos, classfile);
}

void code_exec(Jvm *jvm, Classfile *classfile){
    frame *frame;
    readframe(&frame, classfile);
    jvm->pc = NULL; //Como iremos contar o valor de pc?
    jvm->pilha_de_frames.topo = frame;
    jvm->pilha_de_frames.tamanho++;
    readmethod_area(&jvm->area_de_metodos, classfile);

}


void jvm_exec(Classfile *classfile){
    Jvm jvm;
    code_exec(&jvm, classfile);


}
