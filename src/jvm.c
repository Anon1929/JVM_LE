#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jvm.h"


void (*vetorfuncs[256])(Jvm *, frame*, classcode*);


uint32_t uint32_from_bits_in_i32t(int32_t valor_int32) {
    uint32_t valor_u32;
    memcpy(&valor_u32,&valor_int32,4);
    return valor_u32;
}


void* pointer_from_bits_in_i32t(int32_t valor_int32) {
    void* pointer;
    memcpy(&pointer, &valor_int32,4);
    
    return pointer;
}




void stack_push(stack* pilha, int32_t elem){
    pilha->altura++;
    pilha->stackarr[pilha->altura-1] = elem;
}

int32_t stack_pop(stack* pilha){
    --(pilha->altura);
    return pilha->stackarr[pilha->altura];
}

void push_reference_in_stack(stack* pilha, void* reference) {
    int32_t valor;
    memcpy(&valor, &reference, 4);
    stack_push(pilha, valor);
}
int64_t stack_pop_double(stack* pilha){
    --(pilha->altura);
    --(pilha->altura);
    int32_t first_half = pilha->stackarr[pilha->altura];
    int32_t second_half = pilha->stackarr[pilha->altura+1];
    u1 buffer[8];
    memcpy(buffer, &first_half, 4);
    memcpy(buffer+4, &second_half, 4);
    int64_t valor;
    memcpy(&valor, buffer, 8);
    return valor;
}


