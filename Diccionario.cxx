#ifndef __DICCIONARIO__CXX__
#define __DICCIONARIO__CXX__

#include "Diccionario.h"
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <iostream>

std::vector<std::string> Diccionario::obtenerPalabras() {
    return palabras;
}

bool Diccionario::verificarPalabra(std::string palabra) {
    for (char c : palabra) {
        if (!isalpha(c)) { // Comprueba si el carácter no es una letra
            return false;
        }
    }
    return true;
}

void Diccionario::agregarPalabra(std::string palabra) {
    if (verificarPalabra(palabra)) {
        palabras.push_back(palabra);
    } else {
        std::cout << "La palabra no es válida" << std::endl;
    }
}

bool Diccionario::iniDiccionario(std::string diccionario) {
    std::ifstream archivo(diccionario);

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return false;
    }

    // Lee el archivo línea por línea e imprime su contenido
    std::string linea;
    while (std::getline(archivo, linea)) {
        if (verificarPalabra(linea)) {
            palabras.push_back(linea);
        }
    }
    return true;
    // Cierra el archivo
    archivo.close();
}
#endif