#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
#include <vector>

using namespace std;

class ListaProductos{
    public:
    vector <Producto> VecProductos;
    string nnombre;
    string marca;
    string nSerie;
    int Precio;
    int Cantidad;
    string Categoria;
    Producto nProducto;
    ListaProductos();

    void imprime();

    void agregar();

    void eliminar();

    void modificar();

    void filtro();

    void extraer();

    void agregaraBasedeDatos(string,string,string,int,int,string);
};