#include "instructions.h"
#include "jvm.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "exibidor.h"
#include <string.h>

void func_nop(Jvm * jvm,frame* frame_atual){/*
    jvm->pc++; 
*/}

void func_aconst_null(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) NULL);
    jvm->pc++;
*/}

void func_iconst_m1(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) -1 );
    jvm->pc++;
*/}

void func_iconst_0(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    jvm->pc++;
*/}

void func_iconst_1(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 1 );
    jvm->pc++;
*/}

void func_iconst_2(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 2 );
    jvm->pc++;
*/}

void func_iconst_3(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 3 );
    jvm->pc++;
*/}


void func_iconst_4(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 4 );
    jvm->pc++;
*/}


void func_iconst_5(Jvm * jvm,frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 5 );
    jvm->pc++;
*/}

void func_lconst_0(Jvm * jvm, frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    jvm->pc++;
*/}

void func_lconst_1(Jvm * jvm, frame* frame_atual){/*
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 0 );
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) 1 );
    jvm->pc++;
*/}
// começo instrucoes vinicius
void func_fconst_0(Jvm * jvm, frame* frame_atual){/*
    float temp_float = 0.0;
    int32_t* valor_pilha;   //Ponteiro é utilizado para o memcpy ser feito corretamente sem problemas de casting
    valor_pilha = (int32_t*) malloc(sizeof(int32_t));
    memcpy(valor_pilha, &temp_float, sizeof(int32_t));    
    stack_push(&(frame_atual->pilha_de_operandos),*valor_pilha);

*/}

void func_fconst_1(Jvm * jvm, frame* frame_atual){/*
    float temp_float = 1.0;
    int32_t* valor_pilha; 
    valor_pilha = (int32_t*) malloc(sizeof(int32_t));
    memcpy(valor_pilha, &temp_float, sizeof(int32_t));    
    stack_push(&(frame_atual->pilha_de_operandos),*valor_pilha);
*/}
void func_fconst_2(Jvm * jvm, frame* frame_atual){/*
    float temp_float = 2.0;
    int32_t* valor_pilha; 
    valor_pilha = (int32_t*) malloc(sizeof(int32_t));
    memcpy(valor_pilha, &temp_float, sizeof(int32_t));    
    stack_push(&(frame_atual->pilha_de_operandos),*valor_pilha);

*/}
void func_dconst_0(Jvm * jvm, frame* frame_atual){/*
    double temp_double = 0.0; 
    int64_t *temp_int; 
    int32_t high_bits;
    int32_t low_bits;
    temp_int = (int64_t*) malloc(sizeof(int64_t));
    memcpy(temp_int, &temp_double, sizeof(int64_t));  // procedimento parecido com o de float, porém divido em duas partes
    high_bits = (*temp_int) >>32;
    low_bits = (*temp_int) & 0xffffffff;
    stack_push(&(frame_atual->pilha_de_operandos),high_bits);
    stack_push(&(frame_atual->pilha_de_operandos),low_bits);

*/}
void func_dconst_1(Jvm * jvm, frame* frame_atual){/*
    double temp_double = 1.0; 
    int64_t *temp_int; 
    int32_t high_bits;
    int32_t low_bits;
    temp_int = (int64_t*) malloc(sizeof(int64_t));
    memcpy(temp_int, &temp_double, sizeof(int64_t));  
    high_bits = (*temp_int) >>32;
    low_bits = (*temp_int) & 0xffffffff;
    stack_push(&(frame_atual->pilha_de_operandos),high_bits);
    stack_push(&(frame_atual->pilha_de_operandos),low_bits);

*/}
void func_bipush(Jvm * jvm, frame* frame_atual){/*

    int8_t *argumento_operando = (int8_t) (jvm->pc);
    stack_push(&(frame_atual->pilha_de_operandos),(int32_t) *(argumento_operando+1));
    jvm->pc++;
    jvm->pc++;

*/}
void func_sipush(Jvm * jvm, frame* frame_atual){/*

    int8_t *argumento_operando = (int8_t) (jvm->pc);
    int32_t valor = (*(argumento_operando+1)) << 8 + *(argumento_operando+2);
    stack_push(&(frame_atual->pilha_de_operandos),valor);
    jvm->pc++;
    jvm->pc++;
    jvm->pc++;

*/}
void func_ldc(Jvm * jvm, frame* frame_atual){/*

*/}
void func_ldc_w(Jvm * jvm, frame* frame_atual){/*

*/}
void func_ldc2_w(Jvm * jvm, frame* frame_atual){/*

*/}
void func_iload(Jvm * jvm, frame* frame_atual){/*

*/}
void func_lload(Jvm * jvm, frame* frame_atual){/*

*/}
void func_fload(Jvm * jvm, frame* frame_atual){/*

*/}
void func_dload(Jvm * jvm, frame* frame_atual){/*

*/}
void func_aload(Jvm * jvm, frame* frame_atual){/*
    int8_t *argumento_operando = (int8_t) (jvm->pc);
    int32_t index = *(argumento_operando+1);
    //stack_push(&(frame_atual->pilha_de_operandos),frame_atual->vetor_de_variaveis_locais[index]);
*/}
void func_iload_0(Jvm * jvm, frame* frame_atual){/*
    int32_t valor = frame_atual->vetor_de_variaveis_locais[0];
    stack_push(&(frame_atual->pilha_de_operandos),valor);
    jvm->pc++;
*/}
void func_iload_1(Jvm * jvm, frame* frame_atual){/*
    int32_t valor = frame_atual->vetor_de_variaveis_locais[1];
    stack_push(&(frame_atual->pilha_de_operandos),valor);
    jvm->pc++;
*/}
void func_iload_2(Jvm * jvm, frame* frame_atual){/*
    int32_t valor = frame_atual->vetor_de_variaveis_locais[2];
    stack_push(&(frame_atual->pilha_de_operandos),valor);
    jvm->pc++;

*/}
void func_iload_3(Jvm * jvm, frame* frame_atual){/*
    int32_t valor = frame_atual->vetor_de_variaveis_locais[3];
    stack_push(&(frame_atual->pilha_de_operandos),valor);
    jvm->pc++;
*/}
void func_lload_0(Jvm * jvm, frame* frame_atual){/*
    int32_t high_bits, low_bits;
    high_bits = frame_atual->vetor_de_variaveis_locais[0];
    low_bits  = frame_atual->vetor_de_variaveis_locais[1]; 
    stack_push(&(frame_atual->pilha_de_operandos),high_bits);
    stack_push(&(frame_atual->pilha_de_operandos),low_bits);
    jvm->pc++;
*/}

