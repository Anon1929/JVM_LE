#include "jvm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stack_push(stack* pilha, int32_t elem){
    pilha->altura++;
    pilha->stackarr[pilha->altura-1]=elem;
}


void push_float_in_stack(stack* pilha, float valor_f) {
    int32_t valor;

    memcpy(&valor, &valor_f, 4);
    stack_push(pilha, valor);
}

void push_double_in_stack(stack* pilha, double valor_d) {
    u1 buffer[8];
    memcpy(&buffer, &valor_d, 8);

    int32_t first_half;
    int32_t second_half;

    memcpy(&first_half, buffer+4, 4);
    memcpy(&second_half, buffer, 4);

    stack_push(pilha, first_half);
    stack_push(pilha, second_half);
}


int32_t stack_pop(stack* pilha){
    --(pilha->altura);
    return pilha->stackarr[pilha->altura];
}


void insert_in_local_var_array(local_variable_vector* vetor_variaveis, int32_t elem, int indice) {
    vetor_variaveis->vetor[indice] = elem;
}

int32_t get_from_array(local_variable_vector* vetor_variaveis, int indice) {
    return vetor_variaveis->vetor[indice];
}

char *concatena_strings(char str1[], char str2[]) { 
    char* result = (char*)malloc(sizeof(strlen(str1) + strlen(str2) + 1));   

    memcpy(result, str1, strlen(str1));
    memcpy(result + strlen(str1), str2, strlen(str2));
    memcpy(result + strlen(str1) + strlen(str2), "", 1);
     
    return result;
}



char *ponto_class(char name_class[]) {
    int posicao = strlen(name_class)-1;
    int tamanho = 0;

    while(name_class[posicao] != '/') {
        tamanho++;
        posicao--;
    }

    return concatena_strings(name_class + posicao + 1, ".class");

}

int ja_foi_carregada(char nome_classe[],method_area* area_metodos) {
    
    for(int i = 0;i < area_metodos->qtd_atual;i++){
        method_area_item  m = area_metodos->classes[i];
        if(strcmp(nome_classe, m.class_name) == 0) {
            return 1;
        }
    }

    return 0;
}



u2 get_qtd_fields_estaticos(Classfile* classfile) {
    field_info* fields = classfile->fields;
    u2 contador = 0;

    
    for(int i = 0;i < classfile->fields_count;i++) {
        if ((fields[i].access_flags & 0x0008) == 0x0008) {
            contador++;
        }
    }

    return contador;
}

u2 get_qtd_fields_nao_estaticos(Classfile* classfile) {
    return classfile->fields_count - get_qtd_fields_estaticos(classfile);
}



classfields* get_info_statics(Classfile* classfile){
    u2 qtd = get_qtd_fields_estaticos(classfile);
    field_info* fields_info = classfile->fields;
    classfields* aux = (classfields*)malloc(sizeof(classfields)*qtd);
    int pos_static = 0;
    int i = 0;

    while(pos_static < qtd) {
        field_info f = fields_info[i];

        if ((f.access_flags & 0x0008) == 0x0008) {
            aux[pos_static].name = decodeUTF8(&classfile->constant_pool[f.name_index]);
            aux[pos_static].descriptor = decodeUTF8(&classfile->constant_pool[f.descriptor_index]);
            aux[pos_static].flags = f.access_flags;
            pos_static++;
        }

        i++;
    }

    return aux;
}


classfields* get_info_non_statics(Classfile* classfile){
    u2 qtd = get_qtd_fields_nao_estaticos(classfile);
    field_info* fields_info = classfile->fields;
    classfields* aux = (classfields*)malloc(sizeof(classfields)*qtd);
    int pos_static = 0;
    int i = 0;

    while(pos_static < qtd) {
        field_info f = fields_info[i];

        if ((f.access_flags & 0x0008) != 0x0008) {
            aux[pos_static].name = decodeUTF8(&classfile->constant_pool[f.name_index]);
            aux[pos_static].descriptor = decodeUTF8(&classfile->constant_pool[f.descriptor_index]);
            aux[pos_static].flags = f.access_flags;
            pos_static++;
        }

        i++;
    }

    return aux;
}


field_variable* gera_field_variables(classfields* info_fields, u2 qtd) {
    field_variable* vetor_fields = (field_variable*)malloc(sizeof(field_variable)*qtd);

    for(int i = 0; i < qtd;i++) {
        vetor_fields[i].name = info_fields[i].name;
    }

    return vetor_fields;
}



