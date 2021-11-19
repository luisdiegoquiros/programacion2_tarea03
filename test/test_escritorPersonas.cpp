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
    TEST(EscritorPersonas, Prueba_AgregarPersona)
    {

        Persona personaPrueba{80, "Luis", "Quiros", "luis@correo.com"};

        EscritorPersonas escritor{"pruebaUnaPersona.dat"};
        escritor.agregarPersona(personaPrueba);
        escritor.cerrar();

        // Leer persona de prueba
        LectorPersonas lector{"pruebaUnaPersona.dat"};
        lector.abrirArchivo();
        Persona personaLeida = lector.leerPersonaPosicion(0);
        lector.cerrar();

        EXPECT_EQ(personaLeida.obtenerId(), 80);
        EXPECT_EQ(personaLeida.obtenerNombre(), "Luis");
        EXPECT_EQ(personaLeida.obtenerApellido(), "Quiros");
        EXPECT_EQ(personaLeida.obtenerCorreo(), "luis@correo.com");
    }

    TEST(EscritorPersonas, Prueba_AgregarVariasPersonas)
    {

        Persona personaPruebaUno{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        Persona personaPruebaDos{12, "nombre02", "apellido02", "prueba02@prueba.com"};
        Persona personaPruebaTres{13, "nombre03", "apellido03", "prueba03@prueba.com"};

        std::vector<Persona> personas;
        personas.push_back(personaPruebaUno);
        personas.push_back(personaPruebaDos);
        personas.push_back(personaPruebaTres);

        EscritorPersonas escritor{"pruebaVariasPersonas.dat"};
        escritor.agregarVariasPersonas(personas);
        escritor.cerrar();

        // Leer persona de prueba
        LectorPersonas lector{"pruebaVariasPersonas.dat"};
        lector.abrirArchivo();
        Persona personaLeidaUno = lector.leerPersonaPosicion(0);
        Persona personaLeidaDos = lector.leerPersonaPosicion(1);
        Persona personaLeidaTres = lector.leerPersonaPosicion(2);
        lector.cerrar();

        EXPECT_EQ(personaLeidaUno.obtenerId(), 11);
        EXPECT_EQ(personaLeidaUno.obtenerNombre(), "nombre01");
        EXPECT_EQ(personaLeidaUno.obtenerApellido(), "apellido01");
        EXPECT_EQ(personaLeidaUno.obtenerCorreo(), "prueba01@prueba.com");

        EXPECT_EQ(personaLeidaDos.obtenerId(), 12);
        EXPECT_EQ(personaLeidaDos.obtenerNombre(), "nombre02");
        EXPECT_EQ(personaLeidaDos.obtenerApellido(), "apellido02");
        EXPECT_EQ(personaLeidaDos.obtenerCorreo(), "prueba02@prueba.com");

        EXPECT_EQ(personaLeidaTres.obtenerId(), 13);
        EXPECT_EQ(personaLeidaTres.obtenerNombre(), "nombre03");
        EXPECT_EQ(personaLeidaTres.obtenerApellido(), "apellido03");
        EXPECT_EQ(personaLeidaTres.obtenerCorreo(), "prueba03@prueba.com");
    }

    TEST(EscritorPersonas, Prueba_ExcepcionNoSePuedeAbrirArchivo)
    {
        EXPECT_THROW({
            EscritorPersonas escritor{"NO://no_existo.dat"};
        },
                     ExcepcionNoSePuedeAbrirArchivo);
    }

    TEST(EscritorPersonas, Prueba_Cerrar)
    {
        EscritorPersonas escritor{"pruebaUnaPersona.dat"};
        bool seCerroBien = escritor.cerrar();

        EXPECT_EQ(seCerroBien, true);
    }

}