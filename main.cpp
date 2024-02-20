#include <iostream>
#include <string>

using namespace std;

class Materia{
private:
    int Clave;
    string Nombre;
    string ProfesorTit;
    string LibroTexto;
public:
    Materia(int,string,string,string);

    void Imprime();
    void CambiaClave(int);
    void CambiaProfe(string&);

    int getClaveMateria();

    bool operator==(const Materia& otra) const;
    bool operator!=(const Materia& otra) const;
    bool operator<(const Materia& otra) const;
    bool operator>(const Materia& otra) const;
    friend istream& operator>>(istream& in, Materia& materia);
    friend ostream& operator<<(ostream& out, const Materia& materia);
    Materia operator+(const Materia& otra) const;
};

Materia::Materia(int a, string b, string c, string d)
{
    Clave = a;
    Nombre = b;
    ProfesorTit = c;
    LibroTexto = d;
}

void Materia::Imprime()
{
    cout << "Clave: " << Clave << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Profesor: " << ProfesorTit << endl;
    cout << "libro: " << LibroTexto << endl;
}

void Materia::CambiaClave(int a)
{
    Clave = a;
}

void Materia::CambiaProfe(string& b)
{
    ProfesorTit = b;
}

int Materia::getClaveMateria()
{
    return Clave;
}

bool Materia::operator==(const Materia& otra) const
{
    return (Clave == otra.Clave);
}

bool Materia::operator!=(const Materia& otra) const
{
    return !(*this == otra);
}

bool Materia::operator<(const Materia& otra) const
{
    return (Clave < otra.Clave);
}

bool Materia::operator>(const Materia& otra) const
{
    return (Clave > otra.Clave);
}

istream& operator>>(istream& in, Materia& materia)
{
    in >> materia.Clave >> materia.Nombre >> materia.ProfesorTit >> materia.LibroTexto;
    return in;
}

ostream& operator<<(ostream& out, const Materia& materia)
{
    out << "Clave: " << materia.Clave << endl
        << "Nombre: " << materia.Nombre << endl
        << "Profesor: " << materia.ProfesorTit << endl
        << "Libro: " << materia.LibroTexto << endl;
    return out;
}

Materia Materia::operator+(const Materia& otra) const
{
    string nuevoNombre = this->Nombre + " + " + otra.Nombre;
    return Materia(Clave, nuevoNombre, ProfesorTit, LibroTexto);
}

enum Opciones
{
    OPC_IMPRIMIR = 1,
    OPC_CAMBIACLAVE,
    OPC_CAMBIAPROFE,
    OPC_SALIR
};

int main(){

    Materia Programacion(1234,"Ernesto","Canuto","Elprincipito");
    Materia basesDatos(9876,"Mario","Jirafales","Laodisea");

    int opc,mat,res,nue,nuevaClave;
    string nuevoPro;

    do{

    cout << "Que desea realizar: " << endl << endl
    << OPC_IMPRIMIR << ". Imprimir Datos" << endl
    << OPC_CAMBIACLAVE << ". Cambia clave" << endl
    << OPC_CAMBIAPROFE << ". Cambiar al Profesor" << endl
    << OPC_SALIR << ". Salir" << endl;

    cin >> opc;
    cin.ignore();

    switch(opc)
    {
    case OPC_IMPRIMIR:
        cout << " Imprimir datos de " << endl
             << "1. Programacion" << endl
             << "2. Bases de datos" << endl;
             cin >> mat;
             if(mat == 1)
             {
                 Programacion.Imprime();
             }
             else
                if(mat == 2)
             {
                 basesDatos.Imprime();
             }
             else
             {
                 return 1;
             }break;
    case OPC_CAMBIACLAVE:
        cout << "Cambiar clave de " << endl
             << "1. Programcion" << endl
             << "2. Bases de Datos" << endl;
             cin >> res;
             if(res == 1)
             {
                 cout << "Ingrese la nueva clave: "; cin >> nuevaClave;
                 Programacion.CambiaClave(nuevaClave);
             }
             else
             if(res == 2)
             {
                 cout << "Ingrese la nueva clave: "; cin >> nuevaClave;
                 basesDatos.CambiaClave(nuevaClave);
             }
             else
             {
                 return 1;
             }
             break;
    case OPC_CAMBIAPROFE:
        cout << "Cambia profesor de" << endl
             << "1. Programacion" << endl
             << "2. Bases de datos" << endl;
             cin >> nue;
             cin.ignore();
             if(nue == 1)
             {
                 cout << "Ingresa el nuevo profesor: ";
                 getline(cin, nuevoPro);
                 Programacion.CambiaProfe(nuevoPro);
             }
             else
                if(nue == 2)
             {
                 cout << "Ingresa el nuevo profesor: ";
                 getline(cin, nuevoPro);
                 basesDatos.CambiaProfe(nuevoPro);
             }
             else
             {
                 return 1;
             }break;
    case OPC_SALIR:
        cout << "Vuelva Pronto!" << endl;
        break;
    default:break;
    }

    }while(opc != OPC_SALIR);

    return 0;
}
