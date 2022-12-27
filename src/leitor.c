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

//lendo field_info
void readField_info(field_info* fi)
{
    fi->access_flags = u2Read(fd);
    fi->name_index = u2Read(fd);
    fi->descriptor_index = u2Read(fd);
    fi->attributes_count = u2Read(fd);
    fi->attributes = (attribute_info *)malloc(fi->attributes_count * sizeof(attribute_info));
//    for (int i = 0; i < fi->attributes_count; i++)
//    {
//        fi->attributes[i] =
//    }
}

//lendo method_info
void readMethod_info(method_info* mi)
{
    mi->access_flags = u2Read(fd);
    mi->name_index = u2Read(fd);
    mi->descriptor_index = u2Read(fd);
    mi->attributes_count = u2Read(fd);
    mi->attributes = (attribute_info *)malloc(mi->attributes_count * sizeof(attribute_info));
//    for (int i = 0; i < mi->attributes_count; i++)
//    {
//        mi->attributes[i] =
//    }
}

//lendo attribute_info
void readAttribute_info(attribute_info* ai)
{
    ai->attribute_name_index = u2Read(fd);
    ai->attribute_length = u4Read(fd);
    ai->info = (u1 *)malloc(ai->attribute_length * sizeof(u1));
    for (int i = 0; i < ai->attribute_length; i++)
    {
        ai->info[i] = u1Read(fd);
    }
}