// PAULA SIERRA
// EDA-GDV70

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string> // para el getline

#include "stack_eda.h"

// función que resuelve el problema
bool resolver(std::string linea) 
{
    stack<char> chars;

    int i = 0;
    while (i < linea.size()) 
    {
        if (linea[i] == '(' || linea[i] == '[' || linea[i] == '{')
        {
            chars.push(linea[i]);
        }
        else if (linea[i] == ']') 
        {
            if (!chars.empty() && chars.top() == '[') {
                chars.pop();
            }
            else chars.push(linea[i]);
        }
        else if (linea[i] == '}') 
        {
            if (!chars.empty() && chars.top() == '{') {
                chars.pop();
            }
            else chars.push(linea[i]);
        }
        else if (linea[i] == ')') 
        {
            if (!chars.empty() && chars.top() == '(') {
                chars.pop(); 
            }
            else chars.push(linea[i]);
        }

        i++;
    }

    return chars.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string linea;
    std::getline(std::cin, linea);

    if (!std::cin)
        return false;

    bool sol = resolver(linea);

    // escribir sol
    if(sol) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}