void func_lload_1(Jvm * jvm, frame* frame_atual){/*
    int32_t high_bits, low_bits;
    high_bits = frame_atual->vetor_de_variaveis_locais[1];
    low_bits  = frame_atual->vetor_de_variaveis_locais[2]; 
    stack_push(&(frame_atual->pilha_de_operandos),high_bits);
    stack_push(&(frame_atual->pilha_de_operandos),low_bits);
    jvm->pc++;

*/}

void func_lload_2(Jvm * jvm, frame* frame_atual){/* 
    int32_t high_bits, low_bits;
    high_bits = frame_atual->vetor_de_variaveis_locais[2];
    low_bits  = frame_atual->vetor_de_variaveis_locais[3]; 
    stack_push(&(frame_atual->pilha_de_operandos),high_bits);
    stack_push(&(frame_atual->pilha_de_operandos),low_bits);
    jvm->pc++;
*/}
// termina instruct vinicius


// isntruções Welliton 

void func_lload_3(Jvm * jvm,frame* frame_atual){
    stack_push(&(frame_atual->pilha_de_operandos), 0);
    stack_push(&(frame_atual->pilha_de_operandos), 3);
    jvm->pc++;
}

void func_fload_0(Jvm * jvm,frame* frame_atual){
    push_float_in_stack(&(frame_atual->pilha_de_operandos), 0);
    jvm->pc++;
}

void func_fload_1(Jvm * jvm,frame* frame_atual){
    push_float_in_stack(&(frame_atual->pilha_de_operandos), 1);
    jvm->pc++;
}

void func_fload_2(Jvm * jvm,frame* frame_atual){
    push_float_in_stack(&(frame_atual->pilha_de_operandos), 2);
    jvm->pc++;
}

