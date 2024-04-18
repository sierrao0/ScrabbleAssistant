#ifndef __SISTEMA__H__
#define __SISTEMA__H__

#include "Diccionario.h"
#include "Trie.h"

class Sistema
{
protected:
    Diccionario dicVector;
    Trie dicArbol;

public:
    Diccionario *getDiccionario();
    Trie *getArbol();
};

#include "Sistema.hxx"
#endif