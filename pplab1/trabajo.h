#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    int isEmpty;
    eFecha fecha;




}eTrabajo;


#endif // TRABAJO_H_INCLUDED
#include "bici.h"

void initrabajos(eTrabajo trabajos[],int tamtrabajos);
void altatrabajo(eTrabajo trabajos[],int indicelibre,int id);
int buscartrabajolibre(eTrabajo trabajos[],int tamtrabajos);
void mostrartrabajo(eTrabajo trabajos,eBici bicis[],int tambic,eServicio servicios[],int tamser);
void mostrartrabajos(eTrabajo trabajos[],int tamtra,eBici bicis[],int tambic,eServicio servicios[],int tamser);
