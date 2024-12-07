
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "funcionesGlobales.h"
#include "fecha.h"
#include "jugador.h"
#include "menuJugadores.h"
#include "deporte.h"
#include "MenuDeportes.h"
#include "equipo.h"
#include "menuEquipos.h"
#include "tipoDeporte.h"
#include "menuTipoDeporte.h"
#include "menuReportes.h"
#include "menuConfiguracion.h"



int main()
{
    int opc;
    system("cls");
    while(true){
        cout<< "    MENU PRINCIPAL    " <<endl;
        cout<< "------------------------"<<endl;
        cout<< "1. MENU JUGADORES"<<endl;
        cout<< "2. MENU DEPORTES"<<endl;
        cout<< "3. MENU EQUIPOS"<<endl;
        cout<< "4. MENU TIPOS DE DEPORTES"<<endl;
        cout<< "5. MENU DE REPORTES"<<endl;
        cout<< "6. CONFIGURACION"<<endl;
        cout<< "------------------------"<<endl;
        cout<< "0. SALIR "<<endl;
        cout<<endl;
        cout<< "INGRESAR OPCION: ";
        cin>> opc;
    system("cls");
        switch(opc){
        case 1: menuJugadores();
            break;
        case 2:menuDeportes();
            break;
        case 3: menuEquipos();
            break;
        case 4: menuTipoDeporte();
            break;
        case 5: menuReportes();
            break;
        case 6: menuConfiguracion();
            break;
        case 0: return 0;
            break;
        default: cout<< "OPCION INGRESADA INCORRECTA, INTENTE NUEVAMENTE"<<endl;
            break;
        }
        cout<<endl;
        system("pause");
        system("cls");

    }
    cout <<endl;
    system("puase");
    return 0;
}
