#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Sistema.h"

void clear() { std::cout << "\033[2J\033[1;1H"; }

int main()
{
  std::string opcion;
  bool inicializado = false, inicializado_IN = false, existe = false, valido = false; // Banderas
  Sistema sistema;                                                                    // Crear un objeto de la clase Sistema
  clear();
  std::cout << "|-----Bienvenido al sistema de apoyo para Scrabble-----|\n"
            << std::endl;

  while (true)
  {
    std::cout << "Digite un comando:" << std::endl;
    std::cout << "$ ";
    std::getline(std::cin, opcion);
    std::stringstream ss(opcion);
    std::string token;
    std::vector<std::string> tokens; // Vector para guardar tokens

    while (std::getline(ss, token, ' '))
    {
      tokens.push_back(token); // Guarda cada token en el vector
    }

    if (tokens[0] == "salir")
    {
      break;
    }
    else if (tokens[0] == "inicializar")
    {
      if (inicializado)
      {
        std::cout << "-> El diccionario ya ha sido inicializado." << std::endl;
      }
      else if (tokens.size() == 2)
      {
        // Llamar al método inicializarDiccionario con el nombre del archivo de diccionario como argumento
        if (sistema.getDiccionario()->iniDiccionario(tokens[1]))
        {
          std::cout << "-> El diccionario " << tokens[1] << " se ha inicializado correctamente." << std::endl;
          inicializado = true;
        }
        // sistema.getDiccionario().printDiccionario(); //Imprimir palabras del diccionario
      }
      if (!inicializado)
      {
        std::cout << "-> El archivo no existe o no se ha podido leer correctamente." << std::endl;
      }
    }
    else if (tokens[0] == "iniciar_inverso")
    {
      if (inicializado_IN)
      {
        std::cout << "-> El diccionario ya ha sido inicializado."
                  << std::endl;
      }
      else if (tokens.size() == 2)
      {
        // Llamar y comprobar al método inicializarDiccionario con el nombre del archivo de diccionario como argumento
        if (sistema.getDiccionario()->iniDiccionarioInverso(tokens[1]))
        {
          std::cout << "-> El diccionario " << tokens[1] << " se ha inicializado correctamente." << std::endl;
          inicializado_IN = true;
        }
        // miDiccionario.printDiccionarioInverso(); //Imprimir palabras del diccionario inverso
      }
      if (!inicializado_IN)
      {
        std::cout
            << "-> El archivo no existe o no se ha podido leer correctamente."
            << std::endl;
      }
    }
    else if (tokens[0] == "puntaje")
    {
      int puntaje = sistema.getDiccionario()->puntuarPalabra(tokens[1]);
      if (puntaje > 0)
      {
        std::cout << "-> La palabra tiene un puntaje de: " << puntaje << std::endl;
      }
      else if (puntaje < 0)
      {
        std::cout << "-> La palabra tiene simbolos invalidos" << std::endl;
      }
      else
      {
        std::cout << "-> La palabra no existe en el diccionario." << std::endl;
      }
    }
    else if (tokens[0] == "iniciar_arbol")
    {
      if (inicializado)
      {
        std::cout << "-> El arbol del diccionario ya ha sido inicializado."
                  << std::endl;
      }
      else if (tokens.size() == 2)
      {
        if (sistema.getArbol()->iniArbol(tokens[1]))
        {
          std::cout << "-> El Arbol " << tokens[1] << " se ha inicializado correctamente." << std::endl;
          inicializado = true;
        }
      }
      if (!inicializado)
      {
        std::cout
            << "-> El archivo no existe o no se ha podido leer correctamente."
            << std::endl;
      }
    }
    else if (tokens[0] == "iniciar_arbol_inverso")
    {
      if (inicializado)
      {
        std::cout << "-> El arbol del diccionario inverso ya ha sido inicializado."
                  << std::endl;
      }
      else if (tokens.size() == 2)
      {
        if (sistema.getArbol()->iniArbolInverso(tokens[1]))
        {
          std::cout << "-> El Arbol inverso " << tokens[1] << " se ha inicializado correctamente." << std::endl;
          inicializado = true;
        }
      }
      if (!inicializado)
      {
        std::cout
            << "-> El archivo no existe o no se ha podido leer correctamente."
            << std::endl;
      }
    }
    else if (tokens[0] == "palabras_por_prefijo")
    {
      int puntaje = 0;
      std::vector<std::string> copiaVectorPrefijo;
      std::vector<std::string>::iterator it; 
      copiaVectorPrefijo = sistema.getArbol()->palabrasPrefijo(tokens[1]);
      
      if (copiaVectorPrefijo.empty())
      {
        std::cout << "-> El prefijo no existe en el diccionario." << std::endl;
      }
      else
      {
        std::cout << "-> Las palabras que inician con el prefijo " << tokens[1]
                  << " son: " << std::endl;
        for(it = copiaVectorPrefijo.begin(); it != copiaVectorPrefijo.end(); it++){
            std::cout<<"- "<<*it<<" - Puntaje: "<<sistema.puntuarPalabra(*it)<<" - "<<"Longitud: "<<sistema.longitudPalabra(*it)<<std::endl;
        }
      }
    }
    else if (tokens[0] == "palabras_por_sufijo")
    {
      int puntaje = 0;
      std::vector<std::string> copiaVectorSufijo;
      std::vector<std::string>::iterator it; 
      copiaVectorSufijo = sistema.getArbol()->palabrasSufijo(tokens[1]);
      
      if (copiaVectorSufijo.empty())
      {
        std::cout << "-> El prefijo no existe en el diccionario." << std::endl;
      }
      else
      {
        std::cout << "-> Las palabras que inician con el sufijo " << tokens[1]
                  << " son: " << std::endl;
        for(it = copiaVectorSufijo.begin(); it != copiaVectorSufijo.end(); it++){
            std::cout<<"- "<<*it<<" - Puntaje: "<<sistema.puntuarPalabra(*it)<<" - "<<"Longitud: "<<sistema.longitudPalabra(*it)<<std::endl;
        }
      }
    }
    else if (tokens[0] == "grafo_de_palabras")
    {
      // TODO #8 -> Construir grafo de palabras
      std::cout << "-> Grafo construido correctamente. " << std::endl;
    }
    else if (tokens[0] == "posibles_palabras")
    {
      if (!valido || tokens.size() < 2)
      {
        std::cout << "-> La cadena esta vacia o contiene simbolos invalidos."
                  << std::endl;
      }
      else
      {
        std::cout << "-> Las palabras posibles a construir con las letras "
                  << tokens[1] << " son:" << std::endl;
        // TODO #9 -> Imprimir posibles palabras
      }
    }
    else if (tokens[0] == "ayuda")
    {
      if (tokens.size() == 2)
      {
        if (tokens[1] == "inicializar")
        {
          clear();
          std::cout
              << "********************************************" << std::endl
              << "* Comando: '$ inicializar diccionario.txt' *" << std::endl
              << "********************************************" << std::endl
              << "\nInicializa el sistema a partir del archivo "
                 "diccionario.txt, que contiene "
                 "un diccionario de palabras aceptadas en el idioma inglés "
                 "(idioma original del juego)."
              << std::endl;
        }
        else if (tokens[1] == "iniciar_inverso")
        {
          clear();
          std::cout
              << "************************************************" << std::endl
              << "* Comando: '$ iniciar_inverso diccionario.txt' *" << std::endl
              << "************************************************" << std::endl
              << "\nInicializa el sistema a partir del archivo "
                 "diccionario.txt, que contiene un diccionario de palabras "
                 "aceptadas en el idioma inglés (idioma original del juego). A "
                 "diferencia del comando inicializar, este comando almacena "
                 "las palabras en sentido inverso (leídas de derecha a "
                 "izquierda), teniendo en cuenta que sea fácil recuperarlas "
                 "posteriormente."
              << std::endl;
        }
        else if (tokens[1] == "puntaje")
        {
          clear();
          std::cout << "********************************" << std::endl
                    << "* Comando: '$ puntaje palabra' *" << std::endl
                    << "********************************" << std::endl
                    << "\nEl comando permite conocer la puntuación que puede "
                       "obtenerse con una palabra dada, de acuerdo a la tabla "
                       "de puntuación de cada letra presentada anteriormente."
                    << std::endl;
        }
        else if (tokens[1] == "salir")
        {
          clear();
          std::cout << "**********************" << std::endl
                    << "* Comando: '$ salir' *" << std::endl
                    << "**********************" << std::endl
                    << "\nTermina la ejecución de la aplicación." << std::endl;
        }
        else if (tokens[1] == "iniciar_arbol")
        {
          clear();
          std::cout
              << "**********************************************" << std::endl
              << "* Comando: '$ iniciar_arbol diccionario.txt' *" << std::endl
              << "**********************************************" << std::endl
              << "\nInicializa el sistema a partir del archivo "
                 "diccionario.txt, que contiene un diccionario de palabras "
                 "aceptadas en el idioma inglés (idioma original del juego). A "
                 "diferencia del comando inicializar, este comando almacena "
                 "las palabras en uno o más árboles de letras (como se "
                 "considere conveniente)."
              << std::endl;
        }
        else if (tokens[1] == "iniciar_arbol_inverso")
        {
          clear();
          std::cout << "******************************************************"
                    << std::endl
                    << "* Comando: '$ iniciar_arbol_inverso diccionario.txt' *"
                    << std::endl
                    << "******************************************************"
                    << std::endl
                    << "\nInicializa el sistema a partir del archivo "
                       "diccionario.txt, que contiene un diccionario de "
                       "palabras aceptadas en el idioma inglés (idioma "
                       "original del juego). A diferencia de los comandos "
                       "iniciar_inverso e iniciar_arbol, este comando almacena "
                       "las palabras en uno o más árboles de letras, pero en "
                       "sentido inverso (leídas de derecha a izquierda)."
                    << std::endl;
        }
        else if (tokens[1] == "palabras_por_prefijo")
        {
          clear();
          std::cout << "*********************************************"
                    << std::endl
                    << "* Comando: '$ palabras_por_prefijo prefijo' *"
                    << std::endl
                    << "*********************************************"
                    << std::endl
                    << "\nDado un prefijo de pocas letras, el comando recorre "
                       "el(los) árbol(es) de letras (construído(s) con el "
                       "comando iniciar_arbol) para ubicar todas las palabras "
                       "posibles a construir a partir de ese prefijo."
                    << std::endl;
        }
        else if (tokens[1] == "palabras_por_sufijo")
        {
          clear();
          std::cout
              << "*******************************************" << std::endl
              << "* Comando: '$ palabras_por_sufijo sufijo' *" << std::endl
              << "*******************************************" << std::endl
              << "\nDado un sufijo de pocas letras, el comando recorre el(los) "
                 "árbol(es) de letras (construído(s) con el comando "
                 "iniciar_arbol_inverso) para ubicar todas las palabras "
                 "posibles a construir que terminan con ese sufijo. "
              << std::endl;
        }
        else if (tokens[1] == "grafo_de_palabras")
        {
          clear();
          std::cout << "**********************************" << std::endl
                    << "* Comando: '$ grafo_de_palabras' *" << std::endl
                    << "**********************************" << std::endl
                    << "\nCon las palabras ya almacenadas en el diccionario "
                       "(luego de ejecutar el comando inicializar), el comando "
                       "construye un grafo de palabras."
                    << std::endl;
        }
        else if (tokens[1] == "posibles_palabras")
        {
          clear();
          std::cout << "*****************************************" << std::endl
                    << "* Comando: '$ posibles_palabras letras' *" << std::endl
                    << "*****************************************" << std::endl
                    << "\nDadas ciertas letras en una cadena de caracteres "
                       "(sin importar su orden), el comando debe presentar en "
                       "pantalla todas las posibles palabras válidas a "
                       "construir, indicando la longitud de cada una y la "
                       "puntuación que se puede obtener con cada una."
                    << std::endl;
        }
        else if (tokens[1] == "clear")
        {
          clear();
          std::cout << "**********************" << std::endl
                    << "* Comando: '$ clear' *" << std::endl
                    << "**********************" << std::endl
                    << "\nLimpia la consola." << std::endl;
        }
        else
        {
          clear();
          std::cout << "Escriba un comando valido!! ($ ayuda)" << std::endl;
        }
      }
      else
      {
        clear();
        std::cout << "| Listado de comandos del sistema |\n\n";
        std::cout << "-> inicializar \n";
        std::cout << "-> iniciar_inverso\n";
        std::cout << "-> puntaje \n";
        std::cout << "-> iniciar_arbol \n";
        std::cout << "-> iniciar_arbol_inverso \n";
        std::cout << "-> palabras_por_prefijo \n";
        std::cout << "-> palabras_por_sufijo \n";
        std::cout << "-> grafo_de_palabras \n";
        std::cout << "-> posibles_palabras \n";
        std::cout << "-> clear\n";
        std::cout << "-> salir" << std::endl;
        std::cout << "\nMas informacion: $ ayuda <comando>" << std::endl;
      }
    }
    else if (tokens[0] == "clear" || tokens[0] == "cls")
    {
      clear();
    }
    else
    {
      clear();
      std::cout << "Escriba un comando valido!! ($ ayuda)" << std::endl;
    }
  }

  clear();
  std::cout << "Saliendo del programa..." << std::endl;
  return 0;
}