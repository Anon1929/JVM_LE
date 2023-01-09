#include "classfile.h"

typedef struct stack{
    void *topo;
    void *base;
    int tamanho;
    //Implementação da "classe" stack

}stack;

typedef struct union_variables{
    //tipos de dados: numérico (integral e ponto flutuante), booleano e o tipo returnAddress
    //tipos de referência: array, objeto e string
    int inteiro;
    float flutuante;
    double flutuante_duplo;
    void *returnAddress;
    void *array;
    void *objeto;
    void *string;
    //Será que é preciso ter unions para todos os tipos integrais?

}union_variables;

typedef struct local_variable_vector{
    union_variables variavel_union;


}local_variable_vector;

typedef struct frame{
    //O pc é um ponteiro para o código da JVM que está sendo executado no momento
    //A presença do pc no frame é opcional
    void *pc;
    local_variable_vector vetor_de_variaveis_locais;
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

typedef struct method_area{
    Classfile ***classfile; //ponteiro para um array de ponteiros para classfile
    int tamanho;

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
void carregamento(Classfile *);
void code_exec(Jvm *, Classfile *);

///
void jvm_exec(Classfile *);    //Chamada pelo main
