#ifndef __TRIE__H__
#define __TRIE__H__

#include "TrieNode.h"

class Trie
{
protected:
    TrieNode *root; // Raíz del Trie
    TrieNode *rootIN; // Raíz del Trie inverso

public:
    Trie();
    ~Trie();
    void clear(TrieNode *node);
    void insert(const std::string &word);
    bool search(const std::string &word);
    bool verificarPalabra(std::string palabra);
    void agregarPalabra(std::string palabra);
    bool iniArbol(std::string diccionario);
    bool iniArbolInverso(std::string diccionario);
    void recogerPalabras (TrieNode* nodo, std::string palabraActual, std::vector<std::string>& resultados);
    std::vector<std::string> palabrasPrefijo(std::string prefijo);
    std::vector<std::string> palabrasSufijo(std::string sufijo);

};

#include "Trie.hxx"
#endif
