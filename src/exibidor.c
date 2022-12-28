#include "exibidor.h"

void printClassfile(Classfile *classfile)
{
    printf("Magic: %x", classfile->magic);
    printf("Version: %d.%d", classfile->major_version, classfile->minor_version);
    printf("Constant pool count: %d", classfile->constant_pool_count);
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
    
}

int main(int argc, char *argv[])
{
    Classfile *classfile = (Classfile *)malloc(sizeof(Classfile));
    readClassfile(classfile);
    printClassfile(classfile);
    return 0;
}