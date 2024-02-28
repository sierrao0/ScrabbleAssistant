#ifndef __DICCIONARIO__H__
#define __DICCIONARIO__H__

#include <vector>
#include <string>

class Diccionario{
    protected:
    std::vector<std::string> palabras;
    std::vector<std::string> palabrasInversas;
    public:
    std:: vector<std::string> obtenerPalabras();
    bool verificarPalabra(std::string palabra);
    void agregarPalabra(std::string palabra);
    bool iniDiccionario(std::string diccionario);
    bool iniDiccionarioInverso(std::string diccionario);
    int puntuarPalabra(std::string palabra);
    void printDiccionario();
    void printDiccionarioInverso();
};

#include "Diccionario.cxx"

#endif