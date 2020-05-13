#include <stdio.h>
#include <stdlib.h>
#include "../../mibiblioteca/utn_biblioteca.h"
#include <string.h>
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"
void initrabajos(eTrabajo trabajos[],int tamtrabajos)
{
    for(int i=0; i<tamtrabajos; i++)
    {
        trabajos[i].isEmpty=1;



    }



}
int buscartrabajolibre(eTrabajo trabajos[],int tamtrabajos)
{
    int retorno=-1;

    for(int i=0; i<tamtrabajos; i++)
    {
        if(trabajos[i].isEmpty==1)
        {
            retorno=i;
            break;


        }



    }



    return retorno;
}
void altatrabajo(eTrabajo trabajos[],int indicelibre,int id)
{

    mostrarbicis();
    utn_getEntero(&trabajos[indicelibre].idBicicleta,100,"elija una bici de la lista:","error. Utilice caracteres numericos",1,4);
    mostrarservicios();
    utn_getEntero(&trabajos[indicelibre].idServicio,100,"elija un servicio de la lista:","error. Utilice caracteres numericos",1,4);
    utn_getEntero(&trabajos[indicelibre].fecha.dia,100,"ingrese dia del trabajo:","error.utilice caracteres numericos",1,31);
    utn_getEntero(&trabajos[indicelibre].fecha.mes,100,"ingrese mes del trabajo:","error.utilice caracteres numericos",1,12);
    utn_getEntero(&trabajos[indicelibre].fecha.anio,100,"ingrese anio del trabajo:","error.utilice caracteres numericos",2020,2025);
    trabajos[indicelibre].id=id;
    trabajos[indicelibre].isEmpty=0;
    printf("trabajo guardado\n");

}
void mostrartrabajo(eTrabajo trabajos,eBici bicis[],int tambic,eServicio servicios[],int tamser)
{

    char bici[25];
    char servicio[25];

    for(int i=0; i<tambic; i++)
    {
        if(trabajos.idBicicleta==bicis[i].id)
        {
            strcpy(bici,bicis[i].bici);

        }


    }
    for(int i=0; i<tamser; i++)
    {
        if(trabajos.idServicio==servicios[i].id)
        {
            strcpy(servicio,servicios[i].descripcion);

        }


    }


    printf("%d      %s      %s      %d/%d/%d\n",trabajos.id,bici,servicio,trabajos.fecha.dia,trabajos.fecha.mes,trabajos.fecha.anio);





}
void mostrartrabajos(eTrabajo trabajos[],int tamtra,eBici bicis[],int tambic,eServicio servicios[],int tamser)
{
    printf("        trabajos\n\n");
    printf("id      bicicleta       servicio        fecha\n\n");

    for(int i=0; i<tamtra; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            mostrartrabajo(trabajos[i],bicis,tambic,servicios,tamser);
        }



    }








}
