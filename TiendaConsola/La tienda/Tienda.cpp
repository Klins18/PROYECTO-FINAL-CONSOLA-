
#include <iostream>
#include <string.H>
#include <vector>
#include <windows.h> // Libreria que contiene las funciones de Winapi

/* Includes aqui para evitar confusiones eh?*/

#include "Persona.h"
#include "Producto.h"
#include "Administrador.h"
#include "ListaProductos.h"
#include "Cliente.h"
#include "Correo.h"

using namespace std;

void menu(){
    cout << "\t\tBienvenido a la tienda! :D" << endl;
    cout << "Elija entre alguna de estas opciones" << endl;
    cout << "[1] Ingresar como Usuario" << endl;
    cout << "[2] Ingresar como Admin" << endl;
    cout << "[3] Salir" << endl;
}

int main(){
    // Para crear una persona (nombre, DNI, correo, direccion, telefono)
    Persona Manu = Persona("Manu","92322","jacintopichimawido25@gmail.com","idk","923121311");
    Manu.imprime();

    //Para crear un producto (nombre, marca, nSerie, precio, cantidad, categoria)
    Producto Laptop = Producto("Laptop","Lenovo","201",1200,10,"Tec");
    Laptop.imprime();

    Admin ManuAdmin = Admin("Manu","92322","jacintopichimawido25@gmail.com","idk","923121311", "29", "Manu");
    ManuAdmin.imprime();

    Cliente ManuCliente = Cliente("Manu","92322","jacintopichimawido25@mail.com","idk","923123131","29","Manu", 2000);

    //Para crear un vector vector <tipo> nombre;
    vector <Admin> VecAdmins;
    //Reserva 10 espacios (sino, al alcanzar su capacidad maxima se duplica)
    VecAdmins.reserve(10);
    //Me agrego como admin XD
    VecAdmins.push_back(ManuAdmin);

    vector <Cliente> VecClientes;
    //Reserva 10 espacios (sino, al alcanzar su capacidad maxima se duplica)
    VecClientes.reserve(10);
    //Me agrego como admin XD
    VecClientes.push_back(ManuCliente);
    
    //vector <Producto> VecProductos;
    // Reservasdo 100 espacios para el vector
    //VecProductos.reserve(100);
    //VecProductos.push_back(Laptop);
    ListaProductos LProductos = ListaProductos();
    //LProductos.agregar();
    //Aqui imprime la lista de productos que tenga la lista
    //LProductos.imprime();

    //LProductos.agregar();

    //LProductos.imprime();
    //Extrae elementos de un archivo txt
    LProductos.extraer();

    //LProductos.eliminar();
    //LProductos.filtro();

    int run = 1;
    int Adm = 0;
    int Clt = 0;

    string a;
    string b;

    string Nombre;
    string Marca;
    string Serie;
    int Pprecio;
    int Ccantidad;
    string Ccategoria;

    do{
        menu();
        int r;
        cin >> r;
        switch(r){
            case 3:
                run = 0;
                cout << "Gracias por visitar la tienda, nos vemos pronto! :D " << endl;
                break;
            case 2:
                cout << "Ingrese su ID y su contraseña: " << endl;
                cin >> a;
                cin >> b;
                for(int i = 0; i < VecAdmins.size(); i++){
                    if(a == VecAdmins.at(i).getID() && b == VecAdmins.at(i).getcontraseña()){
                        Adm = 1;
                        cout << "Bienvenido Admin " << VecAdmins.at(i).nombre << "!" << endl;
                        do{
                            cout << "Que le gustaria hacer?: " << endl;
                            cout << "Elija entre alguna de estas opciones" << endl;
                            cout << "[1] Ver la lista de objetos" << endl;
                            cout << "[2] Agregar productos" << endl;
                            cout << "[3] Modificar productos" << endl;
                            cout << "[4] Eliminar productos" << endl;
                            cout << "[5] Agregar a la base de datos" << endl;
                            cout << "[6] Usar el filtro de objetos" << endl;
                            cout << "[7] Salir" << endl;
                            int r2;
                            cin >> r2;
                            switch(r2){
                                case 7:
                                    r = 0;
                                    Adm = 0;
                                    cout << "Ha salido de su cuenta" << endl;
                                    cout << endl;
                                    break;
                                case 1:
                                    LProductos.imprime();
                                    break;
                                case 2:
                                    LProductos.agregar();
                                    break;
                                case 3:
                                    LProductos.modificar();
                                    break;
                                case 4:
                                    LProductos.eliminar();
                                    break;
                                case 5:
                                    cout << "En mantenimiento" << endl;
                                    
                                    
                                    cout << "Que producto desea agregar? " << endl;
                                    cout << "Introduzcalo en el siguiente orden " << endl;
                                    cout << "Nombre, Marca, nªSerie, Precio, Cantidad, Categoria" << endl;
                                    cout << "Nombre: " << endl;
                                    cin >> Nombre,
                                    cout << "Marca: " << endl;
                                    cin >> Marca;
                                    cout << "nº de Serie: " << endl;
                                    cin >> Serie;
                                    cout << "Precio: " << endl;
                                    cin >> Pprecio;
                                    cout << "Cantidad: " << endl;
                                    cin >> Ccantidad;
                                    cout << "Categoria: " << endl;
                                    cin >> Ccategoria;
                                    cout << "Producto: " << Nombre << Marca << Serie << Pprecio << Ccantidad << Ccategoria << endl;

                                    
                                    LProductos.agregaraBasedeDatos(Nombre,Marca,Serie,Pprecio,Ccantidad,Ccategoria);
                                    break;
                                    
                                case 6:
                                    LProductos.filtro();
                                    break;
                                    
                            }
                            r2 = 0;
                        }while(Adm);
                        break;
                    }
                }
                break;
                cout << r;
            case 1:
                cout << "Ingrese su ID y su contraseña: " << endl;
                cin >> a;
                cin >> b;
                for(int i = 0; i < VecClientes.size(); i++){
                    if(a == VecClientes.at(i).getID() && b == VecClientes.at(i).getcontraseña()){
                        Clt = 1;
                        cout << "Bienvenido Cliente " << VecClientes.at(i).nombre << "!" << endl;
                        do{
                            cout << "Que le gustaria hacer?: " << endl;
                            cout << "Elija entre alguna de estas opciones" << endl;
                            cout << "[1] Ver la lista de objetos" << endl;
                            cout << "[2] Añadir al carrito de compras" << endl;
                            cout << "[3] Eliminar del carrito de compras" << endl;
                            cout << "[4] Cancelar sus pagos" << endl;
                            cout << "[5] Usar un filtro de objetos" << endl;
                            //cout << "[7] Dejar un comentario" << endl;
                            cout << "[6] Salir" << endl;
                            int r2;
                            cin >> r2;
                            switch(r2){
                                case 6:
                                    Clt = 0;
                                    r2 = 0;
                                    cout << "Ha salido de su cuenta" << endl;
                                    cout << endl;
                                    break;
                                case 1:
                                    LProductos.imprime();
                                    break;
                                case 2:
                                    VecClientes.at(i).agregar(LProductos);
                                    break;
                                case 3:
                                    VecClientes.at(i).eliminar();
                                    break;
                                case 4:
                                    VecClientes.at(i).comprar(LProductos);
                                    break;
                                case 5:
                                    LProductos.filtro();
                                    break;
                                case 7:
                                    cout << "Enviando Correo..." << endl;
                                    cout << "Registrado como " << VecClientes.at(i).correo;
                                    Correo a = Correo(VecClientes.at(i));
                                    a.imprime(VecClientes.at(i));
                                    break;
                            }       
                        }while(Clt);
                        break;
                    }
                    else{
                        cout << "ID o contraseña incorrectos" << endl;
                    }
                }
        }
        if (r != 1 || r != 2 || r == 3){
            cout << "Error, intrdoujo un numero invalido" << endl;
        }
        r = 0;
    }while(run);
        


    //LProductos.imprime();

    //LProductos.modificar();

    //ManuCliente.agregar(LProductos);

    //ManuCliente.comprar();

    //ManuCliente.imprime();
    
}