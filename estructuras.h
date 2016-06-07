#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <strings.h>
#define INICIO_MBR 0
#define FIN_MBR 219
#define CURRENT_MBR 220
char *fh();
void crearMBR(int size_disco);
void crearParticionNormal(char status, char type, char fit, int seek, int start, int size, char *name);
void actualizarMBR(char * nombre_particion);

struct PARTICION{
        char estado;//esta activa o no
        char tipo;//primario o extendida
        char fit;//best,first,worst
        char name[16];//nombre de la particion
        int start;//bin en q inicia
        int size;//tamaño particion
};

typedef struct PARTICION*ptrParticion;
typedef struct PARTICION particion;
int buscaSiexiste(ptrParticion p, int seek);

struct MBR{
     int tamano;//tamaño de disco duro
     char fecha[100];//fecha de creacion
     int random;//cualkier numero random
     particion part1;
     particion part2;
     particion part3;
     particion part4;
};
typedef struct MBR*ptrMBR;
typedef struct MBR mbr;
mbr leerMBR();
char *fh(){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    printf("%s\n",output);
    printf ("%i \n",sizeof(mbr));
return  output;
}

void crearMBR(int size_disco){
    FILE * ptrfile;
    ptrfile = fopen("/home/daniel/discoduro.txt","rb+");
    if(ptrfile!=NULL){
        fseek(ptrfile,0*sizeof(mbr),SEEK_SET);
        char c [100];
        strcpy(c,fh());
        particion p,p1,p2,p3;
        p.estado='f';
        p.fit ='g';
        strcpy(p.name,"uno");
        p.size=1;
        p.start=1;
        p.tipo='h';

        p1.estado='f';
        p1.fit ='g';
        strcpy(p1.name,"dos");
        p1.size=1;
        p1.start=1;
        p1.tipo='h';

        p2.estado='f';
        p2.fit ='g';
        strcpy(p2.name,"tres");
        p2.size=1;
        p2.start=1;
        p2.tipo='h';

        p3.estado='f';
        p3.fit ='g';
        strcpy(p3.name,"cuatro");
        p3.size=1;
        p3.start=1;
        p3.tipo='h';
        mbr m;
        m.part1=p;
        m.part2=p1;
        m.part3=p2;
        m.part4=p3;
        m.random=1;
        m.tamano=size_disco;
        strcpy(m.fecha,c);
        fwrite(&m,sizeof(mbr),1,ptrfile);
    }
    fclose(ptrfile);
}
//agregar el mètodo acturalizar mbr
mbr leerMBR(){
    FILE* ptrfile;
    ptrfile = fopen("/home/daniel/discoduro.txt","rb");
    mbr c ={0,"",0,0,0,0};
    if(ptrfile!=NULL){
        fseek(ptrfile,0,SEEK_SET);

        fread(&c,sizeof(mbr),1,ptrfile);
        printf("%-5d%-5d%-5s\n",c.tamano,c.random,c.fecha);
       //
        printf("%-5c%-5c%-5c%-5s%-5d%-5d\n",c.part1.fit,c.part1.estado,c.part1.tipo,c.part1.name,c.part1.size,c.part1.start);
        printf("%-5c%-5c%-5c%-5s%-5d%-5d\n",c.part2.fit,c.part2.estado,c.part2.tipo,c.part2.name,c.part2.size,c.part2.start);
        printf("%-5c%-5c%-5c%-5s%-5d%-5d\n",c.part3.fit,c.part3.estado,c.part3.tipo,c.part3.name,c.part3.size,c.part3.start);
        printf("%-5c%-5c%-5c%-5s%-5d%-5d\n",c.part4.fit,c.part4.estado,c.part4.tipo,c.part4.name,c.part4.size,c.part4.start);
    }
    fclose(ptrfile);
    return c;
}


void actualizarMBR(char * nombre_particion){
mbr mbr_1 = leerMBR();
char  constante [120];
char  constante1 [120];
char  constante2 [120];
char  constante3 [120];
strcpy(constante,mbr_1.part1.name);
strcpy(constante1,mbr_1.part2.name);
strcpy(constante2,mbr_1.part3.name);
strcpy(constante3,mbr_1.part4.name);
if(strcmp(constante,nombre_particion)==0){
    mbr_1.part1.estado='0';
    mbr_1.part2.fit ='0';
    strcpy(mbr_1.part1.name,"vacio");
    mbr_1.part1.size=1;
    mbr_1.part1.start=0;
    mbr_1.part1.tipo='0';
}else if(strcmp(constante1,nombre_particion)==0){
    mbr_1.part2.estado='0';
    mbr_1.part2.fit ='0';
    strcpy(mbr_1.part2.name,"vacio");
    mbr_1.part2.size=1;
    mbr_1.part2.start=0;
    mbr_1.part2.tipo='0';
}else if(strcmp(constante2,nombre_particion)==0){
    mbr_1.part3.estado='0';
    mbr_1.part3.fit ='0';
    strcpy(mbr_1.part3.name,"vacio");
    mbr_1.part3.size=1;
    mbr_1.part3.start=0;
    mbr_1.part3.tipo='0';
}else if(strcmp(constante3,nombre_particion)==0){
    mbr_1.part3.estado='0';
    mbr_1.part3.fit ='0';
    strcpy(mbr_1.part3.name,"vacio");
    mbr_1.part3.size=1;
    mbr_1.part3.start=0;
    mbr_1.part3.tipo='0';
}
FILE * ptrfile;
ptrfile = fopen("/home/daniel/discoduro.txt","rb+");
if(ptrfile!=NULL){
    fseek(ptrfile,0*sizeof(mbr),SEEK_SET);
    fwrite(&mbr_1,sizeof(mbr),1,ptrfile);
}
fclose(ptrfile);
int c =0;

}

void crearParticionNormal(char status, char type, char fit,int seek, int start, int size,char * name){
    FILE * ptrfile;
    ptrfile = fopen("/home/daniel/discoduro.txt","rb+");

    if(ptrfile!=NULL){
        fseek(ptrfile,CURRENT_MBR,SEEK_SET);
        printf("%d\n",sizeof(particion));
        particion busca_si_existe;
        busca_si_existe.estado=status;
        busca_si_existe.fit=fit;
        strcpy(busca_si_existe.name,name);
        busca_si_existe.size=size;
        busca_si_existe.start=start;
        busca_si_existe.tipo=type;
        fwrite(&busca_si_existe,sizeof(particion),1,ptrfile);
        int c = buscaSiexiste(&busca_si_existe,CURRENT_MBR);
    }

    fclose(ptrfile);
    leerParticion();
}

void leerParticion(){
    FILE * ptrfile;
    ptrfile = fopen("/home/daniel/discoduro.txt","rb");
    if(ptrfile!=NULL){
        fseek(ptrfile,CURRENT_MBR,SEEK_SET);
        particion p;
        fread(&p,sizeof(particion),1,ptrfile);
        int c =0;
    }
    fclose(ptrfile);
}


int buscaSiexiste(ptrParticion p,int seek){
    FILE * ptrfile;
    ptrfile = fopen("/home/daniel/discoduro.txt","rb");
    particion pp;
    if(ptrfile!=NULL){
        int primera=0;
        int fin = 0;
        while (fin<1024){
            fseek(ptrfile,CURRENT_MBR+primera,SEEK_SET);
            fread(&pp,sizeof(particion),1,ptrfile);
            if((int)(pp).estado==(int)'1'){
                return 1;
            }
            primera= primera+28;
            fin = CURRENT_MBR+primera;
        }
        return 0;
}
}


#endif // ESTRUCTURAS_H
