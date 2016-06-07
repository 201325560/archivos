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
    system("fsutil file createnew C:\\Users\\twa\\discoduro.txt 1024");
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
    impimeMBR();
    crearParticionNormal('1','P','0',400,"nueva1");
    impimeMBR();
    crearParticionNormal('1','P','0',220,"nueva2");
    impimeMBR();
    crearParticionNormal('1','P','0',92,"nueva3");
    impimeMBR();
    crearParticionNormal('1','P','0',92,"nueva4");
    impimeMBR();
    actualizarMBR("nueva4");
    impimeMBR();
    actualizarMBR("nueva3");
    impimeMBR();
    crearParticionNormal('1','P','0',102,"nueva5");
    impimeMBR();




    //principal(&aux);
    return 0;
}
