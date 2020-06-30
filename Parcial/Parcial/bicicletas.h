
#include "linkedList.h"
#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char tipo[20];
    int tiempo;


}eBici;






#endif // BICICLETAS_H_INCLUDED
eBici* bici_new();
void bici_delete(eBici* this);

int bici_setId(eBici* this,int id);
int bici_getId(eBici* this,int* id);
int bici_setNombre(eBici* this,char* nombre);
char* bici_getNombre(eBici* this);
int bici_setTipo(eBici* this,char* tipo);
char* bici_getTipo(eBici* this);
int bici_setTiempo(eBici* this,int tiempo);
int bici_getTiempo(eBici* this,int* tiempo);


eBici* bici_newParametros(char* id,char* nombre,char* tipo,char* tiempo);
int bici_ordenTipo(void* cajaA,void* cajaB);
int bici_ordenTiempo(void* cajaA,void* cajaB);

int getRandom();
int mapTiempos(void* unaBici);


int BMX(void* unaBici);
int PLAYERAS(void* unaBici);
int MTB(void* unaBici);
int PASEO(void* unaBici);

void elegirTipo(void* unaBici,LinkedList* pArrayListaBicis);



int filtrarTipo(void* unaBici);