void func_fload_3(Jvm * jvm,frame* frame_atual){
    push_float_in_stack(&(frame_atual->pilha_de_operandos), 3);
    jvm->pc++;
}

void func_dload_0(Jvm * jvm,frame* frame_atual){
    push_double_in_stack(&(frame_atual->pilha_de_operandos), 0);
    jvm->pc++;
}

void func_dload_1(Jvm * jvm,frame* frame_atual){
    push_double_in_stack(&(frame_atual->pilha_de_operandos), 1);
    jvm->pc++;
}
void func_dload_2(Jvm * jvm,frame* frame_atual){
    push_double_in_stack(&(frame_atual->pilha_de_operandos), 2);
    jvm->pc++;
}

void func_dload_3(Jvm * jvm,frame* frame_atual){
    push_double_in_stack(&(frame_atual->pilha_de_operandos), 3);
    jvm->pc++;
}

void func_aload_0(Jvm * jvm,frame* frame_atual){
    void* referencia = get_reference_from_local_var_array((frame_atual->vetor_de_variaveis_locais), 0);
    stack_push_reference(&(frame_atual->pilha_de_operandos), referencia);
    jvm->pc++;
}
void func_aload_1(Jvm * jvm,frame* frame_atual){
    void* referencia = get_reference_from_local_var_array((frame_atual->vetor_de_variaveis_locais), 1);
    stack_push_reference(&(frame_atual->pilha_de_operandos), referencia);
    jvm->pc++;
}
void func_aload_2(Jvm * jvm,frame* frame_atual){
    void* referencia = get_reference_from_local_var_array((frame_atual->vetor_de_variaveis_locais), 2);
    stack_push_reference(&(frame_atual->pilha_de_operandos), referencia);
    jvm->pc++;
}
void func_aload_3(Jvm * jvm,frame* frame_atual){
    void* referencia = get_reference_from_local_var_array((frame_atual->vetor_de_variaveis_locais), 3);
    stack_push_reference(&(frame_atual->pilha_de_operandos), referencia);
    jvm->pc++;
}

void func_iaload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    int32_t* vetor_int = arrayref->vetor;
    stack_push(&(frame_atual->pilha_de_operandos), vetor_int[indice]);
    jvm->pc++;
}


void func_laload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    int64_t* vetor_long = arrayref->vetor;
    push_long_in_stack(&(frame_atual->pilha_de_operandos), vetor_long[indice]);
    jvm->pc++;
}


void func_faload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    float* vetor_float = arrayref->vetor;
    push_float_in_stack(&(frame_atual->pilha_de_operandos), vetor_float[indice]);
    jvm->pc++;
}


void func_daload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    double* vetor_double = arrayref->vetor;
    push_double_in_stack(&(frame_atual->pilha_de_operandos), vetor_double[indice]);
    jvm->pc++;
}

void func_aaload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    void** vetor_referencias = arrayref->vetor;
    stack_push_reference(&(frame_atual->pilha_de_operandos), vetor_referencias[indice]);
    jvm->pc++;

}
void func_baload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    int8_t* vetor_bytes = arrayref->vetor;
    stack_push(&(frame_atual->pilha_de_operandos), (int32_t)vetor_bytes[indice]);
    jvm->pc++;
}

void func_caload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    uint16_t* vetor_char = arrayref->vetor;
    stack_push(&(frame_atual->pilha_de_operandos), (int32_t)vetor_char[indice]);
    jvm->pc++;
}

