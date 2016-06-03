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

#endif // AUTOMATON_H
