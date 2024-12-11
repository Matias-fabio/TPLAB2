#ifndef MENUTIPODEPORTE_H_INCLUDED
#define MENUTIPODEPORTE_H_INCLUDED

void menuTipoDeporte();
void agregarTipoDeporte();
bool listarTipoPorID();
void listarTodosLosTipos();
bool modificarDificultad();
bool elimiarTipo();





void menuTipoDeporte(){
    int opc;
    system("cls");
    while(true){
        cout<< "    MENU TIPO DE DEPORTE    "<<endl;
        cout<< "------------------------"<<endl;
        cout<< "1. AGREGAR TIPO"<<endl;
        cout<< "2. LISTAR TIPO POR ID"<<endl;
        cout<< "3. LISTAR TODOS LOS TIPOS"<<endl;
        cout<< "4. MODIFICAR NIVEL DE DIFICULTAD"<<endl;
        cout<< "5. ELIMINAR REGISTRO"<<endl;
        cout<< "------------------------"<<endl;
        cout<< "0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<< "INGRESAR OPCION: ";
        cin>> opc;
        system("cls");
        switch(opc){
        case 1: agregarTipoDeporte();
            break;
        case 2:listarTipoPorID();
            break;
        case 3: listarTodosLosTipos();
            break;
        case 4: if(modificarDificultad() == true){
            system("cls");
            cout<< "EL NIVEL SE MODIFICO CORRECTAMENTE"<<endl;
        };
            break;
        case 5: elimiarTipo();
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
// void agregarTipoDeporte(){
//     TipoDeporte reg;
//     ArchivoTipoDeportes archiTp("tipoDeportes.dat");
//     reg.Cargar();
//     bool agregar = archiTp.grabarRegistro(reg);
//     if(agregar == true){
//         cout<< "Tipo de deporte  agregado";
//     }
//     else{
//         cout<< "No se puede agregar el registro"<<endl;
//     }
// }

void agregarTipoDeporte() {
    TipoDeporte reg;
    ArchivoTipoDeportes archiTD("tipoDeportes.dat");
    int id = archiTD.obtenerUltimoId() + 1;
    cout << "ID DE TIPO: " << id << endl;
    reg.setIdTipo(id);
    reg.Cargar(id);
    if (reg.getEstado()) { 
        bool agregar = archiTD.grabarRegistro(reg);
        if (agregar) {
            cout << "Registro agregado" << endl;
        } else {
            cout << "No se pudo agregar el registro" << endl;
        }
    } else {
        cout << "Registro no válido. No se agrega." << endl;
    }
}

bool listarTipoPorID(){
    ArchivoTipoDeportes archiTD("tipoDeportes.dat");
    int idBuscar;
    cout<< "INGRESAR ID DE TIPO A BUSCAR:"<<endl;
    cin>> idBuscar;
    int pos = archiTD.buscarRegistro(idBuscar);
    if(pos == -1){
        cout<< "EL TIPO DE DEPORTE NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    TipoDeporte reg = archiTD.leerRegistro(pos);
    cout<< "-----------------------------"<<endl;
    reg.Mostrar();
    return true;

}
void listarTodosLosTipos(){
    ArchivoTipoDeportes archiTD("tipoDeportes.dat");
    archiTD.listarTipoDeporte();

}

bool modificarDificultad(){
    ArchivoTipoDeportes archiTD("tipoDeportes.dat");
    TipoDeporte reg;
    int idBuscar;
    cout<< "INGRESAR ID :"<<endl;
    cin>> idBuscar;
    int pos = archiTD.buscarRegistro(idBuscar);
    if(pos == -1){
        cout<< "EL TIPO DE DEPORTE NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    reg = archiTD.leerRegistro(pos);
    int nuevoNivel;
    cout<< "MODIFICAR NIVEL DE DIFICULTAD:"<<endl;
    cin>> nuevoNivel;
    if(nuevoNivel >=1 && nuevoNivel <= 8){
        reg.setDificultad(nuevoNivel);
    }
    else{
        cout<< "El nivel ingresado es incorrecto(rangos entre 1 y 8) intente nuevamente"<<endl;
    }
    bool seModifico = archiTD.modificarRegistro(pos, reg);
    return seModifico;
}

bool elimiarTipo(){
    ArchivoTipoDeportes archiTD("tipoDeportes.dat");
    int idBuscar;
    int pos;
    cout<< "INGRESAR ID DE TIPO DE DEPORTE A DAR DE BAJA:"<<endl;
    cin>> idBuscar;
    pos = archiTD.buscarRegistro(idBuscar);
    if(pos == -1){
        cout<< "EL TIPO INGRESADO NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    TipoDeporte reg = archiTD.leerRegistro(pos);
    reg.Mostrar();
    reg.setEstado(false);
    bool seModifico = archiTD.modificarRegistro(pos, reg);
    if(seModifico == true){
        cout<<endl;
        cout<< "BAJA DE TIPO DE DEPORTE REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<< "ERROR, NO SE PUDO BORRAR EL TIPO SOLICITADO";
    }
    cout<<endl;
    return true;

}

#endif // MENUTIPODEPORTE_H_INCLUDED
