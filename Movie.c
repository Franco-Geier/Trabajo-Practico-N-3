#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Movie.h"

static int isValidLink(char* cadena, int longitud);
static int isValidName(char* cadena, int longitud);
static int esNumerica(char* cadena, int limite);


int peli_initArray(EMovie* arrayPunteros[], int limite)
{
    int retorno = -1;
    int i;

    if(arrayPunteros != NULL && limite > 0)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
        {
            arrayPunteros[i] = NULL;
        }
    }
    return retorno;
}



int peli_agregarPeliculaArray(EMovie* arrayPunteros[], int limite, char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImagen, int id)
{
    int retorno = -1;
    int indiceLibre;
    EMovie* pAuxiliarPelicula;

    if(arrayPunteros != NULL && limite > 0 &&
       titulo != NULL && genero != NULL &&
       duracion > 0 && descripcion != NULL &&
       puntaje > 0 && linkImagen != NULL && id >= 0)
       {
           indiceLibre = peli_buscarLibreArray(arrayPunteros, limite);
           pAuxiliarPelicula = peli_newParametros(titulo, genero, duracion, descripcion, puntaje, linkImagen, id);
           if(pAuxiliarPelicula != NULL)
           {
               arrayPunteros[indiceLibre] = pAuxiliarPelicula;
               retorno = indiceLibre;
           }   
        }
        return retorno;
}


    
int peli_buscarLibreArray(EMovie* arrayPunteros[], int limite)
{
    int retorno = -1;
    int i;

    if(arrayPunteros != NULL && limite > 0)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(arrayPunteros[i] == NULL)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


EMovie* peli_newParametros(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImagen, int id)
{
    EMovie* punteroPeli = NULL;
    punteroPeli = peli_new();

    if(punteroPeli != NULL)
    {
        strncpy(punteroPeli->titulo, titulo, 20);
        strncpy(punteroPeli->genero, genero, 20);
        strncpy(punteroPeli->descripcion, descripcion, 50);
        strncpy(punteroPeli->linkImagen, linkImagen, 50);
        punteroPeli->duracion = duracion;
        punteroPeli->puntaje = puntaje;
        punteroPeli->id = id;
    }
    return punteroPeli;
}


EMovie* peli_new(void)
{
    return (EMovie*) malloc(sizeof(EMovie));
}


int peli_borrarPorIdArray(EMovie* arrayPunteros[], int limite, int id)
{
    int retorno = -1;
    int indiceBorrar;

    if(arrayPunteros != NULL && limite > 0 && id >= 0)
    {
        indiceBorrar = peli_buscarPorIdArray(arrayPunteros, limite, id);
        if(indiceBorrar >= 0)
        {
            if(!peli_deleteIndexInArray(arrayPunteros, limite, indiceBorrar))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}


int peli_buscarPorIdArray(EMovie* arrayPunteros[], int limite, int id)
{
    int retorno = -1;
    int i;

    if(arrayPunteros != NULL && limite > 0 && id >= 0)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(arrayPunteros[i] != NULL && arrayPunteros[i]->id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int peli_deleteIndexInArray(EMovie* arrayPunteros[], int limite, int indice)
{
    int retorno = -1;

    if(arrayPunteros != NULL && indice >= 0 && indice < limite && arrayPunteros[indice] != NULL)
    {
        retorno = 0;
        peli_delete(arrayPunteros[indice]);
        arrayPunteros[indice] = NULL;
    }
    return retorno;
}


void peli_delete(EMovie* this)
{
    if(this != NULL)
    {
        free(this);
    }
}


int peli_imprimirArray(EMovie* arrayPunteros[], int limite)
{
    int retorno = -1;
    int i;

    if(arrayPunteros != NULL && limite > 0)
    {
        printf("\n-----LISTA DE PELICULAS-----\n");
        for(i = 0; i < limite; i++)
        {
            if(arrayPunteros[i] != NULL)
            {
                printf("ID - %d - Titulo: %s - Genero: %s - Duracion: %d min - Descripcion: %s - Puntaje %d - Link - %s\n", arrayPunteros[i]->id, arrayPunteros[i]->titulo, arrayPunteros[i]->genero, arrayPunteros[i]->duracion, arrayPunteros[i]->descripcion, arrayPunteros[i]->puntaje, arrayPunteros[i]->linkImagen);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int peli_getId(EMovie* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;  
    }
    return retorno;
}



int peli_getDuracion(EMovie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        retorno = 0;
        *duracion = this->duracion;  
    }
    return retorno;
}



int peli_getPuntaje(EMovie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        retorno = 0;
        *puntaje = this->puntaje;  
    }
    return retorno;
}


int peli_getTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strncpy(titulo, this->titulo, LEN_TIT_GEN);
    }
    return retorno;
}



int peli_getGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strncpy(genero, this->genero, LEN_TIT_GEN);
    }
    return retorno;
}



int peli_getDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strncpy(descripcion, this->descripcion, LEN_DESC_LINK);
    }
    return retorno;
}


