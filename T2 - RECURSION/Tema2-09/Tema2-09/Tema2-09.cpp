// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& datos, int k, int ini, int fin)
{
    if (ini == fin) return datos[ini] == k; // 1 elem
    
    int mitad = (ini + fin) / 2;
    if (datos[mitad] == k) return true;

    // parte izda ordenada
    if (datos[ini] < datos[mitad])
    {
        if (datos[ini] <= k && k < datos[mitad]) // izda
        {
            return resolver(datos, k, ini, mitad);
        }
        else //dch
        {
            return resolver(datos, k, mitad+1, fin);
        }
    }
    // parte dcha ordenada
    else
    {
        if (datos[mitad] < k && k <= datos[fin]) // dch
        {
            return resolver(datos, k, mitad+1, fin);
        }
        else //izd
        {
            return resolver(datos, k, ini, mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n;
    if (n == -1)
        return false;

    cin >> k;

    vector<int> datos;
    int aux;
    for (int i = 0; i < n; ++i)
    {
        cin >> aux;
        datos.push_back(aux);
    }
    bool sol = resolver(datos, k, 0, n-1);

    // escribir sol
    if (sol) cout << "SI";
    else cout << "NO";

    cout << endl;

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
