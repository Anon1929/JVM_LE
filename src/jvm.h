#ifndef FRAMEH
#define FRAMEH

#include "classfile.h"

typedef struct stack{
    int altura;
    int32_t stackarr[99999];

}stack;

void stack_push(stack* pilha, int32_t elem);

int32_t stack_pop(stack* pilha);

typedef struct frame{
    int32_t vetor_de_variaveis_locais[99999];
    stack pilha_de_operandos;
    cp_info * constant_pool ;
    
}frame;



/*
Class{
    field a;
    mehotd(c){
        data e;
        code
        code
        code
    }
}

*/

typedef struct classfields{

}classfields;

typedef struct classdata{

}classdata;

typedef struct classcode{

}classcode;



typedef struct method_area{
    cp_info constant_pool;
    classfields fields;
    classdata data;
    classcode code;
}method_area;


typedef struct Jvm{
    void *pc;
    stack pilha_de_frames;
    method_area area_de_metodos;

}Jvm;

// Union Variables

void readmethod_area(method_area *,Classfile *);
// readclassdata readclasscode readclassfeild

void readframe(frame *,Classfile*);
void readlocal_variable_vector(int32_t vetor[], Classfile*);
//implementar stack

///    Divisões prinicipais, carregamento e execução de classe
void carregamento(Classfile *);
void code_exec(Jvm *);

///
void jvm_exec(Classfile *);    //Chamada pelo main

#endif