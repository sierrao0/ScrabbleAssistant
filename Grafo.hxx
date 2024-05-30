#ifndef __GRAFO__HXX__
#define __GRAFO__HXX__

#include "Grafo.h"
#include <string>
#include <cctype>

// Grafo::Grafo()
// {

// }

void Grafo::addVertice(std::string &word)
{
    adjList[word] = std::unordered_set<std::string>();
}

void Grafo::addArista(std::string &word1, std::string &word2)
{
    adjList[word1].insert(word2);
    adjList[word2].insert(word1); // Para grafo no dirigido
}

void Grafo::imprimirGrafo()
{
    for (const auto &pair : adjList)
    {
        std::cout << pair.first << ": ";
        for (const auto &neighbor : pair.second)
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

bool Grafo::diferencia(std::string &word1, std::string &word2)
{
    if (word1.length() != word2.length())
        return false;

    int count = 0;
    for (size_t i = 0; i < word1.length(); ++i)
    {
        if (word1[i] != word2[i])
        {
            ++count;
            if (count > 1)
                return false;
        }
    }
    return count == 1;
}

bool Grafo::construirGrafo(std::vector<std::string> &dictionary)
{
    for (auto &word : dictionary)
    {
        this->addVertice(word);
    }

    for (size_t i = 0; i < dictionary.size(); ++i)
    {
        for (size_t j = i + 1; j < dictionary.size(); ++j)
        {
            if (diferencia(dictionary[i], dictionary[j]))
            {
                this->addArista(dictionary[i], dictionary[j]);
            }
        }
    }
    return true;
}

int Grafo::puntuarPalabra(std::string palabra)
{
    int puntuacion = 0;
    bool existe = false;
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
    return puntuacion;
}

bool Grafo::validarPalabra(std::string &word)
{
    for (char c : word)
    {
        if (!isalpha(c) && c != '?') // Comprueba si la palabra contiene los digitos validos
        {
            return false;
        }
    }
    return true;
}

void Grafo::generarCombinaciones(std::string prefix, std::string letters, std::unordered_set<std::string> &results)
{
    // Si el prefijo no está vacío y es una palabra válida, se añade a los resultados.
    if (!prefix.empty())
    {
        if (adjList.find(prefix) != adjList.end()) // Verifica si es una palabra válida
        {
            results.insert(prefix);
        }
    }

    // Genera nuevas combinaciones añadiendo una letra del conjunto letters al prefijo actual.
    for (size_t i = 0; i < letters.size(); ++i)
    {
        std::string newPrefix = prefix + letters[i];                                 // Construye un nuevo prefijo
        std::string remainingLetters = letters.substr(0, i) + letters.substr(i + 1); // Letras restantes
        generarCombinaciones(newPrefix, remainingLetters, results);                  // Llamada recursiva
    }

    // Maneja el comodín '?' reemplazándolo por cada letra del alfabeto.
    if (letters.find('?') != std::string::npos)
    {
        std::string remainingLetters = letters;
        remainingLetters.erase(letters.find('?'), 1); // Elimina el comodín de las letras restantes
        for (char c = 'a'; c <= 'z'; ++c)
        {
            generarCombinaciones(prefix + c, remainingLetters, results); // Llamada recursiva con cada letra del alfabeto
        }
    }
}

void Grafo::posiblesPalabras(std::string &letters)
{
    if (!validarPalabra(letters))
    {
        std::cout << "La cadena " << letters << " contiene símbolos inválidos." << std::endl;
        return;
    }

    std::unordered_set<std::string> results;
    generarCombinaciones("", letters, results);

    if (results.empty())
    {
        std::cout << "No se encontraron palabras posibles." << std::endl;
    }
    else
    {
        std::cout << "Las posibles palabras a construir con las letras " << letters << " son:" << std::endl;
        for (const auto &word : results)
        {
            std::cout << word << " (longitud: " << word.length() << ", puntuacion: " << puntuarPalabra(word) << ")" << std::endl;
        }
    }
}

#endif