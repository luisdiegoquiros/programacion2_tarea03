#include "persona.h"
#include <cstring>

Persona::Persona(int id, std::string nombre, std::string apellido, std::string correo) {
    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->apellido, apellido.c_str());
    strcpy(this->correo, correo.c_str());
}


Persona::Persona() {
    this->id = 0;    
    strcpy(this->nombre, "");
    strcpy(this->apellido, "");
    strcpy(this->correo, "");
}
