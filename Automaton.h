#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
extern void crearlista();
extern void insertar(ptrnodo *primero, char palabra [],ptrnodo *ultimo);
extern int contiene(const char *palabra);

static char letras [] = {'a','b','c','d','e','f','g',
                  'h','i','j','k','l','n','m',
                  'o','p','q','r','s','t','u',
                  'v','w','x','y','z',
                  'A','B','C','D','E','F','G',
                  'H','I','J','K','L','N','O',
                  'P','M','Q','R','S','T','U'
                  ,'V','W','X','Y','Z'};

static char * palabras [] = {"mkdisk","rmdisk","fdisk","-mount","-unmount","-size",
                             "-unit","-path","-id","-type","-fit","-delete","-name",
                             "-add","-mkfs","-mkfile","-cat","-rem","-edit","-ren",
                             "mkdir","-cp","-mv","-find","-cont","-p","-dest","-iddest"};
static int numeros [] = {'0','1','2','3','4','5','6','7','8','9'};
static char simbolos []= {};
static int ESTADO=0;
static int salto_linea = (int)'\n';
static int comentario = (int)'#';
static int espacio_blanco = (int)' ';
static int Esletra(char letra);
static int Esreservada(char * palabra);
static int Esnumero(char numero);
static void minusculas(char *s);
char * stchcat(char cadena[], char chr);
int flag=0;

void lexer(char buffer []);
void leer(char buffer[]);

void lexer(char buffer [] ){
    crearlista();
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
              flag=0;
            }else if((int)(buffer[i])==espacio_blanco){
              ESTADO=0;
            }else if(Esletra(buffer[i])==1||Esnumero(buffer[i])){
                dato[pos_vector++]=buffer[i];
                ESTADO=1;
            }else if((int)buffer[i]==comentario){
                flag=1;
            }else if((int)buffer[i]==(int)'/'){
                //dato[pos_vector++]=buffer[i];//aki creo q no tendria q guardar esto
                pos_vector=0;
                ESTADO=0;
            }else if((int)buffer[i]==(int)'.'){
                dato[pos_vector++]=buffer[i];
                ESTADO=1;
            }else if((int)buffer[i]==(int)':'&&ultimo!=NULL){
                limpiar_vector(dato);
                pos_vector=0;
                ESTADO=3;
            }else if((int)buffer[i]==(int)'-'){
                dato[pos_vector++]=buffer[i];
                ESTADO=1;
            }
            break;
        case 1:
            if((int)(buffer[i])==salto_linea||(int)(buffer[i])==espacio_blanco){

                if(Esreservada(&dato[0])==1)
                  {
                    insertar(&primero,dato,&ultimo);
                    flag=0;
                    pos_vector=0;
                    ESTADO=0;
                    limpiar_vector(dato);
                  }else{
                    if(flag==0){
                    printf("%s","The token found ist'n a keyword");
                    printf("%s","\n");
                    printf("%s","ERRONEUS TOKEN: ");
                    printf("%s",&dato[0]);
                    printf("%s","\n");
                    }
                    pos_vector=0;
                    ESTADO=0;
                    limpiar_vector(dato);
                  }

            }else if(Esletra((buffer[i]))==1||Esnumero(buffer[i])==1){
                dato[pos_vector++]=buffer[i];
            }else if((int)buffer[i]==(int)'/'){
                //dato[pos_vector++]=buffer[i];//ni esto iria
                pos_vector=0;
            }else if((int)buffer[i]==(int)'.'){
                dato[pos_vector++]=buffer[i];
            }else if((int)buffer[i]==(int)':'){
                if(Esreservada(dato)){
                    insertar(&primero,dato,&ultimo);
                    pos_vector=0;
                    ESTADO=3;
                }else{
                    if(flag==0){
                    printf("%s","The token found ist'n a keyword");
                    printf("%s","\n");
                    printf("%s","ERRONEUS TOKEN: ");
                    printf("%s",&dato[0]);
                    printf("%s","\n");
                    pos_vector=0;
                    ESTADO=0;
                    }
                }
                limpiar_vector(dato);
            }
            break;
        case 2:
            if((int)buffer[i]!=(int)'\"'){
                dato[pos_vector++]=buffer[i];
            }else if ((int)buffer[i]=='\"'||(int)buffer[i]==salto_linea){
                dato[pos_vector++]=buffer[i];
                if(flag==0){
                setComando(&ultimo,dato);
                }
                flag=0;
                pos_vector=0;
                limpiar_vector(dato);
                ESTADO=0;
            }
            break;
        case 3:
            if((int)(buffer[i])==salto_linea||(int)(buffer[i])==espacio_blanco){
               if(flag==0){
                   setComando(&ultimo,dato);
               }
               flag=0;
                pos_vector=0;
                ESTADO=0;
                limpiar_vector(dato);
            }else if(Esletra((buffer[i]))==1||Esnumero(buffer[i])==1){
                dato[pos_vector++]=buffer[i];
            }else if((int)buffer[i]==(int)'/'){
                //dato[pos_vector++]=buffer[i];//aki tampoco iria esto creo
                pos_vector=0;
            }else if((int)buffer[i]==(int)'.'){
                dato[pos_vector++]=buffer[i];
            }else if((int)buffer[i]==(int)':'){
                pos_vector=0;
                limpiar_vector(dato);
            }else if((int)buffer[i]==(int)'\"'){
                dato[pos_vector++]=buffer[i];
                ESTADO=2;
            }//aki iria un si es igual a "-" para saber si viene numeros negativos
            else if((int)buffer[i]==(int)'-'){
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

static int Esnumero(char  numero){
    int tamano = 10;
    int i =0;
    for(i=0; i<tamano; i++){
        if((int)numero==(int)numeros[i]){
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


#endif // AUTOMATON_H
