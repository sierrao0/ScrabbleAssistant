#ifndef __TRIENODE__H__
#define __TRIENODE__H__

#include <iostream>
#include <vector>

class TrieNode
{

protected:
    std::vector<TrieNode *> hijos;
    bool isEnd;

public:
    TrieNode();
    std::vector<TrieNode *> *gethijos();
    TrieNode* getHijo(int index);
    bool esHijoVacio(int index);
    void setHijo(int index);
    bool getIsEnd();
    void setIsEnd(bool estado);
};

#include "TrieNode.hxx"
#endif