method_area_item* busca_endereco_class_in_method_area(method_area* area_metodos, char class_name[]) {    
    for(int i = 0; i < area_metodos->qtd_atual;i++) {
        method_area_item m = area_metodos->classes[i];

        if(strcmp(class_name, m.class_name) == 0) {
            return area_metodos->classes+i;
        }
    }
}




void imprime_fields(field_variable* vetor_fields, u2 length) {
    for(int i = 0; i < length;i++) {
        printf("[%d] name = %s //", i, vetor_fields[i].name);
    }
    printf("\n");
    printf("\n");
}


void imprime_metodos(classmethod* vetor_metodos, u2 length) {
    for(int i = 0; i < length;i++) {
        printf("Metodo[%d] - %s : ", i, vetor_metodos[i].descriptor);
        printf("%s //   ", vetor_metodos[i].name);
    }
    printf("\n");
    printf("\n");
}

void insere_class_in_method_area(method_area_item* m, method_area* area_metodos) {
    area_metodos->classes[area_metodos->qtd_atual] = (*m);
    area_metodos->qtd_atual++;
}

void preenche_fields_in_class(method_area_item* m, Classfile* classfile) {
    m->qtd_fields_estaticos = get_qtd_fields_estaticos(classfile);
    m->qtd_fields_nao_estaticos = get_qtd_fields_nao_estaticos(classfile);

    m->info_static_fields =  get_info_statics(classfile);
    m->info_non_static_fields =  get_info_non_statics(classfile);

    m->static_fields = gera_field_variables(m->info_static_fields, m->qtd_fields_estaticos); // criando fields estáticos
}


classcode gera_classcode(int num_metodo, Classfile* classfile) {
    classcode c;
    c.tamanho_codigo = classfile->methods[num_metodo].attributes[0]->attr_info_union.Code.code_length;
    c.code = (u1*)malloc(sizeof(u1)* c.tamanho_codigo);
    memcpy(c.code, classfile->methods[num_metodo].attributes[0]->attr_info_union.Code.code, c.tamanho_codigo);
    
    return c;
}


void preenche_methods_in_class(method_area_item* classe, Classfile* classfile, method_area* area_metodos) {
    cp_info* constant_pool = classfile->constant_pool;
    classe->qtd_metodos = classfile->methods_count;
    classe->metodos = (classmethod*)malloc(sizeof(classmethod)*classe->qtd_metodos);
    
    for(int i = 0; i < classe->qtd_metodos;i++) {
        classmethod metodo;
        
        metodo.name = decodeUTF8(&constant_pool[classfile->methods[i].name_index]);
        metodo.descriptor = decodeUTF8(&constant_pool[classfile->methods[i].descriptor_index]);
        metodo.access_flags = classfile->methods[i].access_flags;
        
        metodo.codigo = gera_classcode(i, classfile);

        classe->metodos[i] = metodo;   
    }

}


void carrega_classe_por_nome(char name[], method_area* area_metodos) {
    Classfile* classfile = (Classfile*)malloc(sizeof(Classfile));
    readFile(classfile, concatena_strings("test/", ponto_class(name)));
    carregamento(classfile, area_metodos);   
}



void carregamento(Classfile* classfile, method_area* area_metodos) {

    method_area_item m;

    m.class_name = decodeClassInfo(classfile->constant_pool, classfile->this_class);
    char* father_class_name =  decodeClassInfo(classfile->constant_pool, classfile->super_class);

    if (ja_foi_carregada(m.class_name, area_metodos)) {
        printf("Classe já carregada\n");
        return;
    }

    if(strcmp(father_class_name, "java/lang/Object") != 0) {
        carrega_classe_por_nome(father_class_name, area_metodos);   
    }    
    
    m.father_class = busca_endereco_class_in_method_area(area_metodos,father_class_name);
    m.classfile = classfile;

   
    preenche_fields_in_class(&m, classfile);
    preenche_methods_in_class(&m, classfile, area_metodos);
    insere_class_in_method_area(&m, area_metodos);


    printf("\n\nInformações classe %s\n", m.class_name);
    printf("Fields estáticos\n");
    imprime_fields(m.static_fields, m.qtd_fields_estaticos); 
    printf("Imprime métodos\n");
    imprime_metodos(m.metodos, m.qtd_metodos);
    printf("--------------------------------------------------------------------------------------------\n");
}

