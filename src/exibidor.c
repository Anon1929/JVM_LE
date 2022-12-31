#include "exibidor.h"
#include <stdio.h>
#include <stdlib.h>
void printClassfile(Classfile *classfile)
{
    printf("Magic: %x", classfile->magic);
    printf("Minor version: %d", classfile->minor_version);
    printf("Major version: %d", classfile->major_version);
    printf("Constant pool count: %d", classfile->constant_pool_count);
    // for (int i = 1; i < classfile->constant_pool_count; i++)
    // {
    //     printCpinfo(&classfile->constant_pool[i]);
    // }
    //Acho que não precisa imprimir o constant pool diretamente
    switch(classfile->access_flags){
        case 0x0001:
            printf("Access flags: public");
            break;
        case 0x0010:
            printf("Access flags: final");
            break;
        case 0x0020:
            printf("Access flags: super");
            break;
        case 0x0200:
            printf("Access flags: interface");
            break;
        case 0x0400:
            printf("Access flags: abstract");
            break;
        case 0x1000:
            printf("Access flags: synthetic");
            break;
        case 0x2000:
            printf("Access flags: annotation");
            break;
        case 0x4000:
            printf("Access flags: enum");
            break;
    }
    printf("This class: %d", classfile->this_class);
    printf("Super class: %d", classfile->super_class);
    printf("Interfaces count: %d", classfile->interfaces_count);
    // for (int i = 0; i < classfile->interfaces_count; i++)
    // {
    //     printf("Interfaces: %d", classfile->[i]);
    // }
    //Não sei onde estão as interfaces
    printf("Fields count: %d", classfile->fields_count);
    for (int i = 0; i < classfile->fields_count; i++)
    {
        printField_info(&classfile->fields[i]);
    }
    printf("Methods count: %d", classfile->methods_count);
    for (int i = 0; i < classfile->methods_count; i++)
    {
        printMethod_info(&classfile->methods[i]);
    }
    printf("Attributes count: %d", classfile->attributes_count);
    for (int i = 0; i < classfile->attributes_count; i++)
    {
   //     printAttribute_info(&classfile->attributes[i]);
    }
    



    
}
void printField_info(field_info *field)
{
    printf("Access flags: %d", field->access_flags);
    printf("Name index: %d", field->name_index);
    printf("Descriptor index: %d", field->descriptor_index);
    printf("Attributes count: %d", field->attributes_count);
    for (int i = 0; i < field->attributes_count; i++)
    {
        printAttribute_info(&field->attributes[i]);
    }
}
void printMethod_info(method_info *method)
{
    printf("Access flags: %d", method->access_flags);
    printf("Name index: %d", method->name_index);
    printf("Descriptor index: %d", method->descriptor_index);
    printf("Attributes count: %d", method->attributes_count);
    for (int i = 0; i < method->attributes_count; i++)
    {
    //    printAttribute_info(&method->attributes[i]);
    }
}
void printAttribute_info(attribute_info *attribute)
{
    printf("Attribute name index: %d", attribute->attribute_name_index);
    printf("Attribute length: %d", attribute->attribute_length);
    //Não sei o que tem dentro de info
    for(int i = 0; i < attribute->attribute_length; i++){
        printf("Info: %d", attribute->info[i]);
    }
}
void printCpinfo(cp_info *cpinfo)
{
    printf("Tag: %d", cpinfo->tag);
    switch (cpinfo->tag){
        case 1:
            printf("Utf8: %s", cpinfo->cp_info_union.utf_8_info.bytes);
            break;
        case 3:
            printf("Integer: %d", cpinfo->cp_info_union.integer_info.bytes);
            break;
        case 4:
            printf("Float: %f", cpinfo->cp_info_union.float_info.bytes);
            break;
        case 5:
            printf("H_Long_1: %ld", cpinfo->cp_info_union.long_info.high_bytes);
            printf("L_Long_2: %ld", cpinfo->cp_info_union.long_info.low_bytes);
            break;
        case 6:
            printf("Double_1: %lf", cpinfo->cp_info_union.double_info.high_bytes);
            printf("Double_2: %lf", cpinfo->cp_info_union.double_info.low_bytes);
            break;
        case 7:
            printf("Class: %d", cpinfo->cp_info_union.class_info.name_index);
            break;
        case 8:
            printf("String: %d", cpinfo->cp_info_union.string_info.string_index);
            break;
        case 9:
            printf("Fieldref_1: %d", cpinfo->cp_info_union.field_ref.class_index);
            printf("Fieldref_2: %d", cpinfo->cp_info_union.field_ref.name_and_type_index);
            break;
        case 10:
            printf("Methodref_1: %d", cpinfo->cp_info_union.method_ref.class_index);
            printf("Methodref_2: %d", cpinfo->cp_info_union.method_ref.name_and_type_index);
            break;
        case 11:
            printf("InterfaceMethodref_1: %d", cpinfo->cp_info_union.interface_method_ref.class_index);
            printf("InterfaceMethodref_2: %d", cpinfo->cp_info_union.interface_method_ref.name_and_type_index);
            break;
        case 12:
            printf("NameAndType: %d", cpinfo->cp_info_union.name_and_type.name_index);
            printf("Descriptor: %d", cpinfo->cp_info_union.name_and_type.descriptor_index);
            break;
        
    }
    

}
