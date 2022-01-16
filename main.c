#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Movie.h"

int main()
{
    EMovie* arrayPunterosMovie[QTY_PELIS];
    char bufferLink[LEN_DESC_LINK];
    char bufferDescripcion[LEN_DESC_LINK];
    char bufferTitulo[LEN_TIT_GEN];
    char bufferGenero[LEN_TIT_GEN];
    int opcion;
    int proximoId = 0;
    int bufferDuracion;
    int bufferPuntaje;
    int bufferId;
    
    
    if(!peli_initArray(arrayPunterosMovie, QTY_PELIS))
    {
        peli_guardarArrayEnArchivo(arrayPunterosMovie, "pelis.html");
        do
        {
            utn_GetNumero(&opcion, "1- Agregar pelicula\n"
                                   "2- Borrar pelicula\n"
                                   "3- Generar pagina web\n"
                                   "4- Salir\n\n", 
                                   "Opcion incorrecta", 1, 4, 2);

            switch(opcion)
            {
                case 1:
                    if(!utn_GetDescripcion(bufferTitulo, LEN_TIT_GEN, "\nIngrese el titulo de la pelicula: ", "\nTitulo invalido", 2) &&
                       !utn_GetDescripcion(bufferGenero, LEN_TIT_GEN, "\nIngrese el genero de la pelicula: ", "\nGenero invalido", 2) &&
                       !utn_GetNumero(&bufferDuracion, "\nIngrese la duracion de la pelicula [120 - 300] (en minutos): ", "\nDuracion incorrecta [120 - 300]", 120, 300, 2) &&
                       !utn_GetDescripcion(bufferDescripcion, LEN_DESC_LINK, "\nIngrese la descripcion de la pelicula: ", "\nDescripcion incorrecta", 2) &&
                       !utn_GetNumero(&bufferPuntaje, "\nPuntuacion de la pelicula [1 - 10]: ", "\nPuntaje incorrecto [1 - 10]", 1, 10, 2) &&
                       !utn_GetLink(bufferLink, LEN_DESC_LINK, "\nLink de la pelicula: ", "\nLink incorrecto", 2) &&
                       peli_agregarPeliculaArray(arrayPunterosMovie, QTY_PELIS, bufferTitulo, bufferGenero, bufferDuracion, bufferDescripcion, bufferPuntaje, bufferLink, proximoId) >= 0)
                    {
                        printf("\nALTA OK\n");
                        proximoId++;
                    }
                    break;

                case 2:
                    peli_imprimirArray(arrayPunterosMovie, QTY_PELIS);
                    if(!utn_GetNumero(&bufferId, "\nIngrese ID de la pelicula a borrar: ", "\nID invalido", 0, 10000, 2) &&
                       !peli_borrarPorIdArray(arrayPunterosMovie, QTY_PELIS, bufferId))
                    {
                        printf("\nBAJA OK\n");
                    }
                    else
                    {
                        printf("\nID: %d NO ENCONTRADO\n", bufferId);
                    }
                    break;

                case 3:
                    if(!peli2_guardarArrayEnArchivo(arrayPunterosMovie, QTY_PELIS, "data.csv"))
                    {
                        printf("\nArchivo generado exitosamente\n");
                    }

                    if(!peli_crearPagina(arrayPunterosMovie, QTY_PELIS, "pelis.html"))
                    {
                        printf("\nPagina generada exitosamente\n");
                    }
                    break;
            }
        }while(opcion != 4);
    }
    return EXIT_SUCCESS;
}
