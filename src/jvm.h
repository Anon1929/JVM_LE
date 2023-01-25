/**
 * @file jvm.h
 * @author Vinicius Lima
 * @author Weliton Barreto
 * @author Arthur Souza
 * @author Thiago Vale
 * @brief Arquivo com as funções e estruturas da JVM.
 *
 * @details Declaração das funções e das estruturas necessárias da JVM.
 */

#ifndef FRAMEH
#define FRAMEH

#include "classfile.h"
#include "exibidor.h"
#include "leitor.h"

/// @brief Struct que define um array
typedef struct Array
{
    int32_t arraylength;
    void *vetor;
} Array;

/// @brief Struct que define um numero
typedef struct Numero
{
    union
    {
        void *referencia;
        int32_t valor;
    } info;
} Numero;

/// @brief Struct que define um stack
typedef struct stack
{
    int altura;
    int32_t stackarr[99999];

} stack;

/// @brief Função que coloca um elemento int32 no topo da pilha
void stack_push(stack *pilha, int32_t elem);

/// @brief Função que que coloca um float no topo da pilha
void push_float_in_stack(stack *pilha, float valor_f);

/// @brief Função que que coloca um long no topo da pilha
void push_long_in_stack(stack *pilha, long long valor_l);

/// @brief Função que que coloca um double no topo da pilha
void push_double_in_stack(stack *pilha, double valor_d);

/// @brief Função que que coloca uma referência no topo da pilha
void stack_push_reference(stack *pilha, void *referencia);

/// @brief Função que que remove uma referência do topo da pilha
void *stack_pop_reference(stack *pilha);

/// @brief Função que que remove um elemento int32 do topo da pilha
/// @return Retorna o elemento int32 removido
int32_t stack_pop(stack *pilha);

/// @brief Função que que remove um double do topo da pilha
/// @return Retorna o double removido
int64_t stack_pop_double(stack* pilha);

/// @brief Função que coloca um elemento int32 no topo da pilha
void stack_push(stack* pilha, int32_t elem);

/// @brief Função que que coloca um float no topo da pilha
void push_float_in_stack(stack* pilha, float valor_f);

/// @brief Função que que coloca um long no topo da pilha
void push_long_in_stack(stack* pilha, int64_t valor_l);

/// @brief Função que que coloca um double no topo da pilha
void push_double_in_stack(stack* pilha, double valor_d);

/// @brief Função que que coloca uma referência no topo da pilha
void push_reference_in_stack(stack* pilha, void* reference);

uint32_t uint32_from_bits_in_i32t(int32_t valor_int32);
void* pointer_from_bits_in_i32t(int32_t valor_int32);


/// @brief Função que que remove um elemento int32 do topo da pilha
/// @return Retorna o elemento int32 removido
int32_t stack_pop(stack* pilha);


/// @brief Struct que define o vetor de variáveis locais
typedef struct local_variable_vector{
    int tamanho;
    int32_t vetor[99999];
}local_variable_vector;

/// @brief Função que pega um elemento do array de variáveis locais
int32_t get_from_array(local_variable_vector *variaveis_vetor, int indice);

/// @brief Função que coloca um elemento no array de variaveis locais
void insert_in_local_var_array(int32_t* variaveis_vetor, int32_t elem, int32_t indice);

/// @brief Função que pega um elemento do array de variáveis locais
int32_t get_from_array(local_variable_vector* variaveis_vetor, int indice);


/// @brief Struct que define um frame
typedef struct frame{
    int32_t *vetor_de_variaveis_locais;
    stack pilha_de_operandos;
    cp_info * constant_pool ;
    char pilha_tipos_operandos[999];
    int32_t altura_tipos;

} frame;

/// @brief Função que coloca um double no array de variaveis locais
void insert_in_local_var_array_double(int32_t * ,int64_t, int32_t);


/// @brief Função que coloca o tipo do elemento no topo da pilha
void typepush_opstack(frame *, char);

/// @brief Função que remove o tipo do elemento do topo da pilha
char typepop_opstack(frame *);

int32_t le_inteiro_from_code(u1* code, int x);
u2 concatena_bytes(u1 msb, u1 lsb);

/// @brief Struct que define um field variable
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

/// @brief Struct que define um class fields
typedef struct classfields
{
    char *name;
    char *descriptor;
    u2 flags;
} classfields;

/// @brief Struct que define um class data
typedef struct classdata
{

} classdata;

/// @brief Struct que define um class code
typedef struct classcode
{
    u4 tamanho_codigo;
    u1 *code;
} classcode;

/// @brief Struct que define um class method
typedef struct classmethod
{
    char *name;
    char *descriptor;
    u2 access_flags;
    classcode codigo;
} classmethod;

typedef struct method_area_item method_area_item;

/// @brief Struct que define um method area item
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

/// @brief Struct que define um object
typedef struct Object
{
    int32_t *atributos;
    classfields *atributos_nome;
    method_area_item *classe;
} Object;

/// @brief Struct que define um method area
typedef struct method_area
{
    method_area_item *classes;
    int qtd_atual;
    int tamanho_total;

} method_area;

/// @brief Struct que define uma jvm
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

/// @brief Função que insere uma referência no array
void insert_in_array_ref(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);

/// @brief Função que insere um char no array
void insert_in_array_char(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);

/// @brief Função que insere um short no array
void insert_in_array_short(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);

/// @brief Função que insere um byte no array
void insert_in_array_byte(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t valor);

/// @brief Função que insere um double no array
void insert_in_array_double(Jvm *jvm, int32_t arrayref, int32_t indice, int64_t elem);

/// @brief Função que insere um int no array
void insert_in_array_int(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t elem);

/// @brief Função que insere um long no array
void insert_in_array_long(Jvm *jvm, int32_t arrayref, int32_t indice, int64_t elem);

/// @brief Função que insere um float no array
void insert_in_array_float(Jvm *jvm, int32_t arrayref, int32_t indice, int32_t elem);

/// @brief Função que remove um double do topo da pilha
int64_t stack_pop_double(stack* pilha);

// Union Variables

/// @brief Função que lê o method area
void readmethod_area(method_area *, Classfile *);
// readclassdata readclasscode readclassfeild


/// @brief Função que lê o framme
void readframe(frame *, Classfile *);

/// @brief Função que lê o vetor de variáveis locais
void readlocal_variable_vector(int32_t vetor[], Classfile *);
// implementar stack

/// @brief Função que faz o carregamento
void carregamento(Classfile *classfile, method_area *area_metodos, Jvm *jvm);

/// @brief Função que faz a execução
void code_exec(Jvm *);

/// @brief Função que carrega a classe por nome
void carrega_classe_por_nome(char name[], method_area* area_metodos, Jvm* jvm);

/// @brief Função que verifica se uma classe já foi carregada
int ja_foi_carregada(char nome_classe[],method_area* area_metodos);

/// @brief Função que executa o bytecode
void bytecodeexec(classcode *code,Jvm * jvm, frame *frame_atual);
//void bytecodeexec();

/// @brief Função que executa a JVM
void jvm_exec(method_area* area_metodos,Jvm* jvm);    //Chamada pelo main

frame * allocframe(cp_info *);

Object* instanciarObjeto(method_area_item *ma, Jvm *);

#endif
