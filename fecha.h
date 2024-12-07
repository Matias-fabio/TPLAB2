#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED



class Fecha{
private:
    int dia, mes, anio;

    bool esBisiesto(int anio) {
        return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    }

    bool esFechaValida(int d, int m, int a) {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > 31 ) return false;
        if (a < 2024) return false;

        if (m == 2) {
            if (esBisiesto(a)) {
                return d <= 29;
            } else {
                return d <= 28;
            }
        }

        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return d <= 30;
        }

        return d <= 31;
    }

public:
    void Cargar(int d = 0, int m = 0, int a = 0) {
        cout << "DIA: ";
        cin >> d;
        cout << "MES: ";
        cin >> m;
        cout << "ANIO: ";
        cin >> a;

        if (esFechaValida(d, m, a)) {
            dia = d;
            mes = m;
            anio = a;
            cout << "Fecha correcta." << endl;
        } else {
            cout << "Fecha ingresada incorrecta." << endl;
            dia = mes = anio = 0; // reset to default value
        }
    }

    void Mostrar() {
        if (dia != 0 && mes != 0 && anio != 0) {
            cout << dia << "/";
            cout << mes << "/";
            cout << anio << endl;
        } else {
            cout << "Fecha no válida" << endl;
        }
    }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }

    void setDia(int d) {
        if (esFechaValida(d, mes, anio)) {
            dia = d;
        } else {
            cout << "Dia ingresado incorrecto" << endl;
        }
    }

    void setMes(int m) {
        if (esFechaValida(dia, m, anio)) {
            mes = m;
        } else {
            cout << "Mes ingresado incorrecto" << endl;
        }
    }

    void setAnio(int a) {
        if (esFechaValida(dia, mes, a)) {
            anio = a;
        } else {
            cout << "El año ingresado es incorrecto" << endl;
        }
    }
};

#endif // FECHA_H_INCLUDED


