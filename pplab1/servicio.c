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

void listarservicios(eServicio servicios[],int tamser)
{

    printf("   servicios\n\n");
    printf("id      servicios      precio\n\n");

    for(int i=0;i<tamser;i++)
    {

        printf("%d      %s      %d\n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);



    }



}
void mostrarservicios(void)
{
    printf("    servicios\n");
    printf("1 limpieza\n");
    printf("2 ajuste\n");
    printf("3 balanceo\n");
    printf("4 cadena\n");

}
