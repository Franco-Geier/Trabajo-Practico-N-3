#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{
    char titulo[LEN_TIT_GEN];
    char genero[LEN_TIT_GEN];
    char linkImagen[LEN_DESC_LINK];
    char descripcion[LEN_DESC_LINK];
    int duracion;
    int puntaje;
    int id;
}EMovie;

int peli_agregarPeliculaArray(EMovie* arrayPunteros[], int limite, char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImagen, int id);
int peli_initArray(EMovie* arrayPunteros[], int limite);
int peli_buscarLibreArray(EMovie* arrayPunteros[], int limite);
EMovie* peli_newParametros(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImagen, int id);
EMovie* peli_new(void);
int peli_borrarPorIdArray(EMovie* arrayPunteros[], int limite, int id);
int peli_buscarPorIdArray(EMovie* arrayPunteros[], int limite, int id);
int peli_deleteIndexInArray(EMovie* arrayPunteros[], int limite, int indice);
void peli_delete(EMovie* this);
int peli_imprimirArray(EMovie* arrayPunteros[], int limite);
int peli_crearPagina(EMovie* arrayPunteros[], int limite, char* pathArchivo);


int peli_guardarArrayEnArchivo(EMovie* arrayPunteros[], char* pathArchivo);
int peli_agregarMovieArrayTxt(EMovie* arrayPunteros[], int limite, char* id, char* titulo, char* genero, char* duracion, char* descripcion, char* puntaje, char* link);
EMovie* peli_newParametrosTxt(char* id, char* titulo, char* genero, char* duracion, char* descripcion, char* puntaje, char* link);
int peli_setIdTxt(EMovie* this, char* id);
int peli_setTitulo(EMovie* this, char* titulo);
int peli_setGenero(EMovie* this, char* genero);
int peli_setDuracionTxt(EMovie* this, char* duracion);
int peli_setDescripcion(EMovie* this, char* descripcion);
int peli_setPuntajeTxt(EMovie* this, char* puntaje);
int peli_setLink(EMovie* this, char* link);;
int peli2_guardarArrayEnArchivo(EMovie* arrayPunteros[], int limite, char* pathArchivo);
int peli_leerArchivoEnArray(EMovie* arrayPunteros[], int limite, char* pathArchivo, int* proximoId);

#endif // MOVIE_H_INCLUDED