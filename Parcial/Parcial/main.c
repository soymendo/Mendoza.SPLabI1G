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
#include "time.h"











int main()
{
    srand(time(NULL));
    system("COLOR 0F");
    int opcion = 0;
    int addElements = 0;
    int flagLoad=0;
    int flagOrden=0;
    int flagOrden2=0;
    int option;

    /*printf("Numero: %d\n",getRandom());
    system("pause");*/


    LinkedList* listaBicis = ll_newLinkedList();

    LinkedList* listaFiltrada=ll_newLinkedList();









    while(opcion!=7)
    {
        system("cls");

        opcion=validarOpcion("\n\n\nLista de bicis:\n1.  Cargar los datos de los bicis desde el archivo  (modo texto).\n2.Imprimir Lista .\n3. Asignar tiempos \n4.Filtrar X Tipo  \n5.Mostrar pociciones\n6.Guardar en txt  \n7.SALIR \n\n\n\n","Opcion incorrecta, reingrese opcion : \n\n\n", 1,7);
        switch(opcion)
        {
        case 1:
            system("cls");
            if(addElements < 1)
            {
                addElements = controller_loadFromText("bicicletas.csv",listaBicis);


                if(addElements != -1)
                {
                    printf("Se cargaron %d bicis\n", addElements);

                    flagLoad=1;
                }
                else
                {
                    printf("Error Al cargar la lista\n");
                }
            }
            else
            {
                printf("Esta lista ya fue cargada...\n");
            }
            system("pause");
            break;

        case 2:
            system("cls");
            if(flagLoad)
            {
                mostrarBicis(listaBicis);
                printf("Lsita mostrada sin los tiempos cargados\n");

            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if(flagLoad)
            {
                ll_map(listaBicis,mapTiempos);
                mostrarBicis(listaBicis);
                printf("Tiempos asignados correctamente\n");
                flagOrden=1;

            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            system("pause");
            break;

        case 4:
            system("cls");
            if(flagLoad&&flagOrden)
            {

                while(option!=5)
                {
                    system("cls");

                    option=validarOpcion("\n\n\n*****ELija algun tipo*****\n1)BMX\n2)PLAYERA\n3)MTB\n4)PASEO\n5)salir\nIngrese una opcion: \n\n\n\n","Opcion incorrecta, reingrese opcion : \n\n\n",1,5);
                    switch(option)
                    {
                    case 1:
                        printf("hola\n");


                        listaFiltrada=ll_filter(listaBicis,BMX);
                        mostrarBicis(listaFiltrada);


                        system("pause");
                        break;
                    case 2:

                        listaFiltrada=ll_filter(listaBicis,PLAYERAS);
                        mostrarBicis(listaFiltrada);
                        system("pause");
                        break;
                    case 3:
                         listaFiltrada=ll_filter(listaBicis,MTB);
                        mostrarBicis(listaFiltrada);
                        system("pause");
                        break;
                    case 4:

                        listaFiltrada=ll_filter(listaBicis,PASEO);
                        mostrarBicis(listaFiltrada);
                        system("pause");
                        break;

                    }
                }


                system("pause");
            }
            else
            {
                printf("\nPrimero debe cargar los tiempos!\n\n");
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if(flagLoad&&flagOrden)
            {

                printf("Ordenando...\n");

                ll_sort(listaBicis,bici_ordenTipo,1);
                //ll_sort(listaBicis,bici_ordenTiempo,0);


                system("cls");
                printf("Todo Ordenado\n");
                mostrarBicis(listaBicis);
                flagOrden2=1;

            }
            else
            {
                printf("\nPrimero debe cargar los tiempos!\n\n");
            }
            system("pause");
            break;

        case 6:
            system("cls");
            if(flagLoad&&flagOrden2&&flagOrden)
            {

                controller_saveAsText("posiciones.txt",listaBicis);

                printf("\nGuardado en lista de TEXTO exitosamente!\n\n");

            }
            else
            {
                printf("\nFaltan cargar datos!\n\n");

            }
            system("pause");
            break;


        }

    }
    controller_deleteListBicis(listaBicis);
    return 0;

}

