#ifndef LECTOR_PERSONAS_TEXTO_H
#define LECTOR_PERSONAS_TEXTO_H

#include "persona.h"

#include <string>
#include <fstream>
#include <vector>

class LectorPersonasTexto {

    std::ifstream archivoEntrada;

    public:
    LectorPersonasTexto(std::string nombreArchivo);
    std::vector<Persona> cargarPersonas();
    bool cerrar();
};

#endif