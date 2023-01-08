#include "classfile.h"

typedef struct stack{

}stack;

typedef struct union_variables{
 
}union_variables;

typedef struct local_variable_vector{
    union_variables variavel_union;

}local_variable_vector;

typedef struct frame{
    local_variable_vector vetor_de_variaveis_locais;
    stack pilha_de_operandos;
    cp_info * constant_pool ;
    
}frame;



typedef struct method_area{
    cp_info constant_pool;
}method_area;


typedef struct Jvm{
    void *pc;
    stack pilha_de_frames;
    method_area area_de_metodos;






}Jvm;