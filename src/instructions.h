/**
 * @file instructions.h
 * @author Vinicius Lima
 * @author Weliton Barreto
 * @author Arthur Souza
 * @author Thiago Vale
 * @brief Arquivo com as funções das instruções JVM.
 *
 * @details Declaração das funções das instruções JVM.
 */

#ifndef INSTRUCTH
#define INSTRUCTH
#include "jvm.h"

/// @brief Função que carrega as instruções
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void load_instructions( void (*op_func[256])(Jvm *, frame*, classcode*) );

/// @brief Função nop
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_nop(Jvm *, frame*, classcode*);

/// @brief Função aconst_null
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aconst_null(Jvm *, frame*, classcode*);

/// @brief Função iconst_m1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iconst_m1(Jvm *, frame*, classcode*);

/// @brief Função iconst_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iconst_0(Jvm *, frame*, classcode*);

/// @brief Função iconst_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iconst_1(Jvm *, frame*, classcode*);

/// @brief Função iconst_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iconst_2(Jvm *, frame*, classcode*);

/// @brief Função iconst_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iconst_3(Jvm *, frame*, classcode*);

/// @brief Função iconst_4
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iconst_4(Jvm *, frame*, classcode*);

/// @brief Função iconst_5
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iconst_5(Jvm *, frame*, classcode*);

/// @brief Função lconst_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lconst_0(Jvm *, frame*, classcode*);

/// @brief Função lconst_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lconst_1(Jvm *, frame*, classcode*);

/// @brief Função fconst_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fconst_0(Jvm *, frame*, classcode*);

/// @brief Função fconst_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fconst_1(Jvm *, frame*, classcode*);

/// @brief Função fconst_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fconst_2(Jvm *, frame*, classcode*);

/// @brief Função dconst_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dconst_0(Jvm *, frame*, classcode*);

/// @brief Função dconst_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dconst_1(Jvm *, frame*, classcode*);

/// @brief Função bipush
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_bipush(Jvm *, frame*, classcode*);

/// @brief Função sipush
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_sipush(Jvm *, frame*, classcode*);

/// @brief Função ldc
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ldc(Jvm *, frame*, classcode*);

/// @brief Função ldc_w
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ldc_w(Jvm *, frame*, classcode*);

/// @brief Função ldc2_w
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ldc2_w(Jvm *, frame*, classcode*);

/// @brief Função iload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iload(Jvm *, frame*, classcode*);

/// @brief Função lload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lload(Jvm *, frame*, classcode*);

/// @brief Função fload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fload(Jvm *, frame*, classcode*);

/// @brief Função dload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dload(Jvm *, frame*, classcode*);

/// @brief Função aload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aload(Jvm *, frame*, classcode*);

/// @brief Função iload_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iload_0(Jvm *, frame*, classcode*);

/// @brief Função iload_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iload_1(Jvm *, frame*, classcode*);

/// @brief Função iload_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iload_2(Jvm *, frame*, classcode*);

/// @brief Função iload_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iload_3(Jvm *, frame*, classcode*);

/// @brief Função lload_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lload_0(Jvm *, frame*, classcode*);

/// @brief Função lload_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lload_1(Jvm *, frame*, classcode*);

/// @brief Função lload_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lload_2(Jvm *, frame*, classcode*);

/// @brief Função lload_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lload_3(Jvm *, frame*, classcode*);

/// @brief Função fload_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fload_0(Jvm *, frame*, classcode*);

/// @brief Função fload_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fload_1(Jvm *, frame*, classcode*);

/// @brief Função fload_2
void func_fload_2(Jvm *, frame*, classcode*);

/// @brief Função fload_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fload_3(Jvm *, frame*, classcode*);

/// @brief Função dload_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dload_0(Jvm *, frame*, classcode*);

/// @brief Função dload_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dload_1(Jvm *, frame*, classcode*);

/// @brief Função dload_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dload_2(Jvm *, frame*, classcode*);

/// @brief Função dload_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dload_3(Jvm *, frame*, classcode*);

/// @brief Função aload_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aload_0(Jvm *, frame*, classcode*);

/// @brief Função aload_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aload_1(Jvm *, frame*, classcode*);

/// @brief Função aload_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aload_2(Jvm *, frame*, classcode*);

/// @brief Função aload_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aload_3(Jvm *, frame*, classcode*);

/// @brief Função iaload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iaload(Jvm *, frame*, classcode*);

