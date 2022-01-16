#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

static int getInt(int* pResultado);
static int esNumerica(char* cadena, int limite);

static int getString(char* cadena, int longitud);

static int esDescripcion(char* cadena, int longitud);
static int getDescripcion(char* pResultado, int longitud);

static int isValidLink(char* cadena, int longitud);
static int getLink(char* pResultado, int longitud);


/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 * 
 * */
int utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for (int i = 0; i <= reintentos; i++)
        {
            printf("%s", mensaje);       
            if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        return retorno;
    }   
}



/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 * 
 * */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[64];

    if(pResultado != NULL &&
      !getString(bufferString, sizeof(bufferString)) &&
      esNumerica(bufferString, sizeof(bufferString)))
    {
          retorno = 0;
          *pResultado = atoi(bufferString);
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
        if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
        {
            continue;
        }
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
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de error a ser mostrado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 * 
 * */
int utn_GetDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;

    while (reintentos >= 0)
    {
        reintentos--;
        printf("%s", mensaje);
        if(getDescripcion(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
        {
            strncpy(pResultado, bufferString, longitud);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}


int utn_GetLink(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;

    while (reintentos >= 0)
    {
        reintentos--;
        printf("%s", mensaje);
        if(getLink(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
        {
            strncpy(pResultado, bufferString, longitud);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}



static int getLink(char* pResultado, int longitud)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL &&
      !getString(bufferString, sizeof(bufferString)) &&
      isValidLink(bufferString, sizeof(bufferString))&&
      strnlen(bufferString, sizeof(bufferString)) < longitud)
    {
        strncpy(pResultado, bufferString, longitud);
        retorno = 0;
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





/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 * 
 * */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL &&
      !getString(bufferString, sizeof(bufferString)) &&
      esDescripcion(bufferString, sizeof(bufferString))&&
      strnlen(bufferString, sizeof(bufferString)) < longitud)
    {
        strncpy(pResultado, bufferString, longitud);
        retorno = 0;
    }
    return retorno;    
}



/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 * 
 */
static int esDescripcion(char* cadena, int longitud)
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



/**
 * \brief Lee de stdin hasta que encuentra un '\n'o hasta que haya copiado
 *        en cadena un maximo de 'longitud -1' caracteres
 * \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de la cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 * 
 * */
static int getString(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096]; //ESTA MAAAAL

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
            {
                bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
            }
            if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena, bufferString, longitud);
                retorno = 0;
            }
        }
    }
    return retorno;
}