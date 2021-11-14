#ifndef UNIT_TEST

#include <iostream>
#include <fstream>
#include <vector>

#include "persona.h"
#include "lectorPersonasTexto.h"
#include "escritorPersonas.h"

#include "excepciones/excepcionNoSePuedeAbrirArchivo.h"

#include "string.h"

int main()
{

    std::vector<Persona> personasLeidas;

    //Código para leer las personas en la variable personasLeidas
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

    //Código para escribir las personasLeidas en el archivo binario.
    try
    {
        //Se intenta abrir el archivo
        EscritorPersonas archivoSalida{"C:\\Users\\luis2\\Desktop\\personas.dat"};

        //Se agregan las personas al archivo binario
        archivoSalida.agregarVariasPersonas(personasLeidas);

        //Se cierra el archivo
        archivoSalida.cerrar();
    }
    catch (const ExcepcionNoSePuedeAbrirArchivo &excepcion)
    {
        std::cerr << "Error leyendo el archivo. " << excepcion.what() << '\n';
        return -1;
    }

    return 0;
}

#endif