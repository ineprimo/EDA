// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// En este problema diremos que un vector está parcialmente ordenado si:
// - el valor máximo de su mitad derecha es mayor o igual que todos los valores de la mitad izquierda
// - el valor mínimo de su mitad izquierda es menor o igual que todos los valores de su mitad derecha
// - tanto la mitad izquierda como la derecha cumplen que est´an parcialmente ordenados

bool parcialmenteOrdenado(const std::vector<int>& v, int ini, int fin, int& min, int& max)
{
    int elems = fin - ini;

    if (elems == 0) return true;
    if(elems == 1)
    {
        // establece maximos y minimos
        min = v[ini - 1];
        max = v[fin - 1];

        return min <= max;
    }

    int minIzq = 0;
    int minDer = 0;
    int maxIzq = 0;
    int maxDer = 0;

    int mit = (ini + fin) / 2;

    bool izq = parcialmenteOrdenado(v, ini, mit, minIzq, maxIzq);
    bool der = parcialmenteOrdenado(v, mit + 1, fin, minDer, maxDer);

    return (izq && der) && (maxDer >= maxIzq) && (minIzq <= minDer);
}

bool parcialmenteOrdenado(const std::vector<int>& v)
{
    int min = 0, max = 0;
    return parcialmenteOrdenado(v, 1, v.size(), min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int e;
    std::cin >> e;
    if (e == 0) return false;
    std::vector<int> sec;
    while (e != 0) {
        sec.push_back(e);
        std::cin >> e;
    }
    std::cout << (parcialmenteOrdenado(sec) ? "SI" : "NO") << std::endl;
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