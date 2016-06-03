#include <stdio.h>
#include <stdlib.h>
#include "Automaton.h"
#include "lista.h"
extern void lexer(char buffer[]);
extern void crearlista();
extern void insertar(ptrnodo *primero, const char *palabra);
extern int contiene(const char *palabra);
int main(void)
{

    char  texto [300];
    char b [] = "hola mundo como estas hoy !";
    printf("Hello World!\n");
    fgets(texto,300,stdin);
    lexer(&texto[0]);


    return 0;
}