void func_saload(Jvm * jvm,frame* frame_atual){
    int32_t aux =  stack_pop(&(frame_atual->pilha_de_operandos));
    uint32_t indice;
    memcpy(&indice,&aux,4);

    Array* arrayref = stack_pop_reference(&(frame_atual->pilha_de_operandos));
    int16_t* vetor_short = arrayref->vetor;
    stack_push(&(frame_atual->pilha_de_operandos), (int32_t)vetor_short[indice]);
    jvm->pc++;
}
void func_istore(Jvm * jvm, frame* frame_atual){

}
void func_lstore(Jvm * jvm, frame* frame_atual){

}
void func_fstore(Jvm * jvm, frame* frame_atual){

}
void func_dstore(Jvm * jvm, frame* frame_atual){

}
void func_astore(Jvm * jvm, frame* frame_atual){

}
void func_istore_0(Jvm * jvm,frame* frame_atual){
    int32_t valor = stack_pop(&(frame_atual->pilha_de_operandos));
    insert_in_local_var_array((frame_atual->vetor_de_variaveis_locais),valor,0);
    jvm->pc++;
}
void func_istore_1(Jvm * jvm,frame* frame_atual){
    int32_t valor = stack_pop(&(frame_atual->pilha_de_operandos));
    insert_in_local_var_array((frame_atual->vetor_de_variaveis_locais),valor,1);
    jvm->pc++;
}
// Welliton termina

// Arthur Começa
void func_istore_2(Jvm * jvm, frame* frame_atual){

}
void func_istore_3(Jvm * jvm, frame* frame_atual){

}
void func_lstore_0(Jvm * jvm, frame* frame_atual){

}
void func_lstore_1(Jvm * jvm, frame* frame_atual){

}
void func_lstore_2(Jvm * jvm, frame* frame_atual){

}
void func_lstore_3(Jvm * jvm, frame* frame_atual){

}
void func_fstore_0(Jvm * jvm, frame* frame_atual){

}
void func_fstore_1(Jvm * jvm, frame* frame_atual){

}
void func_fstore_2(Jvm * jvm, frame* frame_atual){

}
void func_fstore_3(Jvm * jvm, frame* frame_atual){

}
void func_dstore_0(Jvm * jvm, frame* frame_atual){

}
void func_dstore_1(Jvm * jvm, frame* frame_atual){

}
void func_dstore_2(Jvm * jvm, frame* frame_atual){

}
void func_dstore_3(Jvm * jvm, frame* frame_atual){

}
void func_astore_0(Jvm * jvm, frame* frame_atual){

}
void func_astore_1(Jvm * jvm, frame* frame_atual){

}
void func_astore_2(Jvm * jvm, frame* frame_atual){

}
void func_astore_3(Jvm * jvm, frame* frame_atual){

}
void func_iastore(Jvm * jvm, frame* frame_atual){

}
void func_lastore(Jvm * jvm, frame* frame_atual){

}
void func_fastore(Jvm * jvm, frame* frame_atual){

}
void func_dastore(Jvm * jvm, frame* frame_atual){

}
void func_aastore(Jvm * jvm, frame* frame_atual){

}
void func_bastore(Jvm * jvm, frame* frame_atual){

}
void func_castore(Jvm * jvm, frame* frame_atual){

}
void func_sastore(Jvm * jvm, frame* frame_atual){

}
void func_pop(Jvm * jvm, frame* frame_atual){

}
// Arthur termina

// Thiago começa

void func_pop2(Jvm * jvm, frame* frame_atual){

}
void func_dup(Jvm * jvm, frame* frame_atual){

}
void func_dup_x1(Jvm * jvm, frame* frame_atual){

}
void func_dup_x2(Jvm * jvm, frame* frame_atual){

}
void func_dup2(Jvm * jvm, frame* frame_atual){

}
void func_dup2_x1(Jvm * jvm, frame* frame_atual){

}
void func_dup2_x2(Jvm * jvm, frame* frame_atual){

}
void func_swap(Jvm * jvm, frame* frame_atual){

}
void func_iadd(Jvm * jvm, frame* frame_atual){

}
void func_ladd(Jvm * jvm, frame* frame_atual){

}
void func_fadd(Jvm * jvm, frame* frame_atual){

}
void func_dadd(Jvm * jvm, frame* frame_atual){

}
void func_isub(Jvm * jvm, frame* frame_atual){

}
void func_lsub(Jvm * jvm, frame* frame_atual){

}
void func_fsub(Jvm * jvm, frame* frame_atual){

}
void func_dsub(Jvm * jvm, frame* frame_atual){

}
void func_imul(Jvm * jvm, frame* frame_atual){

}
void func_lmul(Jvm * jvm, frame* frame_atual){

}
void func_fmul(Jvm * jvm, frame* frame_atual){

}
void func_dmul(Jvm * jvm, frame* frame_atual){

}
void func_idiv(Jvm * jvm, frame* frame_atual){

}
void func_inst_ldiv(Jvm * jvm, frame* frame_atual){

}
void func_fdiv(Jvm * jvm, frame* frame_atual){

}
void func_ddiv(Jvm * jvm, frame* frame_atual){

}
void func_irem(Jvm * jvm, frame* frame_atual){

}
void func_lrem(Jvm * jvm, frame* frame_atual){

}
void func_frem(Jvm * jvm, frame* frame_atual){

}
void func_inst_drem(Jvm * jvm, frame* frame_atual){

}
// Thiago termina

