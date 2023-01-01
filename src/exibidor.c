#include "exibidor.h"
#include "classfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decodeUTF8(cp_info * cp){
    int compr = cp->cp_info_union.utf_8_info.length;
    char *string_final = (char *)malloc((compr +1)*sizeof(char));
    u1 * temp = cp->cp_info_union.utf_8_info.bytes;
    for(int i=0;i<+compr; i++){
        *(string_final+i*sizeof(char)) = (char )*temp;
        temp++;
    }
    return string_final;
}

char * decodeClassInfo(cp_info* cp,int classnumber){
    int utflocal = (cp+classnumber)->cp_info_union.class_info.name_index;
    char * stringfinal;
    stringfinal = decodeUTF8(cp+utflocal);
    return stringfinal;
}


char *decodeAccFlags(u2 flag){
    char *decode = malloc(sizeof(char)*100);
    if(flag & 0x0001){
        strcat(decode,"Public, ");
    }
    if(flag & 0x0010){
        strcat(decode,"Final, ");
    }
    if(flag & 0x0020){
        strcat(decode,"Super, ");
    }
    if(flag & 0x0200){
        strcat(decode,"Interface, ");
    }
    if(flag & 0x0400){
        strcat(decode,"Abstract, ");
    }
    if(flag & 0x1000){
        strcat(decode,"Synthetic, ");
    }
    if(flag & 0x2000){
        strcat(decode,"Annotation, ");
    }
    if(flag & 0x4000){
        strcat(decode,"Enum, ");
    }
    
    return decode;
}







void printClassfile(Classfile *classfile)
{
    printf("Magic: %x\n", classfile->magic);
    printf("Minor version: %d\n", classfile->minor_version);
    printf("Major version: %d\n", classfile->major_version);
    printf("Constant pool count: %d\n", classfile->constant_pool_count);


    // for (int i = 1; i < classfile->constant_pool_count; i++)
    // {
    //     printCpinfo(&classfile->constant_pool[i]);
    // }
    //Acho que não precisa imprimir o constant pool diretamente
    printf("Access flags: %d (%s)\n", classfile->access_flags , decodeAccFlags(classfile->access_flags));

    printf("This class: %d <%s>\n", classfile->this_class, decodeClassInfo(classfile->constant_pool,classfile->this_class));
    printf("This class: %d <%s>\n", classfile->super_class, decodeClassInfo(classfile->constant_pool,classfile->super_class));
    printf("Interfaces count: %d\n", classfile->interfaces_count);
    
    // for (int i = 0; i < classfile->interfaces_count; i++)
    // {
    //     printf("Interfaces: %d\n", classfile->[i]);
    // }
    //Não sei onde estão as interfaces

    printf("Fields count: %d\n", classfile->fields_count);
    /*
    for (int i = 0; i < classfile->fields_count; i++)
    {
        printField_info(&classfile->fields[i]);
    }
    */
    printf("Methods count: %d\n", classfile->methods_count);
    printf("=========\n");
    
    for (int i = 0; i < classfile->methods_count; i++)
    {
        printMethod_info(&classfile->methods[i]);
    }
    printf("=========\n");
    

    printf("Attributes count: %d\n", classfile->attributes_count);
    /*
    for (int i = 0; i < classfile->attributes_count; i++){
        printAttribute_info(&classfile->attributes[i], classfile->constant_pool);
    }
    */
}
void printField_info(field_info *field)
{
    printf("Access flags: %d\n", field->access_flags);
    printf("Name index: %d\n", field->name_index);
    printf("Descriptor index: %d\n", field->descriptor_index);
    printf("Attributes count: %d\n", field->attributes_count);
    for (int i = 0; i < field->attributes_count; i++)
    {
  //      printAttribute_info(&field->attributes[i]);
    }
}
void printMethod_info(method_info *method)
{
    printf("Access flags: %d\n", method->access_flags);
    printf("Name index: %d\n", method->name_index);
    printf("Descriptor index: %d\n", method->descriptor_index);
    printf("Attributes count: %d\n", method->attributes_count);

    for (int i = 0; i < method->attributes_count; i++)
    {
        //printAttribute_info(&method->attributes[i]);

    }



}

void printAttribute_info(attribute_info *attribute,cp_info *cp){
    printf("Attribute name index: %d\n", attribute->attribute_name_index);
    printf("Attribute length: %d\n", attribute->attribute_length);
    char * string_name;
    for(int i = 0; i < attribute->attribute_length; i++){

    string_name = decodeUTF8(cp + attribute->attribute_name_index);

    if(strcmp(string_name, "Code")==0){
            //ai->
    }
    else if (strcmp(string_name, "InnerClasses") == 0){
            //innrt
    }
    else if (strcmp(string_name, "ConstantValue") == 0){

    }
    else if (strcmp(string_name, "Exceptions") == 0){
        //
    }
    else if (strcmp(string_name, "SourceFile") == 0){
        printf("nice\n");
    }
    
    else if (strcmp(string_name, "Exceptions") == 0){
        //
    }

    else if (strcmp(string_name, "LineNumberTable") == 0){
        //
    }

    else if (strcmp(string_name, "LocalVariableTable") == 0){
        //
    }
    

    }
}
void printCpinfo(cp_info *cpinfo)
{
    printf("Tag: %d\n", cpinfo->tag);
    switch (cpinfo->tag){
        case 1:
            printf("Utf8: %s", cpinfo->cp_info_union.utf_8_info.bytes);
            break;
        case 3:
            printf("Integer: %d\n", cpinfo->cp_info_union.integer_info.bytes);
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
            printf("Class: %d\n", cpinfo->cp_info_union.class_info.name_index);
            break;
        case 8:
            printf("String: %d\n", cpinfo->cp_info_union.string_info.string_index);
            break;
        case 9:
            printf("Fieldref_1: %d\n", cpinfo->cp_info_union.field_ref.class_index);
            printf("Fieldref_2: %d\n", cpinfo->cp_info_union.field_ref.name_and_type_index);
            break;
        case 10:
            printf("Methodref_1: %d\n", cpinfo->cp_info_union.method_ref.class_index);
            printf("Methodref_2: %d\n", cpinfo->cp_info_union.method_ref.name_and_type_index);
            break;
        case 11:
            printf("InterfaceMethodref_1: %d\n", cpinfo->cp_info_union.interface_method_ref.class_index);
            printf("InterfaceMethodref_2: %d\n", cpinfo->cp_info_union.interface_method_ref.name_and_type_index);
            break;
        case 12:
            printf("NameAndType: %d\n", cpinfo->cp_info_union.name_and_type.name_index);
            printf("Descriptor: %d\n", cpinfo->cp_info_union.name_and_type.descriptor_index);
            break;
        
    }
    

}