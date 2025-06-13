// Paula Sierra Luque
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// O(log n)

// función que resuelve el problema
int resolver(const vector<int>& datos, int ini, int fin)
{
    // buscar numero impar
    if (fin == ini) return datos[ini]; // 1 elem (se garantiza q habra impar)

    int mitad = (fin + ini) / 2;
    if (datos[mitad] % 2 != 0) return datos[mitad];

    int izd = resolver(datos, ini, mitad);
    if (izd % 2 != 0) return izd;

    return resolver(datos, mitad + 1, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> datos;
    int aux;
    for (int i = 0; i < n; ++i)
    {
        cin >> aux;
        datos.push_back(aux);
    }
    int sol = resolver(datos, 0, n - 1);

    // escribir sol
    cout << sol << endl;

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
