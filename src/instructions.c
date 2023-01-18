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
// começo instrucoes vinicius
void func_fconst_0(Jvm * jvm, frame* frame_atual){

}

void func_fconst_1(Jvm *, frame*){

}
void func_fconst_2(Jvm *, frame*){

}
void func_dconst_0(Jvm *, frame*){

}
void func_dconst_1(Jvm *, frame*){

}
void func_bipush(Jvm *, frame*){

}
void func_sipush(Jvm *, frame*){

}
void func_ldc(Jvm *, frame*){

}
void func_ldc_w(Jvm *, frame*){

}
void func_ldc2_w(Jvm *, frame*){

}
void func_iload(Jvm *, frame*){

}
void func_lload(Jvm *, frame*){

}
void func_fload(Jvm *, frame*){

}
void func_dload(Jvm *, frame*){

}
void func_aload(Jvm *, frame*){

}
void func_iload_0(Jvm *, frame*){

}
void func_iload_1(Jvm *, frame*){

}
void func_iload_2(Jvm *, frame*){

}
void func_iload_3(Jvm *, frame*){

}
void func_lload_0(Jvm *, frame*){

}
void func_lload_1(Jvm *, frame*){

}
void func_lload_2(Jvm *, frame*){

}
// termina instruct vinicius


// isntruções Welliton 

void func_lload_3(Jvm *, frame*){

}
void func_fload_0(Jvm *, frame*){

}
void func_fload_1(Jvm *, frame*){

}
void func_fload_2(Jvm *, frame*){

}
void func_fload_3(Jvm *, frame*){

}
void func_dload_0(Jvm *, frame*){

}
void func_dload_1(Jvm *, frame*){

}
void func_dload_2(Jvm *, frame*){

}
void func_dload_3(Jvm *, frame*){

}
void func_aload_0(Jvm *, frame*){

}
void func_aload_1(Jvm *, frame*){

}
void func_aload_2(Jvm *, frame*){

}
void func_aload_3(Jvm *, frame*){

}
void func_iaload(Jvm *, frame*){

}
void func_laload(Jvm *, frame*){

}
void func_faload(Jvm *, frame*){

}
void func_daload(Jvm *, frame*){

}
void func_aaload(Jvm *, frame*){

}
void func_baload(Jvm *, frame*){

}
void func_caload(Jvm *, frame*){

}
void func_saload(Jvm *, frame*){

}
void func_istore(Jvm *, frame*){

}
void func_lstore(Jvm *, frame*){

}
void func_fstore(Jvm *, frame*){

}
void func_dstore(Jvm *, frame*){

}
void func_astore(Jvm *, frame*){

}
void func_istore_0(Jvm *, frame*){

}
void func_istore_1(Jvm *, frame*){

}
// Welliton termina

