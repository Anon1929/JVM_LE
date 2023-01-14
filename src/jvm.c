#include "jvm.h"

void stack_push(stack* pilha, int32_t elem){
    pilha->altura++;
    pilha->stackarr[pilha->altura-1]=elem;
}

int32_t stack_pop(stack* pilha){
    --(pilha->altura);
    return pilha->stackarr[pilha->altura];
}
void local_variable_vector_push(local_variable_vector* vetor, int32_t elem, int32_t index){
    vetor->variavel_union[index]=elem;
}

