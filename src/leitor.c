#include "leitor.h"
#include <stdio.h>
#include <stdlib.h>
#include "classfile.h"

//abrindo arquivo .class
static FILE *openFile(char *path)
{
    FILE *fd = fopen(path, "rb");
    return fd;
}
//lendo u1, u2, u4 e u8
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
void readCpinfo(cp_info* cp, FILE *fd)
{
    cp->tag = u1Read(fd);
    switch (cp->tag)
    {
    case CONSTANT_Class:
        cp->cp_info_union.class_info.name_index = u2Read(fd);
        break;
    case CONSTANT_Fieldref:
        cp->cp_info_union.field_ref.class_index = u2Read(fd);
        cp->cp_info_union.field_ref.name_and_type_index = u2Read(fd);
        break;
    case CONSTANT_Methodref:
        cp->cp_info_union.method_ref.class_index = u2Read(fd);
        cp->cp_info_union.method_ref.name_and_type_index = u2Read(fd);
        break;
    case CONSTANT_InterfaceMethodref:
        cp->cp_info_union.interface_method_ref.class_index = u2Read(fd);
        cp->cp_info_union.interface_method_ref.name_and_type_index = u2Read(fd);
        break;
    case CONSTANT_String:
        cp->cp_info_union.string_info.string_index = u2Read(fd);
        break;
    case CONSTANT_Integer:
        cp->cp_info_union.integer_info.bytes = u4Read(fd);
        break;
    case CONSTANT_Float:
        cp->cp_info_union.float_info.bytes = u4Read(fd);
        break;
    case CONSTANT_Long:
        cp->cp_info_union.long_info.high_bytes = u4Read(fd);
        cp->cp_info_union.long_info.low_bytes = u4Read(fd);
        break;
    case CONSTANT_Double:
        cp->cp_info_union.double_info.high_bytes = u4Read(fd);
        cp->cp_info_union.double_info.low_bytes = u4Read(fd);
        break;
    case CONSTANT_NameAndType:
        cp->cp_info_union.name_and_type.name_index = u2Read(fd);
        cp->cp_info_union.name_and_type.descriptor_index = u2Read(fd);
        break;
    case CONSTANT_Utf8:
        cp->cp_info_union.utf_8_info.length = u2Read(fd);
        cp->cp_info_union.utf_8_info.bytes = (u1 *)malloc(cp->cp_info_union.utf_8_info.length * sizeof(u1));
        for (int i = 0; i < cp->cp_info_union.utf_8_info.length; i++)
        {
            cp->cp_info_union.utf_8_info.bytes[i] = u1Read(fd);
        }
        break;
    default:
        break;
    }
    
        
}
