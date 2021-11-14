#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "lectorPersonasTexto.h"
#include "excepciones/excepcionNoSePuedeAbrirArchivo.h"

LectorPersonasTexto::LectorPersonasTexto(std::string nombreArchivo)
{

    archivoEntrada.open(nombreArchivo, std::ifstream::in);

    if (!archivoEntrada.is_open())
    {
        throw new ExcepcionNoSePuedeAbrirArchivo();
    }
}

std::vector<Persona> LectorPersonasTexto::cargarPersonas()
{

    // Vector para almacenar las personas
    std::vector<Persona> personasLeidas;

    // Leer línea por línea el archivo
    std::string linea{""};

    int id{0};
    std::string nombre{""};
    std::string apellido{""};
    std::string correo{""};

    while (std::getline(archivoEntrada, linea))
    {

        // Procesamos la línea
        std::istringstream stream(linea);

        id = 0;
        nombre = "";
        apellido = "";
        correo = "";

        stream >> id >> nombre >> apellido >> correo;

        //Se crea la persona
        Persona personaTemporal{id, nombre, apellido, correo};
        personasLeidas.push_back(personaTemporal);
    }

    return personasLeidas;
}

void LectorPersonasTexto::Cerrar()
{
    archivoEntrada.close();
}