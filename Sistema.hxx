#ifndef __SISTEMA__HXX__
#define __SISTEMA__HXX__

Diccionario *Sistema::getDiccionario()
{
    return &dicVector;
}

Trie *Sistema::getArbol()
{
    return &dicArbol;
}

#endif
