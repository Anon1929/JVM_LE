#include "leitor.h"
#include <stdio.h>
#include <stdlib.h>
#include "classfile.h"

// abrindo arquivo .class
static FILE *openFile(char *path)
{
    FILE *fd = fopen(path, "rb");
    return fd;
}
// lendo u1, u2, u4 e u8
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
// lendo cp_info
void readCpinfo(cp_info *cp, FILE *fd)
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
void readField_info(field_info* fi, FILE* fd)
{
    fi->access_flags = u2Read(fd);
    fi->name_index = u2Read(fd);
    fi->descriptor_index = u2Read(fd);
    fi->attributes_count = u2Read(fd);
    fi->attributes = (attribute_info *)malloc(fi->attributes_count * sizeof(attribute_info));
    for (int i = 0; i < fi->attributes_count; i++)
    {
        readAttribute_info(&fi->attributes[i], fd);
    }
}

// lendo method_info
void readMethod_info(method_info *mi, FILE *fd)
{
    mi->access_flags = u2Read(fd);
    mi->name_index = u2Read(fd);
    mi->descriptor_index = u2Read(fd);
    mi->attributes_count = u2Read(fd);
    mi->attributes = (attribute_info *)malloc(mi->attributes_count * sizeof(attribute_info));
    for (int i = 0; i < mi->attributes_count; i++)
    {
        readAttribute_info(&mi->attributes[i], fd);
    }
}

//lendo attribute_info
void readAttribute_info(attribute_info* ai, FILE* fd)
{
    ai->attribute_name_index = u2Read(fd);
    ai->attribute_length = u4Read(fd);
    ai->info = (u1 *)malloc(ai->attribute_length * sizeof(u1));
    for (int i = 0; i < ai->attribute_length; i++)
    {
        ai->info[i] = u1Read(fd);
    }
}

// lendo class_file
void readClassfile(Classfile *cf, FILE *fd)
{
    cf->magic = u4Read(fd);
    cf->minor_version = u2Read(fd);
    cf->major_version = u2Read(fd);
    cf->constant_pool_count = u2Read(fd);
    cf->constant_pool = (cp_info *)malloc(cf->constant_pool_count * sizeof(cp_info));
    for (int i = 1; i < cf->constant_pool_count; i++)
    {
        readCpinfo(&cf->constant_pool[i], fd);
    }
    cf->access_flags = u2Read(fd);
    cf->this_class = u2Read(fd);
    cf->super_class = u2Read(fd);
    cf->interfaces_count = u2Read(fd);
    cf->interfaces = (u2 *)malloc(cf->interfaces_count * sizeof(u2));
    for (int i = 0; i < cf->interfaces_count; i++)
    {
        u2Read(fd);
    }
    cf->fields_count = u2Read(fd);
    cf->fields = (field_info *)malloc(cf->fields_count * sizeof(field_info));
    for (int i = 0; i < cf->fields_count; i++)
    {
        readField_info(&cf->fields[i], fd);
    }
    cf->methods_count = u2Read(fd);
    cf->methods = (method_info *)malloc(cf->methods_count * sizeof(method_info));
    for (int i = 0; i < cf->methods_count; i++)
    {
        readMethod_info(&cf->methods[i], fd);
    }
    cf->attributes_count = u2Read(fd);
    cf->attributes = (attribute_info *)malloc(cf->attributes_count * sizeof(attribute_info));
    for (int i = 0; i < cf->attributes_count; i++)
    {
        readAttribute_info(&cf->attributes[i], fd);
    }
}
//atributo code
//utilizado em estrutura method_info
void readAttribute_code(Code_attribute* ca, FILE* fd)
{
    ca->attribute_name_index = u2Read(fd);
    ca->attribute_length = u4Read(fd);
    ca->max_stack = u2Read(fd);
    ca->max_locals = u2Read(fd);
    ca->code_length = u4Read(fd);
    ca->code = (u1 *)malloc(ca->code_length * sizeof(u1));
    for (int i = 0; i < ca->code_length; i++)
    {
        ca->code[i] = u1Read(fd);
    }
    ca->exception_table_length = u2Read(fd);
    ca->exception_table = (exception_table *)malloc(ca->exception_table_length * sizeof(exception_table));
    for (int i = 0; i < ca->exception_table_length; i++)
    {
        ca->exception_table[i].start_pc = u2Read(fd);
        ca->exception_table[i].end_pc = u2Read(fd);
        ca->exception_table[i].handler_pc = u2Read(fd);
        ca->exception_table[i].catch_type = u2Read(fd);
    }
    ca->attributes_count = u2Read(fd);
    ca->attributes = (attribute_info *)malloc(ca->attributes_count * sizeof(attribute_info));
    for (int i = 0; i < ca->attributes_count; i++)
    {
        readAttribute_info(&ca->attributes[i], fd);
    }
}

