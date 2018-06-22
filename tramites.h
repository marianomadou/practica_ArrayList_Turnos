typedef struct
{
    long int dni;
    int idTramite;
    int turno;
}eTramite;

eTramite* tramite_newTramite();
eTramite* tramite_turnoUrgente(int numTurno);
eTramite* tramite_turnoRegular(int numTurno);
void tramite_siguiente(ArrayList* listaUrgente, ArrayList* listaRegular, ArrayList* listaAtendido);
void tramite_listarPendientes(ArrayList* listaUrgente, ArrayList* listaRegular);
int tramite_ordenarDNI(void*, void*);

/*
eDatos* datos=NULL;



case 2:



            printf("Ingrese el nombre del archivo CSV: ");
            fflush(stdin);
            gets(nameFile);
            if((strcmpi("file.csv",nameFile))==0)
            {
                blackList= fopen("file.csv","r");

                if(blackList==NULL)
                {
                    printf("No se pudo abrir el archivo");
                    //exit(1);
                }
                else
                {
                    printf("Leyendo datos...\n");
                    p=0;
                    while(!feof(blackList))
                    {
                        datos=(eDatos*)malloc(sizeof(eDatos));
                        fscanf(blackList,"%[^,],%[^\n]\n",name,eMail);
                        strcpy(datos->name,name);
                        strcpy(datos->eMail,eMail);

                        al_add(listaNegra,datos);
                        p++;
                    }
                    printf("Datos cargados en la Lista.\n");
                    printf("\nCantidad de datos cargados: %d.-\n",p);
                    fclose(blackList);
                }


            }
            else
            {
                printf("Se ingreso MAL el nombre del archivo.\n");
            }

            getche();
            system("cls");
            break;
*/
