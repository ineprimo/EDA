// Ejercicio 1: ULTIMO DE LA SERIE (2,5 puntos)
// Tipo: DIVIDE ET IMPERA

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int>& datos, int ini, int fin)
{
    int tam = fin - ini;

    if (tam == 1) return datos[ini];

    int mit = (fin + ini) / 2;

    // miras a la der
    if (datos[0] + mit == datos[mit]) return resolver(datos, mit, fin);
    // miras a la izq
    return resolver(datos, ini, mit);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> e;
        v[i] = e;
    }

    int sol = resolver(v, 0, n);

    // escribir sol
    std::cout << sol << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input.txt");
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