// Daniel Começa 
void func__drem(Jvm * jvm, frame* frame_atual){

}
void func_ineg(Jvm * jvm, frame* frame_atual){

}
void func_lneg(Jvm * jvm, frame* frame_atual){

}
void func_fneg(Jvm * jvm, frame* frame_atual){

}
void func_dneg(Jvm * jvm, frame* frame_atual){

}
void func_ishl(Jvm * jvm, frame* frame_atual){

}
void func_lshl(Jvm * jvm, frame* frame_atual){

}
void func_ishr(Jvm * jvm, frame* frame_atual){

}
void func_lshr(Jvm * jvm, frame* frame_atual){

}
void func_iushr(Jvm * jvm, frame* frame_atual){

}
void func_lushr(Jvm * jvm, frame* frame_atual){

}
void func_iand(Jvm * jvm, frame* frame_atual){

}
void func_land(Jvm * jvm, frame* frame_atual){

}
void func_ior(Jvm * jvm, frame* frame_atual){

}
void func_lor(Jvm * jvm, frame* frame_atual){

}
void func_ixor(Jvm * jvm, frame* frame_atual){

}
void func_lxor(Jvm * jvm, frame* frame_atual){

}
void func_iinc(Jvm * jvm, frame* frame_atual){

}
void func_i2l(Jvm * jvm, frame* frame_atual){

}
void func_i2f(Jvm * jvm, frame* frame_atual){

}
void func_i2d(Jvm * jvm, frame* frame_atual){

}
void func_l2i(Jvm * jvm, frame* frame_atual){

}
void func_l2f(Jvm * jvm, frame* frame_atual){

}
void func_l2d(Jvm * jvm, frame* frame_atual){

}
void func_f2i(Jvm * jvm, frame* frame_atual){

}
void func_f2l(Jvm * jvm, frame* frame_atual){

}
void func_f2d(Jvm * jvm, frame* frame_atual){

}
void func_d2i(Jvm * jvm, frame* frame_atual){

}
void func_d2l(Jvm * jvm, frame* frame_atual){

}
void func_d2f(Jvm * jvm, frame* frame_atual){

}
void func_i2b(Jvm * jvm, frame* frame_atual){

}
void func_i2c(Jvm * jvm, frame* frame_atual){

}
void func_i2s(Jvm * jvm, frame* frame_atual){

}
void func_lcmp(Jvm * jvm, frame* frame_atual){

}
void func_fcmpl(Jvm * jvm, frame* frame_atual){

}
void func_fcmpg(Jvm * jvm, frame* frame_atual){

}
void func_dcmpl(Jvm * jvm, frame* frame_atual){

}


void func_dcmpg(Jvm * jvm, frame* frame_atual){

}

// Termina Daniel


