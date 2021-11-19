#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/escritorPersonas.h"
#include "../src/lectorPersonas-ProgramaLector.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "../src/excepciones/excepcionPersonaNoExiste.h"

using namespace std;

namespace
{

    TEST(Persona, Prueba_ObtenerId)
    {
        Persona personaPrueba{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        EXPECT_EQ(personaPrueba.obtenerId(), 11);
    }

    TEST(Persona, Prueba_ObtenerNombre)
    {
        Persona personaPrueba{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        EXPECT_EQ(personaPrueba.obtenerNombre(), "nombre01");
    }

    TEST(Persona, Prueba_ObtenerApellido)
    {
        Persona personaPrueba{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        EXPECT_EQ(personaPrueba.obtenerApellido(), "apellido01");
    }

    TEST(Persona, Prueba_ObtenerCorreo)
    {
        Persona personaPrueba{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        EXPECT_EQ(personaPrueba.obtenerCorreo(), "prueba01@prueba.com");
    }
}