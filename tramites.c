#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tramites.h"

eTramite* tramite_newTramite()
{
    eTramite* turno;
    eTramite* returnaux=NULL;
    turno= (eTramite*)malloc(sizeof(eTramite));
    if(turno!=NULL)
    {
        returnaux=turno;
    }
   return returnaux;
}

eTramite* tramite_turnoUrgente(int numTurno)
{
    long int dniAux;
    eTramite* tramite=tramite_newTramite();

    if(tramite != NULL)
    {
        printf("Ingrese dni: ");
        scanf("%ld",&dniAux);

        tramite->dni=dniAux;
        tramite->idTramite=100;
        tramite->turno =numTurno;

        printf("\nTramite urgente CARGADO!\nNumero de turno:%d\n\n",tramite->turno);
    }
    return tramite ;
}


eTramite* tramite_turnoRegular(int numTurno)
{
    long int dniAux;
    eTramite* tramite=tramite_newTramite();

    if(tramite != NULL)
    {
        printf("Ingrese dni: ");
        scanf("%ld",&dniAux);

        tramite->dni=dniAux;
        tramite->idTramite=102;
        tramite->turno =numTurno;

        printf("\nTramite regular CARGADO!\nNumero de turno:%d\n\n",tramite->turno);
    }
    return tramite ;
}


void tramite_siguiente(ArrayList* listaUrgente, ArrayList* listaRegular, ArrayList* listaAtendido)
{
    eTramite* aux;
    eTramite* atendido;
    if(listaUrgente->size!=0)
            {
                printf("Proximo cliente: \n");
                aux=(eTramite*)al_get(listaUrgente,0);
                printf("Tramite urgente.\nTurno:%d \nDNI:%ld \n\n",aux->turno,aux->dni);
                atendido=(eTramite*)al_pop(listaUrgente,0);
                al_add(listaAtendido,aux);
            }
            else if(listaRegular->size!=0)
            {
                printf("Proximo cliente: \n");
                aux=(eTramite*)al_get(listaRegular,0);
                printf("Tramite regular.\nTurno:%d \nDNI:%ld \n\n",aux->turno,aux->dni);
                atendido=(eTramite*) al_pop(listaRegular,0);
                al_add(listaAtendido,atendido);
            }
            else
            {
                printf("\nYa no hay mas clientes en espera.\n\n");
            }
}

void tramite_listarPendientes(ArrayList* listaUrgente, ArrayList* listaRegular)
{
     eTramite* aux;
    int i;
    if(listaUrgente->size!=0)
            {
                for(i=0;i<listaUrgente->size;i++)
                {
                    aux=(eTramite*) al_get(listaUrgente,i);
                    printf("Tramite urgente:\n");
                    printf("Turno: %d\n",aux->turno);
                    printf("DNI: %ld\n\n",aux->dni);
                }
            }
            else
            {
                printf("No hay tramites urgentes pendientes.\n");
            }

            if(listaRegular->size!=0)
            {
                for(i=0;i<listaRegular->size;i++)
                {
                    aux=(eTramite*) al_get(listaRegular,i);
                    printf("Tramite Regular:\n");
                    printf("Turno: %d\n",aux->turno);
                    printf("DNI: %ld\n\n",aux->dni);
                }
            }
                else
                {
                    printf("No hay tramites regulares pendientes.\n");
                }
}
int tramite_ordenarDNI(void* tramite1, void* tramite2)
{
    int returnAux;
    eTramite* tramiteUno = (eTramite*) tramite1;
    eTramite* tramiteDos = (eTramite*) tramite2;
        if(tramiteUno->dni > tramiteDos->dni)
        {
            returnAux =1;
        }
            else if( tramiteUno->dni < tramiteDos->dni)
            {
                returnAux =-1;
            }
                else
                {
                    returnAux = 0;
                }
    return returnAux;
}
