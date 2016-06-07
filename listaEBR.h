#ifndef LISTAEBR_H
#define LISTAEBR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

struct NodoEBR{
        char estado;//esta activa o no
        char fit;//best,first,worst
        char name[16];//nombre de la particion
        int start;//bin en q inicia
        int size;//tamaño particion
        int next;//byte en el q  inicia el siguiente EBR o -1 si no hay siguiente
};
typedef struct NodoEBR nodo;
typedef struct NodoEBR * ptrnodo;
ptrnodo primero;
ptrnodo ultimo;
int size=0;
void insertar(ptrnodo *primero, char palabra[], ptrnodo *ultimo);
void iniciar(ptrnodo *THIS,  char palabra[]);
int  contiene(const char *palabra);
void setComando(ptrnodo * primero,char comando []);

void setComando(ptrnodo *ultimo, char comando[]){
    strcpy((*ultimo)->comando,comando);
}

void crearlista(){
    primero = NULL;
    ultimo=NULL;
}

void insertar(ptrnodo *primero,  char palabra [],ptrnodo *ultimo){
    ptrnodo nuevo = (ptrnodo)malloc(sizeof(nodo));
    char palabra1 [1200]={};
    strcpy(palabra1,palabra);
    if(nuevo!=NULL){
     size++;
     iniciar(&nuevo,palabra);
     if((*primero)==NULL&&(*ultimo)==NULL){
          nuevo->sig = NULL;
         (*primero)=nuevo;
         (*ultimo)=nuevo;
     }else{
         nuevo->sig=(*ultimo)->sig;
         (*ultimo)->sig=nuevo;
         (*ultimo)=nuevo;
     }

    }else{
        printf("An error has ocurred");
    }

}

void iniciar(ptrnodo *THIS, char palabra[]){
    strcpy((*THIS)->palabra,palabra);
    //aqui estaba el strcpy ! estupido !
}


int contiene(const char *palabra){
    ptrnodo aux = primero;
    while(aux!=NULL){
        if(strcmp(aux->palabra,palabra)==0){
            return 1;
        }
        aux=aux->sig;
    }
    return 0;
}





#endif // LISTAEBR_H
