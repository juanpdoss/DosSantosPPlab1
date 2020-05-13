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
#include "bici.h"

#define CANTMOT 5


int main()
{
    int indiceLibreMoto;
    int flagtrabajo=0;
    char confirma;
    int idtrabajo=100;
    int trabajolibre;
    int flagcargo=0;
    int nuevaCilindrada;
    int idmoto=100;
    int auxid;
    char seguir='s';
    eTipo tipos[4]= {{1000,"enduro"},{1001,"chopera"},{1002,"scooter"},{1003,"ciclomotor"}};
    eColor colores[6]= {{10000,"gris"},{10001,"negro"},{10002,"blanco"},{10003,"azul"},{10004,"rojo"}};
    eServicio servicios[4]= {{20000,"limpieza",250},{20001,"ajuste",300},{20002,"balanceo",17},{20003,"cadena",190}};
    eTrabajo trabajos[10];
    eBici bicis[5]={{1,"playera"},{2,"mountainbike"},{3,"generica"},{4,"decarga"}};

    eMoto motos[CANTMOT];


    initrabajos(trabajos,5);

    initMoto(motos,5);

    do
    {
        switch(menuMotos())
        {
        case 1:
            indiceLibreMoto=buscarLibreMoto(motos,CANTMOT);
            if(indiceLibreMoto>=0)
            {
                altaMoto(motos,indiceLibreMoto,idmoto);
                idmoto++;
                flagcargo=1;



            }
            else
            {

                printf("no hay lugar para mas motos\n");
            }
            break;
        case 2:
            if(flagcargo)
            {
                utn_getEntero(&auxid,100,"ingrese id de moto a modificar:","Error.Utilice caracteres numericos",0,100000);
                indiceLibreMoto=buscarMotoPorId(motos,CANTMOT,auxid);
                if(indiceLibreMoto>=0)
                {
                    mostrarColores();
                    utn_getEntero(&motos[indiceLibreMoto].idcolor,100,"ingrese id del nuevo color","error. opcion invalida",10000,10004);
                    printf("ingrese nueva cilindrada");
                    nuevaCilindrada=tomarCilindrada();
                    motos[indiceLibreMoto].cilindrada=nuevaCilindrada;



                }
                else
                {
                    printf("no hay registros del id ingresado\n");
                }


            }
            else
            {
                printf("primero cargue una moto");
            }


            break;
        case 3:
            if(flagcargo)
            {
                utn_getEntero(&auxid,100,"ingrese id de moto a dar de baja:","error. Utilice caracteres numeriso",0,10000);
                indiceLibreMoto=buscarMotoPorId(motos,CANTMOT,auxid);
                if(indiceLibreMoto>=0)
                {
                    printf("ingrese s para dar de baja la moto:");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma=='s')
                    {
                        motos[indiceLibreMoto].isEmpty=1;
                        printf("baja exitosa");

                    }
                    else
                    {
                        printf("baja cancelada\n");
                    }



                }
                else
                {
                    printf("no hay registros del id ingresado\n");
                }

            }
            else
            {
                printf("primero cargue una moto\n");
            }

            break;
        case 4:
          if(flagcargo)
          {
                ordenarMotos(motos,CANTMOT);
                mostrarMotos(motos,CANTMOT,tipos,4,colores,6);

          }
          else
          {
              printf("primero cargue una moto");

          }
            break;
        case 5://no uso mas la bandera ya que no dependen de la moto
            listartipos(tipos,4);
            break;
        case 6:
            listarcolores(colores,6);
            break;
        case 7:
            listarservicios(servicios,4);
            break;
        case 8:
            trabajolibre=buscartrabajolibre(trabajos,10);
            if(trabajolibre>=0)
            {
                altatrabajo(trabajos,trabajolibre,idtrabajo);
                idtrabajo++;
                flagtrabajo=1;

            }
            else
            {
                printf("ya no quedan trabajos disponibles\n");
            }

            break;
        case 9:
            if(flagtrabajo)
            {
                 mostrartrabajos(trabajos,5,bicis,5,servicios,4);

            }
            else
            {
                printf("primero cargue un trabajo\n");
            }
            break;

        case 10:
            seguir='n';
            break;
        default:
            printf("opcion no valida\n");
            break;


        }
        system("pause");
        system("cls");

    }
    while(seguir=='s');





    return 0;

}
