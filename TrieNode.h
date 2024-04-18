#ifndef __TRIENODE__H__
#define __TRIENODE__H__

#include <iostream>
#include <vector>

class TrieNode
{

protected:
    std::vector<bool> caracteres;
    bool isEnd;
    std::vector<TrieNode *> hijos;

public:
    TrieNode();
    std::vector<bool> getCaracteres();
    bool getIsEnd();
    void setIsEnd(bool estado);
    std::vector<TrieNode *> *gethijos();
    TrieNode* getHijo(int index); 
    bool esHijoVacio(int index);
    void setHijo(int index);
};

#include "TrieNode.hxx"
#endif
