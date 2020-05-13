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



void mostrarColores(void)
{

    printf(" colores\n\n");
    printf("10000 gris\n");
    printf("10001 negro\n");
    printf("10002 blanco\n");
    printf("10003 azul\n");
    printf("10004 rojo\n");



}
void listarcolores(eColor colores[],int tamcol)
{
    printf("    colores\n\n");
    printf("id      color\n\n");
    for(int i=0;i<tamcol;i++)
    {

        printf("%d      %s\n",colores[i].id,colores[i].nombreColor);



    }




}
