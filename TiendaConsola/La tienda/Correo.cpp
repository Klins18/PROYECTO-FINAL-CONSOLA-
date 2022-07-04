#include "Correo.h"
#include "fstream"
#include "sstream"
#include "Persona.h"

Correo::Correo(string nombre, string DNI, string correo, string direccion, string telefono, int n):Persona(nombre,DNI,correo,direccion,telefono){
    n = 0;
}
Correo::Correo(Persona &o){

}
void Correo::imprime(Persona &o){
    string linea;
    string texto;
    string l;
    char escrito[250];
    cout << endl;
    cin.get();
    getline(cin,l);

    ifstream archivo("Comentarios.txt");
        while (getline(archivo,linea)){
            texto = texto + linea+"\n";
        }
        archivo.close();

    ofstream archivo2("Comentarios.txt");
    archivo2 << texto << l << "Escrito por: " << o.nombre << " DNI: " << o.DNI << " correo: " << o.correo << " Telefono: " << o.telefono << " Direccion: " << o.direccion;
    archivo2.close();
}