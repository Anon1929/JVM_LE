#include "classfile.h"
#include <stdio.h>
#ifndef LEITORH
#define LEITORH

static u1 u1Read();
static u2 u2Read();
static u4 u4Read();
static u8 u8Read();


void readClassfile(Classfile *, FILE *);
void readCpinfo(cp_info *, FILE *);
void readField_info(field_info *, FILE *,cp_info*);
void readMethod_info(method_info *, FILE *,cp_info *);
void readAttribute_info(attribute_info *, FILE *,cp_info *);
void readAttribute_code(Code_attribute *, FILE *,cp_info *);
void readFile(Classfile *,char *);
void readAttrLineNumberTable(LineNumberTableAttr *, FILE*);
void readAttrInnerClass(InnerClasses_attribute *, FILE*);
void readAttrException(Exceptions_attribute *, FILE*);


#endif 
