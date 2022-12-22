#include <stdint.h>
#ifndef CLASSFILEH
#define CLASSFILEH

/*
Classfile {
    u4             magic;
    u2             minor_version;
    u2             major_version;
    u2             constant_pool_count;
    cp_info        constant_pool[constant_pool_count-1];
    u2             access_flags;
    u2             this_class;
    u2             super_class;
    u2             interfaces_count;
    u2             interfaces[interfaces_count];
    u2             fields_count;
    field_info     fields[fields_count];
    u2             methods_count;
    method_info    methods[methods_count];
    u2             attributes_count;
    attribute_info attributes[attributes_count];
}
*/

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned long u8;

typedef struct attribute_info
{
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *info;

} attribute_info;

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
    attribute_info *attributes;

} method_info;

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
} Classfile;

#endif
