#ifndef __SISTEMA__H__
#define __SISTEMA__H__

#include "Diccionario.h"


class Sistema
{
protected:
    Diccionario dicVector;
    //Arbol dicArbol;
public:
    // Sistema();
    // ~Sistema();
    Diccionario* getDiccionario();
    // Arbol* getArbol();
};

#include "Sistema.hxx"
#endif