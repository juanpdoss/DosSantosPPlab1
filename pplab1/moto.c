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

int menuMotos(void)
{
    int opcion; //no valido la opcion ya que luego descartare las incorrectas con el default del switch

    printf("        ABM motos\n\n");
    printf("1 ALTA MOTO\n");
    printf("2 MODIFICAR MOTO\n");
    printf("3 BAJA MOTO\n");
    printf("4 LISTAR MOTOS\n");
    printf("5 LISTAR TIPOS\n");
    printf("6 LISTAR COLORES\n");
    printf("7 LISTAR SERVICIOS\n");
    printf("8 ALTA TRABAJO\n");
    printf("9 LISTAR TRABAJOS\n");
    printf("10 SALIR\n");
    scanf("%d",&opcion);




    return opcion;

}
void initMoto(eMoto motos[],int tammot)
{


    for(int i=0; i<tammot; i++)
    {

        motos[i].isEmpty=1;


    }



}
int  buscarLibreMoto(eMoto motos[],int tammot)
{

    int retorno=-1;

    for(int i=0; i<tammot; i++)
    {

        if(motos[i].isEmpty==1)
        {
            retorno=i;
            break;


        }


    }



    return retorno;



}
int menuCilindradas(void)
{
    int cilindrada;

    printf("    cilindradas\n\n");
    printf("1 50\n");
    printf("2 125\n");
    printf("3 500\n");
    printf("4 600\n");
    printf("5 750\n");
    scanf("%d",&cilindrada);


    return cilindrada;

}
int tomarCilindrada(void)
{
    int retornoCilindrada;

    switch(menuCilindradas())
    {
    case 1:
        retornoCilindrada=50;
        break;
    case 2:
        retornoCilindrada=125;
        break;
    case 3:
        retornoCilindrada=500;
        break;
    case 4:
        retornoCilindrada=600;
        break;
    case 5:
        retornoCilindrada=750;
        break;
    default:
        printf("opcion no valida\n");
        break;

    }


    return retornoCilindrada;




}

void altaMoto(eMoto motos[],int indiceLibre,int id)
{
    char auxMarca[20];
    int auxtipo;
    int auxcolor;
    int auxcilindrada;



    system("cls");
    printf("        alta moto\n");

    utn_getCadena(auxMarca,20,100,"ingrese marca de la moto:","Error.Utilice solo 20 caracteres no numericos");
    mostrartipos();
    utn_getEntero(&auxtipo,100,"ingrese el id de tipo de la lista","Error. Opcion invalida",1000,1003);
    mostrarColores();
    utn_getEntero(&auxcolor,100,"ingrese el id de color de la lista","Error. Opcion invalida",10000,10004);

    auxcilindrada=tomarCilindrada();



    strcpy(motos[indiceLibre].marca,auxMarca);
    motos[indiceLibre].idcolor=auxcolor;
    motos[indiceLibre].idtipo=auxtipo;
    motos[indiceLibre].cilindrada=auxcilindrada;
    motos[indiceLibre].id=id;
    motos[indiceLibre].isEmpty=0;



    printf("alta exitosa\n");




}
int buscarMotoPorId(eMoto motos[],int tammot,int id)
{
    int retorno=-1;

    for(int i=0; i<tammot; i++)
    {
        if(motos[i].id==id&&motos[i].isEmpty==0)
        {
            retorno=i;
            break;

        }



    }



    return retorno;
}
void mostrarmoto(eMoto moto,eTipo tipos[],int tamtip,eColor colores[],int tamcol)
{

    char color[20];
    char tipo[20];

    for(int i=0; i<tamtip; i++)
    {
        if(moto.idtipo==tipos[i].id)
        {
            strcpy(tipo,tipos[i].descripcion);

        }


    }
    for(int i=0; i<tamcol; i++)
    {
        if(moto.idcolor==colores[i].id)
        {
            strcpy(color,colores[i].nombreColor);

        }


    }



    printf("%d      %s      %s      %s      %d",moto.id,moto.marca,tipo,color,moto.cilindrada);


}
void mostrarMotos(eMoto motos[],int tammot,eTipo tipos[],int tamtip,eColor colores[],int tamcol)
{
    system("cls");

    printf("        motos\n\n\n");
    printf("id      marca       tipo        color       cilindrada\n\n");

    for(int i=0;i<tammot;i++)
    {
        if(motos[i].isEmpty==0)
        {

            mostrarmoto(motos[i],tipos,tamtip,colores,tamcol);


        }



    }




}
void ordenarMotos(eMoto motos[],int tammot)
{
    eMoto aux;

    for(int i=0;i<tammot-1;i++)
    {
        for(int j=i+1;j<tammot;j++)
        {
            if(motos[i].idtipo>motos[j].idtipo)
            {
                aux=motos[i];
                motos[i]=motos[j];
                motos[j]=aux;


            }
            else if(motos[i].idtipo==motos[j].idtipo&&motos[i].id>motos[j].id)
            {
                aux=motos[i];
                motos[i]=motos[j];
                motos[j]=aux;


            }

        }


    }









}
