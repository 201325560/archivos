#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
extern void lexer(char *buffer);
extern void crearlista();
extern void insertar(ptrnodo *primero, const char *palabra);
extern int contiene(const char *palabra);

static char letras [] = {'a','b','c','d','e','f','g',
                  'h','i','j','k','l','n','m',
                  'o','p','q','r','s','t','u',
                  'v','w','x','y','z',
                  'A','B','C','D','E','F','G',
                  'H','I','J','K','L','N','O',
                  'P','M','Q','R','S','T','U'
                  ,'V','W','X','Y','Z'};

static int numeros [] = {0,1,2,3,4,5,6,7,8,9};
static char simbolos []= {};
static int ESTADO=0;
static int salto_linea = (int)'\n';
static int espacio_blanco = (int)' ';
static int Esletra(char letra);
static int Esnumero(int numero);
static void minusculas(char *s);
char * stchcat(char cadena[], char chr);
static const char * palabras []={"",};

void lexer(char buffer []);



void lexer(char *buffer){
    int  i =0;
    const char * b = &buffer[0];
    char *dato = "";
    char * a = buffer;


    while (*a!='\0'){

        switch (ESTADO) {
        case 0:
            if((int)(*a)==salto_linea){
              ESTADO=0;
            }else if((int)(*a)==espacio_blanco){
              ESTADO=0;
            }else if(Esletra((*a))==1){

            }

            break;
        case 1:
            if((int)(*a)==salto_linea||(int)(*a)==espacio_blanco){

                ESTADO=0;
            }else if(Esletra((*a))==1){

            }


            break;
        }
        *a++;
    }

}

static int Esletra(char letra){
    int tamano  = sizeof(letras);
    int i =0;
    for(i=0; i<tamano; i++){
        if((int)letras[i]==(int)letra){
            return 1;
        }
    }
    return 0;
}

static int Esnumero(int numero){
    int tamano = sizeof(numeros);
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

#endif // AUTOMATON_H
