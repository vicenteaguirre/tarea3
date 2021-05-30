
#include "hash.h"

int main(int argc, char const * argv[]){
    if (argc != 2) {
        fprintf(stderr, "***\nYou must use one parameter!\n***\n");
        return 1;
    }
    char *filename = argv[1];
    int tabla_dim = 27;
  
    Elemento ** tabla = ;
    print_hash(tabla,tabla_dim);



    FILE * file;
    if (argc != 2) {
        fprintf(stderr, "Debe ingresar solamente un argumento.");        
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "El archivo no existe.");
        return 2;
    }
    Elemento ** tabla;
    Lista * lista = malloc(sizeof(Lista));
    inicializacion(lista);
    lectura_csv(file,lista);
    //buscar_hash(lista);
    hash(lista->inicio);
    fclose(file);
    return 0;
}