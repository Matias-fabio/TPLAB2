#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED



void menuConfiguracion();
bool copiaSeguridadJugador();
bool copiaSeguridadDeportes();
bool restaurarArchivoJugadores();
bool restaurarArchivoDeportes();
bool copiaSeguridadEquipos();
bool copiaSeguridadTipoDeporte();



void menuConfiguracion(){
    int opc;
    system("cls");
    while(true){
        cout<< "    MENU CONFIGURACION    " <<endl;
        cout<< "------------------------"<<endl;
        cout<< "1. COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<< "2. COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<< "3. RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<< "4. RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<< "5. ESTABLECER DATOS DE INICIO"<<endl;
        cout<< "6. COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS"<<endl;
        cout<< "7. COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<< "------------------------"<<endl;
        cout<< "0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<< "INGRESAR OPCION: ";
        cin>> opc;
        system("cls");
        switch(opc){
        case 1: copiaSeguridadJugador();
            break;
        case 2: copiaSeguridadDeportes();
            break;
        case 3: restaurarArchivoJugadores();
            break;
        case 4: restaurarArchivoDeportes();
            break;
        case 5:
            break;
        case 6:copiaSeguridadEquipos();
            break;
        case 7:copiaSeguridadTipoDeporte();
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


bool copiaSeguridadJugador(){
    Jugador obj;
    FILE *pJug, *pBak;
    pJug = fopen("jugadores.dat", "rb");
    if(pJug == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        return false;
    }
    pBak = fopen("jugadores.bkp", "wb");
    if(pBak == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        fclose(pJug);
        return false;

    }

    while(fread(&obj, sizeof obj, 1, pJug) == 1){
        fwrite(&obj , sizeof obj, 1 , pBak);
    }

    fclose(pBak);
    fclose(pJug);
    return true;

}

bool copiaSeguridadDeportes(){
    Deporte obj;
    FILE *pDep, *pBak;
    pDep = fopen("deportes.dat", "rb");
    if(pDep == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        return false;
    }
    pBak = fopen("deportes.bkp", "wb");
    if(pBak == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        fclose(pDep);
        return false;

    }

    while(fread(&obj, sizeof obj, 1, pDep) == 1){
        fwrite(&obj , sizeof obj, 1 , pBak);
    }

    fclose(pBak);
    fclose(pDep);
    return true;
}

bool restaurarArchivoJugadores(){
    Jugador obj;
    FILE *pJug, *pBak;
    pJug = fopen("jugadores.dat", "wb");
    if(pJug == NULL) return false;
    pBak = fopen("jugadores.bkp", "rb");
    if(pBak == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        fclose(pJug);
        return false;
    }
    while(fread(&obj, sizeof obj, 1, pBak) == 1){
        fwrite(&obj , sizeof obj, 1 , pJug);
    }
    fclose(pBak);
    fclose(pJug);
    return true;

}

bool restaurarArchivoDeportes(){
    Deporte obj;
    FILE *pDep, *pBak;
    pDep = fopen("deportes.dat", "wb");
    if(pDep == NULL) return false;
    pBak = fopen("deportes.bkp", "rb");
    if(pBak == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        fclose(pDep);
        return false;
    }
    while(fread(&obj, sizeof obj, 1, pBak) == 1){
        fwrite(&obj , sizeof obj, 1 , pDep);
    }
    fclose(pBak);
    fclose(pDep);
    return true;
    

}

bool copiaSeguridadEquipos(){
    Equipo obj;
    FILE *pEq, *pBak;
    pEq = fopen("equipos.dat", "rb");
    if(pEq == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        return false;
    }
    pBak = fopen("equipos.bkp", "wb");
    if(pBak == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        fclose(pEq);
        return false;

    }

    while(fread(&obj, sizeof obj, 1, pEq) == 1){
        fwrite(&obj , sizeof obj, 1 , pBak);
    }

    fclose(pBak);
    fclose(pEq);
    return true;
}

bool copiaSeguridadTipoDeporte(){
    TipoDeporte obj;
    FILE *pTd, *pBak;
    pTd = fopen("tipoDeportes.dat", "rb");
    if(pTd == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        return false;
    }
    pBak = fopen("tipoDeportes.bkp", "wb");
    if(pBak == NULL){
        cout<< "no se puede crear el archivo"<<endl;
        fclose(pTd);
        return false;

    }

    while(fread(&obj, sizeof obj, 1, pTd) == 1){
        fwrite(&obj , sizeof obj, 1 , pBak);
    }

    fclose(pBak);
    fclose(pTd);
    return true;

}






#endif // MENUCONFIGURACION_H_INCLUDED
