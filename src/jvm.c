#include "exibidor.h"
#include "classfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitor.h"
#include "exibidor.h"
#include "jvm.h"

void readmethod_area(method_area * method_area, Classfile *classfile){
    //o classfile está chegando até aqui.
    method_area->classfile = (Classfile **)malloc(sizeof(Classfile *)*2);
    method_area->classfile[0] = classfile;
    method_area->tamanho = 1;
    char * super_classe = malloc(sizeof(char)*classfile->constant_pool[classfile->super_class].cp_info_union.utf_8_info.length);
    for(int i = 0; i < classfile->constant_pool[classfile->super_class].cp_info_union.utf_8_info.length; i++){
        super_classe[i] = decodeUTF8(classfile->constant_pool[classfile->super_class].cp_info_union.utf_8_info.bytes[i]);
    }
    strcat(super_classe, ".class");
    strcat(super_classe, "\0");
    strcat("/test/", super_classe);
    printf("%s", super_classe);
    FILE *super_class_file = fopen(super_classe, "rb");
    method_area->classfile[1] = (Classfile *)malloc(sizeof(Classfile));
    readFile(method_area->classfile[1], super_class_file);
    method_area->tamanho++;
    fclose(super_class_file);
    printClassfile(method_area->classfile[1]);

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

void carregamento(Jvm *jvm, Classfile * classfile){
    method_area area_de_metodos;
    readmethod_area(&area_de_metodos, classfile);
    jvm->area_de_metodos = area_de_metodos;
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
    carregamento(&jvm, classfile);
    // printClassfile(jvm.area_de_metodos.classfile[0]);

}
