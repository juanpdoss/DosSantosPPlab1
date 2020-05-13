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
void mostrartipos(void)
{
    printf(" tipos\n\n");
    printf("1000 enduro\n");
    printf("1001 chopera\n");
    printf("1002 scooter\n");
    printf("1003 ciclomotor\n");


}
void listartipos(eTipo tipos[],int tamtip)
{
    printf("        tipos\n\n");
    printf("id      tipo\n");

    for(int i=0;i<tamtip;i++)
    {

        printf("%d      %s\n",tipos[i].id,tipos[i].descripcion);

    }



}
