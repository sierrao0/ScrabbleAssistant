#ifndef __DICCIONARIO__CXX__
#define __DICCIONARIO__CXX__

#include "Diccionario.h"
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string.h>

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
        if (!isalpha(c)) // Comprueba si el carácter no es una letra
        { 
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

int Diccionario::puntuarPalabra(std::string palabra)
{
    int puntuacion = 0;
    bool existe = false;
    if (!verificarPalabra(palabra))
    {
        return -1;
    }
    // Verifica si existe la palabra en el diccionario normal
    for (std::vector<std::string>::iterator it = palabras.begin(); it != palabras.end(); ++it)
    {
        if (*it == palabra)
        {
            existe = true;
        }
    }
    // Verifica si existe la palabra en el diccionario inverso
    for (std::vector<std::string>::iterator it = palabrasInversas.begin(); it != palabrasInversas.end(); ++it)
    {
        if (*it == palabra)
        {
            existe = true;
        }
    }

    if (existe)
    {
        for (char c : palabra)
        {
            if (c == 'e' || c == 'a' || c == 'i' || c == 'o' || c == 'n' || c == 'r' || c == 't' || c == 'l' || c == 's' || c == 'u')
            {
                puntuacion++;
            }
            if (c == 'd' || c == 'g')
            {
                puntuacion += 2;
            }
            if (c == 'b' || c == 'c' || c == 'm' || c == 'p')
            {
                puntuacion += 3;
            }
            if (c == 'f' || c == 'h' || c == 'v' || c == 'w' || c == 'y')
            {
                puntuacion += 4;
            }
            if (c == 'k')
            {
                puntuacion += 5;
            }
            if (c == 'j' || c == 'x')
            {
                puntuacion += 8;
            }
            if (c == 'q' || c == 'z')
            {
                puntuacion += 10;
            }
        }
    }
    else
    {
        return 0; // No se ha encontrado la palabra
    }
    return puntuacion;
}
#endif