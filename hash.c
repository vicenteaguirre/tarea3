#include "hash.h"




void busqueda_hash(char letra){
}

void buscar_hash(Lista * lista){
    char letra;
    printf("INGRESE UNA LETRA: ");
    scanf("%c", &letra);
    busqueda_hash(letra);
}

void hash(Elemento * alumno){
    char * apellido;
    char inicial;
    //Asumimos que el alumno tiene solamente un nombre y no es compuesto
    apellido = strtok(alumno->nombre," ");
    inicial = apellido[0];
    printf("%c\n",inicial);
}