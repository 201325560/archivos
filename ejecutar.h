#ifndef EJECUTAR_H
#define EJECUTAR_H
#include "Automaton.h"
#include "archivo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
void principal(ptrnodo*abc);
void eliminar(ptrnodo*abc);
void aaaa(ptrnodo *aux);
void ahora_si(ptrArchivo *aux);
int generar_random();
void ejecutar_fdisk(ptrnodo*aux);
void correr();
void correr3();
const char* SIZE="-size";
const char* PATH="-path";
const char* UNIT="-unit";
const char* MKDISK="mkdisk";
const char* RMDISK="rmdisk";
const char* FDISK="fdisk";
ptrArchivo ARCHIVO;

void correr(){
    ARCHIVO = (ptrArchivo)malloc(sizeof(file));
}

void correr3(){
  default_size(&ARCHIVO);
}

void principal(ptrnodo *abc){
    char pa [1200]={};
    while((*abc)!=NULL){
        strcpy(pa,(*abc)->palabra);
        if(strcmp(pa,MKDISK)==0){
            (*abc)=(*abc)->sig;
           aaaa(abc);
        }else if(strcmp(pa,RMDISK)==0){
            (*abc)=(*abc)->sig;
            eliminar(abc);
        }else if(strcmp(pa,FDISK)==0){
            (*abc)=(*abc)->sig;
            ejecutar_fdisk(abc);
        }
        (*abc)=(*abc)->sig;
    }
}
void eliminar(ptrnodo *aux){

    char pa [1200]={};
        strcpy(pa,(*aux)->palabra);
        if(strcmp(pa,PATH)==0){
            printf("se eliminira un disco\n");
            char*espacio=" ";
                        char cadena[20];
                        char eli[100]="";
                        char*p="rm";
                        strcat(eli,p);
                        strcat(eli,espacio);
                        strcat(eli,(*aux)->comando);
                        printf("seguro de eliminar el disco:\n");
                        printf("1. SI:\n");
                        printf("2. NO:\n");
                        fgets(cadena,100,stdin);
                        if(strcmp(cadena,"1\n")==0){
                        system(eli);
                        }else{
                            printf("ya no se elimino el disco..\n");
                        }
        }
    calcularsize(&ARCHIVO);

}
void aaaa(ptrnodo*aux){
    int c =0;
    int fin2=4;
    char pa [1200]={};
    while(c<fin2){
        strcpy(pa,(*aux)->palabra);
        if(strcmp(pa,SIZE)==0){
            //aki comparar si size es mayor q cero.. q ejecute sino muestra error
            int tam=0;
            tam=atoi((*aux)->comando);
            if(tam>0){
            setSize(&ARCHIVO,atoi((*aux)->comando));
            }else{
                printf("error, el tamaño del disco tiene q ser mayor a cero");
            }
        }else if(strcmp(pa,UNIT)==0){
            char v [1200];
            strcpy(v,(*aux)->comando);
            setUnit(&ARCHIVO,v[0]);
        }else if(strcmp(pa,PATH)==0){
            setPath(&ARCHIVO,(*aux)->comando);
        }
        c++;
        char pa[1200]={};
        strcpy(pa,(*aux)->palabra);
        if(strcmp(pa,MKDISK)==0){
            break;
        }else if(strcmp(pa,RMDISK)==0){
            break;
        }else if(strcmp(pa,FDISK)==0){
            break;
        }
        (*aux)=(*aux)->sig;

    }
    calcularsize(&ARCHIVO);
    ahora_si(&ARCHIVO);//crea el disco
}

void ahora_si(ptrArchivo*aux){
    char dire[1200]={};
    char*p="dd if=/dev/zero of=";
    char*p1="bs=";
    char*espacio=" ";
    char*p2=" count=1 ";
    char *pat="";
    char carpetas[1200]={};
    char *car="mkdir -p ";
    pat=(*aux)->path;
    strcat(dire,p);
    strcat(dire,pat);
    strcat(carpetas,car);
    strcat(carpetas,pat);
    strcat(dire,espacio);
    strcat(dire,p1);
    char cap[25]="";
  //  itoa(totalD,cap,10);
    sprintf(cap,"%d",(*aux)->size);
    strcat(dire,cap);
    strcat(dire,espacio);
    strcat(dire,p2);
    printf("%s",&dire[0]);
    char*pru=dire;
    //system(carpetas);//aki se manda el comando para crear la carpeta(  mkdir -p "path"     )
    system(pru);

}

ejecutar_fdisk(ptrnodo *aux){

}

int generar_random(){
    int num=0;
    num=rand()%10000;
    return num;
}


#endif // EJECUTAR_H
