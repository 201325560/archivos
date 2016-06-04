#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

struct Nodo{
    char palabra [1200];
    char comando [1200];
    struct Nodo * sig;
};
typedef struct Nodo nodo;
typedef struct Nodo * ptrnodo;
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





#endif // LISTA_H
