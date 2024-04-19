#ifndef __TRIE__HXX__
#define __TRIE__HXX__

#include "Trie.h"
#include "TrieNode.h"

// Constructor
Trie::Trie()
{
    root = new TrieNode();
}

// Destructor
Trie::~Trie()
{
    clear(root);
}

// Función para limpiar la memoria recursivamente
void Trie::clear(TrieNode *node)
{
    if (node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->gethijos()->at(i))
            {
                clear(node->gethijos()->at(i));
            }
        }
        delete node;
    }
}

// Insertar una palabra en el Trie
void Trie::insert(const std::string &word)
{
    TrieNode *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (!current->gethijos()->at(index))
        {
            current->gethijos()->at(index) = new TrieNode();
        }
        current = current->gethijos()->at(index);
    }
    current->setIsEnd(true);
}

// Buscar una palabra en el Trie
bool Trie::search(const std::string &word)
{
    TrieNode *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (!current->gethijos()->at(index))
        {
            return false;
        }
        current = current->gethijos()->at(index);
    }
    return current->getIsEnd();
}

bool Trie::verificarPalabra(std::string palabra)
{
    for (char c : palabra)
    {
        if (!isalpha(c) || std::isupper(c)) // Comprueba si el carácter no es una letra o es mayuscula
        {
            return false;
        }
    }
    return true;
}

void Trie::agregarPalabra(std::string palabra)
{
    if (verificarPalabra(palabra))
    {
        this->insert(palabra);
    }
    else
    {
        std::cout << "La palabra no es válida" << std::endl;
    }
}

bool Trie::iniArbol(std::string diccionario)
{
    int i=0;
    std::ifstream archivo(diccionario);

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        std::cout << "Error al abrir el archivo." << std::endl;
        return false;
    }

    // Lee el archivo línea por línea e almacena su contenido
    std::string linea;
    while (std::getline(archivo, linea))
    {
        if (verificarPalabra(linea))
        {
            this->insert(linea);
            // std::cout<<i++<<". "<<linea<<std::endl; //---> Probe
        }
    }
    // Cierra el archivo
    archivo.close();
    return true;
}

bool Trie::iniArbolInverso(std::string diccionario)
{
    int h=0;
    std::ifstream archivo(diccionario);

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        std::cout << "Error al abrir el archivo." << std::endl;
        return false;
    }

    // Lee el archivo línea por línea e almacena su contenido
    std::string linea;
    while (std::getline(archivo, linea))
    { // Lee cada línea del archivo
        std::string palabra;
        for (int i = linea.size() - 1; i >= 0; --i)
        { // Lee la línea de derecha a izquierda
            if (linea[i] != ' ')
            {
                palabra += linea[i]; // Construye la palabra invertida
            }
            else
            {
                std::cout<<h++<<". "<<palabra<<std::endl;
                if (verificarPalabra(palabra))
                {
                    // Agrega la palabra invertida al arbol
                    this->insert(palabra);
                    palabra.clear();
                }
            }
        }
        if (!palabra.empty())
        {
            if (verificarPalabra(palabra))
            {
                // Agrega la última palabra invertida al arbol
                // std::cout<<h++<<". "<<palabra<<std::endl; //---> Probe
                this->insert(palabra);
            }
        }
    }
    // Cierra el archivo
    archivo.close();
    return true;
}

#endif

/*
std::vector<std::string> Trie::palabrasPrefijo(std::string prefijo) {
    TrieNode* actual = root;
    std::vector<std::string> resultados;

    // Navegar hasta el nodo del último carácter del prefijo
    for (char ch : prefijo) {
        int pos = ch - 'a';
        if (!actual->gethijos->at(pos)) return resultados;  // Retorna lista vacía si el prefijo no existe
        actual = actual->gethijos->at(pos);
    }

    // Recopilar todas las palabras que extienden este prefijo
    recogerPalabras(actual, prefijo, resultados);

    return resultados;
}

void Trie::recogerPalabras(TrieNode* nodo, std::string palabraActual, std::vector<std::string>& resultados) {
    if (nodo->esFinDePalabra()) {
        resultados.push_back(palabraActual);
    }
    for (int i = 0; i < 26; i++) {  // Suponiendo un alfabeto de 'a' a 'z'
        if (nodo->gethijos()->at(i)) {
            char siguienteChar = 'a' + i;
            recogerPalabras(nodo->gethijos->at(i), palabraActual + siguienteChar, resultados);
        }
    }
}

*/
