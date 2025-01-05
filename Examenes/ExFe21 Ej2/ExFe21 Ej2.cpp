#include <iostream>
#include <fstream>
#include "bintree_eda.h"

template <class T>
bool hijosSimetricos(const bintree<T>& ramaIzq, const bintree<T>& ramaDer)
{
    // si ninguna tiene hijos -> es simetrico
    if (ramaIzq.empty() && ramaDer.empty()) return true;

    // si tiene una y no su contraria -> no simetrico
    if ((ramaIzq.empty() && !ramaDer.empty()) || (!ramaIzq.empty() && ramaDer.empty())) return false;

    // se llama al metodo comparando cada rama con su simetrica
    return hijosSimetricos(ramaIzq.left(), ramaDer.right()) && hijosSimetricos(ramaIzq.right(), ramaDer.left());
}

// Un arbol binario no vacio es simetrico respecto al eje vertical que pasa por la raiz
// si al "doblarlo" por ese eje todo nodo de un lado coincide con un nodo del otro

// Complejidad: O(n) siendo el numero de elementos del arbol, solo pasas por cada nodo una vez
template <class T>
bool simetrico(const bintree<T>& arbol)
{
    // Caso base -> arbol vacio es simetrico
	if(arbol.empty())
	{
        return true;
	}

    // Caso hijos -> si tiene hijos los comprobamos
    bool hijos = hijosSimetricos(arbol.left(), arbol.right());

    return hijos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso()
{
    // lee arbol
    bintree<char> arbol;
    arbol = leerArbol('.'); // '.' es la representacion de arbol vacio

    // escribe solucion
    bool sol = simetrico(arbol);
    if (sol) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
    {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}