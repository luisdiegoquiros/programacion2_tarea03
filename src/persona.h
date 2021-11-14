#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
    int id;
    char nombre[15];
    char apellido[15];
    char correo[50];

    public:
    Persona(int id, std::string nombre, std::string apellido, std::string correo);
    Persona();
};


#endif