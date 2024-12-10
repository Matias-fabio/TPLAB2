#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "deporte.h"
#include "equipo.h"
class Jugador
{
private:
    int dni;
    char nombre[30], apellido[30], email[30];
    char telefono[30];
    int claustro; /// 1:docente / 2:alumno / 3:No docente / 4:graduado
    int deporte; /// numero entr 1 y 10
    int numEquipo;
    Fecha inscripcion;
    float matricula;
    bool estado;
public:

        /// Gets
    int getDni(){return dni;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    int getClaustro(){return claustro;}
    int getDeporte(){return deporte;}
    int getNumeroEquipo(){return numEquipo;}
    Fecha getFechaInscripcion(){return inscripcion;}
    float getMatricula(){return matricula;}
    bool getEstado(){return estado;}


    /// Sets
    void setDni(int d){dni = d;}
    void setNombre( const char * nom){strcpy(nombre, nom);}
    void setApellido( const char * ap){strcpy(apellido, ap);}
    void setEmail( const char * em){strcpy(email, em);}
    void setTelefono( const char* t){strcpy(telefono, t);}

    void setClaustro(int cl){
        if(cl > 0 && cl <=4){
            claustro = cl;
        }
        else{
            cout<< "El claustro ingresado no es valido"<<endl;
        }
    }
    void setDeporte(int dep){
        if(dep > 0 && dep <= 10){
            deporte = dep;
        }
        else{
            cout<< "El deporte ingresado no es valido"<<endl;
        }
    }
    void setNumEquipo(int ne){numEquipo =ne;}
    void setFechaInscripcion(Fecha f){
        if(inscripcion.getAnio() <= 2024){
            inscripcion = f;}
        }

    void setMatricula(float mat){
        if(matricula >= 0){
            matricula = mat;
        }
    }
    void setEstado(bool e){estado = e;}

    void cargar(int d = 0) {
        if(dni == d) {
            cout << "DNI: ";
            cin >> dni;
        } else {
            dni = d;
        }
        // cambiar a while?
        do {

            cout << "CLAUSTRO (1: Docente, 2: Alumno, 3: No docente, 4: Graduado): ";
            cin >> claustro;
            if (claustro < 1 || claustro > 4) {
                cout << "Valor de claustro no valido. Intente nuevamente." << endl;
                system("pause");
                system("cls");
            }
        } while (claustro < 1 || claustro > 4);
        cout << "ID DE DEPORTE (entre 1 y 10): ";
        cin >> deporte;
        if (!idDeporteExiste(deporte)) {
            cout << "El ID de deporte ingresado no existe. Registro no cargado." << endl;
            estado = false;
            return;
        }

        cout << "ID EQUIPO: ";
        cin >> numEquipo;
        if (!idEquipoExiste(numEquipo)) {
            cout << "El ID de equipo ingresado no existe. Registro no cargado." << endl;
            estado = false;
            return;
        }
        cout << "NOMBRE:";
        cargarCadena(nombre, 29);
        cout << "APELLIDO:";
        cargarCadena(apellido, 29);
        cout << "EMAIL:";
        cargarCadena(email, 29);
        cout << "TELEFONO:";
        cargarCadena(telefono, 29);
        cout << "FECHA INSCRIPCION:";
        inscripcion.Cargar();
        if (inscripcion.getAnio() == 0 || inscripcion.getMes() == 0 || inscripcion.getDia() == 0) {
            cout << "Fecha de inscripcion incorrecta. Registro no cargado." << endl;
            estado = false;  
            return;
        }
        cout << "VALOR DE LA MATRICULA: ";
        cin >> matricula;
        if (matricula < 0) {
            cout << "Valor de matricula no valido. Registro no cargado." << endl;
            estado = false;
            return;
        }
        estado = true;
    };

   void Mostrar(){
       if(estado == true){
            cout<< "DNI: "<< dni <<endl;
            cout<< "CLAUSTRO: "<< claustro<<endl;
            cout<< "ID DE DEPORTE: "<< deporte<<endl;
            cout<< "ID EQUIPO: "<<numEquipo<<endl;
            cout<< "NOMBRE: "<< nombre<<endl;
            cout<< "APELLIDO: "<< apellido<<endl;
            cout<< "EMAIL: "<<email<<endl;
            cout<< "TELEFONO: "<<telefono<<endl;
            cout<< "FECHA INSCRIPCION: "<<endl;
            inscripcion.Mostrar();
            cout<< "VALOR DE LA MATRICULA: $ "<<matricula<<endl;
       }
   }

       bool idDeporteExiste(int idDeporte) {
        ArchivoDeportes archivo("deportes.dat");
        return archivo.buscarRegistro(idDeporte) >= 0;
    }


    bool idEquipoExiste(int idEquipo) {
        ArchivoEquipos archivo("equipos.dat");
        return archivo.buscarRegistro(idEquipo) >= 0; }
};


class ArchivoJugadores
{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *n){
        strcpy(nombre, n);
    }

    Jugador leerRegistro(int pos){
        Jugador reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Jugador);
    }
    bool grabarRegistro(Jugador reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    bool listarJugadores(){
        Jugador reg;
        FILE *p = fopen(nombre, "rb");
        if(p == NULL)return false;
        while(fread(&reg, sizeof reg, 1, p) == 1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
    }
    int buscarRegistro(int dni){
        Jugador reg;
        FILE *p = fopen(nombre, "rb");
        if(p == NULL) return -2;
        int cont = 0;
        while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getDni()== dni){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
    }
    bool modificarRegistro(int pos, Jugador reg);
};




bool ArchivoJugadores::modificarRegistro(int pos, Jugador reg){
    FILE *p = fopen(nombre, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof (Jugador)* pos, 0);
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;

}


#endif // JUGADOR_H_INCLUDED
