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




eBici* bici_new()
{
    eBici* newBici;
    newBici=(eBici*)malloc(sizeof(eBici));
    if(newBici!=NULL)
    {
        newBici->id=0;
        strcpy(newBici->nombre," ");
        strcpy(newBici->tipo," ");
        newBici->tiempo=0;
    }
    return newBici;
}




void bici_delete(eBici* this)
{
    if(this != NULL)
    {
        free(this);
    }
}



int bici_setId(eBici* this,int id)
{
    int estado=-1;
    if(this!=NULL)
    {
        this->id=id;
        estado=0;
    }
    return estado;
}



int bici_getId(eBici* this,int* id)
{
    int estado=-1;
    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        estado=0;
    }

    return estado;
}




int bici_setNombre(eBici* this,char* nombre)
{
    int estado = -1;

    if(this != NULL && nombre != NULL)
    {

        strcpy(this->nombre,nombre);
        estado = 0;

    }

    return estado;
}



char* bici_getNombre(eBici* this)
{
    char* nombre=NULL;
    if(this!=NULL)
    {
        nombre=(char*)malloc(sizeof(char)*20);
        strcpy(nombre,this->nombre);
    }
    return nombre;

}





int bici_setTipo(eBici* this,char* tipo)
{
    int estado = -1;

    if(this != NULL && tipo != NULL)
    {

        strcpy(this->tipo,tipo);
        estado = 0;

    }

    return estado;
}



char* bici_getTipo(eBici* this)
{
    char* tipo=NULL;
    if(this!=NULL)
    {
        tipo=(char*)malloc(sizeof(char)*20);
        strcpy(tipo,this->tipo);
    }
    return tipo;

}





int bici_setTiempo(eBici* this,int tiempo)
{
    int estado=-1;
    if(this!=NULL)
    {
        this->tiempo=tiempo;
        estado=0;
    }
    return estado;
}



int bici_getTiempo(eBici* this,int* tiempo)
{
    int estado=-1;
    if(this!=NULL&&tiempo!=NULL)
    {
        *tiempo=this->tiempo;
        estado=0;
    }

    return estado;
}




eBici* bici_newParametros(char* id,char* nombre,char* tipo,char* tiempo)
{
    eBici* newBici;
    int aux;
    int errorFlag;
    newBici=bici_new();
    if(newBici != NULL && id != NULL && nombre != NULL && tipo != NULL&& tiempo != NULL)
    {

        aux=atoi(id);
        if(bici_setId(newBici,aux))
        {
            errorFlag=1;
        }

        if(bici_setNombre(newBici,nombre))
        {
            errorFlag=1;
        }

        if(bici_setTipo(newBici,tipo))
        {
            errorFlag=1;
        }


        aux=atoi(tiempo);
        if(bici_setTiempo(newBici,aux))
        {
            errorFlag=1;
        }



        if(errorFlag==1)
        {
            free(newBici);
            newBici=NULL;
        }

    }

    return newBici;
}





int bici_ordenTiempo(void* cajaA,void* cajaB)
{
    int estado = -2;
    eBici* biA;
    eBici* biB;
    int tiempoA;
    int tiempoB;

    if(cajaA != NULL && cajaB != NULL)
    {
        biA = (eBici*) cajaA;
        biB = (eBici*) cajaB;
         if(biA != NULL && biB != NULL)
        {
           bici_getTiempo(biA,&tiempoA);
           bici_getTiempo(biB,&tiempoB);

           if(tiempoA > tiempoB)
            {
                estado = 1;
            }
            else if(tiempoA < tiempoB)
            {
                estado = -1;
            }
        }
    }
    return estado;
}














int bici_ordenTipo(void* cajaA,void* cajaB)
{
    int estado = -2;
    eBici* biA;
    eBici* biB;
    char* biciA;
    char* biciB;

    int tiempoA;
    int tiempoB;


    if(cajaA != NULL && cajaB != NULL)
    {
        biA = (eBici*) cajaA;
        biB = (eBici*) cajaB;



        if(biA != NULL && biB != NULL)
        {
            biciA = bici_getTipo(cajaA);
            biciB = bici_getTipo(cajaB);

            bici_getTiempo(biA,&tiempoA);
            bici_getTiempo(biB,&tiempoB);

           if(tiempoA > tiempoB)
            {
                estado = 1;
            }
            else if(tiempoA < tiempoB)
            {
                estado = -1;
            }

        }
         estado = strcmp(biciA,biciB);
    }

    return estado;
}






int getRandom()
{
    int aleatorio;

    aleatorio=rand()% 21 + 50;

return aleatorio;
}




int mapTiempos(void* unaBici)
{
     int retorno=0;
    eBici* x;


    if(unaBici!=NULL)
    {
        x=(eBici*)unaBici;
        if(x->tiempo==0)
        {
            x->tiempo=getRandom();
        }


    }
    return retorno;

}




int BMX(void* unaBici)
{
    int retorno=0;
    eBici* x;


    if(unaBici!=NULL)
    {
        x=(eBici*)unaBici;

        if(strcmp(x->tipo,"BMX")==0)
        {
            retorno=1;
        }
    }
    return retorno;


}


int PLAYERAS(void* unaBici)
{
    int retorno=0;
    eBici* x;


    if(unaBici!=NULL)
    {
        x=(eBici*)unaBici;

        if(strcmp(x->tipo,"PLAYERA")==0)
        {
            retorno=1;
        }
    }
    return retorno;


}


int MTB(void* unaBici)
{
    int retorno=0;
    eBici* x;


    if(unaBici!=NULL)
    {
        x=(eBici*)unaBici;

        if(strcmp(x->tipo,"MTB")==0)
        {
            retorno=1;
        }
    }
    return retorno;


}



int PASEO(void* unaBici)
{
    int retorno=0;
    eBici* x;


    if(unaBici!=NULL)
    {
        x=(eBici*)unaBici;

        if(strcmp(x->tipo,"PASEO")==0)
        {
            retorno=1;
        }
    }
    return retorno;


}


void elegirTipo(void* unaBici,LinkedList* pArrayListaBicis)
{
    LinkedList* listaFiltrada=ll_newLinkedList();


    int opcion;

    while(opcion!=5)
    {
        system("cls");

        opcion=validarOpcion("\n\n\n*****ELija algun tipo*****\n1)BMX\n2)PLAYERA\n3)MTB\n4)PASEO\n5)salir\nIngrese una opcion: \n\n\n\n","Opcion incorrecta, reingrese opcion : \n\n\n",1,5);
        switch(opcion)
        {
        case 1:
            printf("hola\n");


            listaFiltrada=ll_filter(pArrayListaBicis,BMX);
            mostrarBicis(listaFiltrada);


           system("pause");
        break;
        case 2:
                //controller_inputEmployeeWorkHours(pEmployee);
           system("pause");     //printf("\nHoras cambiadas exitosamente!\n\n");
        break;
        case 3:
                //controller_inputEmployeeSalary(pEmployee);
                //printf("\nSueldo cambiado exitosamente!\n\n");
                system("pause");
        break;
        case 4:
                //controller_inputEmployeeSalary(pEmployee);
                //printf("\nSueldo cambiado exitosamente!\n\n");
                system("pause");
        break;

        }
    }


}













int filtrarTipo(void* unaBici)
{
    int retorno=0;
    eBici* x;


    if(unaBici!=NULL)
    {
        x=(eBici*)unaBici;

        if(strcmp(x->tipo,"BMX")==0)
        {
            retorno=1;
        }
    }
    return retorno;

}
