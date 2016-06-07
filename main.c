#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "ejecutar.h"
extern void lexer(char buffer[]);
extern void leer(char buffer[]);
extern void ejecutar_crear_disco(ptrnodo *primero);
extern void crearlista();
extern void insertar(ptrnodo *primero, char palabra [],ptrnodo *ultimo);
extern int contiene(const char *palabra);
int main(void)
{
    //system("fsutil file createnew C:\\Users\\SAMSUNG\\Desktop\\discoduro.txt 1024");
    char  texto [300];
    crearlista();
    printf("ingrese un comando!\n\nO cero para salir\n\n");
    fgets(texto,300,stdin);
    leer(texto);
    lexer(&texto[0]);
    ptrnodo aux = (ptrnodo)malloc(sizeof(nodo));
    printf("%i",size);
    aux=primero;
    correr();
    correr3();
    crearMBR(1024);
    crearParticionNormal('1','0','0',220,128,2,"primera");

   //principal(&aux);
    return 0;
}
