#ifndef __DICCIONARIO__H__
#define __DICCIONARIO__H__

#include <vector>
#include <string>

class Diccionario{
    protected:
    std::vector<std::string> palabras;
    public:
    std:: vector<std::string> obtenerPalabras();
    bool verificarPalabra(std::string palabra);
    void agregarPalabra(std::string palabra);
    bool iniDiccionario(std::string diccionario);
};

#include "Diccionario.cxx"

#endif