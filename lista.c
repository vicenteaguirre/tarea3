#include "lista.h"
//https://www.monografias.com/trabajos90/listas-c/listas-c.shtml#:~:text=Las%20listas%20enlazadas%20son%20estructuras,lo%20que%20concierne%20al%20enlazado.

void inicializacion (Lista *lista){
    lista->inicio = NULL;
    lista->fin=NULL;
    lista->cont =0;
}

// inserción en una lista vacía 
int ins_en_lista_vacia (Lista * lista, char * nombre, float nota){
    Elemento * nuevo_elemento;
    if((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return 1;

    if ((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return 1;
    strcpy(nuevo_elemento->nombre,nombre);
    nuevo_elemento->nota = nota;
    nuevo_elemento->siguiente = NULL;
    lista->inicio = nuevo_elemento;
    lista->fin = nuevo_elemento;
    lista->cont++;
    return 0;
}

// inserción al inicio de la lista 
int ins_inicio_lista (Lista * lista, char * nombre, float nota){
    Elemento * nuevo_elemento;
    if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
    if ((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    strcpy(nuevo_elemento->nombre,nombre);
    nuevo_elemento->nota = nota;
    nuevo_elemento->siguiente = lista->inicio;
    lista->inicio = nuevo_elemento;
    lista->cont++;

    return 0;
}

//inserción al final de la lista
int ins_fin_lista (Lista * lista, Elemento * ult_elemento, char * nombre, float nota){
    Elemento * nuevo_elemento;
    if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
    if ((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    strcpy(nuevo_elemento->nombre,nombre);
    nuevo_elemento->nota = nota;
    ult_elemento->siguiente = nuevo_elemento; 
    nuevo_elemento->siguiente = NULL;
    lista->fin = nuevo_elemento;
    lista->cont++;

    return 0;
}

// insercion en la posicion solicitada
int ins_lista(Lista * lista, char * nombre, float nota, int pos){
    /*if (lista->cont < 2){
        printf("Error ins_lista\n");
        return -1;}

    if (pos < 1 || pos >= lista->cont){
        printf("Error ins_lista\n");
        return -1;
    }*/
    Elemento *actual;
    Elemento *nuevo_elemento;
    int i;

    if((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;

    if((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;

    actual = lista->inicio;
    for(i = 1; i < pos; ++i)
        actual = actual->siguiente;

    if(actual->siguiente == NULL)
        return -1;
    strcpy(nuevo_elemento->nombre,nombre);
    nuevo_elemento->nota = nota;
    nuevo_elemento->siguiente = actual->siguiente;
    actual->siguiente = nuevo_elemento;
    lista->cont++;
    return 0;
}

int ins(Lista * lista,Elemento * ult_elemento,char * nombre, float nota,int pos, int cont){
    if(pos == 0)
        ins_inicio_lista(lista,nombre,nota);
    else if(pos == (cont-1))
        ins_fin_lista(lista,ult_elemento,nombre,nota);
    else  
        ins_lista(lista,nombre,nota,pos);
    return 0;
}
// eliminación al inicio de la lista
int sup_inicio (Lista * lista){
    if (lista->cont == 0)
        return 1;
    Elemento * sup_elemento;
    sup_elemento = lista->inicio;
    lista->inicio = lista->inicio->siguiente;
    if (lista->cont == 1)
        lista->fin = NULL;
        free (sup_elemento->nombre);
        free (sup_elemento);
        lista->cont--;
        return 0;
}

// eliminar un elemento después de la posición solicitada
int sup_en_lista (Lista * lista, int pos){
    /*if (lista->cont == lista->cont-1)
        printf("Error suprimir\n");
        return 1;*/
    int i;
    Elemento * actual;
    Elemento * sup_elemento;
    actual = lista->inicio;
    for (i = 1; i < pos; ++i)
        actual = actual->siguiente;
        sup_elemento = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
    if(actual->siguiente == NULL)
    lista->fin = actual;
    free (sup_elemento->nombre);
    free (sup_elemento);
    lista->cont--;
    return 0;
}
int sup(Lista * lista,int posc_eliminar){
    if(posc_eliminar == 0){
        sup_inicio(lista);
    }
    else
        sup_en_lista(lista,posc_eliminar);
    return 0;
}

// Visualizar
void visualizacion (Lista * lista){
    Elemento * actual;
    actual = lista->inicio;
    while (actual != NULL){
        printf ("%s: %.1f\n",actual->nombre,actual->nota);
        actual = actual->siguiente;
    }
}

int compara(const void *p,const void *q){
    int x,y;
    x= *(int*)p;
    y= *(int*)q;
    if (x<y)
        return -1;
    if (x==y)
        return 0;
    else 
        return 1;
}

void copiararrays(Lista * lista,float *b, int size){
    Elemento * actual = lista->inicio;
    for (int i =0;i<size;i++){
        b[i] = actual->nota;
        actual = actual->siguiente;        
    }
}

void swap(Lista * lista,int eje_i,int eje_j){
    Elemento * actual = lista->inicio;
    Elemento * destino = lista->inicio;
    Elemento * aux;
    for(int i = 0;i<eje_j;i++){ // ir a la posicion actual en la lista
        actual = actual->siguiente;
    }
    for(int j = 0;j<eje_i;j++){ // ir a la posicion de destino en la lista
        destino = destino->siguiente;
    }
    printf("Actual: %f\nDestino: %f\n",actual->nota,destino->nota);
    aux = actual;
    actual = destino;
    destino = aux;
    //sup_en_lista(lista,eje_i);
    //ins_lista(lista,destino,eje_i);
    //sup_en_lista(lista,eje_j);
    //ins_lista(lista,actual,eje_j);

    
    printf("Actual: %f\nDestino: %f\n--------------------\n",actual->nota,destino->nota);
    visualizacion(lista);

}

int buscar_swapear(Lista * lista,float * copia, int size){
    Elemento * actual = lista->inicio; 
    for(int j; j<size;j++){
        for (int i=0;i<= size ;i++){
            if (actual->nota==copia[i]){//para nombre i se busca la nota respecto a j
                //printf("Se encontro: %f = %f\n",actual->nota,copia[i]);
                //swap(lista,i,j);
                break;
            }
        }
        actual = actual->siguiente;
    }   
    return 0;
}

void print_sort(FILE* f, Lista * lista) {
    char line[1001]; 
    float sum = 0; 
    float sum_students = 0; 
    int count = 0;
    int count_students = 0; 
    char * field;
    int cant_estudiantes = 0;
    char * nombre_t;
    float nota_t;
    int cant_e = 0;
    Elemento * actual;
    // Calcular cantidad de estudiantes
    fgets(line, 1000, f); 
    while (fgets(line, 1000, f) != NULL)
        cant_estudiantes++;
    rewind(f);

    // Almacenar nombre y nota en la lista
    fgets(line, 1000, f); 
    while (fgets(line, 1000, f) != NULL) { 
        field = strtok(line, ","); 
        nombre_t = field;
        field = strtok(NULL, ","); 
        sum = 0.0; 
        count = 0; 
        while (field != NULL) { 
            sum += atof(field); 
            count++; 
            field = strtok(NULL, ",");
        }
        count_students++; 
        sum_students += sum / count; 
        nota_t = sum/count;
        if(cant_e==0){
            ins_en_lista_vacia(lista,nombre_t,nota_t);
            actual = lista->inicio;
            cant_e += 1;
        }
        else{
            ins_fin_lista(lista,actual,nombre_t,nota_t);
            actual = actual->siguiente;
            cant_e += 1;
        }      
    }
    visualizacion(lista);
    printf("--------------------------\n");
    
    printf("Alumnos en la lista: %d\n",lista->cont);

    //printf("------------------\n");
    // Hacemos una copia del arreglo notas
    float * notas_copia = malloc(cant_estudiantes*sizeof(float));
    copiararrays(lista,notas_copia,cant_estudiantes);
    
    // Ordenamos copia del arreglo notas
    qsort(notas_copia,cant_estudiantes,sizeof(float),compara);  
    printf("--------------------------\n");

    //v Generamos los cambios en los arreglos originales (nombres y notas)
    

    Elemento * ultimo = lista->inicio;
    for(int a = 0; a<lista->cont;a++){
        ultimo = ultimo->siguiente;
    }
    printf("Ultimo elemento: %s",ultimo->nombre);
    Elemento * cambiar = lista->inicio;
    Elemento * por = lista->inicio;
    int posc_eliminar = 0;
    int posc_agregar = 1;

    for(int a = 0; a<posc_eliminar;a++){
        cambiar = cambiar->siguiente;
    }
    for(int a = 1; a<posc_agregar;a++){
        por = por->siguiente;
    }
    //visualizacion(lista);

    printf("Cambiar: %s\nPor: %s\n\n",cambiar->nombre,por->nombre); //Indica a quien se elimina
    //buscar_swapear(lista,notas_copia,cant_estudiantes);
    sup(lista,posc_eliminar);

    printf("Alumnos en la lista: %d\n",lista->cont);
    //ins(lista,ultimo,cambiar->nombre,cambiar->nota,posc_agregar,lista->cont);
    printf("--------------------------\n");

    visualizacion(lista);



    printf("-------------------\nPromedio: %1.1f\n", sum_students / count_students);
}