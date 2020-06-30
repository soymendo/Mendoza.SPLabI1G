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



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;// le asigno la direccion de memoria del vagon 1 y recorro hasta indice -1
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode;

    if(this != NULL && nodeIndex >=0 && nodeIndex <= ll_len(this))
    {
        newNode = malloc(sizeof(Node));
        if(ll_len(this)==0  && nodeIndex == 0)//cuando no hay nodos
        {
            newNode->pElement = pElement;
            newNode->pNextNode=NULL;
            this->pFirstNode = newNode;
        }
        else if(ll_len(this)>0  && nodeIndex == 0)//cuando quiero que sea el primer nodo
        {
            newNode->pElement = pElement;
            newNode->pNextNode = this->pFirstNode;//conoce la ubicacion del vagon 0
            this->pFirstNode = newNode;

        }
        else if(ll_len(this) > 0  && nodeIndex > 0 && nodeIndex == ll_len(this))//cuando quiero que sea el ultimo nodo
        {
            newNode->pElement =pElement;
            newNode->pNextNode = NULL;
            getNode(this,nodeIndex-1)->pNextNode = newNode;
        }
        else if(ll_len(this) > 0  && nodeIndex < ll_len(this))//cuando lo queiro metrer en el medio de la lista
        {
            newNode->pElement = pElement;
            newNode->pNextNode = getNode(this,nodeIndex-1)->pNextNode;
            getNode(this,nodeIndex-1)->pNextNode = newNode;
        }
        this->size += 1;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && ll_len(this)>=0)
    {
        addNode(this,ll_len(this),pElement)   ;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    Node* auxNode;
    void* returnAux = NULL;

    if(this != NULL && index >=0 && ll_len(this)>=0 && index < ll_len(this))
    {
        auxNode= getNode(this,index);

        if(auxNode!=NULL)
        {
            returnAux= auxNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)//sobreescribe el campo pElement del nodo indicado a traves del index con el nuevo puntero que llega por parametro
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL && index >= 0 && index <ll_len(this))
    {

        auxNode = getNode(this,index);

        if(auxNode!=NULL)
        {

            auxNode->pElement=pElement;
            returnAux = 0;
        }

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)//saco del tren el nodo que apuntaba a ese elemento,
{
    int returnAux = -1;
    Node* actual;
    if(this != NULL && index < ll_len(this)&& index >=0 && ll_len(this)>=0  )
    {

        actual= getNode(this,index);//variable de referencia
        if (actual!=NULL && index ==0)//cuando elimino el nodo del indice 0
        {
            this->pFirstNode=actual->pNextNode;
        }
        else if(index >0 && index !=(ll_len(this)-1))//cuando elimino a un node de en medio o al ultimo
        {

        getNode(this, index -1)->pNextNode = actual->pNextNode;

        }
        else if(index == ll_len(this))//cuando elimino al unico nodo
        {
            this->pFirstNode = NULL;
        }
        this->size=(this->size)-1;
        free(actual );
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
	if (this != NULL)
    {
        /*for(int i=ll_len(this);i>=0;i--)
        {
           ll_remove(this, 0);
        }*/


		while (ll_len(this))//mientras halla elementos en la lista
        {
			ll_remove(this, 0);
		}
		returnAux = 0;
	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int auxClear;
    auxClear =ll_clear(this)  ;//primero elimino todos los nodos
    if(this !=  NULL&& auxClear== 0)
    {
        free(this);//ahora elimino la lista
        returnAux =0;

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)//recupero un
{
    int returnAux = -1;
    int i;

    if(this !=NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            if(ll_get(this,i) == pElement)// ll_get(this,i) consigo el pElement de cada uno en la lista y despues compraro con el que llega por parametro
            {
                returnAux = i;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL && ll_len(this)== 0)//ll_len(this)
    {
        returnAux = 1;
    }
    else if (this != NULL  &&ll_len(this)> 0)
    {
        returnAux =0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{

    return addNode(this,index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this !=NULL && index >=0 && index < ll_len(this))
    {
        returnAux = ll_get(this,index)/*getNode(this,index)->pElement*/;
        if(ll_remove(this,index)==-1)
        {
            returnAux=NULL;
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this !=NULL)
    {
        returnAux=0;
        if(ll_indexOf(this,pElement)>=0)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* elemento;

    if (this != NULL && this2 != NULL)
    {
        returnAux=1;

        for(i=0; i<ll_len(this2); i++)
        {
            elemento=ll_get(this2,i);
            if(!ll_contains(this,elemento))
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if (!(this == NULL || from < 0 || from > ll_len(this) || to <= from || to > ll_len(this)))
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=from;i<to;i++)
            {
               ll_add(cloneArray,ll_get(this,i));
            }

        }

    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    cloneArray = ll_subList(this,0,ll_len(this));

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux=-1;
    int tam;
    void* aux;

    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        tam=ll_len(this);
        for(int i=0; i<tam-1;i++)
        {
            for(int j=i+1; j<tam;j++)
            {
              if(pFunc(ll_get(this,i),ll_get(this,j))>0 && order==1)//obtenemos los pelement
              {
                  aux=ll_get(this,i);//
                  ll_set(this,i,ll_get(this,j));
                  ll_set(this,j,aux);

              }
              else if(pFunc(ll_get(this,i),ll_get(this,j))<0 && order==0)
              {
                  aux=ll_get(this,i);
                  ll_set(this,i,ll_get(this,j));
                  ll_set(this,j,aux);

              }

            }
        }
        returnAux=0;

    }
    return returnAux;

}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* retorno = NULL;
    int i;
    LinkedList* listfilter;
    void *pElement=NULL;

    if(this != NULL && pFunc!=NULL)
    {
     listfilter=ll_newLinkedList();
     if(listfilter!=NULL)
     {
         for (i=0; i<ll_len(this); i++)
        {
            pElement = ll_get(this,i);
            if(pFunc(pElement)==1)
            {
                ll_add(listfilter,pElement);

            }
        }
           retorno = listfilter;
     }

    }
    return retorno;

}



int ll_map(LinkedList* this, int (*pFunc)(void*))

  {
    int i ;
    int retorno =-1;
    void * pElement = NULL;

  if (this != NULL && pFunc !=NULL)
  {
        for (i=0; i<ll_len(this);i++)
            {
                pElement =  ll_get(this,i);
                pFunc(pElement);
            }
            retorno = 0;

  }

  return retorno;

  }

