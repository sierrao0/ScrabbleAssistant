#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// Representación del Grafo
class Grafo
{
protected:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

public:
    void addVertex(std::string &word);
    void addEdge(std::string &word1, std::string &word2);
    bool buildWordGraph(std::vector<std::string> &dictionary);
    bool differByOne(std::string &word1, std::string &word2);
    void printGraph();
};

#include "Grafo.hxx"
#endif