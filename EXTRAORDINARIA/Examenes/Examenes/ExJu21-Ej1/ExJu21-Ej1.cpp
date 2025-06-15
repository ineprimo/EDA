// Ejercicio 1: Dar la vuelta (2,5 puntos)
// Tipo: TADs EXTERNO (lista)

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <list>
#include <utility>

using namespace std;

// P -> pos inicio del segmento (se empieza a numerar en 1 xD)
// L -> longitud del segmento
// función que resuelve el problema
void resolver(list<int>& lista, int N, int P, int L)
{
    if (lista.empty()) return;

    auto it = lista.begin();
    while (*it != P + L - 1)
        ++it;

    int e = P + L;
    while (e != P)
    {
        lista.push_back(*it);
        it = lista.erase(it);
        if (it != lista.begin())
            --it;
        e--;
    }

    if (it != lista.end())
        ++it;

    int resto = N - (P + L) + 1;
    int i = 0;
    while (it != lista.end() && i < resto)
    {
        lista.push_back(*it);
        it = lista.erase(it);
        i++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    if (!std::cin)
        return false;

    int N = 0, P = 0, L = 0;

    std::cin >> N;
    std::cin >> P;
    std::cin >> L;

    list<int> lista;
    int e = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> e;
        lista.push_back(e);
    }

    // escribir sol
    resolver(lista, N, P, L);

    auto it = lista.begin();
    while (it != lista.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << '\n';

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input.txt");
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