#ifndef __GRAFO__HXX__
#define __GRAFO__HXX__

#include "Grafo.h"

// Grafo::Grafo()
// {

// }

void Grafo::addVertex(std::string &word)
{
    adjList[word] = std::unordered_set<std::string>();
}

void Grafo::addEdge(std::string &word1, std::string &word2)
{
    adjList[word1].insert(word2);
    adjList[word2].insert(word1); // Para grafo no dirigido
}

void Grafo::printGraph()
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

bool Grafo::differByOne(std::string &word1, std::string &word2)
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

bool Grafo::buildWordGraph(std::vector<std::string> &dictionary)
{
    for (auto &word : dictionary)
    {
        this->addVertex(word);
    }

    for (size_t i = 0; i < dictionary.size(); ++i)
    {
        for (size_t j = i + 1; j < dictionary.size(); ++j)
        {
            if (differByOne(dictionary[i], dictionary[j]))
            {
                this->addEdge(dictionary[i], dictionary[j]);
            }
        }
    }
    return true;
}

#endif