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


#endif 
