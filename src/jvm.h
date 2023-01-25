#ifndef FRAMEH
#define FRAMEH

#include "classfile.h"
#include "exibidor.h"
#include "leitor.h"

typedef struct Array
{
    int32_t arraylength;
    void *vetor;
} Array;

typedef struct Numero
{
    union
    {
        void *referencia;
        int32_t valor;
    } info;
} Numero;

typedef struct stack
{
    int altura;
    int32_t stackarr[99999];

} stack;

void stack_push(stack *pilha, int32_t elem);
void push_float_in_stack(stack *pilha, float valor_f);
void push_long_in_stack(stack *pilha, long long valor_l);
void push_double_in_stack(stack *pilha, double valor_d);
void stack_push_reference(stack *pilha, void *referencia);
void *stack_pop_reference(stack *pilha);
int32_t stack_pop(stack *pilha);
int64_t stack_pop_double(stack* pilha);

void stack_push(stack* pilha, int32_t elem);
void push_float_in_stack(stack* pilha, float valor_f);
void push_long_in_stack(stack* pilha, int64_t valor_l);
void push_double_in_stack(stack* pilha, double valor_d);
void push_reference_in_stack(stack* pilha, void* reference);

uint32_t uint32_from_bits_in_i32t(int32_t valor_int32);
void* pointer_from_bits_in_i32t(int32_t valor_int32);


int32_t stack_pop(stack* pilha);


typedef struct local_variable_vector{
    int tamanho;
    int32_t vetor[99999];
}local_variable_vector;

int32_t get_from_array(local_variable_vector *variaveis_vetor, int indice);


void insert_in_local_var_array(int32_t* variaveis_vetor, int32_t elem, int32_t indice);
int32_t get_from_array(local_variable_vector* variaveis_vetor, int indice);


typedef struct frame{
    int32_t *vetor_de_variaveis_locais;
    stack pilha_de_operandos;
    cp_info * constant_pool ;
    char pilha_tipos_operandos[9999];
    int32_t altura_tipos;

} frame;
void insert_in_local_var_array_double(frame * ,int64_t, int32_t);

void typepush_opstack(frame *, char);
char typepop_opstack(frame *);

int32_t le_inteiro_from_code(u1* code, int x);
u2 concatena_bytes(u1 msb, u1 lsb);

typedef struct field_variable {
    char* name;
} field_variable;

/*
Class{
    field a;
    mehotd(c){
        data e;
        code
        code
        code
    }
}

*/

typedef struct classfields
{
    char *name;
    char *descriptor;
    u2 flags;
} classfields;

typedef struct classdata
{

} classdata;

typedef struct classcode
{
    u4 tamanho_codigo;
    u1 *code;
} classcode;

typedef struct classmethod
{
    char *name;
    char *descriptor;
    u2 access_flags;
    classcode codigo;
} classmethod;

typedef struct method_area_item method_area_item;

struct method_area_item
{
    char *class_name;
    method_area_item *father_class;

    Classfile *classfile;
    classdata data;

    u2 qtd_fields_estaticos;
    classfields *info_static_fields;

    u2 qtd_fields_nao_estaticos;
    classfields *info_non_static_fields;

    u2 qtd_metodos;
    classmethod *metodos;

    field_variable *static_fields;
};

typedef struct Object
{
    int32_t *atributos;
    classfields *atributos_nome;
    method_area_item *classe;
} Object;

typedef struct method_area
{
    method_area_item *classes;
    int qtd_atual;
    int tamanho_total;

} method_area;

typedef struct Jvm
{
    u4 pc;
    frame pilha_de_frames[999];
    int32_t framecount;
    method_area area_de_metodos;
} Jvm;

classcode*  busca_codigo(method_area* area_metodos, char* nome_classe, char* nome_metodo, char* descriptor);
classcode* busca_codigo_in_classe(method_area_item* classe, char nome_metodo[], char descritor[]);
method_area_item* busca_endereco_class_in_method_area(method_area* area_metodos, char class_name[]);

void insert_in_array_ref(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);
void insert_in_array_char(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);
void insert_in_array_short(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);
void insert_in_array_byte(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);
void insert_in_array_double(Jvm *jvm, int32_t arrayref, int32_t indice, int64_t elem);
void insert_in_array_int(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t elem);
void insert_in_array_long(Jvm *jvm, int32_t arrayref, int32_t indice, int64_t elem);
void insert_in_array_float(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t elem);

int64_t stack_pop_double(stack* pilha);

// Union Variables

void readmethod_area(method_area *, Classfile *);
// readclassdata readclasscode readclassfeild

void readframe(frame *, Classfile *);
void readlocal_variable_vector(int32_t vetor[], Classfile *);
// implementar stack

///    Divisões prinicipais, carregamento e execução de classe
void carregamento(Classfile *classfile, method_area *area_metodos, Jvm *jvm);
void code_exec(Jvm *);
void carrega_classe_por_nome(char name[], method_area* area_metodos, Jvm* jvm);


int ja_foi_carregada(char nome_classe[],method_area* area_metodos);
///
void bytecodeexec(classcode *code,Jvm * jvm, frame *frame_atual);
//void bytecodeexec();
void jvm_exec(method_area* area_metodos,Jvm* jvm);    //Chamada pelo main

frame * allocframe(cp_info *);

Object* instanciarObjeto(method_area_item *ma, Jvm *);

#endif
