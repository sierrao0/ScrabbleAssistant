#ifndef __SISTEMA__H__
#define __SISTEMA__H__

#include "Diccionario.h"
#include "Trie.h"
#include "Grafo.h"

class Sistema
{
protected:
    Diccionario dicVector;
    Trie dicArbol;
    Grafo dicGrafo;

public:
    Diccionario *getDiccionario();
    Trie *getArbol();
    Grafo *getGrafo();
    int longitudPalabra(std::string palabra);
    int puntuarPalabra(std::string palabra);
};

#include "Sistema.hxx"
#endif