// void readAttribute_code(code_attribute* ca, FILE* fd)
// {
//     ca->attribute_name_index = u2Read(fd);
//     ca->attribute_length = u4Read(fd);
//     ca->max_stack = u2Read(fd);
//     ca->max_locals = u2Read(fd);
//     ca->code_length = u4Read(fd);
//     ca->code = (u1 *)malloc(ca->code_length * sizeof(u1));
//     for (int i = 0; i < ca->code_length; i++)
//     {
//         ca->code[i] = u1Read(fd);
//     }
//     ca->exception_table_length = u2Read(fd);
//     ca->exception_table = (code_attribute ->exception_table *)malloc(ca->exception_table_length * sizeof(exception_table));
//     for (int i = 0; i < ca->exception_table_length; i++)
//     {
//         ca->exception_table[i].start_pc = u2Read(fd);
//         ca->exception_table[i].end_pc = u2Read(fd);
//         ca->exception_table[i].handler_pc = u2Read(fd);
//         ca->exception_table[i].catch_type = u2Read(fd);
//     }
//     ca->attributes_count = u2Read(fd);
//     ca->attributes = (attribute_info *)malloc(ca->attributes_count * sizeof(attribute_info));
// //    for (int i = 0; i < ca->attributes_count; i++)
// //    {
// //        ca->attributes[i] =;
// //    }
// }

// void readAttribute_deprecated(deprecated_attribute* da, FILE* fd)
// {
//     da->attribute_name_index = u2Read(fd);
//     da->attribute_length = u4Read(fd);
// }

// void readAttribute_exceptions(exceptions_attribute* ea, FILE* fd)
// {
//     ea->attribute_name_index = u2Read(fd);
//     ea->attribute_length = u4Read(fd);
//     ea->number_of_exceptions = u2Read(fd);
//     ea->exception_index_table = (u2 *)malloc(ea->number_of_exceptions * sizeof(u2));
//     for (int i = 0; i < ea->number_of_exceptions; i++)
//     {
//         ea->exception_index_table[i] = u2Read(fd);
//     }
// }

// void readAttribute_innerClasses(innerClasses_attribute* ica, FILE* fd)
// {
//     ica->attribute_name_index = u2Read(fd);
//     ica->attribute_length = u4Read(fd);
//     ica->number_of_classes = u2Read(fd);
//     ica->classes = (classes *)malloc(ica->number_of_classes * sizeof(classes));
//     for (int i = 0; i < ica->number_of_classes; i++)
//     {
//         ica->classes[i].inner_class_info_index = u2Read(fd);
//         ica->classes[i].outer_class_info_index = u2Read(fd);
//         ica->classes[i].inner_name_index = u2Read(fd);
//         ica->classes[i].inner_class_access_flags = u2Read(fd);
//     }
// }

// void readAttribute_lineNumberTable(lineNumberTable_attribute* lnta, FILE* fd)
// {
//     lnta->attribute_name_index = u2Read(fd);
//     lnta->attribute_length = u4Read(fd);
//     lnta->line_number_table_length = u2Read(fd);
//     lnta->line_number_table = (line_number_table *)malloc(lnta->line_number_table_length * sizeof(line_number_table));
//     for (int i = 0; i < lnta->line_number_table_length; i++)
//     {
//         lnta->line_number_table[i].start_pc = u2Read(fd);
//         lnta->line_number_table[i].line_number = u2Read(fd);
//     }
// }

// void readAttribute_localVariableTable(localVariableTable_attribute* lvta, FILE* fd)
// {
//     lvta->attribute_name_index = u2Read(fd);
//     lvta->attribute_length = u4Read(fd);
//     lvta->local_variable_table_length = u2Read(fd);
//     lvta->local_variable_table = (local_variable_table *)malloc(lvta->local_variable_table_length * sizeof(local_variable_table));
//     for (int i = 0; i < lvta->local_variable_table_length; i++)
//     {
//         lvta->local_variable_table[i].start_pc = u2Read(fd);
//         lvta->local_variable_table[i].length = u2Read(fd);
//         lvta->local_variable_table[i].name_index = u2Read(fd);
//         lvta->local_variable_table[i].descriptor_index = u2Read(fd);
//         lvta->local_variable_table[i].index = u2Read(fd);
//     }
// }

// void readAttribute_sourceFile(sourceFile_attribute* sfa, FILE* fd)
// {
//     sfa->attribute_name_index = u2Read(fd);
//     sfa->attribute_length = u4Read(fd);
//     sfa->sourcefile_index = u2Read(fd);
// }
