#ifndef UNIT_TEST

#include <iostream>
#include <fstream>

#include "persona.h"
#include "lectorPersonasTexto.h"

#include "excepciones/excepcionNoSePuedeAbrirArchivo.h"

#include "string.h"

int main()
{

    std::vector<Persona> personasLeidas;

    try
    {
        //Se intenta abrir el archivo
        LectorPersonasTexto archivoEntrada{"C:\\personas.txt"};

        //Se carga el archivo de texto donde están las personas
        personasLeidas = archivoEntrada.cargarPersonas();

        //Se cierra el archivo
        archivoEntrada.Cerrar();
    }
    catch (const ExcepcionNoSePuedeAbrirArchivo &excepcion)
    {
        std::cerr << "Error leyendo el archivo. " << excepcion.what() << '\n';
        return -1;
    }



    
    for (Persona persona : personasLeidas)
    {
        persona.getInformaciónPersona();
    }

    return 0;
}

#endif