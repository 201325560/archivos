#ifndef EJECUTAR_H
#define EJECUTAR_H
#include "Automaton.h"
#include "archivo.h"

void ejecutar(ptrnodo *aux);
void correr();
char SIZE[100]="-size";
char PATH[100]="-path";
char UNIT[100]="-unit";
ptrArchivo ARCHIVO;

void correr(){
    ARCHIVO = (ptrArchivo)malloc(sizeof(file));
}


void ejecutar(ptrnodo *aux){
    while(aux!=NULL){
        if(strcmp((*aux)->palabra,SIZE)==0){
            setSize(&ARCHIVO,atoi((*aux)->comando));
        }else if(strcmp((*aux)->palabra,UNIT)==0){

        }else if(strcmp((*aux)->palabra,PATH)==0){


        }




        (*aux)=(*aux)->sig;
    }
}

#endif // EJECUTAR_H