/// @brief Função laload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_laload(Jvm *, frame*, classcode*);

/// @brief Função faload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_faload(Jvm *, frame*, classcode*);

/// @brief Função daload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_daload(Jvm *, frame*, classcode*);

/// @brief Função aaload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aaload(Jvm *, frame*, classcode*);

/// @brief Função baload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_baload(Jvm *, frame*, classcode*);

/// @brief Função caload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_caload(Jvm *, frame*, classcode*);

/// @brief Função saload
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_saload(Jvm *, frame*, classcode*);

/// @brief Função istore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_istore(Jvm *, frame*, classcode*);

/// @brief Função lstore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lstore(Jvm *, frame*, classcode*);

/// @brief Função fstore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fstore(Jvm *, frame*, classcode*);

/// @brief Função dstore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dstore(Jvm *, frame*, classcode*);

/// @brief Função astore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_astore(Jvm *, frame*, classcode*);

/// @brief Função istore_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_istore_0(Jvm *, frame*, classcode*);

/// @brief Função istore_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_istore_1(Jvm *, frame*, classcode*);

/// @brief Função istore_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_istore_2(Jvm *, frame*, classcode*);

/// @brief Função istore_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_istore_3(Jvm *, frame*, classcode*);

/// @brief Função lstore_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lstore_0(Jvm *, frame*, classcode*);

/// @brief Função lstore_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lstore_1(Jvm *, frame*, classcode*);

/// @brief Função lstore_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lstore_2(Jvm *, frame*, classcode*);

/// @brief Função lstore_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lstore_3(Jvm *, frame*, classcode*);

/// @brief Função fstore_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fstore_0(Jvm *, frame*, classcode*);

/// @brief Função fstore_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fstore_1(Jvm *, frame*, classcode*);

/// @brief Função fstore_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fstore_2(Jvm *, frame*, classcode*);

/// @brief Função fstore_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fstore_3(Jvm *, frame*, classcode*);

/// @brief Função dstore_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dstore_0(Jvm *, frame*, classcode*);

/// @brief Função dstore_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dstore_1(Jvm *, frame*, classcode*);

/// @brief Função dstore_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dstore_2(Jvm *, frame*, classcode*);

/// @brief Função dstore_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dstore_3(Jvm *, frame*, classcode*);

/// @brief Função astore_0
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_astore_0(Jvm *, frame*, classcode*);

/// @brief Função astore_1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_astore_1(Jvm *, frame*, classcode*);

/// @brief Função astore_2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_astore_2(Jvm *, frame*, classcode*);

/// @brief Função astore_3
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_astore_3(Jvm *, frame*, classcode*);

/// @brief Função iastore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iastore(Jvm *, frame*, classcode*);

/// @brief Função lastore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lastore(Jvm *, frame*, classcode*);

/// @brief Função fastore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fastore(Jvm *, frame*, classcode*);

/// @brief Função dastore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dastore(Jvm *, frame*, classcode*);

/// @brief Função aastore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_aastore(Jvm *, frame*, classcode*);

/// @brief Função bastore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_bastore(Jvm *, frame*, classcode*);

/// @brief Função castore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_castore(Jvm *, frame*, classcode*);

/// @brief Função sastore
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_sastore(Jvm *, frame*, classcode*);

/// @brief Função pop
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_pop(Jvm *, frame*, classcode*);

/// @brief Função pop2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_pop2(Jvm *, frame*, classcode*);

/// @brief Função dup
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dup(Jvm *, frame*, classcode*);

/// @brief Função dup_x1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dup_x1(Jvm *, frame*, classcode*);

/// @brief Função dup_x2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dup_x2(Jvm *, frame*, classcode*);

/// @brief Função dup2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dup2(Jvm *, frame*, classcode*);

/// @brief Função dup2_x1
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dup2_x1(Jvm *, frame*, classcode*);

/// @brief Função dup2_x2
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dup2_x2(Jvm *, frame*, classcode*);

/// @brief Função swap
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_swap(Jvm *, frame*, classcode*);

/// @brief Função iadd
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iadd(Jvm *, frame*, classcode*);

/// @brief Função ladd
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ladd(Jvm *, frame*, classcode*);

/// @brief Função fadd
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fadd(Jvm *, frame*, classcode*);

/// @brief Função dadd
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dadd(Jvm *, frame*, classcode*);

/// @brief Função isub
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_isub(Jvm *, frame*, classcode*);

