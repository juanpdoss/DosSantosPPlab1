#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
typedef struct
{
    int id;
    char marca[20];
    int idtipo;
    int idcolor;
    int cilindrada;
    int isEmpty;


}eMoto;

#endif // MOTO_H_INCLUDED
void initMoto(eMoto motos[],int tammot);
int buscarLibreMoto(eMoto motos[],int tammot);
int menuMotos(void);
int menuCilindradas(void);
void altaMoto(eMoto motos[],int indiceLibre,int id);
int tomarCilindrada(void);
int buscarMotoPorId(eMoto motos[],int tammot,int id);
void mostrarmoto(eMoto moto,eTipo tipos[],int tamtip,eColor colores[],int tamcol);
void ordenarMotos(eMoto motos[],int tammot);
void mostrarMotos(eMoto motos[],int tammot,eTipo tipos[],int tamtip,eColor colores[],int tamcol);

