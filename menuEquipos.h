#ifndef MENUEQUIPOS_H_INCLUDED
#define MENUEQUIPOS_H_INCLUDED

void menuEquipos();
void agregarEquipo();
bool listarPorIdEquipo();
void listarTodosLosEquipos();
bool modificarNombre();
bool elimiarEquipo();

void menuEquipos(){
    int opc;
    system("cls");
    while(true){
        cout<< "    MENU EQUIPOS    " <<endl;
        cout<< "------------------------"<<endl;
        cout<< "1. AGREGAR EQUIPO"<<endl;
        cout<< "2. LISTAR EQUIPO POR ID"<<endl;
        cout<< "3. LISTAR TODOS LOS EQUIPOS"<<endl;
        cout<< "4. MODIFICAR NOMBRE"<<endl;
        cout<< "5. ELIMINAR EQUIPO"<<endl;
        cout<< "------------------------"<<endl;
        cout<< "0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<< "INGRESAR OPCION: ";
        cin>> opc;
        system("cls");
        switch(opc){
        case 1: agregarEquipo();
            break;
        case 2:listarPorIdEquipo();
            break;
        case 3: listarTodosLosEquipos();
            break;
        case 4: modificarNombre();
            break;
        case 5: elimiarEquipo();
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


// void agregarEquipo(){
//     Equipo reg;
//     ArchivoEquipos archiE("equipos.dat");
//     reg.Cargar();
//     bool agregar = archiE.grabarRegistro(reg);
//     if(agregar == true){
//         cout<< "Equipo agregado";
//     }
//     else{
//         cout<< "No se puede agregar el registro"<<endl;
//     }
// }


void agregarEquipo() {
    Equipo reg;
    ArchivoEquipos archiE("equipos.dat");
    int id = archiE.obtenerUltimoId() + 1;
    cout << "ID DE EQUIPO: " << id << endl;
    reg.setIdEquipo(id);
    reg.Cargar(id);
    if (reg.getEstado()) { 
        bool agregar = archiE.grabarRegistro(reg);
        if (agregar) {
            cout << "Registro agregado" << endl;
        } else {
            cout << "No se pudo agregar el registro" << endl;
        }
    } else {
        cout << "Registro no valido. No se agrega." << endl;
    }
}
bool listarPorIdEquipo(){
    ArchivoEquipos archiE("equipos.dat");
    int idBuscar;
    cout<< "INGRESAR ID DE EQUIPO A BUSCAR:"<<endl;
    cin>> idBuscar;
    int pos = archiE.buscarRegistro(idBuscar);
    if(pos == -1){
        cout<< "EL EQUIPO NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    Equipo reg = archiE.leerRegistro(pos);
    cout<< "-----------------------------"<<endl;
    reg.Mostrar();
    return true;

}
void listarTodosLosEquipos(){
    ArchivoEquipos archiE("equipos.dat");
    archiE.listarEquipos();

}
bool modificarNombre(){
    ArchivoEquipos archiE("equipos.dat");
    Equipo reg;
    int idBuscar;
    char nombreBuscar[30];
    cout<< "INGRESAR ID :"<<endl;
    cin>> idBuscar;
    cout<< "INGRESAR NOMBRE :"<<endl;
    cargarCadena(nombreBuscar, 29);
    int pos = archiE.buscarRegistroYNombre(idBuscar, nombreBuscar);
    if(pos == -1){
        cout<< "EL EQUIPO NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    reg = archiE.leerRegistro(pos);
    char nombreNuevo[30];
    cout<< "MODIFICAR NOMBRE:"<<endl;
    cargarCadena(nombreNuevo,29);
    reg.setNombreEquipo(nombreNuevo);
    bool seModifico = archiE.modificarRegistro(pos, reg);
    return seModifico;
}
bool elimiarEquipo(){
    ArchivoEquipos archiE("equipos.dat");
    int idBuscar;
    int pos;
    cout<< "INGRESAR ID DE EQUIPO A DAR DE BAJA:"<<endl;
    cin>> idBuscar;
    pos = archiE.buscarRegistro(idBuscar);
    if(pos == -1){
        cout<< "EL EQUIPO NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    Equipo reg = archiE.leerRegistro(pos);
    reg.Mostrar();
    reg.setEstado(false);
    bool seModifico = archiE.modificarRegistro(pos, reg);
    if(seModifico == true){
        cout<<endl;
        cout<< "BAJA DE EQUIPO REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<< "ERROR, NO SE PUDO BORRAR EL EQUIPO SOLICITADO";
    }
    cout<<endl;
    return true;

}

#endif // MENUEQUIPOS_H_INCLUDED
