/**
 * @file leitor.h
 * @author Vinicius Lima
 * @author Weliton Barreto
 * @author Arthur Souza
 * @author Thiago Vale
 * @brief Arquivo com as funções de leitura.
 *
 * @details Declaração das funções de leitura de diversos campos e atributos.
 */

#include "classfile.h"
#include <stdio.h>
#ifndef LEITORH
#define LEITORH

/// @brief Função que lê o tipo de dado u1
static u1 u1Read();

/// @brief Função que lê o tipo de dado u2
static u2 u2Read();

/// @brief Função que lê o tipo de dado u4
static u4 u4Read();

/// @brief Função que lê o tipo de dado u8
static u8 u8Read();

/// @brief Função que lê o arquivo classfile
/// @param classfile Nome do classfile
/// @param file Nome do arquivo
void readClassfile(Classfile *, FILE *);

/// @brief Função que lê o constant pool
/// @param constant_pool Constant pool
/// @param file Nome do arquivo
/// @param tag Tag do constant pool
void readCpinfo(cp_info *, FILE *, int *);

/// @brief Função que lê o field info
/// @param field_info Field info
/// @param file Nome do arquivo
/// @param constant_pool Constant pool
void readField_info(field_info *, FILE *,cp_info*);

/// @brief Função que lê o method info
/// @param method_info Method info
/// @param file Nome do arquivo
/// @param constant_pool Constant pool
void readMethod_info(method_info *, FILE *,cp_info *);

/// @brief Função que lê o attribute info
/// @param attribute_info Attribute info
/// @param file Nome do arquivo
/// @param constant_pool Constant pool
void readAttribute_info(attribute_info *, FILE *,cp_info *);

/// @brief Função que lê o code attribute
/// @param code_attribute Code attribute
/// @param file Nome do arquivo
/// @param constant_pool Constant pool
void readAttribute_code(Code_attribute *, FILE *,cp_info *);

/// @brief Função que lê o arquivo
/// @param classfile Nome do classfile
/// @param file Nome do arquivo
void readFile(Classfile *,char *);

/// @brief Função que lê o LineNumberTable Attribute
/// @param line_number_table_attribute LineNumberTable Attribute
/// @param file Nome do arquivo
void readAttrLineNumberTable(LineNumberTableAttr *, FILE*);

/// @brief Função que lê o InnerClasses Attribute
/// @param inner_classes_attribute InnerClasses Attribute
/// @param file Nome do arquivo
void readAttrInnerClass(InnerClasses_attribute *, FILE*);

/// @brief Função que lê o Exceptions Attribute
/// @param exceptions_attribute Exceptions Attribute
/// @param file Nome do arquivo
void readAttrException(Exceptions_attribute *, FILE*);

/// @brief Função que lê o LocalVariableTable Attribute
/// @param local_variable_table_attribute LocalVariableTable Attribute
/// @param file Nome do arquivo
void readAttrLocalVariableTable(LocalVariableTableAttr *, FILE*);

#endif 
