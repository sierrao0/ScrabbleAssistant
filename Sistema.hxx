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

Grafo *Sistema::getGrafo()
{
    return &dicGrafo;
}

int Sistema::puntuarPalabra(std::string palabra)
{
    int puntuacion = 0;
    for (char c : palabra)
    {
        if (c == 'e' || c == 'a' || c == 'i' || c == 'o' || c == 'n' || c == 'r' || c == 't' || c == 'l' || c == 's' || c == 'u')
        {
            puntuacion++;
        }
        if (c == 'd' || c == 'g')
        {
            puntuacion += 2;
        }
        if (c == 'b' || c == 'c' || c == 'm' || c == 'p')
        {
            puntuacion += 3;
        }
        if (c == 'f' || c == 'h' || c == 'v' || c == 'w' || c == 'y')
        {
            puntuacion += 4;
        }
        if (c == 'k')
        {
            puntuacion += 5;
        }
        if (c == 'j' || c == 'x')
        {
            puntuacion += 8;
        }
        if (c == 'q' || c == 'z')
        {
            puntuacion += 10;
        }
    }

    return puntuacion;
}

int Sistema::longitudPalabra(std::string palabra){
    int longitud = 0;

    for (char c : palabra){
        longitud++;
    }

    return longitud;
}

#endif
