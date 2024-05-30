#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cctype>

// Representación del Grafo
class Grafo
{
protected:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

public:
    void addVertice(std::string &word);
    void addArista(std::string &word1, std::string &word2);
    bool construirGrafo(std::vector<std::string> &dictionary);
    bool diferencia(std::string &word1, std::string &word2);
    bool validarPalabra (std::string &word);
    int puntuarPalabra(std::string palabra);
    void posiblesPalabras(std::string &word);
    void generarCombinaciones(std::string prefix, std::string letters, std::unordered_set<std::string> &results);
    void imprimirGrafo();
};

#include "Grafo.hxx"
#endif