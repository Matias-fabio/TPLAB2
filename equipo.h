#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED


class Equipo{
private:
    int idEquipo;
    char nombre[30];
    int nivel;
    bool estado;

public:

    ///GETS
    int getIdEquipo(){return idEquipo;}
    const char* getNombreEquipo(){return nombre;}
    int getNivel(){return nivel;}
    bool getEstado(){return estado;}

    ///SETS
    void setIdEquipo(int iE){idEquipo = iE;}
    void setNombreEquipo(const char* n){strcpy(nombre, n);}
    void setNivel(int lvl){
        if (lvl > 0 && lvl < 4){
            nivel = lvl;
        }
    }
    void setEstado(bool e){estado = e;}

    void Cargar(int idE = 0){
        if(idEquipo == idE){
            cout<< "INGRESAR ID DE EQUIPO: ";
            cin>> idEquipo;
        }
        else{
            idEquipo = idE;
        }
        cout<< "NOMBRE DEL EQUIPO:";
        cin>>nombre;
        cout<< "NIVEL";
        cin>>nivel;
        estado = true;
    }

    void Mostrar(){
        if(estado == true){
        cout<< "------------------------------------------"<<endl;
        cout<<endl;
        cout<< "ID DE EQUIPO: "<< idEquipo<<endl;
        cout<< "NOMBRE DEL EQUIPO: "<< nombre<<endl;
        cout<< "NIVEL: " << nivel<<endl;
        }
    }
};


class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){
            strcpy(nombre, n);
    }
    
    Equipo leerRegistro(int pos){
        Equipo reg;
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
        return tam/sizeof(Equipo);
    }
    bool grabarRegistro(Equipo reg){
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
    bool listarEquipos();
    int buscarRegistro(int id);
    bool modificarRegistro(int pos, Equipo reg);
    int buscarRegistroYNombre(int id, const char *n);

};

bool ArchivoEquipos::listarEquipos(){
    Equipo reg;
    FILE *p = fopen(nombre, "rb");
    if(p == NULL)return false;
    while(fread(&reg, sizeof reg, 1, p) == 1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

int ArchivoEquipos::buscarRegistro(int id){
    Equipo reg;
    FILE *p = fopen(nombre, "rb");
    if(p == NULL) return -2;
    int cont = 0;
    while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getIdEquipo()== id){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

bool ArchivoEquipos::modificarRegistro(int pos, Equipo reg){
    FILE *p = fopen(nombre, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof (Equipo)* pos, 0);
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoEquipos::buscarRegistroYNombre(int id, const char *n){
    Equipo reg;
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
}

#endif // EQUIPO_H_INCLUDED
