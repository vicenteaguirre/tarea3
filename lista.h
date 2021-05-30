#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ElementoLista{
    char * nombre;
    float nota;
    struct ElementoLista * siguiente;
}Elemento;

typedef struct lista{
    Elemento * inicio;
    Elemento * fin;
    int cont;
}Lista;

Elemento** rellenar_tabla(char* filename, int number) {
    Elemento ** tabla = crear_tabla_hash(number);
    return tabla;
}
void insertar(Elemento ** tabla, Elemento * nuevo_alumno);

void inicializacion (Lista *lista);

// inserción en una lista vacía 
int ins_en_lista_vacia (Lista * lista, char * nombre, float nota);

// inserción al inicio de la lista 
int ins_inicio_lista (Lista * lista,char * nombre, float nota);

//inserción al final de la lista 
int ins_fin_lista (Lista *lista, Elemento *actual, char * nombre, float nota);

// insercion en la posicion solicitada 
int ins_lista (Lista *lista, char * nombre, float nota,int pos);

int ins(Lista * lista,Elemento * ult_elemento,char * nombre, float nota,int pos, int cont);

// eliminación al inicio de la lista 
int sup_inicio (Lista *lista);

// eliminar un elemento después de la posición solicitada
int sup_en_lista (Lista *lista, int pos);
//eliminar elemento de la lista
int sup(Lista * lista,int posc_eliminar);

//Visualizar
void visualizacion (Lista * lista);

int compara(const void *p,const void *q);

void copiararrays(Lista * lista,float *b, int size);

void swap(Lista * lista,int eje_i,int eje_j);

int buscar_swapear(Lista * lista,float * ordenado, int size);

void print_sort(FILE * file, Lista * lista); 
