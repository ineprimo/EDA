// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Divide y vencerás. Búsqueda binaria, complejidad -> O(log(n)) siendo n el tamaño del vector
int resolver(const std::vector<int>& sec, int ini, int fin)
{
    int elems = fin - ini;

    if (elems == 1) return sec[ini]; // caso base / se asegura un elemento impar

    int mit = (ini + fin) / 2;

    if (sec[ini] % 2 != 0) return sec[ini]; // caso base / ini impar
    if (sec[mit] % 2 != 0) return sec[mit]; // caso base / mitad impar

    int numMit = sec[ini] + (mit - ini)*2; // el num que debería estar a la mitad

    // si el que está a la mitad es igual que el que debería estar -> buscar derecha
    if(sec[mit] == numMit)
    {
        return resolver(sec, mit, fin);
    }
    else
    {
        return resolver(sec, ini, mit);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n == 0) return false;
    std::vector<int> sec(n);
    for (int& e : sec) std::cin >> e;
    std::cout << resolver(sec, 0, n) << std::endl;
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