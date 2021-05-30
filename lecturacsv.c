#include "lecturacsv.h"
void lectura_csv(FILE* f,Lista * lista) {
  char line[1001];
  float sum = 0;
  float sum_students = 0;
  int count = 0;
  int count_students = 0;
  char* field;
  char * nombre;
  float nota;
  fgets(line, 1000, f);
  while (fgets(line, 1000, f) != NULL) {
    field = strtok(line, ",");
    //printf("%s: ", field);
    nombre = field;
    field = strtok(NULL, ",");
    sum = 0.0;
    count = 0;
    while (field != NULL) {
      sum += atof(field);
      count++;
      field = strtok(NULL, ",");
      
    }
    //printf("%f\n", sum / count);
    count_students++;
    sum_students += sum / count;
    nota = sum/count;
    if(lista->cont==0){
        ins_en_lista_vacia(lista,nombre,nota);
    }
    else{
        ins_fin_lista(lista,lista->fin,nombre,nota);
    }
  }
  visualizacion(lista);
  //printf("---\nPromedio: %f\n", sum_students / count_students);
}