#include <stdint.h>
#ifndef CLASSFILEH
#define CLASSFILEH

/*
ClassFile {
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

typedef struct cp_info{

}cp_info;

typedef struct field_info{

}field_info;

typedef struct method_info{

}method_info;

typedef struct attribute_info{

}attribute_info;

typedef struct ClassFile {
    u4             magic;
    u2             minor_version;
    u2             major_version;
    u2             constant_pool_count;
    cp_info        *constant_pool;
    u2             access_flags;
    u2             this_class;
    u2             super_class;
    u2             interfaces_count;
    u2             interfaces;
    u2             fields_count;
    field_info     *fields;
    u2             methods_count;
    method_info    *methods;
    u2             attributes_count;
    attribute_info *attributes;
}ClassFile;

#endif
