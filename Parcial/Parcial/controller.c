#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "parser.h"
#include "controller.h"
#include "bicicletas.h"
#include "linkedList.h"





int controller_loadFromText(char* path, LinkedList* pArrayListBicis)
{
    int estado=-1;
    FILE* pArchivo;

    if(pArrayListBicis != NULL && path != NULL)
    {
        pArchivo = fopen(path,"r");

        if(pArchivo != NULL)
        {
           estado = parser_BiciFromText(pArchivo,pArrayListBicis);
           fclose(pArchivo);
        }
        else
        {
            printf("No existe el archivo\n");
        }
    }

    return estado;
}




int mostrarBici(eBici* this)
{
    int estado = -1;

    int id;
    int tiempo;


    if(this != NULL)
    {
        bici_getId(this,&id);
        bici_getTiempo(this,&tiempo);

        printf("%5d %20s %20s %10d \n", id,bici_getNombre(this),bici_getTipo(this),tiempo);
    }

    return estado;
}


int mostrarBicis(LinkedList* pArrayListabicis)
{
    int estado=-1;
    int i;
    int elements;
    eBici* biciAux;
    if(pArrayListabicis != NULL)
    {


        elements = ll_len(pArrayListabicis);
        if(elements > 0)
        {
            printf("%5s %20s %20s %10s ","ID", "NOMBRE", "TIPO", "TIEMPO\n");
            for(i=0; i < elements; i++)
            {
                biciAux = ll_get(pArrayListabicis, i);
                mostrarBici(biciAux);
            }
        }

        estado=0;
    }

    return estado;
}



int controller_saveAsText(char* path, LinkedList* pArrayListaBicis)
{
    int estado = -1;
    FILE* pArchivo;
    eBici* biciAux;
    int i;
    int listLen;
    int* idAux;
    char* nombreAux;
    char* tipoAux;
    int* tiempoAux;

    if(pArrayListaBicis != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nombreAux = malloc(sizeof(char)*100);
        tipoAux = malloc(sizeof(char)*100);
        tiempoAux = malloc(sizeof(int));

        pArchivo = fopen(path,"w");
        listLen = ll_len(pArrayListaBicis);
        fprintf(pArchivo,"id,nombre,tipo,tiempo\n");

        for(i=0; i<listLen; i++)
        {
            biciAux = ll_get(pArrayListaBicis,i);
            bici_getId(biciAux,idAux);
            nombreAux=bici_getNombre(biciAux);
            tipoAux=bici_getTipo(biciAux);
            bici_getTiempo(biciAux,tiempoAux);



            fprintf(pArchivo,"%d,%s,%s,%d\n",*idAux,nombreAux,tipoAux,*tiempoAux);
        }
        free(idAux);
        free(nombreAux);
        free(tipoAux);
        free(tiempoAux);

        fclose(pArchivo);
    }
    return estado;


}







int controller_deleteListBicis(LinkedList* pArrayListaBicis)
{
    int estado = -1;
    int len;
    int i;
    eBici* pBici;
    if(pArrayListaBicis != NULL)
    {
        len = ll_len(pArrayListaBicis);
        if(len > 0)
        {
            for(i=0; i<len; i++)
            {
                pBici = ll_get(pArrayListaBicis, i);
                bici_delete(pBici);
            }
            ll_deleteLinkedList(pArrayListaBicis);
            estado = 0;
        }
    }
    return estado;

}



