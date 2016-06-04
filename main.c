#include <stdio.h>
#include <stdlib.h>
#include "ejecutar.h"
extern void lexer(char buffer[]);
extern void leer(char buffer[]);
extern void ejecutar(ptrnodo *primero);
extern void crearlista();
extern void insertar(ptrnodo *primero, char palabra [],ptrnodo *ultimo);
extern int contiene(const char *palabra);
int main(void)
{

        char  texto [300];
    //do{
        crearlista();
    printf("ingrese un comando!\n\nO cero para salir\n\n");
    fgets(texto,300,stdin);
    //lexer(&texto[0]);
    leer(texto);
    lexer(&texto[0]);
    //aki empezar a ejecutar
    ptrnodo aux = (ptrnodo)malloc(sizeof(nodo));
    printf("%i",size);
    aux=primero;
    ejecutar(&aux);
    //}while(strcmp(texto,"0")==1);


    return 0;
}

