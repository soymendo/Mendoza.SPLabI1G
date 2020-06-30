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





int parser_BiciFromText(FILE* pFile , LinkedList* pArrayListBicis)
{
    int estado=-1;
    char idAux[100];
    char nombreAux[128];
    char tipoAux[100];
    char tiempoAux[100];
    eBici* biciAux;


    while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux,tipoAux, tiempoAux);
                if(estado != -1)
                {
                    biciAux = bici_newParametros(idAux, nombreAux,tipoAux, tiempoAux);
                    if(biciAux != NULL)
                    {
                        ll_add(pArrayListBicis, biciAux);

                    }

                    else
                    {
                        printf("\n ERROR EN EL ARCHIVO\n");
                        controller_deleteListBicis(pArrayListBicis);
                        estado = -1;
                        break;
                    }
                }
                estado++;
            }
  return estado;

}
