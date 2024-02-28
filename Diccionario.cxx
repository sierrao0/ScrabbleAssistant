#ifndef __DICCIONARIO__CXX__
#define __DICCIONARIO__CXX__

#include "Diccionario.h"
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <iostream>

std::vector<std::string> Diccionario::obtenerPalabras()
{
    return palabras;
}

void Diccionario::printDiccionario()
{
    for (std::vector<std::string>::iterator it = palabras.begin(); it != palabras.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void Diccionario::printDiccionarioInverso()
{
    for (std::vector<std::string>::iterator it = palabrasInversas.begin(); it != palabrasInversas.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

bool Diccionario::verificarPalabra(std::string palabra)
{
    for (char c : palabra)
    {
        if (!isalpha(c))
        { // Comprueba si el carácter no es una letra
            return false;
        }
    }
    return true;
}

void Diccionario::agregarPalabra(std::string palabra)
{
    if (verificarPalabra(palabra))
    {
        palabras.push_back(palabra);
    }
    else
    {
        std::cout << "La palabra no es válida" << std::endl;
    }
}

bool Diccionario::iniDiccionario(std::string diccionario)
{
    std::ifstream archivo(diccionario);

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        std::cout << "Error al abrir el archivo." << std::endl;
        return false;
    }

    // Lee el archivo línea por línea e almacena su contenido
    std::string linea;
    while (std::getline(archivo, linea))
    {
        if (verificarPalabra(linea))
        {
            palabras.push_back(linea);
        }
    }
    // Cierra el archivo
    archivo.close();
    return true;
}

bool Diccionario::iniDiccionarioInverso(std::string diccionario)
{
    std::ifstream archivo(diccionario);

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        std::cout << "Error al abrir el archivo." << std::endl;
        return false;
    }

    // Lee el archivo línea por línea e almacena su contenido
    std::string linea;
    while (std::getline(archivo, linea))
    { // Lee cada línea del archivo
        std::string palabra;
        for (int i = linea.size() - 1; i >= 0; --i)
        { // Lee la línea de derecha a izquierda
            if (linea[i] != ' ')
            {
                palabra += linea[i]; // Construye la palabra invertida
            }
            else
            {
                if (verificarPalabra(palabra))
                {
                    // Agrega la palabra invertida al vector
                    palabrasInversas.push_back(palabra);
                    palabra.clear();
                }
            }
        }
        if (!palabra.empty())
        {
            if (verificarPalabra(palabra))
            {
                // Agrega la última palabra invertida al vector
                palabrasInversas.push_back(palabra);
            }
        }
    }
    // Cierra el archivo
    archivo.close();
    return true;
}
#endif