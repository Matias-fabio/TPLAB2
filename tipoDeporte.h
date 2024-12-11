#ifndef TIPODEPORTE_H_INCLUDED
#define TIPODEPORTE_H_INCLUDED

class TipoDeporte{
private:
    int IdTipo;
    char nombreTipo[30];
    int nivelDificultad;
    bool estado;
public:
    ///GETS
    int getIdTipo(){return IdTipo;}
    const char* getNombreTipo(){return nombreTipo;}
    int getDificultad(){return nivelDificultad;}
    bool getEstado(){return estado;}
    ///SETS
    void setIdTipo(int iT){IdTipo = iT;}
    void setNombreTipo(const char* nt){strcpy(nombreTipo, nt);}
    void setDificultad(int d){
        if(d > 0 && d < 9){
            nivelDificultad = d;
        }
    }
    void setEstado(bool e){estado = e;}
    void Cargar(int idT = 0) {
        // if (IdTipo == idT) {
        //     cout << "ID TIPO: ";
        //     cin >> IdTipo;
        // } else {
        //     IdTipo = idT;
        // }
        cout << "NOMBRE TIPO: ";
        cargarCadena(nombreTipo, 29);
        cout << "NIVEL DE DIFICULTAD (1-8): ";
        cin >> nivelDificultad;
        if (nivelDificultad < 1 || nivelDificultad > 8) {
            cout << "Nivel de dificultad no válido. Registro no cargado." << endl;
            estado = false;
            return;
        }

        estado = true;
    }
    void Mostrar(){
        if(estado == true){
        cout<< "ID TIPO: "<< IdTipo<<endl;
        cout<< "NOMBRE TIPO: "<<nombreTipo<<endl;
        cout<< "NIVEL DE DIFICULTAD: "<<nivelDificultad<<endl;
        }
    }

};

class ArchivoTipoDeportes{
private:
    char nombre[30];
public:
    ArchivoTipoDeportes(const char *n){
            strcpy(nombre, n);
    }
    TipoDeporte leerRegistro(int pos){
        TipoDeporte reg;
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
        return tam/sizeof(TipoDeporte);
    }

    int obtenerUltimoId() {
        FILE* p = fopen(nombre, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        if (ftell(p) == 0) {
            fclose(p);
            return 0; // No hay registros
        }
        int pos = (ftell(p) / sizeof(TipoDeporte)) - 1;
        fclose(p);
        TipoDeporte ultimo = leerRegistro(pos);
        return ultimo.getIdTipo();
    }
    
    bool grabarRegistro(TipoDeporte reg){
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
    bool listarTipoDeporte();
    int buscarRegistro(int id);
    bool modificarRegistro(int pos, TipoDeporte reg);
    ///int buscarRegistroYNombre(int id, const char *n);

};

bool ArchivoTipoDeportes::listarTipoDeporte(){
    TipoDeporte reg;
    FILE *p = fopen(nombre, "rb");
    if(p == NULL)return false;
    while(fread(&reg, sizeof reg, 1, p) == 1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}


int ArchivoTipoDeportes::buscarRegistro(int id){
    TipoDeporte reg;
    FILE *p = fopen(nombre, "rb");
    if(p == NULL) return -2;
    int cont = 0;
    while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getIdTipo() == id){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

bool ArchivoTipoDeportes::modificarRegistro(int pos, TipoDeporte reg){
    FILE *p = fopen(nombre, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof (TipoDeporte)* pos, 0);
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

/*int ArchivoTipoDeportes::buscarRegistroYNombre(int id, const char *n){
    TipoDeporte reg;
    FILE *p = fopen(nombre, "rb");
    if(p == NULL) return -2;
    int cont = 0;
    while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getIdEquipo() == id && strcmp(reg.getNombreEquipo(), n)== 0){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}*/



#endif // TIPODEPORTE_H_INCLUDED






