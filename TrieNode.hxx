#ifndef __TRIENODE__HXX__
#define __TRIENODE__HXX__

#include "TrieNode.h"
#include <iostream>
#include <vector>

TrieNode::TrieNode()
{
    hijos.resize(26, nullptr);    // el vector hijos inicializa con 26 hijos "vacios"
    isEnd = false;
}

bool TrieNode::getIsEnd()
{
    return this->isEnd;
}

std::vector<TrieNode *> *TrieNode::gethijos()
{
    return &hijos;
}

TrieNode* TrieNode::getHijo(int index)
{
    return hijos[index];
}

bool TrieNode::esHijoVacio(int index)
{
    return this->hijos[index] == NULL;
}

void TrieNode::setHijo(int index)
{
    this->hijos[index] = new TrieNode();
}

void TrieNode::setIsEnd(bool estado)
{
    this->isEnd = estado;
}

#endif