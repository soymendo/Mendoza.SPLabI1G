
#include "bicicletas.h"
#include "linkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


int controller_loadFromText(char* path, LinkedList* pArrayListBicis);
int mostrarBici(eBici* this);
int mostrarBicis(LinkedList* pArrayListabicis);








int controller_saveAsText(char* path, LinkedList* pArrayListaBicis);
int controller_deleteListBicis(LinkedList* pArrayListaBicis);
