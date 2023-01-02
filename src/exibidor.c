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
        strcat(decode,"Public ");
    }
    if(flag & 0x0008){
        strcat(decode,"Static ");
    }
    if(flag & 0x0010){
        strcat(decode,"Final ");
    }
    if(flag & 0x0020){
        strcat(decode,"Super ");
    }
    if(flag & 0x0200){
        strcat(decode,"Interface ");
    }
    if(flag & 0x0400){
        strcat(decode,"Abstract ");
    }
    if(flag & 0x1000){
        strcat(decode,"Synthetic ");
    }
    if(flag & 0x2000){
        strcat(decode,"Annotation ");
    }
    if(flag & 0x4000){
        strcat(decode,"Enum ");
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
    printf("Access flags: %d [%s]\n", classfile->access_flags , decodeAccFlags(classfile->access_flags));

    printf("This class: %d <%s>\n", classfile->this_class, decodeClassInfo(classfile->constant_pool,classfile->this_class));
    printf("This class: %d <%s>\n", classfile->super_class, decodeClassInfo(classfile->constant_pool,classfile->super_class));
    printf("Interfaces count: %d\n", classfile->interfaces_count);
    
    // for (int i = 0; i < classfile->interfaces_count; i++)
    // {
    //     printf("Interfaces: %d\n", classfile->[i]);
    // }
    //Não sei onde estão as interfaces

    printf("EXIBIÇÃO DE FIELDS\n");
    printf("=========\n");

    printf("Fields count: %d\n", classfile->fields_count);
    
    for (int i = 0; i < classfile->fields_count; i++)
    {
        printField_info(&classfile->fields[i],classfile->constant_pool);
        printf("=========\n");
    }
    
    printf("FIM EXIBIÇÃO DE FIELDS\n");




    printf("Methods count: %d\n", classfile->methods_count);
    printf("EXIBIÇÃO DE MÉTODOS\n");
    printf("=========\n");
    
    for (int i = 0; i < classfile->methods_count; i++)
    {
        printMethod_info(&classfile->methods[i],classfile->constant_pool);
        printf("=========\n");
    }
    printf("FIM EXIBIÇÃO DE MÉTODOS\n");
    
    
    printf("EXIBIÇÃO DE ATRIBUTOS\n");
    printf("=========\n");
    
    printf("Attributes count: %d\n", classfile->attributes_count);
    
    for (int i = 0; i < classfile->attributes_count; i++){
        printAttribute_info(&classfile->attributes[i], classfile->constant_pool);
        printf("=========\n");
    }

    printf("FIM EXIBIÇÃO DE ATRIBUTOS\n");
}
void printField_info(field_info *field,cp_info * cp)
{
    printf("Access flags: %d\n", field->access_flags);
    printf("Name index: %d\n", field->name_index);
    printf("Descriptor index: %d\n", field->descriptor_index);
    printf("Attributes count: %d\n", field->attributes_count);
    for (int i = 0; i < field->attributes_count; i++)
    {
        printAttribute_info(field->attributes[i],cp);
    }
}
void printMethod_info(method_info *method,cp_info *cp)
{
    printf("Access flags: %d [%s]\n", method->access_flags, decodeAccFlags(method->access_flags));
    printf("Name index: %d <%s>\n", method->name_index, decodeUTF8(cp + method->name_index));
    printf("Descriptor index: %d <%s>\n", method->descriptor_index, decodeUTF8(cp + method->descriptor_index));
    printf("Attributes count: %d\n", method->attributes_count);

    for (int i = 0; i < method->attributes_count; i++)
    {
        printAttribute_info(method->attributes[i],cp);

    }
}