//  avançadas depois 
void func_ifeq(Jvm * jvm, frame* frame_atual){

}
void func_ifne(Jvm * jvm, frame* frame_atual){

}
void func_iflt(Jvm * jvm, frame* frame_atual){

}
void func_ifge(Jvm * jvm, frame* frame_atual){

}
void func_ifgt(Jvm * jvm, frame* frame_atual){

}
void func_ifle(Jvm * jvm, frame* frame_atual){

}
void func_if_icmpeq(Jvm * jvm, frame* frame_atual){

}
void func_if_icmpne(Jvm * jvm, frame* frame_atual){

}
void func_if_icmplt(Jvm * jvm, frame* frame_atual){

}
void func_if_icmpge(Jvm * jvm, frame* frame_atual){

}
void func_if_icmpgt(Jvm * jvm, frame* frame_atual){

}
void func_if_icmple(Jvm * jvm, frame* frame_atual){

}
void func_if_acmpeq(Jvm * jvm, frame* frame_atual){

}
void func_if_acmpne(Jvm * jvm, frame* frame_atual){

}
void func_inst_goto(Jvm * jvm, frame* frame_atual){

}
void func_jsr(Jvm * jvm, frame* frame_atual){

}
void func_ret(Jvm * jvm, frame* frame_atual){

}
void func_tableswitch(Jvm * jvm, frame* frame_atual){

}
void func_lookupswitch(Jvm * jvm, frame* frame_atual){

}
void func_ireturn(Jvm * jvm, frame* frame_atual){

}
void func_lreturn(Jvm * jvm, frame* frame_atual){

}
void func_freturn(Jvm * jvm, frame* frame_atual){

}
void func_dreturn(Jvm * jvm, frame* frame_atual){

}
void func_areturn(Jvm * jvm, frame* frame_atual){

}
void func_inst_return(Jvm * jvm, frame* frame_atual){

}
void func_getstatic(Jvm * jvm, frame* frame_atual){

}
void func_putstatic(Jvm * jvm, frame* frame_atual){

}
void func_getfield(Jvm * jvm, frame* frame_atual){

}
void func_putfield(Jvm * jvm, frame* frame_atual){

}
void func_invokevirtual(Jvm * jvm, frame* frame_atual){

}
void func_invokespecial(Jvm * jvm, frame* frame_atual){

}
void func_invokestatic(Jvm * jvm, frame* frame_atual){

}
void func_invokeinterface(Jvm * jvm, frame* frame_atual){

}
void func_invokedynamic(Jvm * jvm, frame* frame_atual){

}
void func_inst_new(Jvm * jvm, frame* frame_atual){

}
void func_new(Jvm * jvm, frame* frame_atual){

}
void func_newarray(Jvm * jvm, frame* frame_atual){

}
void func_anewarray(Jvm * jvm, frame* frame_atual){

}
void func_athrow(Jvm * jvm, frame* frame_atual){

}
void func_arraylength(Jvm * jvm, frame* frame_atual){

}
void func_checkcast(Jvm * jvm, frame* frame_atual){

}
void func_instanceof(Jvm * jvm, frame* frame_atual){

}
void func_monitorenter(Jvm * jvm, frame* frame_atual){

}
void func_monitorexit(Jvm * jvm, frame* frame_atual){

}
void func_wide(Jvm * jvm, frame* frame_atual){

}
void func_multianewarray(Jvm * jvm, frame* frame_atual){

}
void func_ifnull(Jvm * jvm, frame* frame_atual){

}
void func_ifnonnull(Jvm * jvm, frame* frame_atual){

}
void func_goto_w(Jvm * jvm, frame* frame_atual){

}
void func_jsr_w(Jvm * jvm, frame* frame_atual){

}




