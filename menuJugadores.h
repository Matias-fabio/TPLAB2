#ifndef MENUJUGADORES_H_INCLUDED
#define MENUJUGADORES_H_INCLUDED
void menuJugadores();
void agregarJugador();
void listarTodosLosJugadores();
bool modificarFecha();
bool elimiarJugador();
bool listarPorDni();

void menuJugadores(){
    int opc;
    system("cls");
    while(true){
        cout<< "    MENU JUGADORES    " <<endl;
        cout<< "------------------------"<<endl;
        cout<< "1. AGREGAR JUGADOR"<<endl;
        cout<< "2. LISTAR JUGADOR POR DNI"<<endl;
        cout<< "3. LISTAR TODOS LOS JUGADORES"<<endl;
        cout<< "4. MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<< "5. ELIMINAR REGISTRO DE JUGADOR"<<endl;
        cout<< "------------------------"<<endl;
        cout<< "0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<< "INGRESAR OPCION: ";
        cin>> opc;
        system("cls");
        switch(opc){
        case 1: agregarJugador();
            break;
        case 2:listarPorDni();
            break;
        case 3: listarTodosLosJugadores();
            break;
        case 4: modificarFecha();
            break;
        case 5: elimiarJugador();
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


void agregarJugador() {
    Jugador reg;
    ArchivoJugadores archiJ("jugadores.dat");
    int dni;
    cout << "DNI: ";
    cin >> dni;
    int pos = archiJ.buscarRegistro(dni);
    if (pos == -1) {
        reg.cargar(dni);
        if (reg.getEstado()) { 
            bool agregar = archiJ.grabarRegistro(reg);
            if (agregar) {
                cout << "Registro agregado" << endl;
            } else {
                cout << "No se pudo agregar el registro" << endl;
            }
        } else {
            cout << "Registro no valido. No se agrega." << endl;
        }
    } else {
        cout << "YA EXISTE UN JUGADOR CON ESE NUMERO DE DNI" << endl;
    }
}




bool listarPorDni(){
    ArchivoJugadores archiJ("jugadores.dat");
    int dniBuscar;
    cout<< "INGRESAR DNI A BUSCAR:"<<endl;
    cin>> dniBuscar;
    int pos = archiJ.buscarRegistro(dniBuscar);
    if(pos == -1){
        cout<< "EL JUGADOR NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    Jugador reg = archiJ.leerRegistro(pos);
    cout<< "-----------------------------"<<endl;
    reg.Mostrar();
    return true;
}

void listarTodosLosJugadores(){
    ArchivoJugadores archiJ("jugadores.dat");
    Jugador reg;
    int CantReg = archiJ.contarRegistros();
    for (int i = 0; i < CantReg; i++)
    {
        reg = archiJ.leerRegistro(i);
        cout<< "---------------------"<<endl;
        cout<<endl;
        reg.Mostrar();
    }


}

bool modificarFecha(){
    ArchivoJugadores archiJ("jugadores.dat");
    Jugador reg;
    int dniBuscar;
    Fecha nuevaFecha;
    cout<< "INGRESAR DNI :"<<endl;
    cin>> dniBuscar;
    int pos = archiJ.buscarRegistro(dniBuscar);
    if(pos == -1){
        cout<< "EL JUGADOR NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    reg = archiJ.leerRegistro(pos);
    cout<< "MODIFICAR FECHA DE INSCRIPCION:"<<endl;
    nuevaFecha.Cargar();
    reg.setFechaInscripcion(nuevaFecha);
    bool seModifico = archiJ.modificarRegistro(pos, reg);
    return seModifico;

}


bool elimiarJugador(){
    ArchivoJugadores archiJ("jugadores.dat");
    int dniBuscar;
    int pos;
    cout<< "INGRESAR DNI A DAR DE BAJA:"<<endl;
    cin>> dniBuscar;
    pos = archiJ.buscarRegistro(dniBuscar);
    if(pos == -1){
        cout<< "EL JUGADOR NO SE ENCUENTRA REGISTRADO"<<endl;
        return false;
    }
    else{
        if(pos == -2){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
    }
    Jugador reg = archiJ.leerRegistro(pos);
    reg.Mostrar();
    reg.setEstado(false);
    bool seModifico = archiJ.modificarRegistro(pos, reg);
    if(seModifico == true){
        cout<<endl;
        cout<< "BAJA DE JUGADOR REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<< "ERROR, NO SE PUDO BORRAR AL JUGADOR";
    }
    cout<<endl;
    return true;

}


#endif // MENUJUGADORES_H_INCLUDED