void printAttribute_info(attribute_info *attribute,cp_info *cp){
    printf("\n");
    printf("Attribute name index: %d <%s> \n", attribute->attribute_name_index, decodeUTF8(cp + attribute->attribute_name_index));
    printf("Attribute length: %d\n", attribute->attribute_length);
    char * string_name;

    string_name = decodeUTF8(cp + attribute->attribute_name_index);

    if(strcmp(string_name, "Code")==0){

        printCodeAttr(attribute->attr_info_union.Code, cp);

    }
    else if (strcmp(string_name, "InnerClasses") == 0){
        printf("Inner Classes length: %d\n", attribute->attr_info_union.InnerClass.number_of_classes);
        for (int i = 0; i < attribute->attr_info_union.InnerClass.number_of_classes; i++){
            printf("Inner Class Info: %d\n", attribute->attr_info_union.InnerClass.classes[i].inner_class_info_index);
            printf("Outer Class Info: %d\n", attribute->attr_info_union.InnerClass.classes[i].outer_class_info_index);
            printf("Inner Name Index: %d\n", attribute->attr_info_union.InnerClass.classes[i].inner_name_index);
            printf("Inner Class Access Flags: %d\n", attribute->attr_info_union.InnerClass.classes[i].inner_class_access_flags);
        }
    }
    else if (strcmp(string_name, "ConstantValue") == 0){
        printf("Constant Value Index: %d <%s>\n", attribute->attr_info_union.ConstantValueindex, decodeUTF8(cp + attribute->attr_info_union.ConstantValueindex));


    }
    else if (strcmp(string_name, "Exceptions") == 0){
        printf("Number of Exceptions: %d\n", attribute->attr_info_union.Exception.number_of_exceptions);
        for (int i = 0; i < attribute->attr_info_union.Exception.number_of_exceptions; i++){
            printf("Exception Index: %d <%s>\n", attribute->attr_info_union.Exception.exception_index_table[i], decodeUTF8(cp + attribute->attr_info_union.Exception.exception_index_table[i]));
        }
    }
    else if (strcmp(string_name, "SourceFile") == 0){
        printf("Source File Name Index: %d <%s>\n", attribute->attr_info_union.SourceFileindex, decodeUTF8(cp + attribute->attr_info_union.SourceFileindex));
    }

    else if (strcmp(string_name, "LineNumberTable") == 0){

        printf("Line Number Table length: %d\n", attribute->attr_info_union.LineNumberTable_attr.line_number_table_length);
        printf("start_pc\tline_number\n");
        for(int i=0;i<attribute->attr_info_union.LineNumberTable_attr.line_number_table_length; i++){
            int startpc = attribute->attr_info_union.LineNumberTable_attr.line_number_table[i].start_pc;
            int linenumber = attribute->attr_info_union.LineNumberTable_attr.line_number_table[i].line_number;
            printf("%d\t\t\t%d\n",startpc,linenumber);
        }

    }

    else if (strcmp(string_name, "LocalVariableTable") == 0){
        printf("Local Variable Table length: %d\n", attribute->attr_info_union.LocalVariableTable_attr.local_variable_table_length);
        printf("start_pc\tlength\tname_index\tdescriptor_index\tindex\n");
        for(int i=0;i<attribute->attr_info_union.LocalVariableTable_attr.local_variable_table_length; i++){
            int startpc = attribute->attr_info_union.LocalVariableTable_attr.local_variable_table[i].start_pc;
            int length = attribute->attr_info_union.LocalVariableTable_attr.local_variable_table[i].length;
            int nameindex = attribute->attr_info_union.LocalVariableTable_attr.local_variable_table[i].name_index;
            int descriptorindex = attribute->attr_info_union.LocalVariableTable_attr.local_variable_table[i].descriptor_index;
            int index = attribute->attr_info_union.LocalVariableTable_attr.local_variable_table[i].index;
            printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",startpc,length,nameindex,descriptorindex,index);
        }
    }

    printf("\n");
    

    
}

void printCodeAttr(Code_attribute ca, cp_info * cp){
    printf("Max Stack: %d\n", ca.max_stack);
    printf("Max Locals: %d\n", ca.max_locals);
    printf("Code Length: %d\n", ca.code_length);

    printf("1 - %d\n", *(ca.code));
    // printCode
    printf("Exception Table Length: %d\n", ca.exception_table_length);
    // printExcepTable
    printf("Attributes Count: %d\n", ca.attributes_count);

    printf("PRINT ATRIBUTOS DE CODE\n");

    for (int i = 0; i < ca.attributes_count; i++)
    {
        printAttribute_info(&ca.attributes[i],cp);

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