void push_long_in_stack(stack* pilha, int64_t valor_l) {
    u1 buffer[8];
    memcpy(&buffer, &valor_l, 8);

    int32_t first_half;
    int32_t second_half;

    memcpy(&first_half, buffer+4, 4);
    memcpy(&second_half, buffer, 4);

    stack_push(pilha, first_half);
    stack_push(pilha, second_half);
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
void insert_in_local_var_array_double(frame *, int64_t,int32_t){

}

void insert_in_array_short(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor) {
    Array *array = (Array *) arrayref;
    int16_t *vetor = (int16_t *) array->vetor;
    vetor[indice] = valor;
}
void insert_in_array_char(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor) {
    Array *array = (Array *) arrayref;
    int16_t *vetor = (int16_t *) array->vetor;
    vetor[indice] = valor;
}
void insert_in_array_byte(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor) {
    Array *array = (Array *) arrayref;
    int8_t *vetor = (int8_t *) array->vetor;
    vetor[indice] = valor;
}
void insert_in_array_ref(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor) {
    Array *array = (Array *) arrayref;
    int32_t *vetor = (int32_t *) array->vetor;
    vetor[indice] = valor;
}
void insert_in_array_double(Jvm *jvm, int32_t arrayref, int32_t indice, int64_t elem) {
    Array *array = (Array *) arrayref;
    double *vetor = (double *) array->vetor;
    vetor[indice] = elem;
}
void insert_in_array_int(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t elem) {
    Array *array = (Array *) arrayref;
    int32_t *vetor = (int32_t *) array->vetor;
    vetor[indice] = elem;
}
void insert_in_array_long(Jvm *jvm, int32_t arrayref, int32_t indice, int64_t elem) {
    Array *array = (Array *) arrayref;
    long *vetor = (long *) array->vetor;
    vetor[indice] = elem;
}
void insert_in_array_float(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t elem) {
    Array *array = (Array *) arrayref;
    float *vetor = (float *) array->vetor;
    vetor[indice] = elem;
}
void typepush_opstack(frame * frame_atual, char c){
    frame_atual->pilha_tipos_operandos[frame_atual->altura_tipos++] = c;
}
char typepop_opstack(frame * frame_atual){
    return frame_atual->pilha_tipos_operandos[--(frame_atual->altura_tipos)];
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
        method_area_item  ma = area_metodos->classes[i];
        if(strcmp(nome_classe, ma.class_name) == 0) {
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
        method_area_item ma = area_metodos->classes[i];

        if(strcmp(class_name, ma.class_name) == 0) {
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
void insert_in_local_var_array(int32_t* variaveis_vetor, int32_t elem, int32_t indice){
    variaveis_vetor[indice]= elem;
}
void insere_class_in_method_area(method_area_item* ma, method_area* area_metodos) {
    area_metodos->classes[area_metodos->qtd_atual] = (*ma);
    area_metodos->qtd_atual++;
}

void preenche_fields_in_class(method_area_item* ma, Classfile* classfile) {
    ma->qtd_fields_estaticos = get_qtd_fields_estaticos(classfile);
    ma->qtd_fields_nao_estaticos = get_qtd_fields_nao_estaticos(classfile);

    ma->info_static_fields =  get_info_statics(classfile);
    ma->info_non_static_fields =  get_info_non_statics(classfile);

    ma->static_fields = gera_field_variables(ma->info_static_fields, ma->qtd_fields_estaticos); // criando fields estáticos
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


void carrega_classe_por_nome(char name[], method_area* area_metodos, Jvm* jvm) {
    Classfile* classfile = (Classfile*)malloc(sizeof(Classfile));
    readFile(classfile, concatena_strings("test/", ponto_class(name)));
    carregamento(classfile, area_metodos, jvm);   
}



void carregamento(Classfile* classfile, method_area* area_metodos,Jvm* jvm) {

    method_area_item ma;

    ma.class_name = decodeClassInfo(classfile->constant_pool, classfile->this_class);
    char* father_class_name =  decodeClassInfo(classfile->constant_pool, classfile->super_class);

    if (ja_foi_carregada(ma.class_name, area_metodos)) {
        printf("Classe já carregada\n");
        return;
    }

    if(strcmp(father_class_name, "java/lang/Object") != 0) {
        carrega_classe_por_nome(father_class_name, area_metodos, jvm);   
    }    
    
    ma.father_class = busca_endereco_class_in_method_area(area_metodos,father_class_name);
    ma.classfile = classfile;
   
    preenche_fields_in_class(&ma, classfile);
    preenche_methods_in_class(&ma, classfile, area_metodos);
    insere_class_in_method_area(&ma, area_metodos);


    printf("\n\nInformações classe %s\n", ma.class_name);
    printf("Fields estáticos\n");
    imprime_fields(ma.static_fields, ma.qtd_fields_estaticos); 
    printf("Imprime métodos\n");
    imprime_metodos(ma.metodos, ma.qtd_metodos);
    printf("--------------------------------------------------------------------------------------------\n");
    
    for(int i=0;i<ma.qtd_metodos;i++){
        if(strcmp(ma.metodos[i].name, "<clinit>")==0){
            frame *frame_novo;
            frame_novo = allocframe(ma.classfile->constant_pool);
            jvm->pilha_de_frames[jvm->framecount]= *frame_novo;
            jvm->framecount++;
            printf("Iniciando Execução Clinit\n");
            bytecodeexec(&(ma.metodos[i].codigo), jvm, frame_novo);
                //clinit_exec(&ma);
        }
    }
    
}

void jvm_exec(method_area* area_metodos,Jvm* jvm){
    //Varredura total para ver se encontra main
    method_area_item ma;
    int mainencontrado = 0;
    int i=0,j=0;

    for(int i=0;i<area_metodos->qtd_atual;i++){
        ma = area_metodos->classes[i];
        for(;j<ma.qtd_metodos;j++){
            if(strcmp(ma.metodos[j].name, "main")==0){
                printf("Main encontrado\n");
                mainencontrado=1;
                goto found_main;
            }
        }    
    }
    found_main:
    if(mainencontrado){
        frame *frame_novo = allocframe(ma.classfile->constant_pool);
        jvm->pilha_de_frames[jvm->framecount]= *frame_novo;
        jvm->framecount++;
        printf("Iniciando Execução Main\n");
        bytecodeexec(&(ma.metodos[j].codigo), jvm, frame_novo);

    }
    else{
        printf("Main não encontrado\n");
    }
}

void bytecodeexec(classcode *code,Jvm * jvm, frame *frame_atual){
    jvm->pc=0;
    u1 bytecode;
    while(jvm->pc < code->tamanho_codigo){
        bytecode = code->code[jvm->pc];
        printf("%s\n",get_op_name(bytecode));
        vetorfuncs[bytecode](jvm,frame_atual,code);
    }
}
/*
Object* instanciarObjeto(method_area_item *ma){
    Object *newobject = (Object *) malloc(sizeof(Object));
    newobject->atributos = (int32_t *) malloc(sizeof(int32_t)*ma->qtd_fields_nao_estaticos*2);
    newobject->atributos_nome = (classfields *) malloc(sizeof(classfields)*ma->qtd_fields_nao_estaticos*2);
    newobject->classe = ma;
    return newobject;
}
*/

frame * allocframe(cp_info * cp){
    frame *frame_novo;
    frame_novo = (frame *) malloc(sizeof(frame));
	frame_novo->vetor_de_variaveis_locais = (int32_t *) malloc(sizeof(int32_t));
    frame_novo->constant_pool = cp;
    frame_novo->altura_tipos = 0;
    return frame_novo;
}