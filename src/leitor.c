#include "leitor.h"
#include "exibidor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "classfile.h"

// abrindo arquivo .class
static FILE *openFile(char *path)
{
    FILE *fd = fopen(path, "rb");
    if(!fd){
        printf("Arquivo não encontrado\n");
    }
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
void readField_info(field_info* fi, FILE* fd,cp_info* cp)
{
    fi->access_flags = u2Read(fd);
    fi->name_index = u2Read(fd);
    fi->descriptor_index = u2Read(fd);
    fi->attributes_count = u2Read(fd);
    fi->attributes = (attribute_info *)malloc(fi->attributes_count * sizeof(attribute_info));
    for (int i = 0; i < fi->attributes_count; i++)
    {
        readAttribute_info(&fi->attributes[i], fd,cp);
    }
}

// lendo method_info
void readMethod_info(method_info *mi, FILE *fd,cp_info* cp)
{
    mi->access_flags = u2Read(fd);
    mi->name_index = u2Read(fd);
    mi->descriptor_index = u2Read(fd);
    mi->attributes_count = u2Read(fd);
 /*   mi->attributes = (attribute_info *)malloc(mi->attributes_count * sizeof(attribute_info));
    for (int i = 0; i < mi->attributes_count; i++)
    {
        readAttribute_info(&mi->attributes[i], fd,cp);
    } */
}

//lendo attribute_info
void readAttribute_info(attribute_info* ai, FILE* fd, cp_info* cp)
{
    ai->attribute_name_index = u2Read(fd);
    ai->attribute_length = u4Read(fd);
    /*
    ai->info = (u1 *)malloc(ai->attribute_length * sizeof(u1));
    for (int i = 0; i < ai->attribute_length; i++)
    {
        ai->info[i] = u1Read(fd);
    }          
    /*         //leitura direta

    // Solução por union   |
                           V

    Comparar strings 
    e fazer leitura de acordo
    
    */

    if(ai->attribute_length > 0){
        char * string_comp;
        string_comp = translateUTF8(cp + ai->attribute_name_index - 1);
        if(strcmp(string_comp, "Code")==0){
            //ai->
        }
        else if (strcmp(string_comp, "InnerClasses") == 0){
            //innrt
        }
        else if (strcmp(string_comp, "ConstantValue") == 0){
            ai->attr_info_union.ConstantValue = u2Read(fd);

        }
        else if (strcmp(string_comp, "Exceptions") == 0){
            //
        }



    }


      
}

//atributo code
//utilizado em estrutura method_info
void readAttribute_code(Code_attribute* ca, FILE* fd,cp_info* cp)
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
        readAttribute_info(&ca->attributes[i], fd,cp);
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
        readField_info(&cf->fields[i], fd, cf->constant_pool);
    }
    cf->methods_count = u2Read(fd);
    cf->methods = (method_info *)malloc(cf->methods_count * sizeof(method_info));
    for (int i = 0; i < cf->methods_count; i++)
    {
        readMethod_info(&cf->methods[i], fd,cf->constant_pool);
    }
    cf->attributes_count = u2Read(fd);
    cf->attributes = (attribute_info *)malloc(cf->attributes_count * sizeof(attribute_info));
    for (int i = 0; i < cf->attributes_count; i++)
    {
        readAttribute_info(&cf->attributes[i], fd,cf->constant_pool);
    }
}

void readFile(Classfile * cf, char *nome){
    FILE * arquivo = openFile(nome);
    readClassfile(cf,arquivo);

}
