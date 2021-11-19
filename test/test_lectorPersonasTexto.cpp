#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/lectorPersonasTexto.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"

using namespace std;

namespace
{
    TEST(LectorPersonasTexto, Prueba_CargarPersonas)
    {

        std::vector<Persona> personasLeidas;

        LectorPersonasTexto archivoEntrada{"prueba.txt"};
        personasLeidas = archivoEntrada.cargarPersonas();
        archivoEntrada.cerrar();

        EXPECT_EQ(personasLeidas[0].obtenerId(), 11);
        EXPECT_EQ(personasLeidas[0].obtenerNombre(), "nombre01");
        EXPECT_EQ(personasLeidas[0].obtenerApellido(), "apellido01");
        EXPECT_EQ(personasLeidas[0].obtenerCorreo(), "prueba01@prueba.com");

        EXPECT_EQ(personasLeidas[1].obtenerId(), 12);
        EXPECT_EQ(personasLeidas[1].obtenerNombre(), "nombre02");
        EXPECT_EQ(personasLeidas[1].obtenerApellido(), "apellido02");
        EXPECT_EQ(personasLeidas[1].obtenerCorreo(), "prueba02@prueba.com");

        EXPECT_EQ(personasLeidas[2].obtenerId(), 13);
        EXPECT_EQ(personasLeidas[2].obtenerNombre(), "nombre03");
        EXPECT_EQ(personasLeidas[2].obtenerApellido(), "apellido03");
        EXPECT_EQ(personasLeidas[2].obtenerCorreo(), "prueba03@prueba.com");
    }

    TEST(LectorPersonasTexto, Prueba_ExcepcionNoSePuedeAbrirArchivo)
    {
        EXPECT_THROW({
            LectorPersonasTexto archivoEntrada{"no_existo.txt"};
        },
                     ExcepcionNoSePuedeAbrirArchivo);
    }

    TEST(LectorPersonasTexto, Prueba_Cerrar)
    {
        LectorPersonasTexto archivoEntrada{"prueba.txt"};
        bool seCerroBien = archivoEntrada.cerrar();

        EXPECT_EQ(seCerroBien, true);
    }
}