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
    
     for (int i = 0; i < classfile->interfaces_count; i++)
     {
         printf("Interfaces: %s\n", decodeUTF8(classfile->constant_pool + classfile->interfaces[i]));
     }

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

    printf("MNEMONICOS CODIGO\n");

    for(int i=0; i<ca.code_length;i++){
        int op = *(ca.code+i);
        int type = get_op_type(op);
        opcode mnem = op;
        printf("%d %s ",i, get_op_name(mnem));
        treatoperand(ca,cp, &i,type);
        printf("\n");
        //printf("i = %d\n",i);
    }
 
    printf("Exception Table Length: %d\n", ca.exception_table_length);
    // printExcepTable
    printf("Attributes Count: %d\n", ca.attributes_count);

    printf("PRINT ATRIBUTOS DE CODE\n");

    for (int i = 0; i < ca.attributes_count; i++)
    {
        printAttribute_info(&ca.attributes[i],cp);

    }

}

void treatoperand(Code_attribute ca, cp_info* cp, int * oper, int type){

    switch(type){
        case 0:  return;
        
        case 1:
        //treatcpattr?
        ++(*oper);
        printf("#%d", *(ca.code+ *oper));
        return;

        case 2:
        //treatcpattr
        ++(*oper);
        u2 temp;
        temp = *(ca.code+*oper) << 8;
        ++(*oper);
        temp |= *(ca.code+*oper);
        printf("#%d", temp);
        return;

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


const char *get_op_name(opcode op)
{
    switch (op)
    {

case    nop:                      return "nop";       
case    aconst_null:              return "aconst_null";               
case    iconst_m1:                return "iconst_m1";             
case    iconst_0:                 return "iconst_0";            

case    iconst_1:                 return "iconst_1";            
case    iconst_2:                 return "iconst_2";            
case    iconst_3:                 return "iconst_3";            
case    iconst_4:                 return "iconst_4";            

case    iconst_5:                 return "iconst_5";            
case    lconst_0:                 return "lconst_0";            
case    lconst_1:                 return "lconst_1";            
case    fconst_0:                 return "fconst_0";            

case    fconst_1:                 return "fconst_1";            
case    fconst_2:                 return "fconst_2";            
case    dconst_0:                 return "dconst_0";            
case    dconst_1:                 return "dconst_1";            

case    bipush:                   return "bipush";          
case    sipush:                   return "sipush";          
case    ldc:                      return "ldc";       
case    ldc_w:                    return "ldc_w";         
case    ldc2_w:                   return "ldc2_w";          

case    iload:                    return "iload";         
case    lload:                    return "lload";         
case    fload:                    return "fload";         
case    dload:                    return "dload";         
case    aload:                    return "aload";         

case    iload_0:                  return "iload_0";           
case    iload_1:                  return "iload_1";           
case    iload_2:                  return "iload_2";           
case    iload_3:                  return "iload_3";           
case    lload_0:                  return "lload_0";           

case    lload_1:                  return "lload_1";           
case    lload_2:                  return "lload_2";           
case    lload_3:                  return "lload_3";           
case    fload_0:                  return "fload_0";           
case    fload_1:                  return "fload_1";           

case    fload_2:                  return "fload_2";           
case    fload_3:                  return "fload_3";           
case    dload_0:                  return "dload_0";           
case    dload_1:                  return "dload_1";           
case    dload_2:                  return "dload_2";           

case    dload_3:                  return "dload_3";           
case    aload_0:                  return "aload_0";           
case    aload_1:                  return "aload_1";           
case    aload_2:                  return "aload_2";           
case    aload_3:                  return "aload_3";           

case    iaload:                   return "iaload";          
case    laload:                   return "laload";          
case    faload:                   return "faload";          
case    daload:                   return "daload";          
case    aaload:                   return "aaload";          
case    baload:                   return "baload";          

case    caload:                   return "caload";          
case    saload:                   return "saload";          
case    istore:                   return "istore";          
case    lstore:                   return "lstore";          
case    fstore:                   return "fstore";          
case    dstore:                   return "dstore";          

case    astore:                   return "astore";          
case    istore_0:                 return "istore_0";            
case    istore_1:                 return "istore_1";            
case    istore_2:                 return "istore_2";            
case    istore_3:                 return "istore_3";            

case    lstore_0:                 return "lstore_0";            
case    lstore_1:                 return "lstore_1";            
case    lstore_2:                 return "lstore_2";            
case    lstore_3:                 return "lstore_3";            
case    fstore_0:                 return "fstore_0";            

case    fstore_1:                 return "fstore_1";            
case    fstore_2:                 return "fstore_2";            
case    fstore_3:                 return "fstore_3";            
case    dstore_0:                 return "dstore_0";            
case    dstore_1:                 return "dstore_1";            

case    dstore_2:                 return "dstore_2";            
case    dstore_3:                 return "dstore_3";            
case    astore_0:                 return "astore_0";            
case    astore_1:                 return "astore_1";            
case    astore_2:                 return "astore_2";            

case    astore_3:                 return "astore_3";            
case    iastore:                  return "iastore";           
case    lastore:                  return "lastore";           
case    fastore:                  return "fastore";           
case    dastore:                  return "dastore";           

case    aastore:                  return "aastore";           
case    bastore:                  return "bastore";           
case    castore:                  return "castore";           
case    sastore:                  return "sastore";           
case    pop:                      return "pop";       
case    pop2:                     return "pop2";        

case    dup:                      return "dup";       
case    dup_x1:                   return "dup_x1";          
case    dup_x2:                   return "dup_x2";          
case    dup2:                     return "dup2";        
case    dup2_x1:                  return "dup2_x1";           
case    dup2_x2:                  return "dup2_x2";           
case    swap:                     return "swap";        

case    iadd:                     return "iadd";        
case    ladd:                     return "ladd";        
case    fadd:                     return "fadd";        
case    dadd:                     return "dadd";        
case    isub:                     return "isub";        
case    lsub:                     return "lsub";        
case    fsub:                     return "fsub";        
case    dsub:                     return "dsub";        

case    imul:                     return "imul";        
case    lmul:                     return "lmul";        
case    fmul:                     return "fmul";        
case    dmul:                     return "dmul";        
case    idiv:                     return "idiv";        
case    inst_ldiv:                return "inst_ldiv";             
case    fdiv:                     return "fdiv";        
case    ddiv:                     return "ddiv";        

case    irem:                     return "irem";        
case    lrem:                     return "lrem";        
case    frem:                     return "frem";        
case    inst_drem:                return "inst_drem";             
case    ineg:                     return "ineg";        
case    lneg:                     return "lneg";        
case    fneg:                     return "fneg";        
case    dneg:                     return "dneg";        

case    ishl:                     return "ishl";        
case    lshl:                     return "lshl";        
case    ishr:                     return "ishr";        
case    lshr:                     return "lshr";        
case    iushr:                    return "iushr";         
case    lushr:                    return "lushr";         
case    iand:                     return "iand";        
case    land:                     return "land";        

case    ior:                      return "ior";       
case    lor:                      return "lor";       
case    ixor:                     return "ixor";        
case    lxor:                     return "lxor";        
case    iinc:                     return "iinc";        
case    i2l:                      return "i2l";       
case    i2f:                      return "i2f";       
case    i2d:                      return "i2d";       
case    l2i:                      return "l2i";       

case    l2f:                      return "l2f";       
case    l2d:                      return "l2d";       
case    f2i:                      return "f2i";       
case    f2l:                      return "f2l";       
case    f2d:                      return "f2d";       
case    d2i:                      return "d2i";       
case    d2l:                      return "d2l";       
case    d2f:                      return "d2f";       
case    i2b:                      return "i2b";       
case    i2c:                      return "i2c";       
case    i2s:                      return "i2s";       
case    lcmp:                     return "lcmp";        
case    fcmpl:                    return "fcmpl";         
case    fcmpg:                    return "fcmpg";         
case    dcmpl:                    return "dcmpl";         
case    dcmpg:                    return "dcmpg";         
case    ifeq:                     return "ifeq";        

case    ifne:                     return "ifne";        
case    iflt:                     return "iflt";        
case    ifge:                     return "ifge";        
case    ifgt:                     return "ifgt";        
case    ifle:                     return "ifle";        
case    if_icmpeq:                return "if_icmpeq";             
case    if_icmpne:                return "if_icmpne";             

case    if_icmplt:                return "if_icmplt";             
case    if_icmpge:                return "if_icmpge";             
case    if_icmpgt:                return "if_icmpgt";             
case    if_icmple:                return "if_icmple";             
case    if_acmpeq:                return "if_acmpeq";             

case    if_acmpne:                return "if_acmpne";             
case    inst_goto:                return "inst_goto";             
case    jsr:                      return "jsr";       
case    ret:                      return "ret";       
case    tableswitch:              return "tableswitch";               

case    lookupswitch:             return "lookupswitch";                
case    ireturn:                  return "ireturn";           
case    lreturn:                  return "lreturn";           
case    freturn:                  return "freturn";           
case    dreturn:                  return "dreturn";           

case    areturn:                  return "areturn";           
case    inst_return:              return "inst_return";               
case    getstatic:                return "getstatic";             
case    putstatic:                return "putstatic";             
case    getfield:                 return "getfield";            

case    putfield:                 return "putfield";            
case    invokevirtual:            return "invokevirtual";                 
case    invokespecial:            return "invokespecial";                 
case    invokestatic:             return "invokestatic";                

case    invokeinterface:          return "invokeinterface";               
case    invokedynamic:            return "invokedynamic";                   
case    new:                      return "new";            
case    newarray:                 return "newarray";            
case    anewarray:                return "anewarray";             

case    arraylength:              return "arraylength";               
case    athrow:                   return "athrow";          
case    checkcast:                return "checkcast";             
case    instanceof:               return "instanceof";

case    monitorenter:             return "monitorenter";                
case    monitorexit:              return "monitorexit";               
case    wide:                     return "wide";        
case    multianewarray:           return "multianewarray";                  
case    ifnull:                   return "ifnull";          

case    ifnonnull:                return "ifnonnull";             
case    goto_w:                   return "goto_w";          
case    jsr_w:                    return "jsr_w";         
    }

    return "Unknown op";
}

//https://en.wikipedia.org/wiki/List_of_Java_bytecode_instructions

int get_op_type(int op){
    switch(op){

        case wide: return 4;
        case tableswitch: return 41;
        case lookupswitch: return 42;
        case invokeinterface: return 43;
        case invokedynamic: return 44;

        case goto_w:
        case jsr_w: return 45;

        case aload:
        case astore:
        case dload:
        case dstore:
        case fload:
        case fstore:
        case iload:
        case istore:
        case ldc:
        case lload:
        case lstore:
        case ret: return 1;  //index

        case bipush: return 10; //byte
        case newarray: return 12; //atype

        case anewarray:
        case checkcast:
        case getfield:
        case getstatic:
        case instanceof:
        case invokespecial:
        case invokestatic:
        case invokevirtual:
        case ldc_w:
        case ldc2_w:
        case new:
        case putfield:
        case putstatic: return 2;  //index

        case iinc: return 21;     //ind const
        case sipush: return 22;   //byte byte

        case inst_goto:
        case if_acmpeq:
        case if_acmpne:
        case if_icmpeq:
        case if_icmpge:
        case if_icmpgt:
        case if_icmple:
        case if_icmplt:
        case if_icmpne:
        case ifge:
        case ifgt:
        case ifeq:
        case ifle:
        case iflt:
        case ifne:
        case ifnonnull:
        case ifnull:
        case jsr: return 23;   //branchbyte


        default:
            return 0;
    }
    
}