// Arthur Começa
void func_istore_2(Jvm * jvm, frame* frame_atual){
    int32_t index = 2;
    int32_t valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;
}
void func_istore_3(Jvm * jvm, frame* frame_atual){
    int32_t index = 3;
    int32_t valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_lstore_0(Jvm * jvm, frame* frame_atual){
    int32_t index = 0;
    long valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;
}
void func_lstore_1(Jvm * jvm, frame* frame_atual){
    int32_t index = 1;
    long valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;
}
void func_lstore_2(Jvm * jvm, frame* frame_atual){
    int32_t index = 2;
    long valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;
}
void func_lstore_3(Jvm * jvm, frame* frame_atual){
    int32_t index = 3;
    long valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_fstore_0(Jvm * jvm, frame* frame_atual){
    int32_t index = 0;
    float valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_fstore_1(Jvm * jvm, frame* frame_atual){
    int32_t index = 1;
    float valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_fstore_2(Jvm * jvm, frame* frame_atual){
    int32_t index = 2;
    float valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_fstore_3(Jvm * jvm, frame* frame_atual){
    int32_t index = 3;
    float valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_dstore_0(Jvm * jvm, frame* frame_atual){
    int32_t index = 0;
    double valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;


}
void func_dstore_1(Jvm * jvm, frame* frame_atual){
    int32_t index = 1;
    double valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;


}
void func_dstore_2(Jvm * jvm, frame* frame_atual){
    int32_t index = 2;
    double valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_dstore_3(Jvm * jvm, frame* frame_atual){
    int32_t index = 3;
    double valor = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),valor, index);
    jvm->pc++;

}
void func_astore_0(Jvm * jvm, frame* frame_atual){
    //store a object reference into local variable 0
    //astore_0
    //Operands: No operands
    int32_t index = 0;
    int32_t object_ref = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),object_ref, index);
    jvm->pc++;
}
void func_astore_1(Jvm * jvm, frame* frame_atual){
    //store a object reference into local variable 1
    //astore_1
    //Operands: No operands
    int32_t index = 1;
    int32_t object_ref = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),object_ref, index);
    jvm->pc++;

}
void func_astore_2(Jvm * jvm, frame* frame_atual){
    //store a object reference into local variable 2
    //astore_2
    //Operands: No operands
    int32_t index = 2;
    int32_t object_ref = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),object_ref, index);
    jvm->pc++;


}
void func_astore_3(Jvm * jvm, frame* frame_atual){
    //store a object reference into local variable 3
    //astore_3
    //Operands: No operands
    int32_t index = 3;
    int32_t object_ref = stack_pop(&(frame_atual->pilha_de_operandos));
    local_variable_vector_push(&(frame_atual->vetor_de_variaveis_locais),object_ref, index);
    jvm->pc++;

    //o tipo do object_ref tem que ser 32 bits para poder entrar no vetor de variáveis locais, então eu não sou louco

}
void func_iastore(Jvm * jvm, frame* frame_atual){
    //store into int array
    //iastore
    //Operands: No operands
    //Description: The arrayref must be of type reference and must refer to an array whose components are of type int. The index must be of type int. The value must be of type int. The arrayref, index, and value are popped from the operand stack. The int value is stored as the component of the array indexed by index.
    int value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    int * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;
    jvm->pc++;

    
}
void func_lastore(Jvm * jvm, frame* frame_atual){
    long value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    long * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;
    jvm->pc++;


}
void func_fastore(Jvm * jvm, frame* frame_atual){
    //store into float array
    //fastore
    //Operands: No operands
    //Description: The arrayref must be of type reference and must refer to an array whose components are of type float. The index must be of type int. The value must be of type float. The arrayref, index, and value are popped from the operand stack. The float value is stored as the component of the array indexed by index.
    float value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    float * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;
    jvm->pc++;
}
void func_dastore(Jvm * jvm, frame* frame_atual){
    double value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    double * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;
    jvm->pc++;

}
void func_aastore(Jvm * jvm, frame* frame_atual){
    //store into reference array
    //aastore
    //Operands: No operands
    //Description: The arrayref must be of type reference and must refer to an array whose components are of type reference. The index must be of type int. The value must be of type reference. The arrayref, index, and value are popped from the operand stack. The reference value is stored as the component of the array indexed by index.
    int32_t * value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;
    jvm->pc++;
    //supondo que o tipo do value seja 32 bits.


}
void func_bastore(Jvm * jvm, frame* frame_atual){
    //store into byte or boolean array
    //bastore
    //Operands: No operands
    //Description: The arrayref must be of type reference and must refer to an array whose components are of type byte or of type boolean. The index must be of type int. The value must be of type int. It is popped from the operand stack. The arrayref and index are also popped from the operand stack. The int value is truncated to a byte. The resulting value is stored as the component of the array indexed by index.
    int32_t value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    int8_t * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;  

}
void func_castore(Jvm * jvm, frame* frame_atual){
    //store into char array
    //castore
    //Operands: No operands
    //Description: The arrayref must be of type reference and must refer to an array whose components are of type char. The index must be of type int. The value must be of type int. It is popped from the operand stack. The arrayref and index are also popped from the operand stack. The int value is truncated to a char. The resulting value is stored as the component of the array indexed by index.
    int32_t value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    int16_t * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;  


}
void func_sastore(Jvm * jvm, frame* fram_atual){
    //store into short array
    //sastore
    //Operands: No operands
    //Description: The arrayref must be of type reference and must refer to an array whose components are of type short. The index must be of type int. The value must be of type int. It is popped from the operand stack. The arrayref and index are also popped from the operand stack. The int value is truncated to a short. The resulting value is stored as the component of the array indexed by index.
    int32_t value = stack_pop(&(frame_atual->pilha_de_operandos));
    int32_t index = stack_pop(&(frame_atual->pilha_de_operandos));
    int16_t * arrayref = stack_pop(&(frame_atual->pilha_de_operandos));
    *(arrayref + index) = value;  


}
void func_pop(Jvm * jvm, frame* frame){
    //pop no valor no topo da pilha de operandos
    stack_pop(&(frame->pilha_de_operandos));

}
// Arthur termina

// Thiago começa

void func_pop2(Jvm *, frame*){

}
void func_dup(Jvm *, frame*){

}
void func_dup_x1(Jvm *, frame*){

}
void func_dup_x2(Jvm *, frame*){

}
void func_dup2(Jvm *, frame*){

}
void func_dup2_x1(Jvm *, frame*){

}
void func_dup2_x2(Jvm *, frame*){

}
void func_swap(Jvm *, frame*){

}
void func_iadd(Jvm *, frame*){

}
void func_ladd(Jvm *, frame*){

}
void func_fadd(Jvm *, frame*){

}
void func_dadd(Jvm *, frame*){

}
void func_isub(Jvm *, frame*){

}
void func_lsub(Jvm *, frame*){

}
void func_fsub(Jvm *, frame*){

}
void func_dsub(Jvm *, frame*){

}
void func_imul(Jvm *, frame*){

}
void func_lmul(Jvm *, frame*){

}
void func_fmul(Jvm *, frame*){

}
void func_dmul(Jvm *, frame*){

}
void func_idiv(Jvm *, frame*){

}
void func_inst_ldiv(Jvm *, frame*){

}
void func_fdiv(Jvm *, frame*){

}
void func_ddiv(Jvm *, frame*){

}
void func_irem(Jvm *, frame*){

}
void func_lrem(Jvm *, frame*){

}
void func_frem(Jvm *, frame*){

}
void func_inst_drem(Jvm *, frame*){

}
// Thiago termina

