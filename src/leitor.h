#include "classfile.h"
#ifndef LEITORH
#define LEITORH

static u1 u1Read();
static u2 u2Read();
static u4 u4Read();
static u8 u8Read();


void readClassfile(ClassFile *);
void readCpinfo(cp_info *);
void readField_info(field_info *);
void readMethod_info(method_info *);
void readAttribute_info(attribute_info *);


#endif 