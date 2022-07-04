#pragma once
#include <string>
#include <iostream>
#include "Persona.h"

using namespace std;

class Correo:public Persona{
	public:
		string nombre;
		string DNI;
		string correo;
		string direccion;
		string telefono;

        Correo();

        Correo(string , string , string , string , string, int );
		Correo(Persona &o);
        void imprime(Persona &o);
};