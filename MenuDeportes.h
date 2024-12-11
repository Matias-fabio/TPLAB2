#ifndef MENUDEPORTES_H_INCLUDED
#define MENUDEPORTES_H_INCLUDED

void menuDeportes();
void agregarDeporte();
bool listarPorID();
void listarTodosLosDeportes();
bool modificarAnioOrigen();
bool elimiarDeporte();

//TODO: revisar carga de los registros.
void menuDeportes(){
    int opc;
    int id = 0;
    system("cls");
    while(true){
        cout<< "    MENU DEPORTES    " <<endl;
        cout<< "------------------------"<<endl;
        cout<< "1. AGREGAR DEPORTE"<<endl;
        cout<< "2. LISTAR DEPORTE POR ID"<<endl;
        cout<< "3. LISTAR TODOS LOS DEPORTES"<<endl;
        cout<< "4. MODIFICAR ANIO DE ORIGEN"<<endl;
        cout<< "5. ELIMINAR REGISTRO DE DEPORTE"<<endl;
        cout<< "------------------------"<<endl;
        cout<< "0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<< "INGRESAR OPCION: ";
        cin>> opc;
        system("cls");
        switch(opc){
        case 1: agregarDeporte();
                id++;
            break;
        case 2:listarPorID();
            break;
        case 3: listarTodosLosDeportes();
            break;
        case 4: modificarAnioOrigen();
            break;
        case 5: elimiarDeporte();
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

void agregarDeporte() {
    Deporte reg;
    ArchivoDeportes archiD("deportes.dat");
    int id = archiD.obtenerUltimoId() + 1;
    cout << "ID DE DEPORTE: " << id << endl;
    reg.setIdDeporte(id);
    reg.Cargar();
    if (reg.getEstado()) {
        bool agregar = archiD.grabarRegistro(reg);
        if (agregar) {
            cout << "Registro agregado" << endl;
        } else {
            cout << "No se pudo agregar el registro" << endl;
        }
    } else {
        cout << "Registro no válido. No se agrega." << endl;
    }
}

bool listarPorID(){
    ArchivoDeportes archiD("deportes.dat");
    int idBuscar;
    cout<< "INGRESAR ID DE DEPORTE A BUSCAR:"<<endl;
    cin>> idBuscar;
    int pos = archiD.buscarRegistro(idBuscar);
    if(pos == -1){
        cout<< "EL DEPORTE NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    Deporte reg = archiD.leerRegistro(pos);
    cout<< "-----------------------------"<<endl;
    reg.Mostrar();
    return true;

}
void listarTodosLosDeportes(){
    ArchivoDeportes archiD("deportes.dat");
    archiD.listarDeportes();

}

bool modificarAnioOrigen(){
    ArchivoDeportes archiD("deportes.dat");
    Deporte reg;
    int idBuscar;
    int anioBuscar;
    cout<< "INGRESAR ID :";
    cin>> idBuscar;
    cout<< "INGRESAR ANIO DE ORIGEN:";
    cin>> anioBuscar;
    int pos = archiD.buscarRegistroYOrigen(idBuscar, anioBuscar);
    if(pos == -1){
        cout<< "EL DEPORTE NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }

    reg = archiD.leerRegistro(pos);

    int anioNuevo;
    cout<< "MODIFICAR ANIO DE ORIGEN (1800-2024):";
    cin>> anioNuevo;
    if (anioNuevo < 1800 || anioNuevo > 2024) {
        cout << "El anio ingresado estA fuera de rango. Intente nuevamente." << endl;
        return false;
    }

    Fecha fmod = reg.getFechaOrigen();
    fmod.setAnio(anioNuevo);
    reg.setFechaOrigen(fmod);
    bool seModifico = archiD.modificarRegistro(pos, reg);

    if (seModifico) {
        cout << "Anio de origen modificado correctamente." << endl;
    } else {
        cout << "No se pudo modificar el anio de origen." << endl;
    }

    return seModifico;
}

bool elimiarDeporte(){
    ArchivoDeportes archiD("deportes.dat");
    int idBuscar;
    int pos;
    cout<< "INGRESAR ID A DAR DE BAJA:"<<endl;
    cin>> idBuscar;
    pos = archiD.buscarRegistro(idBuscar);
    if(pos == -1){
        cout<< "EL DEPORTE NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    Deporte reg = archiD.leerRegistro(pos);
    reg.Mostrar();
    reg.setEstado(false);
    bool seModifico = archiD.modificarRegistro(pos, reg);
    if(seModifico == true){
        cout<<endl;
        cout<< "BAJA DE DEPORTE REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<< "ERROR, NO SE PUDO BORRAR EL DEPORTE SOLICITADO";
    }
    cout<<endl;
    return true;

}

bool  verificarIdDeporte(int id){
    ArchivoDeportes archiD("deportes.dat");
    Deporte reg;
    int cantReg = archiD.contarRegistros();
    for(int i = 0; i <cantReg; i++){
        reg = archiD.leerRegistro(i);
        int pos = archiD.buscarRegistro(id);
        if(pos == -1 && reg.getIdDeporte() == id){
            return true;
        }
    }
    return false;
}


#endif // MENUDEPORTES_H_INCLUDED
