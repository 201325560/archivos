#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
struct Archivo{
    int size;
    int unit;
    char path [1200];
};

typedef struct Archivo file;
typedef struct Archivo * ptrArchivo;

void setSize(ptrArchivo * arc,int size);
void setUnit(ptrArchivo * arc,char unit);
void setPath(ptrArchivo * arc,char path[]);
void calcularsize(ptrArchivo *arc);
void default_size(ptrArchivo *arc);

void setPath(ptrArchivo *arc, char path[]){
    strcpy((*arc)->path,path);
}
//este metodo siempre se llama
void setUnit(ptrArchivo *arc, char unit){
    if((int)unit==(int)'k'){
        (*arc)->unit=1024;
    }else if((int)unit==(int)'m'){
        (*arc)->unit=1024*1024;
    }
}

void setSize(ptrArchivo *arc, int size){
    (*arc)->size = size;
}

void calcularsize(ptrArchivo *arc){
    (*arc)->size=(*arc)->unit*(*arc)->size;
}

void default_size(ptrArchivo *arc){
    (*arc)->unit=1024*1024;
}

#endif // ARCHIVO_H