// Daniel Começa 
void func__drem(Jvm *, frame*){

}
void func_ineg(Jvm *, frame*){

}
void func_lneg(Jvm *, frame*){

}
void func_fneg(Jvm *, frame*){

}
void func_dneg(Jvm *, frame*){

}
void func_ishl(Jvm *, frame*){

}
void func_lshl(Jvm *, frame*){

}
void func_ishr(Jvm *, frame*){

}
void func_lshr(Jvm *, frame*){

}
void func_iushr(Jvm *, frame*){

}
void func_lushr(Jvm *, frame*){

}
void func_iand(Jvm *, frame*){

}
void func_land(Jvm *, frame*){

}
void func_ior(Jvm *, frame*){

}
void func_lor(Jvm *, frame*){

}
void func_ixor(Jvm *, frame*){

}
void func_lxor(Jvm *, frame*){

}
void func_iinc(Jvm *, frame*){

}
void func_i2l(Jvm *, frame*){

}
void func_i2f(Jvm *, frame*){

}
void func_i2d(Jvm *, frame*){

}
void func_l2i(Jvm *, frame*){

}
void func_l2f(Jvm *, frame*){

}
void func_l2d(Jvm *, frame*){

}
void func_f2i(Jvm *, frame*){

}
void func_f2l(Jvm *, frame*){

}
void func_f2d(Jvm *, frame*){

}
void func_d2i(Jvm *, frame*){

}
void func_d2l(Jvm *, frame*){

}
void func_d2f(Jvm *, frame*){

}
void func_i2b(Jvm *, frame*){

}
void func_i2c(Jvm *, frame*){

}
void func_i2s(Jvm *, frame*){

}
void func_lcmp(Jvm *, frame*){

}
void func_fcmpl(Jvm *, frame*){

}
void func_fcmpg(Jvm *, frame*){

}
void func_dcmpl(Jvm *, frame*){

}


void func_dcmpg(Jvm *, frame*){

}

// Termina Daniel


//  avançadas depois 
void func_ifeq(Jvm *, frame*){

}
void func_ifne(Jvm *, frame*){

}
void func_iflt(Jvm *, frame*){

}
void func_ifge(Jvm *, frame*){

}
void func_ifgt(Jvm *, frame*){

}
void func_ifle(Jvm *, frame*){

}
void func_if_icmpeq(Jvm *, frame*){

}
void func_if_icmpne(Jvm *, frame*){

}
void func_if_icmplt(Jvm *, frame*){

}
void func_if_icmpge(Jvm *, frame*){

}
void func_if_icmpgt(Jvm *, frame*){

}
void func_if_icmple(Jvm *, frame*){

}
void func_if_acmpeq(Jvm *, frame*){

}
void func_if_acmpne(Jvm *, frame*){

}
void func_inst_goto(Jvm *, frame*){

}
void func_jsr(Jvm *, frame*){

}
void func_ret(Jvm *, frame*){

}
void func_tableswitch(Jvm *, frame*){

}
void func_lookupswitch(Jvm *, frame*){

}
void func_ireturn(Jvm *, frame*){

}
void func_lreturn(Jvm *, frame*){

}
void func_freturn(Jvm *, frame*){

}
void func_dreturn(Jvm *, frame*){

}
void func_areturn(Jvm *, frame*){

}
void func_inst_return(Jvm *, frame*){

}
void func_getstatic(Jvm *, frame*){

}
void func_putstatic(Jvm *, frame*){

}
void func_getfield(Jvm *, frame*){

}
void func_putfield(Jvm *, frame*){

}
void func_invokevirtual(Jvm *, frame*){

}
void func_invokespecial(Jvm *, frame*){

}
void func_invokestatic(Jvm *, frame*){

}
void func_invokeinterface(Jvm *, frame*){

}
void func_invokedynamic(Jvm *, frame*){

}
void func_inst_new(Jvm *, frame*){

}
void func_new(Jvm *, frame*){

}
void func_newarray(Jvm *, frame*){

}
void func_anewarray(Jvm *, frame*){

}
void func_athrow(Jvm *, frame*){

}
void func_arraylength(Jvm *, frame*){

}
void func_checkcast(Jvm *, frame*){

}
void func_instanceof(Jvm *, frame*){

}
void func_monitorenter(Jvm *, frame*){

}
void func_monitorexit(Jvm *, frame*){

}
void func_wide(Jvm *, frame*){

}
void func_multianewarray(Jvm *, frame*){

}
void func_ifnull(Jvm *, frame*){

}
void func_ifnonnull(Jvm *, frame*){

}
void func_goto_w(Jvm *, frame*){

}
void func_jsr_w(Jvm *, frame*){

}




void load_instructions( void (*op_func[256])(Jvm*,frame*) ){
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

