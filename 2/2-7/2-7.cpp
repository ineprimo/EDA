// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Divide y vencerás, búsqueda binaria. Complejidad: O(log n)
int minimo(const std::vector<int>& sec, int ini, int fin)
{
    int elems = fin - ini;
    if (elems == 1) return sec[ini];

    int mit = (fin + ini) / 2;

    if(sec[mit] > sec[mit - 1]) // si a la izq hay valores menores -> buscar izq
    {
        return minimo(sec, ini, mit);
    }

    if (sec[mit] < sec[mit - 1]) // si a la izq hay valores mayores -> buscar der
    {
        return minimo(sec, mit, fin);
    }

    if (sec[mit] > sec[mit + 1]) // si a la der hay valores menores -> buscar der
    {
        return minimo(sec, mit, fin);
    }

    if (sec[mit] < sec[mit + 1]) // si a la der hay valores mayores -> buscar der
    {
        return minimo(sec, ini, mit);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (!std::cin) return false;
    std::vector<int> sec(n);
    for (int& e : sec) std::cin >> e;
    std::cout << minimo(sec, 0, n) << std::endl;
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
    //system("PAUSE");
#endif

    return 0;
}