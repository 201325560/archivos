#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
extern void crearlista();
extern void insertar(ptrnodo *primero, char palabra []);
extern int contiene(const char *palabra);

static char letras [] = {'a','b','c','d','e','f','g',
                  'h','i','j','k','l','n','m',
                  'o','p','q','r','s','t','u',
                  'v','w','x','y','z',
                  'A','B','C','D','E','F','G',
                  'H','I','J','K','L','N','O',
                  'P','M','Q','R','S','T','U'
                  ,'V','W','X','Y','Z'};

static char * palabras [] = {"mkdisk","rmdisk","fdisk","mount","unmount","size",
                             "unit","path","id","type","fit","delete","name",
                             "add","mkfs","mkfile","cat","rem","edit","ren",
                             "mkdir","cp","mv","find","cont","p","dest","iddest"};
static int numeros [] = {0,1,2,3,4,5,6,7,8,9};
static char simbolos []= {};
static int ESTADO=0;
static int salto_linea = (int)'\n';
static int espacio_blanco = (int)' ';
static int Esletra(char letra);
static int Esreservada(char * palabra);
static int Esnumero(int numero);
static void minusculas(char *s);
char * stchcat(char cadena[], char chr);


void lexer(char buffer []);
void leer(char buffer[]);
void ejecutar(ptrnodo *aux);

void lexer(char buffer [] ){
    int  i =0;
    minusculas(&buffer[0]);
    int tamano = strlen(&buffer[0]);
    char dato [1000]={};
    int pos_vector =0;
    while (i<tamano){

        switch (ESTADO) {
        case 0:
            if((int)(buffer[i])==salto_linea){
              ESTADO=0;
            }else if((int)(buffer[i])==espacio_blanco){
              ESTADO=0;
            }else if(Esletra(buffer[i])==1){
                dato[pos_vector++]=buffer[i];
                ESTADO=1;
            }
            break;
        case 1:
            if((int)(buffer[i])==salto_linea||(int)(buffer[i])==espacio_blanco){
                if(Esreservada(&dato[0])==1)
                  {
                    insertar(&primero,dato);
                  }else{
                    printf("%s","The token found ist'n a keyword");
                    printf("%s","\n");
                    printf("%s","ERRONEUS TOKEN: ");
                    printf("%s",&dato[0]);
                    printf("%s","\n");
                  }

                pos_vector=0;
                ESTADO=0;
                limpiar_vector(dato);
            }else if(Esletra((buffer[i]))==1){
                dato[pos_vector++]=buffer[i];
            }


            break;
        }
        i++;
    }

}

static int Esletra(char letra){
    int tamano  = strlen(letras);
    int i =0;
    for(i=0; i<tamano; i++){
        if((int)letras[i]==(int)letra){
            return 1;
        }
    }
    return 0;
}

static int Esnumero(int numero){
    int tamano = strlen(numeros);
    int i =0;
    for(i=0; i<tamano; i++){
        if(numero==numeros[i]){
            return 1;
        }
    }
    return 0;
}

static void minusculas(char *s)
{
    char com='\"';
    while(*s!='\0')
    {
        if(*s>='A' && *s<='Z')
            if((*s)==com){
                while(*s==com){
                    *s+=(char)32;
                    s++;
                }
            }else{
            *s+=(char)32;
            } if((*s)==com){
            s++;
               while(*s!=com){
                   s++;
               }
        }
        s++;
    }
}

void limpiar_vector(char v []){
  int tamano = strlen(v);
  int i =0;
  for(i=0; i<tamano; i++){
      v[i]='\0';
    }
}

static int Esreservada(char *palabra){
  int tamano = 28;
  int i =0;
  for(;i<tamano; i++){
      if(strcmp(palabra,palabras[i])==0){
          return 1;
        }
    }
  return 0;
}

void leer(char buffer[]){
    FILE *ptrCf;
    char hola[10000];
    if ( ( ptrCf = fopen( "/home/daniel/scrip.dat", "r" ) ) == NULL ) {
    printf( "No pudo abrirse el archivo.\n");
    }
    else {
    while (!feof(ptrCf)) {
    fgets(hola,10000,ptrCf);
    strcat(buffer,hola);
    }
    fclose( ptrCf ); /* fclose cierra el archivo */
    }
}
void ejecutar(ptrnodo *aux){


    while(aux!=NULL){
        char *palabra="";
        palabra=(*aux)->palabra;
        if(strcmp(palabra,"rmdisk")==0){
            (*aux)=(*aux)->sig;
            printf("se eliminira un disco\n");
            char*espacio=" ";
            char cadena[20];
            char eli[100]="";
            char*p="rm";
            strcat(eli,p);
            strcat(eli,espacio);
            //strcat(eli,(*aux)->comando);
            printf("seguro de eliminar el disco:\n");
            printf("1. SI:\n");
            printf("2. NO:\n");
            fgets(cadena,100,stdin);
            if(strcmp(cadena,"1\n")==0){
            //solo con una diagonal para eliminar
            system(eli);
            }else{
                printf("ya no se elimino el disco..\n");
            }
        }else if(strcmp((*aux)->palabra,"mkdisk")==0){
/************************************duda*****************************************/
            const char*unit="k";
            int ta=atoi("100");
            int byt=1024;
            int mbyt=1024*1024;
            int totalD=0;
            if(strcmp(unit,"k")==0){
                totalD=ta*byt;
            }else if(strcmp(unit,"m")==0){
                totalD=ta*mbyt;
            }else{
                totalD=ta*mbyt;
            }
            if(ta>0){
           printf("\nse creara un disco\n");
           char*dire="";
           char*espacio=" ";
           char*p=" dd if=/dev/zero of=";
           char*p1="bs= ";
           char*p2=" count=1 ";
           strcat(dire,p);
           strcat(dire,"/home/daniel/nuevo.txt ");
           strcat(dire,p1);
           strcat(dire,"1024 ");
           strcat(dire,p2);
           char cap[25]="";
         //  itoa(totalD,cap,10);
           strcat(dire,cap);
           //printf("\n%s",dire);
           char*pr="dd if=/dev/zero of=/home/daniel/prueba.txt bs=1024 count=1";
           printf("%s",dire);
           system(dire);
            }else{
                printf("error...... tamaño tiene q ser mayor a 0\n");
            }
/*****************************************************************************/


        (*aux)=(*aux)->sig;
        if(strcmp((*aux)->palabra,"size")==0){

        }else if(strcmp((*aux)->palabra,"unit")==0){

        }else if(strcmp((*aux)->palabra,"path")==0){

        }else{

        }
        }

    }
}

#endif // AUTOMATON_H