void load_instructions( void (*op_func[256])(Jvm*,frame* frame_atual) ){
   op_func[nop] = func_nop;
   op_func[aconst_null] = func_aconst_null;
   op_func[iconst_m1] = func_iconst_m1;
   op_func[iconst_0] = func_iconst_0;
   op_func[iconst_1] = func_iconst_1;
   op_func[iconst_2] = func_iconst_2;
   op_func[iconst_3] = func_iconst_3;
   op_func[iconst_4] = func_iconst_4;
   op_func[iconst_5] = func_iconst_5;
   op_func[lconst_0] = func_lconst_0;
   op_func[lconst_1] = func_lconst_1;
   op_func[fconst_0] = func_fconst_0;
   op_func[fconst_1] = func_fconst_1;
   op_func[fconst_2] = func_fconst_2;
   op_func[dconst_0] = func_dconst_0;
   op_func[dconst_1] = func_dconst_1;
   op_func[bipush] = func_bipush;
   op_func[sipush] = func_sipush;
   op_func[ldc] = func_ldc;
   op_func[ldc_w] = func_ldc_w;
   op_func[ldc2_w] = func_ldc2_w;
   op_func[iload] = func_iload;
   op_func[lload] = func_lload;
   op_func[fload] = func_fload;
   op_func[dload] = func_dload;
   op_func[aload] = func_aload;
   op_func[iload_0] = func_iload_0;
   op_func[iload_1] = func_iload_1;
   op_func[iload_2] = func_iload_2;
   op_func[iload_3] = func_iload_3;
   op_func[lload_0] = func_lload_0;
   op_func[lload_1] = func_lload_1;
   op_func[lload_2] = func_lload_2;
   op_func[lload_3] = func_lload_3;
   op_func[fload_0] = func_fload_0;
   op_func[fload_1] = func_fload_1;
   op_func[fload_2] = func_fload_2;
   op_func[fload_3] = func_fload_3;
   op_func[dload_0] = func_dload_0;
   op_func[dload_1] = func_dload_1;
   op_func[dload_2] = func_dload_2;
   op_func[dload_3] = func_dload_3;
   op_func[aload_0] = func_aload_0;
   op_func[aload_1] = func_aload_1;
   op_func[aload_2] = func_aload_2;
   op_func[aload_3] = func_aload_3;
   op_func[iaload] = func_iaload;
   op_func[laload] = func_laload;
   op_func[faload] = func_faload;
   op_func[daload] = func_daload;
   op_func[aaload] = func_aaload;
   op_func[baload] = func_baload;
   op_func[caload] = func_caload;
   op_func[saload] = func_saload;
   op_func[istore] = func_istore;
   op_func[lstore] = func_lstore;
   op_func[fstore] = func_fstore;
   op_func[dstore] = func_dstore;
   op_func[astore] = func_astore;
   op_func[istore_0] = func_istore_0;
   op_func[istore_1] = func_istore_1;
   op_func[istore_2] = func_istore_2;
   op_func[istore_3] = func_istore_3;
   op_func[lstore_0] = func_lstore_0;
   op_func[lstore_1] = func_lstore_1;
   op_func[lstore_2] = func_lstore_2;
   op_func[lstore_3] = func_lstore_3;
   op_func[fstore_0] = func_fstore_0;
   op_func[fstore_1] = func_fstore_1;
   op_func[fstore_2] = func_fstore_2;
   op_func[fstore_3] = func_fstore_3;
   op_func[dstore_0] = func_dstore_0;
   op_func[dstore_1] = func_dstore_1;
   op_func[dstore_2] = func_dstore_2;
   op_func[dstore_3] = func_dstore_3;
   op_func[astore_0] = func_astore_0;
   op_func[astore_1] = func_astore_1;
   op_func[astore_2] = func_astore_2;
   op_func[astore_3] = func_astore_3;
   op_func[iastore] = func_iastore;
   op_func[lastore] = func_lastore;
   op_func[fastore] = func_fastore;
   op_func[dastore] = func_dastore;
   op_func[aastore] = func_aastore;
   op_func[bastore] = func_bastore;
   op_func[castore] = func_castore;
   op_func[sastore] = func_sastore;
   op_func[pop] = func_pop;
   op_func[pop2] = func_pop2;
   op_func[dup] = func_dup;
   op_func[dup_x1] = func_dup_x1;
   op_func[dup_x2] = func_dup_x2;
   op_func[dup2] = func_dup2;
   op_func[dup2_x1] = func_dup2_x1;
   op_func[dup2_x2] = func_dup2_x2;
   op_func[swap] = func_swap;
   op_func[iadd] = func_iadd;
   op_func[ladd] = func_ladd;
   op_func[fadd] = func_fadd;
   op_func[dadd] = func_dadd;
   op_func[isub] = func_isub;
   op_func[lsub] = func_lsub;
   op_func[fsub] = func_fsub;
   op_func[dsub] = func_dsub;
   op_func[imul] = func_imul;
   op_func[lmul] = func_lmul;
   op_func[fmul] = func_fmul;
   op_func[dmul] = func_dmul;
   op_func[idiv] = func_idiv;
   op_func[inst_ldiv] = func_inst_ldiv;
   op_func[fdiv] = func_fdiv;
   op_func[ddiv] = func_ddiv;
   op_func[irem] = func_irem;
   op_func[lrem] = func_lrem;
   op_func[frem] = func_frem;
   op_func[inst_drem] = func_inst_drem;
   op_func[ineg] = func_ineg;
   op_func[lneg] = func_lneg;
   op_func[fneg] = func_fneg;
   op_func[dneg] = func_dneg;
   op_func[ishl] = func_ishl;
   op_func[lshl] = func_lshl;
   op_func[ishr] = func_ishr;
   op_func[lshr] = func_lshr;
   op_func[iushr] = func_iushr;
   op_func[lushr] = func_lushr;
   op_func[iand] = func_iand;
   op_func[land] = func_land;
   op_func[ior] = func_ior;
   op_func[lor] = func_lor;
   op_func[ixor] = func_ixor;
   op_func[lxor] = func_lxor;
   op_func[iinc] = func_iinc;
   op_func[i2l] = func_i2l;
   op_func[i2f] = func_i2f;
   op_func[i2d] = func_i2d;
   op_func[l2i] = func_l2i;
   op_func[l2f] = func_l2f;
   op_func[l2d] = func_l2d;
   op_func[f2i] = func_f2i;
   op_func[f2l] = func_f2l;
   op_func[f2d] = func_f2d;
   op_func[d2i] = func_d2i;
   op_func[d2l] = func_d2l;
   op_func[d2f] = func_d2f;
   op_func[i2b] = func_i2b;
   op_func[i2c] = func_i2c;
   op_func[i2s] = func_i2s;
   op_func[lcmp] = func_lcmp;
   op_func[fcmpl] = func_fcmpl;
   op_func[fcmpg] = func_fcmpg;
   op_func[dcmpl] = func_dcmpl;
   op_func[dcmpg] = func_dcmpg;
   op_func[ifeq] = func_ifeq;
   op_func[ifne] = func_ifne;
   op_func[iflt] = func_iflt;
   op_func[ifge] = func_ifge;
   op_func[ifgt] = func_ifgt;
   op_func[ifle] = func_ifle;
   op_func[if_icmpeq] = func_if_icmpeq;
   op_func[if_icmpne] = func_if_icmpne;
   op_func[if_icmplt] = func_if_icmplt;
   op_func[if_icmpge] = func_if_icmpge;
   op_func[if_icmpgt] = func_if_icmpgt;
   op_func[if_icmple] = func_if_icmple;
   op_func[if_acmpeq] = func_if_acmpeq;
   op_func[if_acmpne] = func_if_acmpne;
   op_func[inst_goto] = func_inst_goto;
   op_func[jsr] = func_jsr;
   op_func[ret] = func_ret;
   op_func[tableswitch] = func_tableswitch;
   op_func[lookupswitch] = func_lookupswitch;
   op_func[ireturn] = func_ireturn;
   op_func[lreturn] = func_lreturn;
   op_func[freturn] = func_freturn;
   op_func[dreturn] = func_dreturn;
   op_func[areturn] = func_areturn;
   op_func[inst_return] = func_inst_return;
   op_func[getstatic] = func_getstatic;
   op_func[putstatic] = func_putstatic;
   op_func[getfield] = func_getfield;
   op_func[putfield] = func_putfield;
   op_func[invokevirtual] = func_invokevirtual;
   op_func[invokespecial] = func_invokespecial;
   op_func[invokestatic] = func_invokestatic;
   op_func[invokeinterface] = func_invokeinterface;
   op_func[invokedynamic] = func_invokedynamic;
   op_func[new] = func_new;
   op_func[newarray] = func_newarray;
   op_func[anewarray] = func_anewarray;
   op_func[arraylength] = func_arraylength;
   op_func[athrow] = func_athrow;
   op_func[checkcast] = func_checkcast;
   op_func[instanceof] = func_instanceof;
   op_func[monitorenter] = func_monitorenter;
   op_func[monitorexit] = func_monitorexit;
   op_func[wide] = func_wide;
   op_func[multianewarray] = func_multianewarray;
   op_func[ifnull] = func_ifnull;
   op_func[ifnonnull] = func_ifnonnull;
   op_func[goto_w] = func_goto_w;
   op_func[jsr_w] = func_jsr_w;

//regex



}

//op_func[x](frame_atual,);