/// @brief Função lsub
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lsub(Jvm *, frame*, classcode*);

/// @brief Função fsub
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fsub(Jvm *, frame*, classcode*);

/// @brief Função dsub
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dsub(Jvm *, frame*, classcode*);

/// @brief Função imul
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_imul(Jvm *, frame*, classcode*);

/// @brief Função lmul
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lmul(Jvm *, frame*, classcode*);

/// @brief Função fmul
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fmul(Jvm *, frame*, classcode*);

/// @brief Função dmul
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dmul(Jvm *, frame*, classcode*);

/// @brief Função idiv
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_idiv(Jvm *, frame*, classcode*);

/// @brief Função ldiv
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_inst_ldiv(Jvm *, frame*, classcode*);

/// @brief Função fdiv
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fdiv(Jvm *, frame*, classcode*);

/// @brief Função ddiv
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ddiv(Jvm *, frame*, classcode*);

/// @brief Função irem
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_irem(Jvm *, frame*, classcode*);

/// @brief Função lrem
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lrem(Jvm *, frame*, classcode*);

/// @brief Função frem
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_frem(Jvm *, frame*, classcode*);

/// @brief Função drem
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_inst_drem(Jvm *, frame*, classcode*);

/// @brief Função ineg
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func__drem(Jvm *, frame*, classcode*);

/// @brief Função ineg
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ineg(Jvm *, frame*, classcode*);

/// @brief Função lneg
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lneg(Jvm *, frame*, classcode*);

/// @brief Função fneg
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fneg(Jvm *, frame*, classcode*);

/// @brief Função dneg
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dneg(Jvm *, frame*, classcode*);

/// @brief Função ishl
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ishl(Jvm *, frame*, classcode*);

/// @brief Função lshr
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lshl(Jvm *, frame*, classcode*);

/// @brief Função ishr
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ishr(Jvm *, frame*, classcode*);

/// @brief Função lshr
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lshr(Jvm *, frame*, classcode*);

/// @brief Função iushr
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iushr(Jvm *, frame*, classcode*);

/// @brief Função lushr
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lushr(Jvm *, frame*, classcode*);

/// @brief Função iand
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iand(Jvm *, frame*, classcode*);

/// @brief Função land
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_land(Jvm *, frame*, classcode*);

/// @brief Função ior
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ior(Jvm *, frame*, classcode*);

/// @brief Função lor
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lor(Jvm *, frame*, classcode*);

/// @brief Função ixor
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ixor(Jvm *, frame*, classcode*);

/// @brief Função lxor
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lxor(Jvm *, frame*, classcode*);

/// @brief Função iinc
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iinc(Jvm *, frame*, classcode*);

/// @brief Função i2l
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_i2l(Jvm *, frame*, classcode*);

/// @brief Função i2f
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_i2f(Jvm *, frame*, classcode*);

/// @brief Função i2d
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_i2d(Jvm *, frame*, classcode*);

/// @brief Função l2i
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_l2i(Jvm *, frame*, classcode*);

/// @brief Função l2f
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_l2f(Jvm *, frame*, classcode*);

/// @brief Função l2d
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_l2d(Jvm *, frame*, classcode*);

/// @brief Função f2i
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_f2i(Jvm *, frame*, classcode*);

/// @brief Função f2l
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_f2l(Jvm *, frame*, classcode*);

/// @brief Função f2d
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_f2d(Jvm *, frame*, classcode*);

/// @brief Função d2i
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_d2i(Jvm *, frame*, classcode*);

/// @brief Função d2l
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_d2l(Jvm *, frame*, classcode*);

/// @brief Função d2f
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_d2f(Jvm *, frame*, classcode*);

/// @brief Função i2b
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_i2b(Jvm *, frame*, classcode*);

/// @brief Função i2c
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_i2c(Jvm *, frame*, classcode*);

/// @brief Função i2s
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_i2s(Jvm *, frame*, classcode*);

/// @brief Função lcmp
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lcmp(Jvm *, frame*, classcode*);

/// @brief Função fcmpl
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fcmpl(Jvm *, frame*, classcode*);

/// @brief Função fcmpg
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_fcmpg(Jvm *, frame*, classcode*);

/// @brief Função dcmpl
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dcmpl(Jvm *, frame*, classcode*);

/// @brief Função dcmpg
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dcmpg(Jvm *, frame*, classcode*);

/// @brief Função ifeq
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ifeq(Jvm *, frame*, classcode*);