int peli_getLink(EMovie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        retorno = 0;
        strncpy(link, this->linkImagen, LEN_DESC_LINK);
    }
    return retorno;
}



int peli_guardarArrayEnArchivo(EMovie* arrayPunteros[], char* pathArchivo)
{
    FILE* fpArchivo;
    int retorno = -1;

    if(arrayPunteros != NULL && pathArchivo != NULL)
    {
        fpArchivo = fopen(pathArchivo, "w");
        if(fpArchivo != NULL)
        {
            retorno = 0;
            fprintf(fpArchivo, "<!DOCTYPE html>\n");
            fprintf(fpArchivo, "<!-- Template by Quackit.com -->\n");
            fprintf(fpArchivo, "<html lang='en'>\n");
            fprintf(fpArchivo, "<head>\n");
            fprintf(fpArchivo, "    <meta charset='utf-8'>\n");
            fprintf(fpArchivo, "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
            fprintf(fpArchivo, "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
            fprintf(fpArchivo, "    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
            fprintf(fpArchivo, "    <title>Lista peliculas</title>\n");
            fprintf(fpArchivo, "    <!-- Bootstrap Core CSS -->\n");
            fprintf(fpArchivo, "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
            fprintf(fpArchivo, "    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
            fprintf(fpArchivo, "    <link href='css/custom.css' rel='stylesheet'>\n");
            fprintf(fpArchivo, "    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
            fprintf(fpArchivo, "    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
            fprintf(fpArchivo, "    <!--[if lt IE 9]>\n");
            fprintf(fpArchivo, "        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
            fprintf(fpArchivo, "        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
            fprintf(fpArchivo, "    <![endif]-->\n");
            fprintf(fpArchivo, "</head>\n");
            fprintf(fpArchivo, "<body>\n");
            fprintf(fpArchivo, "    <div class='container'>\n");
            fprintf(fpArchivo, "        <div class='row'>\n");



            fprintf(fpArchivo, "        </div>\n");
            fprintf(fpArchivo, "        <!-- /.row -->\n");
            fprintf(fpArchivo, "    </div>\n");
            fprintf(fpArchivo, "    <!-- /.container -->\n");
            fprintf(fpArchivo, "    <!-- jQuery -->\n");
            fprintf(fpArchivo, "    <script src='js/jquery-1.11.3.min.js'></script>\n");
            fprintf(fpArchivo, "    <!-- Bootstrap Core JavaScript -->\n");
            fprintf(fpArchivo, "    <script src='js/bootstrap.min.js'></script>\n");
            fprintf(fpArchivo, "	   <!-- IE10 viewport bug workaround -->\n");
            fprintf(fpArchivo, "	   <script src='js/ie10-viewport-bug-workaround.js'></script\n");
            fprintf(fpArchivo, "	   <!-- Placeholder Images -->\n");
            fprintf(fpArchivo, "	   <script src='js/holder.min.js'></script>\n");
            fprintf(fpArchivo, "</body>\n");              
            fclose(fpArchivo);
        }
    }
    return retorno;
}



int peli_crearPagina(EMovie* arrayPunteros[], int limite, char* pathArchivo)
{
    FILE* fpArchivo;
    int retorno = -1;
    int i;
    int auxiliarId;
    int auxiliarDuracion;
    int auxiliarPuntaje;
    char auxiliarTitulo[LEN_TIT_GEN];
    char auxiliarGenero[LEN_TIT_GEN];
    char auxiliarDescripcion[LEN_DESC_LINK];
    char auxiliarLink[LEN_DESC_LINK];

    if(arrayPunteros != NULL && limite > 0 && pathArchivo != NULL)
    {
        fpArchivo = fopen(pathArchivo, "a");
        if(fpArchivo != NULL)
        {
            retorno = 0;
            for(i = 0; i < limite; i++)
            {
                if(arrayPunteros[i] != NULL)
                {
                    if(!peli_getId(arrayPunteros[i], &auxiliarId) &&
                       !peli_getTitulo(arrayPunteros[i], auxiliarTitulo) &&
                       !peli_getGenero(arrayPunteros[i], auxiliarGenero) &&
                       !peli_getDuracion(arrayPunteros[i], &auxiliarDuracion) &&
                       !peli_getDescripcion(arrayPunteros[i], auxiliarDescripcion) &&
                       !peli_getPuntaje(arrayPunteros[i], &auxiliarPuntaje) &&
                       !peli_getLink(arrayPunteros[i], auxiliarLink))
                    {
                       fprintf(fpArchivo, "<article class='col-md-4 article-intro'>\n");
                       fprintf(fpArchivo, "   <a href='#'>\n");
                       fprintf(fpArchivo, "       <img class='img-responsive img-rounded' src='%s' alt=''>\n", arrayPunteros[i]->linkImagen);
                       fprintf(fpArchivo, "   </a>\n");
                       fprintf(fpArchivo, "   <h3>\n");
                       fprintf(fpArchivo, "       <a href='#'>%s</a>\n", arrayPunteros[i]->titulo);
                       fprintf(fpArchivo, "   </h3>\n");
                       fprintf(fpArchivo, "   <ul>\n");
                       fprintf(fpArchivo, "     <li>Genero:%s</li>\n", arrayPunteros[i]->genero);
                       fprintf(fpArchivo, "     <li>Puntaje:%d</li>\n", arrayPunteros[i]->puntaje);
                       fprintf(fpArchivo, "     <li>Duración:%d</li>\n ", arrayPunteros[i]->duracion);
                       fprintf(fpArchivo, "   </ul>\n");
                       fprintf(fpArchivo, "   <p>%s</p>\n", arrayPunteros[i]->descripcion);
                       fprintf(fpArchivo, "</article>\n");
                    }              
                }
            }
            fclose(fpArchivo);
        }
    }
    return retorno;
}





int peli2_guardarArrayEnArchivo(EMovie* arrayPunteros[], int limite, char* pathArchivo)
{
    FILE* fpArchivo;
    int retorno = -1;
    int i;
    int auxiliarId;
    int auxiliarDuracion;
    int auxiliarPuntaje;
    char auxiliarTitulo[LEN_TIT_GEN];
    char auxiliarGenero[LEN_TIT_GEN];
    char auxiliarDescripcion[LEN_DESC_LINK];
    char auxiliarLink[LEN_DESC_LINK];

    if(arrayPunteros != NULL && limite > 0 && pathArchivo != NULL)
    {
        fpArchivo = fopen(pathArchivo, "w");
        if(fpArchivo != NULL)
        {
            retorno = 0;
            for(i = 0; i < limite; i++)
            {
                if(!peli_getId(arrayPunteros[i], &auxiliarId) &&
                   !peli_getTitulo(arrayPunteros[i], auxiliarTitulo) &&
                   !peli_getGenero(arrayPunteros[i], auxiliarGenero) &&
                   !peli_getDuracion(arrayPunteros[i], &auxiliarDuracion) &&
                   !peli_getDescripcion(arrayPunteros[i], auxiliarDescripcion) &&
                   !peli_getPuntaje(arrayPunteros[i], &auxiliarPuntaje) &&
                   !peli_getLink(arrayPunteros[i], auxiliarLink))
                {
                    
                    fprintf(fpArchivo, "%d, %s, %s, %d, %s, %d, %s\n", auxiliarId, auxiliarTitulo, auxiliarGenero, auxiliarDuracion,
                                                                       auxiliarDescripcion, auxiliarPuntaje, auxiliarLink); 
                }
            }
            fclose(fpArchivo);
        }
    }
    return retorno;
}



int peli_leerArchivoEnArray(EMovie* arrayPunteros[], int limite, char* pathArchivo, int* proximoId)
{
    int retorno = -1;
    FILE* fpArchivo;
    char auxiliarId[4096];
    char auxiliarTitulo[4096];
    char auxiliarGenero[4096];
    char auxiliarDuracion[4096];
    char auxiliarDescripcion[4096];
    char auxiliarPuntaje[4096];
    char auxiliarLink[4096];

    if(arrayPunteros != NULL && limite > 0 && pathArchivo != NULL)
    {
        fpArchivo = fopen(pathArchivo, "r");
        if(fpArchivo != NULL)
        {
            retorno = 0;
            do
            {
               if(fscanf(fpArchivo, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxiliarId, auxiliarTitulo, auxiliarGenero,
                                                                                          auxiliarDuracion, auxiliarDescripcion, auxiliarPuntaje, 
                                                                                          auxiliarLink) == 7)
               {
                   if(peli_agregarMovieArrayTxt(arrayPunteros, limite, auxiliarId, auxiliarTitulo, auxiliarGenero,
                                                auxiliarDuracion, auxiliarDescripcion, auxiliarPuntaje, auxiliarLink) >= 0)
                   {
                        if(atoi(auxiliarId) >= *proximoId)
                        {
                            *proximoId = atoi(auxiliarId) + 1;
                        }
                    }
                } 
            }while(!feof(fpArchivo));    
            fclose(fpArchivo);
        }
    }
    return retorno;
}



int peli_agregarMovieArrayTxt(EMovie* arrayPunteros[], int limite, char* id, char* titulo, char* genero, char* duracion, char* descripcion, char* puntaje, char* link)
{
    int retorno = -1;
    int indiceLibre;
    EMovie* pAuxiliarMovie;

    if(arrayPunteros != NULL && limite > 0 && id != NULL && titulo != NULL && genero != NULL &&
       duracion != NULL && descripcion != NULL  && puntaje != NULL && link != NULL)
    {
        indiceLibre = peli_buscarLibreArray(arrayPunteros, limite);
        if(indiceLibre >= 0)
        {
            pAuxiliarMovie = peli_newParametrosTxt(id, titulo, genero, duracion, descripcion, puntaje, link);
            if(pAuxiliarMovie != NULL)
            {
                arrayPunteros[indiceLibre] = pAuxiliarMovie; 
                retorno = indiceLibre;
            }
        }   
    }
    return retorno;
}



EMovie* peli_newParametrosTxt(char* id, char* titulo, char* genero, char* duracion, char* descripcion, char* puntaje, char* link)
{
    EMovie* this = NULL;
    this = peli_new();

    if(this != NULL && id != NULL && titulo != NULL && genero != NULL &&
       duracion != NULL && descripcion != NULL  && puntaje != NULL && link != NULL)
    {
        if(!peli_setIdTxt(this, id) == -1 ||
           !peli_setTitulo(this, titulo) == -1 ||
           !peli_setGenero(this, genero) == -1 ||
           !peli_setDuracionTxt(this, duracion) == -1 ||
           !peli_setDescripcion(this, descripcion) == -1 ||
           !peli_setPuntajeTxt(this, puntaje) == -1 ||
           !peli_setLink(this, link) == -1) 
        {
            peli_delete(this);
            this = NULL;
        }
    }
    return this;
}



int peli_setIdTxt(EMovie* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        if(esNumerica(id, 10))
        {
            retorno = 0;
            this->id = atoi(id);
        }
    }
    return retorno;
}




/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 * 
 */
static int esNumerica(char* cadena, int limite)
{
    int retorno = 1;
    int i;

    for(i = 0; i < limite && cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
        //CONTINUE
    }
    //BREAK
    return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 * 
 */
static int isValidName(char* cadena, int longitud)
{
    int retorno = 1;
    int i;

    if(cadena != NULL && longitud > 0)
    {
        for(i = 0; i < longitud && cadena[i] != '\0'; i++)
        {
            if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > '}') &&
              (cadena[i] < 'A' || cadena[i] > ']') && (cadena[i] < ',' || cadena[i] > ';') &&
              cadena[i] != '"' && cadena[i] != '(' && cadena[i] != ')')
            {
                retorno = 0;
                break;
            }
        }   
    }
    return retorno;
}

int peli_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        if(isValidName(titulo, LEN_TIT_GEN))
        {
            retorno = 0;
            strncpy(this->titulo, titulo, LEN_TIT_GEN);
        }
    }
    return retorno;
}


int peli_setGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        if(isValidName(genero, LEN_TIT_GEN))
        {
            retorno = 0;
            strncpy(this->genero, genero, LEN_TIT_GEN);
        }
    }
    return retorno;
}



int peli_setDuracionTxt(EMovie* this, char* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        if(esNumerica(duracion, 300))
        {
            retorno = 0;
            this->duracion = atoi(duracion);
        }
    }
    return retorno;
}



int peli_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        if(isValidName(descripcion, LEN_DESC_LINK))
        {
            retorno = 0;
            strncpy(this->descripcion, descripcion, LEN_DESC_LINK);
        }
    }
    return retorno;
}


int peli_setPuntajeTxt(EMovie* this, char* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        if(esNumerica(puntaje, 10))
        {
            retorno = 0;
            this->puntaje = atoi(puntaje);
        }
    }
    return retorno;
}



int peli_setLink(EMovie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        if(isValidLink(link, LEN_DESC_LINK))
        {
            retorno = 0;
            strncpy(this->linkImagen, link, LEN_DESC_LINK);
        }
    }
    return retorno;
}



static int isValidLink(char* cadena, int longitud)
{
    int retorno = 1;
    int i;

    if(cadena != NULL && longitud > 0)
    {
        for(i = 0; i < longitud && cadena[i] != '\0'; i++)
        {
            if((cadena[i] != ']') && (cadena[i] < '@' || cadena[i] > '[') &&
              ((cadena[i] != '~') && cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < '#' || cadena[i] > ';') &&
              cadena[i] != '=' && cadena[i] != '?' && cadena[i] != '!')
            {
                retorno = 0;
                break;
            }
        }   
    }
    return retorno;
}