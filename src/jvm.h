#ifndef FRAMEH
#define FRAMEH

#include "classfile.h"
#include "exibidor.h"
#include "leitor.h"

typedef struct stack{
    int altura;
    int32_t stackarr[99999];

}stack;

void stack_push(stack* pilha, int32_t elem);
void push_float_in_stack(stack* pilha, float valor_f);
void push_double_in_stack(stack* pilha, double valor_d);
int32_t stack_pop(stack* pilha);


typedef struct union_variables{
 
}union_variables;

typedef struct local_variable_vector{
    int tamanho;
    int32_t vetor[99999];
}local_variable_vector;


void insert_in_local_var_array(local_variable_vector* variaveis_vetor, int32_t elem, int indice);
int32_t get_from_array(local_variable_vector* variaveis_vetor, int indice);



typedef struct frame{
    local_variable_vector vetor_de_variaveis_locais;
    stack pilha_de_operandos;
    cp_info * constant_pool ;
    
}frame;


typedef struct field_variable {
    char* name;
} field_variable;


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
    char* name;
    char* descriptor;
    u2 flags;
}classfields;


typedef struct classdata{

}classdata;


typedef struct classcode{
    u4 tamanho_codigo;
    u1* code;
}classcode;

typedef struct classmethod{
    char* name;
    char* descriptor;
    u2 access_flags;
    classcode codigo;
} classmethod;



typedef struct method_area_item method_area_item;

struct method_area_item{
    char* class_name;
    method_area_item* father_class;

    Classfile* classfile;
    classdata data;

    u2 qtd_fields_estaticos;
    classfields* info_static_fields;

    u2 qtd_fields_nao_estaticos;
    classfields* info_non_static_fields;

    u2 qtd_metodos;
    classmethod* metodos;

    field_variable* static_fields;

};



typedef struct method_area {
    method_area_item* classes;
    int qtd_atual;
    int tamanho_total;
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
void readlocal_variable_vector(local_variable_vector *, Classfile*);
//implementar stack

///    Divisões prinicipais, carregamento e execução de classe
void carregamento(Classfile* classfile, method_area* area_metodos);
void code_exec(Jvm *);

///
void jvm_exec(Classfile *);    //Chamada pelo main

#endif
