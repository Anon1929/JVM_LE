#include <stdint.h>
#ifndef CLASSFILEH
#define CLASSFILEH

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned long u8;

typedef struct cp_info
{
    u1 tag;
    union
    {
        struct
        {
            u2 name_index;
        } class_info;
        struct
        {
            u2 class_index;
            u2 name_and_type_index;
        } field_ref;
        struct
        {
            u2 class_index;
            u2 name_and_type_index;

        } method_ref;
        struct
        {
            u2 class_index;
            u2 name_and_type_index;
        } interface_method_ref;
        struct
        {
            u2 name_index;
            u2 descriptor_index;
        } name_and_type;
        struct
        {
            u2 length;
            u1 *bytes;
        } utf_8_info;
        struct
        {
            u2 string_index;
        } string_info;
        struct
        {
            u4 bytes;
        } integer_info;
        struct
        {
            u4 bytes;
        } float_info;
        struct
        {
            u4 high_bytes;
            u4 low_bytes;
        } long_info;
        struct
        {
            u4 high_bytes;
            u4 low_bytes;
        } double_info;

    } cp_info_union;

} cp_info;

typedef struct attribute_info
{
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *info;

} attribute_info;

typedef struct exception_table
{
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;

} exception_table;

typedef struct Code_attribute
{
    u2 attribute_name_index;
    u4 attribute_length;
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1 *code;
    u2 exception_table_length;
    exception_table *exception_table; //ponteiro para uma struct exception_table?
    u2 attributes_count;
    attribute_info *attributes;

} Code_attribute;

typedef struct Exceptions_attribute
{
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_exceptions;
    u2 *exception_index_table;

} Exceptions_attribute;

typedef struct classes
{
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags;

} classes;

typedef struct InnerClasses_attribute
{
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    classes *classes;

} InnerClasses_attribute;

typedef struct field_info
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;

} field_info;

typedef struct method_info
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info **attributes;

} method_info;

enum tagswitch
{
    CONSTANT_Class = 7,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_String = 8,
    CONSTANT_Integer = 3,
    CONSTANT_Float = 4,
    CONSTANT_Long = 5,
    CONSTANT_Double = 6,
    CONSTANT_NameAndType = 12,
    CONSTANT_Utf8 = 1,
    CONSTANT_MethodHandle = 15,
    CONSTANT_MethodType = 16,
    CONSTANT_InvokeDynamic = 18
};

typedef struct Classfile
{
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    cp_info *constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 interfaces;
    u2 fields_count;
    field_info *fields;
    u2 methods_count;
    method_info *methods;
    u2 attributes_count;
    attribute_info *attributes;
    InnerClasses_attribute *inner_classes_attribute;

} Classfile;

#endif
