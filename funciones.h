#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define QTY_PELIS 10
#define LEN_TIT_GEN 20
#define LEN_DESC_LINK 200

int utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_GetDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_GetLink(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);


#endif // FUNCIONES_H_INCLUDED
