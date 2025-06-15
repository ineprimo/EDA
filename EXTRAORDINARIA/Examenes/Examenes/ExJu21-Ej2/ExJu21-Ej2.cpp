// Ejercicio 1: ELEMENTO FALTA (3 puntos)
// Tipo: DIVIDE ET IMPERA

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int>& v, std::vector<int>& vFalta, int ini, int fin)
{
    int tam = fin - ini;

    if (tam == 1) return v[ini];

    int mit = (fin + ini) / 2;

    // miras a la der
    if (v[mit-1] == vFalta[mit-1]) return resolver(v, vFalta, mit, fin);
    // miras a la izq
    return resolver(v, vFalta, ini, mit);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n = 0;
    std::cin >> n;
    int m = n - 1;

    std::vector<int> v1(n);
    int e1 = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> e1;
        v1[i] = e1;
    }

    std::vector<int> v2(m);
    int e2 = 0;
    for (int i = 0; i < m; i++)
    {
        std::cin >> e2;
        v2[i] = e2;
    }

    int sol = resolver(v1, v2, 0, n);

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