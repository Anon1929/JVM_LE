#include "classfile.h"
#ifndef EXIBIDORH
#define EXIBIDORH

void printClassfile(Classfile *);
void printCpinfo(cp_info *);
void printField_info(field_info *,cp_info *);
void printMethod_info(method_info *,cp_info *);
void printAttribute_info(attribute_info *,cp_info *);
void printCodeAttr(Code_attribute, cp_info *);

char *decodeUTF8(cp_info *);
char *decodeAccFlags(u2);
char *decodeClassInfo(cp_info* cp,int classnumber);
#endif 