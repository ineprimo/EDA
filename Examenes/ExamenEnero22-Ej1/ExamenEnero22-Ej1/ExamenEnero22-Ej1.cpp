

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;
using lit = list<char>::iterator;

// función que resuelve el problema
list<char> resolver(list<char>& letras, int pos, int lon, int k) 
{
    // si no es valido no tiene efecto
    if (letras.empty() || lon == 0 || k == 0 || pos >= letras.size() || pos-k < 0) {
        return letras;
    }

    // si se sale:
    if (pos + lon > letras.size())                 // a b c d e f g  // si pos=4, lon=4, 
    {                                              //         ^
        lon = letras.size() - pos;                 // lon = 7-4 = 3 y asi no se sale
    }

    // iterador para el inicio, hasta pos
    lit itStart = letras.begin();
    for (int i = 0; i < pos; ++i) {                 // hasta q apunte a 'e' (itStart == 'e')
        ++itStart; 
    }

    // para el final, desde pos hasta lon 
    lit itEnd = itStart;
    for (int i = 0; i < lon; ++i) {
        ++itEnd;                                    // empieza en 'e', hasta 'g'
    }

    // cogemos cacho que vamos a mover en una lista auxiliar
    list<char> trozo;
    for (auto it = itStart; it != itEnd;)           // 'e', 
    {
        trozo.insert(trozo.end(), *it);             // mete 'e' 
        it = letras.erase(it);                      // borra de letras, it ahora apunta al siguiente: 'f'
    }

    // nueva pos
    int nueva = 0;
    if (pos >= k)  nueva = pos - k;
    else nueva = 0;

    // donde vamos a isnertar el trozo:
    lit itInsert = letras.begin();
    for (int i = 0; i < nueva; ++i) {
        ++itInsert;
    }

    // insertamos
    for (const char& c : trozo) {
        itInsert = letras.insert(itInsert, c);
        ++itInsert;
    }

    return letras;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, pos, lon, k;
    std::cin >> n >> pos >> lon >> k;

    list<char> letras;
    for (int i = 0; i < n; ++i) 
    {
        char c;
        std::cin >> c;
        letras.insert(letras.end(), c); // añade al final de la lista
    }

    list<char> sol = resolver(letras, pos, lon, k);

    // escribir sol
    for (auto it = sol.begin(); it != sol.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}