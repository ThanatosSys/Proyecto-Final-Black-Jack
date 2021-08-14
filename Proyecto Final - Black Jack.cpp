/*Francisco Javier Montes Martinez
Proyecto final - Black Jack*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;


//Variables relacionadas con el menu,jugadores y sus datos

int jug=0;                                //Contador de jugadores que inicia en 0
string datos[2]={"Nombre: ","Dinero: "};  //Cadena que guarda datos de cada jugador en forma de arreglo
int cantdatos = 2;                        //Datos que llenara el usuario
int totales[4];                           //Arreglo que guarda el total de cartas de cada jugador
char menu;                                //Variable de opciones del menu

//Variables relacionadas con el juego y sus reglas

int carta;                //Variable que genera una carta al azar
int as;                   //Variable de opcion que le pregunta al usuario sobre su AS
int totalcarta;           //Total que se obtiene cada vez que se suman las cartas de cada jugador
int pedir;                //Variable usada para tomar decisiones de PEDIR o QUEDARSE
int j;                    //Contador para la posicion de las cartas

int main()
{
    srand(time(NULL));           //Generador de seeds de numeros aleatorios
    void MenuPrincipal();        //Void declarado del menu principal
    MenuPrincipal();             //Funcion que ejecuta el menu principal junto al juego
    return 0;                    //Return 0
}//Fin de la funcion main


//Funcion que define tanto el juego como el registro de datos del usuario
void juego()
{
    void repartircarta();       //Se manda llamar la funcion que reparte una carta nueva cada vez que es llamada

       //El usuario define la cantidad de jugadores mayor a 1 y menor o igual a 4
        cout<<"Ingrese la cantidad de jugadores a participar (max 4 )"<<endl;      //Pide al usuario registrar el numero de jugadores
        cin>>jug;                      //Variable que captura el numero de jugadores
        system("CLS");                 //Limpiamos pantalla
        string jugador[jug][2];        //El usuario declara el tamaño de las filas con el numero de jugadores, y bloqueamos las columnas para evitar errores logicos

        //Si el usuario ingresa el numero correcto de jugadores, el programa pasara a capturr datos
        if(jug>0&&jug<=4)
           {
               //Ciclo for anidado que captura datos de cada jugador
               for(int i=0;i<jug;i++)
                {
                    cout<<"Jugador " <<i+1<<". Respondiendo...\n"<<endl;
                    //Ciclo que captura los datos NOMBRES Y DINERO

                    //Pasa por cada dato de columna a cada jugador
                    for(int j=0;j<cantdatos;j++)
                        {
                            cout<<datos[j]<<"\n"<<endl;    //Pregunta cada dato declarado
                            cin>>jugador[i][j];            //captura por el usuario
                        }
                        system("CLS");   //Limpiar pantalla
                }

                //Se imprime los datos ingresado por cada jugador antes de comenzar a jugar
                system("CLS");
                cout<<"Datos ingresados, mostrando datos de los jugadores: "<<endl;

                for(int i=0;i<jug;i++)      //Ciclo que imprime los datos que se ingresaron
                    {
                        cout<<"Jugador "<<i+1<<".\n"<<endl;

                        for(int j=0;j<cantdatos;j++)        //ciclo que pasa por cada jugador
                            {
                                cout<<"\t"<<datos[j]<<endl;             //Imprime datos
                                cout<<"\t"<<jugador[i][j]<<"\n"<<endl;  //Imprime datos
                            }
                    }
                    cout<<"Todo listo !\n"<<endl;
                    cin.get();      //Input para continuar con el programa

          }




    //Inicio del juego
    cout<<"Bienvenido al juego BLACK JACK"<<endl;        //Mensajes de bienvenida
    cout<<"Presione ENTER para continuar"<<endl;         //Instruccion
    cin.get();         //Input para pasar a repartir cartas
    system("CLS");     //Limpiar pantalla

    //Inicio del turno del jugador x
    for(int i=0;i<jug;i++)
    {
        pedir=1;           //Inicializamos pedir en 1 para entrar al ciclo while, aplica para todos los jugadores
        totalcarta=0;      //Su total de cartas iniciara siempre en 0, para no mezclar resultados de otro jugadores
        j=1;               //Contador de cartas iniciada en 1 para la carta inicial

        cout<<"Turno de "<<jugador[i][0]<<endl;         //Imprime el turno del jugador al momento

        while(pedir!=2&&totalcarta<21)   //Mientras que pedir sea diferente de 2, y totalcarta sea menor a 21, el usuario puede tomar las cartas que desee
            {
                for(j;j<3;j++)           //For para contador de las primeras dos cartas iniciales del jugador
                {
                    repartircarta();     //Manda a llamar la Funcion que reparte cartas al azar
                    cout<<"Carta "<<j<<": "<<carta<<endl;    //Imprime la ultima carta tomada
                    if(carta==1)        //Si la carta que recibe el usuario es igual a 1
                    {
                        cout<<"Obtuvo un AS, que valor quiere darle ? 1. 2) o 11. 2)"<<endl;    //Le da a escoger entre dos valores: 1 y 11
                        cin>>as;          //Se captura la respuesta del usuario

                        if(as==1)         //En caso de que el usuario decida la opcion 1
                        {
                            carta=1;      //la carta se quedara con un valor de 1
                        }
                        else if (as==2)   //En caso de que escoga 2
                        {
                            carta=11;     //La carta ahora valdra 11
                        }
                    }
        		    totalcarta+=carta;    //Se suma el total mas la ultima carta
                }
                while(pedir!=2&&totalcarta<21)    //Mientras que pedir sea diferente de 2, y totalcarta sea menor a 21, el usuario tiene la opcion de tomar o salir
                    {
                        cout<<"Su total es: "<<totalcarta<<endl;  //Muestra el nuevo total de cartas
                        cout<<"\nDesea PEDIR '1' o QUEDARSE '2'"<<endl;       //Pregunta al jugador si desea pedir mas cartas o quedarse con sus cartas actuales
                        cin>>pedir;                          //Se recibe la recibe la respuesta del usuario
                        system("cls");                       //Se limpia pantalla

                        switch(pedir)                        //Usamos un switch
                        {
                            case 1:
                            repartircarta();                 //Se reparte otra carta
                            cout<<"Carta "<<j<<": "<<carta<<endl;        //Imprime la ultima carta recibida
                            if (carta==1)                                //
                                {
                                    cout<<"Obtuvo un AS, que valor quiere darle ? 1. 2) o 11. 2)"<<endl;
                                    cin>>as;
                                    if(as==1)           //Si la carta que recibe el usuario es igual a 1
                                        {
                                            carta=1;    //la carta se quedara con un valor de 1
                                        }
                                    else if (as==2)     //En caso de que escoga 2
                                        {
                                            carta=11;   //La carta ahora valdra 11
                                        }
                                }
                            totalcarta+=carta;          //Se suma el total mas la ultima carta
                            j++;                        //Se suma el contador, para recibir la segunda carta inicial, y asi ciclar las cartas
                            break;                      //continua
                            case 2:                     //case 2
                            break;                      //continua
                            default:                    //Termina el switch
                            break;                      //continua
                        }
                    }
                    totales[i]=totalcarta;             //Se le asigna el total de cartas a cada posicion del arreglo (Jugadores)
                    system("CLS");                     //Limpiar pantalla
            }
    }

    //Ciclo for que que recorre cada jugador para mostrar su resultado final
    for(int i=0;i<jug;i++)
    {
        cout<<jugador[i][0]<<" se quedo con: "<<totales[i]<<endl;   //Imprime el nombre del jugador del turno con su respectivo total
    }

    //***Simulador de dealer, turno dealer
    cout<<"\nTurno del Dealer"<<endl;   //Turno del crupier
    pedir=1;                            //Se inicializa pedir en 1
    totalcarta=0;                       //Totalcaarta en 0 para limpiar el resultado de los jugadores
    j=1;                                //j en 1 para mostrar la posicion de la ultima carta tomadada

    while(pedir!=2&&totalcarta<21)      //Mientras que pedir sea diferente de 2, y totalcarta sea menor a 21, el dealer tomara las una carta
    {
        for(j;j<3;j++)              //For para contador de las primeras dos cartas iniciales del dealer
        {
            {
                repartircarta();       //Manda a llamar la Funcion que reparte cartas al azar
                cout<<"Carta "<<j<<": "<<carta<<endl;         //Imprime la ultima carta recibida del dealer
                totalcarta+=carta;                            //Suma la ultima carta para obtener el nuevo resultado
            }
            while(pedir!=2&&totalcarta<21)           //Mientras que pedir sea diferente de 2, y totalcarta sea menor a 21, el dealer tiene unas opciones
            {
                if(totalcarta<16)                //Si totalcarta es menor a 16
                        {
                            pedir=1;                 //pedir toma el valor de 1, y toma otra carta
                        }
                        else if(totalcarta<21)      //Si totalcarta es menor a 21
                            {
                                pedir=2;            //pedir toma el valor de 2, y deja de tomar cartas
                            }
                        else                        //O si se pasa de 21
                        {
                            pedir=2;                //deja de pedir cartas
                        }

                        switch(pedir)               //switch de pedir
                        {
                            case 1:
                            repartircarta();       //Si reparte la carta
                            cout<<"Carta "<<j<<": "<<carta<<endl;       //carta generada de manera aleatoria
                            totalcarta+=carta;         //Se suma el total mas la ultima carta
                            j++;                       //Se suma el contador, para recibir la segunda carta inicial, y asi ciclar las cartas
                            cout<<"\nEl total del dealer es:  "<<totalcarta<<endl;     //Se imprime el resultado final del dealer
                            j++;                        //Se suma el contador, para recibir la segunda carta inicial, y asi ciclar las cartas
                            break;                     //continua
                            case 2:                    //caso 2
                            break;                    //Continua
                            default:                  //Termina el switch
                            break;                    //continua
                        }
            }
      }   //Fin del dealer

     //ciclo for que compara los resultados finales de cada jugador, incluyendo el dealer
     for(int i=0;i<jug;i++)     //pasa por cada jugador
        {
            if((totales[i]>totalcarta||totalcarta>21)&&totales[i]<22)    //si el total del jugador en turno es mayor a total carta o total carta es mayor a 21 y total del jugador es menor a 22
            {
                cout<<"\n"<<jugador[i][0]<<" Gano"<<endl;                //el jugador actual gana al dealer
            }
            else if(totales[i]==totalcarta&&totales[i]<22)               //si total del jugador en turno es igaul a total de carta y total del jugador del turno
                {
                    cout<<"\n"<<jugador[i][0]<<" empato"<<endl;          //el jugador empata con el dealer
                }
            else                                                         //ultimo caso
                {
                    cout<<"\n"<<jugador[i][0]<<" perdio"<<endl;          //el jugador en turno pierde contra el dealer
                }
        }//Fin del turno del dealer y el juego
        cout<<"\nDesea volver a jugar ? 1)Si. 2)No. "<<endl;
        cin>>menu;
        system("CLS");
   }
}

//Funcion MenuPrincipal, que declara un simple menu, y define el nombre de los jugadores.
void MenuPrincipal()
{
    void juego();  //manda a llamar a la funcion Juego. para comenzar a registrar datos del jugador y pasar a jugar
    cout<<"Bienvenido al juego BLACK JACK." << endl;             //Bienvenida para el usuario
	cout<<"Selecciona una de las siguientes opciones\n" << endl;
	cout<<"Jugar 1)"<<endl;        //Opcion que pasa a registrar datos y al juego
	cout<<"Salir 2)"<<endl;        //Termina el programa
	cin>>menu;                     //Se caputra la opcion que de el usuario
	system("CLS");

    do   //Abrimos un ciclo do while para el menu principal
        {

            switch(menu)   //Inicia el juego
            {
            	case '1':
                	juego();  //Funcion juego
                break;

                case '2':
                	//Condicion en caso de que el usuario no quiera jugar
                	system("cls");   //Limpia pantalla
                    cout<<"Hasta pronto"<<endl; //output
                    exit(0);         //Fin del programa
                break;
                 //Condicion a prueba de usuario
                default:
                	system("CLS");      //refrescar pantalla para imprimir un aviso al usuario
                    cout<<"Opcion incorrecta, presione ENTER para intentar de nuevo."<<endl;     //Indicaciones para el usuario
                    cin.get();        //Input para pasar a la siguiente instruccion
                    menu='0';         //Reinicia el menu
                    cin.ignore();     //Ignora lo que hay en la memoria ingresado por el usario
                    system("CLS");    //refrescar pantalla para mostrar de nuevo el menu en limpio
                    MenuPrincipal();  //Regresa el menu principal
                break;                //continua
            }

        }while(menu!=1); //Ciclo en caso de que se seleccione algo ajeno a las opciones
                           //Fin de del menu principal
}

//Reparte una carta nueva y es llamada siempre que el jugador desee una nueva carta
void repartircarta()
{
    //Genera la carta de manera aleatoria
    carta=rand()% 52 + 1;       //Rango de 52 cartas, en las que pasando 13 cambia de palo la carta
    while(carta>10)             //Dado caso que la carta sea mayor a 10, esta a la transforma a un valor individual que es igual o menor a 10
        {
            if(carta>13)        //Cuando la carta dada sea mayor a 13
            {
                carta-=13;      //resta el valor dado
            }
            else if(carta>10)   //Cuando la carta sea mayor a 10
                {
                    carta=10;   //Da un valor de 10
                }
        }
}
