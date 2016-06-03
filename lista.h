#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

struct Nodo{
    char *palabra;
    struct Nodo * sig;
};
typedef struct Nodo nodo;
typedef struct Nodo * ptrnodo;
ptrnodo primero;

void insertar(ptrnodo *primero, char palabra[]);
void iniciar(ptrnodo *THIS, const char *palabra);
int  contiene(const char *palabra);
void crearlista(){
    primero = NULL;
}

void insertar(ptrnodo *primero,  char palabra []){
    ptrnodo nuevo = (ptrnodo)malloc(sizeof(nodo));
    char palabra1 [1024]={};
    strcpy(palabra1,palabra);
    if(nuevo!=NULL){
     iniciar(&nuevo,&palabra1[0]);
     nuevo->sig=(*primero);
     (*primero)=nuevo;
    }else{
        printf("An error has ocurred");
    }

}

void iniciar(ptrnodo *THIS,const char * palabra){
    (*THIS)->palabra=palabra;
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
