#include "instructions.h"
#include "jvm.h"
#include <stddef.h>
#include "exibidor.h"

void func_nop(Jvm * jvm,frame* frame_atual){
    jvm->pc++; 
}

void func_aconst_null(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) NULL);
    jvm->pc++;
}

void func_iconst_m1(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) -1 );
    jvm->pc++;
}

void func_iconst_0(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    jvm->pc++;
}

void func_iconst_1(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 1 );
    jvm->pc++;
}

void func_iconst_2(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 2 );
    jvm->pc++;
}

void func_iconst_3(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 3 );
    jvm->pc++;
}


void func_iconst_4(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 4 );
    jvm->pc++;
}


void func_iconst_5(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 5 );
    jvm->pc++;
}

void func_lconst_0(Jvm * jvm, frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    jvm->pc++;
}

void func_lconst_1(Jvm * jvm, frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 1 );
    jvm->pc++;
}

void func_fconst_0(Jvm * jvm, frame* frame_atual){

}






void load_instructions( void (*op_func[256])(Jvm*,frame*) ){
    op_func[nop] = func_nop;



// fazer regex para colocar





}

//op_func[x](frame_atual,);