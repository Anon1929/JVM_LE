#include "leitor.h"
#include <stdio.h>
#include "classfile.h"

FILE *fd; //como posso abrir a o arquivo .class?

static u1 u1Read(FILE *fd)
{
    u1 toReturn = getc(fd);
    return toReturn;
}
static u2 u2Read(FILE *fd)
{
    u2 toReturn = getc(fd);
    toReturn = (toReturn << 8) | (getc(fd));
    return toReturn;
}
static u4 u4Read(FILE *fd)
{
    u4 toReturn = getc(fd);
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    return toReturn;
}
static u8 u8Read(FILE *fd)
{
    u8 toReturn = getc(fd);
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    toReturn = (toReturn << 8) | (getc(fd));
    return toReturn;
}
//lendo cp_info
// void readCpinfo(cp_info* cp, FILE *fd)
// {
//     cp->tag = u1Read(fd);
//     switch (cp->tag)
//     {
//     case CONSTANT_Class:
//         cp->class_info.name_index = u2Read(fd);
//         break;
//     case CONSTANT_Fieldref:
//         cp->field_ref.class_index = u2Read(fd);
//         cp->field_ref.name_and_type_index = u2Read(fd);
//         break;
//     case CONSTANT_Methodref:
//         cp->method_ref.class_index = u2Read(fd);
//         cp->method_ref.name_and_type_index = u2Read(fd);
//         break;
//     case CONSTANT_InterfaceMethodref:
//         cp->interface_method_ref.class_index = u2Read(fd);
//         cp->interface_method_ref.name_and_type_index = u2Read(fd);
//         break;
//     case CONSTANT_String:
//         cp->string_info.string_index = u2Read(fd);
//         break;
//     case CONSTANT_Integer:
//         cp->integer_info.bytes = u4Read(fd);
//         break;
//     case CONSTANT_Float:
//         cp->float_info.bytes = u4Read(fd);
//         break;
//     case CONSTANT_Long:
//         cp->long_info.high_bytes = u4Read(fd);
//         cp->long_info.low_bytes = u4Read(fd);
//         break;
//     case CONSTANT_Double:
//         cp->double_info.high_bytes = u4Read(fd);
//         cp->double_info.low_bytes = u4Read(fd);
//         break;
//     case CONSTANT_NameAndType:
//         cp->name_and_type.name_index = u2Read(fd);
//         cp->name_and_type.descriptor_index = u2Read(fd);
//         break;
//     case CONSTANT_Utf8:
//         cp->utf_8_info.length = u2Read(fd);
//         cp->utf_8_info.bytes = (u1 *)malloc(cp->utf_8_info.length * sizeof(u1));
//         for (int i = 0; i < cp->utf_8_info.length; i++)
//         {
//             cp->utf_8_info.bytes[i] = u1Read(fd);
//         }
//         break;
//     default:
//         break;
//     }
// }
