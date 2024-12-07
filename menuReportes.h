#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void menuReportes();


void menuReportes(){
    int opc;
    system("cls");
    while(true){
        cout<< "    MENU DE REPORTES    "<<endl;
        cout<< "------------------------"<<endl;
        cout<< "1. PUNTO 1"<<endl;
        cout<< "2. PUNTO 2"<<endl;
        cout<< "3. PUNTO 3"<<endl;
        cout<< "------------------------"<<endl;
        cout<< "0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<< "INGRESAR OPCION: ";
        cin>> opc;
        system("cls");
        switch(opc){
        case 1: //PUNTO1();
            break;
        case 2: //PUNTO2();
            break;
        case 3: //PUNTO3();
            break;
        case 0: return;
            break;
        default: cout<< "OPCION INGRESADA INCORRECTA, INTENTE NUEVAMENTE"<<endl;
            break;
        }
        cout<<endl;
        system("pause");
        system("cls");

    }
    return ;
}



#endif // MENUREPORTES_H_INCLUDED
