#ifndef EJECUTAR_H
#define EJECUTAR_H
#include "Automaton.h"
#include "archivo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void ejecutar_crear_disco(ptrnodo *aux);
void correr();
void correr3();
const char* SIZE="-size";
const char* PATH="-path";
const char* UNIT="-unit";
ptrArchivo ARCHIVO;

void correr(){
    ARCHIVO = (ptrArchivo)malloc(sizeof(file));
    //ejecutar123(&primero);
}

void correr3(){
  default_size(&ARCHIVO);
}

void ejecutar_crear_disco(ptrnodo *aux){
    int c =0;
    int fin =4;//fin
    int fin2=4;
    char pa [1200]={};
    while(c<fin2){
        strcpy(pa,(*aux)->palabra);
        if(strcmp(pa,SIZE)==0){
            setSize(&ARCHIVO,atoi((*aux)->comando));
        }else if(strcmp(pa,UNIT)==0){
            char v [1200];
            strcpy(v,(*aux)->comando);
            setUnit(&ARCHIVO,v[0]);
        }else if(strcmp(pa,PATH)==0){
            setPath(&ARCHIVO,(*aux)->comando);
        }
        c++;
        (*aux)=(*aux)->sig;

    }
    calcularsize(&ARCHIVO);
}


#endif // EJECUTAR_H
