#include "classfile.h"
#ifndef EXIBIDORH
#define EXIBIDORH

void printClassfile(Classfile *);
void printCpinfo(cp_info *);
void printField_info(field_info *);
void printMethod_info(method_info *);
void printAttribute_info(attribute_info *);

char *translateUTF8(cp_info *);
char *decodeAccFlags(u2);
#endif 