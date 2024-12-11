#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED


#include "tipoDeporte.h"

class Deporte{
    private:
        int idDeporte; // autoIncrementable
        char nombre[30];
        int tipoDeporte; // num entre 1 y 21
        Fecha origen; // num entre 1800 y fecha actual
        bool estado;

    public:
        void setIdDeporte(int id){idDeporte = id;}
        void setNombre(const char* nom){strcpy(nombre,nom);}
        void setTipoDeporte(int dep){
            if(dep >= 1 && dep <=21){
                tipoDeporte = dep;
            }
            else{
                cout<< "EL TIPO DE DEPORTE INGRESADO NO EXISTE"<<endl;
            }
        }
        void setFechaOrigen(Fecha ori){
            if(ori.getAnio() >= 1800 && ori.getAnio() <= 2024){
                origen = ori;
            }
            else{
                cout<< "FECHA INGRESADA FUERA DE RANGO"<<endl;
            }
        }
        void setEstado(bool e){estado = e;}

        int getIdDeporte(){return idDeporte;}
        const char* getNombre(){return nombre;}
        int getTipoDeporte(){return tipoDeporte;}
        Fecha getFechaOrigen(){return origen;}
        bool getEstado(){return estado;}

    void Cargar() {
        cout << "Nombre: ";
        cargarCadena(nombre, 29);
        cout << "Tipo de deporte (1-21): ";
        cin >> tipoDeporte;
        if (!idTipoExiste(tipoDeporte)) {
            cout << "El ID de tipo de deporte ingresado no existe. Registro no cargado." << endl;
            estado = false;
            return;
        }
        cout << "Fecha de origen: ";
        origen.Cargar();
        if (origen.getAnio() < 1800 || origen.getAnio() > 2024) {
            cout << "Fecha ingresada fuera de rango." << endl;
            estado = false;
            return;
        }

        estado = true;
    }
    void Mostrar(){
            if(estado == true){
                cout<< "ID de deporte: "<<idDeporte<<endl;
                cout<< "Nombre: "<<nombre<<endl;
                cout<< "Tipo de deporte: "<<tipoDeporte<<endl;
                cout<< "Fecha de origen: "<<endl;
                origen.Mostrar();

            }

        }
    bool idTipoExiste(int idTipo) {
        ArchivoTipoDeportes archivo("tipoDeportes.dat");
        return archivo.buscarRegistro(idTipo) >= 0;
    }

};


class ArchivoDeportes
{
private:
    char nombre[30];
public:
    ArchivoDeportes(const char* n){
        strcpy(nombre, n);
    }

    Deporte leerRegistro(int pos){
        Deporte reg;
        reg.setEstado(false);
        FILE *p = fopen(nombre, "rb");
        if( p  == NULL) return reg;
        fseek(p, sizeof reg * pos, 0);
        fread(&reg, sizeof reg ,1 ,p);
        fclose(p);
        return reg;
    }

    int contarRegistros(){
        FILE *p = fopen(nombre,"rb");
        if( p  == NULL) return -1;
        fseek(p, 0, 2);
        int tam= ftell(p);
        fclose(p);
        return tam/sizeof(Deporte);
    }

        int obtenerUltimoId() {
        FILE* p = fopen(nombre, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Deporte);
    }

    bool grabarRegistro(Deporte reg){
        FILE *p = fopen(nombre, "ab");
        if( p == NULL){
            cout<< "ERROR DE ARCHIVO"<<endl;
            return false;
        }
        int escribio = fwrite(&reg, sizeof reg, 1 , p);
        fclose(p);
        return escribio;
    }

    int buscarRegistro(int id){
        Deporte reg;
        FILE *p = fopen(nombre, "rb");
        if(p == NULL) return -2;
        int cont = 0;
        while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getIdDeporte()== id){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
    }
    
    
    int buscarRegistroYOrigen(int id, int anio){
    Deporte reg;
    FILE *p = fopen(nombre, "rb");
    if(p == NULL) return -2;
    int cont = 0;
    while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getIdDeporte()== id && reg.getFechaOrigen().getAnio() == anio){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

    bool listarDeportes(){
        Deporte reg;
        FILE *p = fopen(nombre, "rb");
        if(p == NULL)return false;
        while(fread(&reg, sizeof reg, 1, p) == 1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
    }

    bool modificarRegistro(int pos, Deporte reg){
        FILE *p = fopen(nombre, "rb+");
        if(p == NULL) return false;
        fseek(p, sizeof (Deporte)* pos, 0);
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;

    }
};




#endif // DEPORTE_H_INCLUDED
