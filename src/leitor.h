#include "classfile.h"
#include <stdio.h>
#ifndef LEITORH
#define LEITORH

static u1 u1Read();
static u2 u2Read();
static u4 u4Read();
static u8 u8Read();


void readClassfile(Classfile *);
void readCpinfo(cp_info *, FILE *);
void readField_info(field_info *, FILE *);
void readMethod_info(method_info *, FILE *);
void readAttribute_info(attribute_info *, FILE *);
void readAttribute_code(code_attribute *, FILE *);
void readAttribute_deprecated(deprecated_attribute *, FILE *);
void readAttribute_exceptions(exceptions_attribute *, FILE *);
void readAttribute_innerClasses(innerClasses_attribute *, FILE *);
void readAttribute_lineNumberTable(lineNumberTable_attribute *, FILE *);
void readAttribute_localVariableTable(localVariableTable_attribute *, FILE *);
void readAttribute_sourceFile(sourceFile_attribute *, FILE *);


#endif 
