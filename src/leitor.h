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
void readField_info(field_info *);
void readMethod_info(method_info *);
void readAttribute_info(attribute_info *);
void readAttribute_code(code_attribute *);
void readAttribute_deprecated(deprecated_attribute *);
void readAttribute_exceptions(exceptions_attribute *);
void readAttribute_innerClasses(innerClasses_attribute *);
void readAttribute_lineNumberTable(lineNumberTable_attribute *);
void readAttribute_localVariableTable(localVariableTable_attribute *);
void readAttribute_sourceFile(sourceFile_attribute *);


#endif 
