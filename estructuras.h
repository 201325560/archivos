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
void crearParticionNormal(char status, char type, char fit, int size, char *name);
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
int espacio_disponible1(mbr m);

char *fh(){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    printf("%s\n",output);
return  output;
}

void crearMBR(int size_disco){
    FILE * ptrfile;
    ptrfile = fopen("C:\\Users\\twa\\discoduro.txt","rb+");
    if(ptrfile!=NULL){
        fseek(ptrfile,0*sizeof(mbr),SEEK_SET);
        char c [100];
        strcpy(c,fh());
        particion p;
        p.estado='0';
        p.fit ='B';
        strcpy(p.name,"uno");
        p.size=0;
        p.start=220;
        p.tipo='P';
        mbr m;
        m.part1=p;
        m.part2=p;
        m.part3=p;
        m.part4=p;
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
    ptrfile = fopen("C:\\Users\\twa\\discoduro.txt","rb");
    mbr c ={0,"",0,0,0,0};
    if(ptrfile!=NULL){
        fseek(ptrfile,0*sizeof(mbr),SEEK_SET);
        fread(&c,sizeof(mbr),1,ptrfile);      
    }else{
      printf("an error has ocurred");
      return c;
    }
    fclose(ptrfile);
    return c;
}

void impimeMBR(){
  FILE* ptrfile;
  ptrfile = fopen("C:\\Users\\twa\\discoduro.txt","rb");
  mbr c =leerMBR();
  if(ptrfile!=NULL){
      fseek(ptrfile,0*sizeof(mbr),SEEK_SET);
      fread(&c,sizeof(mbr),1,ptrfile);
      printf("%-5d%-5d%-5s\n",c.tamano,c.random,c.fecha);
      printf("%-10c%-10c%-10c%-10s%-10d%-10d\n",c.part1.fit,c.part1.estado,c.part1.tipo,c.part1.name,c.part1.size,c.part1.start);
      printf("%-10c%-10c%-10c%-10s%-10d%-10d\n",c.part2.fit,c.part2.estado,c.part2.tipo,c.part2.name,c.part2.size,c.part2.start);
      printf("%-10c%-10c%-10c%-10s%-10d%-10d\n",c.part3.fit,c.part3.estado,c.part3.tipo,c.part3.name,c.part3.size,c.part3.start);
      printf("%-10c%-10c%-10c%-10s%-10d%-10d\n",c.part4.fit,c.part4.estado,c.part4.tipo,c.part4.name,c.part4.size,c.part4.start);
      printf("%d\n",sizeof(mbr));
  }
  fclose(ptrfile);
}


//Cantidad de Particiones Primarias =cpp
int cpp=0;
//Cantidad de Particiones Extendidas =cpe
int cpe=0;

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
    mbr_1.part1.fit ='0';
    strcpy(mbr_1.part1.name,"vacio");

    mbr_1.part1.start=0;
    mbr_1.part1.tipo='0';
}else if(strcmp(constante1,nombre_particion)==0){
    mbr_1.part2.estado='0';
    mbr_1.part2.fit ='0';
    strcpy(mbr_1.part2.name,"vacio");

    mbr_1.part2.start=0;
    mbr_1.part2.tipo='0';
}else if(strcmp(constante2,nombre_particion)==0){
    mbr_1.part3.estado='0';
    mbr_1.part3.fit ='0';
    strcpy(mbr_1.part3.name,"vacio");

    mbr_1.part3.start=0;
    mbr_1.part3.tipo='0';
}else if(strcmp(constante3,nombre_particion)==0){
    mbr_1.part4.estado='0';
    mbr_1.part4.fit ='0';
    strcpy(mbr_1.part4.name,"vacio");

    mbr_1.part4.start=0;
    mbr_1.part4.tipo='0';
}
FILE * ptrfile;
ptrfile = fopen("C:\\Users\\twa\\discoduro.txt","rb+");
if(ptrfile!=NULL){
    fseek(ptrfile,0*sizeof(mbr),SEEK_SET);
    fwrite(&mbr_1,sizeof(mbr),1,ptrfile);
}
fclose(ptrfile);
int c =0;
cpp--;
}

void crearParticionNormal(char status, char type, char fit, int size,char * name){
    mbr m = leerMBR();
    FILE * ptrfile;
    ptrfile = fopen("C:\\Users\\twa\\discoduro.txt","rb+");
    if(ptrfile!=NULL&&((cpe==1&&cpp<=3)||(cpe==0&&cpp<=4))){
        fseek(ptrfile,0*sizeof(mbr),SEEK_SET);
        int espacio_disponible=espacio_disponible1(m);
        if(size<=espacio_disponible){
            if((int)type==(int)'E'){
                cpe++;
              }else if((int)type==(int)'P'){
                cpp++;
              }
            if((int)m.part1.estado!=(int)'1'&&verificaAgujero(size,m.part1.size)==1){
                m.part1.estado=status;
                m.part1.fit=fit;
                strcpy(m.part1.name,name);
                m.part1.size=size;
                m.part1.start=220;
                m.part1.tipo=type;
              }else if((int)m.part2.estado!=(int)'1'&&verificaAgujero(size,m.part2.size)==1){
                m.part2.estado=status;
                m.part2.fit=fit;
                strcpy(m.part2.name,name);
                m.part2.size=size;
                m.part2.start=220+m.part1.size;
                m.part2.tipo=type;
              }else if((int)m.part3.estado!=(int)'1'&&verificaAgujero(size,m.part3.size)==1){
                m.part3.estado=status;
                m.part3.fit=fit;
                strcpy(m.part3.name,name);
                m.part3.size=size;
                m.part3.start=220+m.part1.size+m.part2.size;
                m.part3.tipo=type;
              }else if((int)m.part4.estado!=(int)'1'&&verificaAgujero(size,m.part4.size)==1){
                m.part4.estado=status;
                m.part4.fit=fit;
                strcpy(m.part4.name,name);
                m.part4.size=size;
                m.part4.start=220+m.part1.size+m.part2.size+m.part3.size;
                m.part4.tipo=type;
              }else{
                printf("error, the size is bigger than the free space in the disc\n");
              }

          }else{
            printf("error, the size is bigger than the free space in the disc\n");
          }

    }

    fwrite(&m,sizeof(mbr),1,ptrfile);
    fclose(ptrfile);
}

int espacio_disponible1(mbr m){
  int espacio=m.tamano-220;
  if((int)m.part1.estado==(int)'1'){
      espacio-=m.part1.size;
    }else if((int)m.part2.estado==(int)'1'){
      espacio-=m.part2.size;
    }else if((int)m.part3.estado==(int)'1'){
      espacio-=m.part3.size;
    }else if((int)m.part4.estado==(int)'1'){
      espacio-=m.part4.size;
    }
  return espacio;
}

int verificaAgujero(int size, int size_disponible){
  if(size_disponible==0){
      return 1;
    }else if(size<=size_disponible){
      return 1;
    }else{
      return 0;
    }

}







#endif // ESTRUCTURAS_H
