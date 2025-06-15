
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& datos, int ini, int fin) 
{
    if (fin == ini) return datos[ini];
    if (fin - ini == 1)
    {
        if (datos[ini] != datos[fin] - 1) return datos[ini];
        else return datos[fin];
    }

    int mitad = (ini + fin) / 2;

    // si las mitades no son consecutivas estara en la izda
    if (datos[mitad] - datos[mitad - 1] != 1)
        return resolver(datos, ini, mitad); // izda

    // si los indices coinciden en la mitad, estara a la dcha
    if (datos[mitad] - datos[ini] == mitad - ini)
        return resolver(datos, mitad, fin); // dcha
    else // si no coinciden estara a la izda
        return resolver(datos, ini, mitad);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v) cin >> e;

    // Llamada a la función resolver
    int sol = resolver(v, 0, n - 1);

    // Mostrar el resultado
    cout << sol << endl;
}


//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}