/// @brief Função ifne
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ifne(Jvm *, frame*, classcode*);

/// @brief Função iflt
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_iflt(Jvm *, frame*, classcode*);

/// @brief Função ifge
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ifge(Jvm *, frame*, classcode*);

/// @brief Função ifgt
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ifgt(Jvm *, frame*, classcode*);

/// @brief Função ifle
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ifle(Jvm *, frame*, classcode*);

/// @brief Função if_icmpeq
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_icmpeq(Jvm *, frame*, classcode*);

/// @brief Função if_icmpne
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_icmpne(Jvm *, frame*, classcode*);

/// @brief Função if_icmplt
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_icmplt(Jvm *, frame*, classcode*);

/// @brief Função if_icmpge
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_icmpge(Jvm *, frame*, classcode*);

/// @brief Função if_icmpgt
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_icmpgt(Jvm *, frame*, classcode*);

/// @brief Função if_icmple
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_icmple(Jvm *, frame*, classcode*);

/// @brief Função if_acmpeq
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_acmpeq(Jvm *, frame*, classcode*);

/// @brief Função if_acmpne
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_if_acmpne(Jvm *, frame*, classcode*);

/// @brief Função goto
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_inst_goto(Jvm *, frame*, classcode*);

/// @brief Função jsr
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_jsr(Jvm *, frame*, classcode*);

/// @brief Função ret
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ret(Jvm *, frame*, classcode*);

/// @brief Função tableswitch
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_tableswitch(Jvm *, frame*, classcode*);

/// @brief Função lookupswitch
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lookupswitch(Jvm *, frame*, classcode*);

/// @brief Função ireturn
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ireturn(Jvm *, frame*, classcode*);

/// @brief Função lreturn
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_lreturn(Jvm *, frame*, classcode*);

/// @brief Função freturn
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_freturn(Jvm *, frame*, classcode*);

/// @brief Função dreturn
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_dreturn(Jvm *, frame*, classcode*);

/// @brief Função areturn
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_areturn(Jvm *, frame*, classcode*);

/// @brief Função return
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_inst_return(Jvm *, frame*, classcode*);

/// @brief Função getstatic
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_getstatic(Jvm *, frame*, classcode*);

/// @brief Função putstatic
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_putstatic(Jvm *, frame*, classcode*);

/// @brief Função getfield
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_getfield(Jvm *, frame*, classcode*);

/// @brief Função putfield
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_putfield(Jvm *, frame*, classcode*);

/// @brief Função invokevirtual
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_invokevirtual(Jvm *, frame*, classcode*);

/// @brief Função invokespecial
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_invokespecial(Jvm *, frame*, classcode*);

/// @brief Função invokestatic
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_invokestatic(Jvm *, frame*, classcode*);

/// @brief Função invokeinterface
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_invokeinterface(Jvm *, frame*, classcode*);

/// @brief Função invokedynamic
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_invokedynamic(Jvm *, frame*, classcode*);

/// @brief Função new
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_inst_new(Jvm *, frame*, classcode*);

/// @brief Função new
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_new(Jvm *, frame*, classcode*);

/// @brief Função newarray
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_newarray(Jvm *, frame*, classcode*);

/// @brief Função anewarray
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_anewarray(Jvm *, frame*, classcode*);

/// @brief Função athrow
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_athrow(Jvm *, frame*, classcode*);

/// @brief Função arraylength
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_arraylength(Jvm *, frame*, classcode*);

/// @brief Função checkcast
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_checkcast(Jvm *, frame*, classcode*);

/// @brief Função instanceof
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_instanceof(Jvm *, frame*, classcode*);

/// @brief Função monitorenter
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_monitorenter(Jvm *, frame*, classcode*);

/// @brief Função monitorexit
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_monitorexit(Jvm *, frame*, classcode*);

/// @brief Função wide
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_wide(Jvm *, frame*, classcode*);

/// @brief Função multianewarray
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_multianewarray(Jvm *, frame*, classcode*);

/// @brief Função ifnull
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ifnull(Jvm *, frame*, classcode*);

/// @brief Função ifnonnull
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_ifnonnull(Jvm *, frame*, classcode*);

/// @brief Função goto_w
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_goto_w(Jvm *, frame*, classcode*);

/// @brief Função jsr_w
/// @param jvm JVM
/// @param frame frame
/// @param classcode class code
void func_jsr_w(Jvm *, frame*, classcode*);


#endif 