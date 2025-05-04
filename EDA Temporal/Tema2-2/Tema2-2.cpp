// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// El algoritmo tiene una complejidad O(log(n))
int resolverRec(vector<int>& vec1, vector<int>& vec2, int ini, int fin) {
    if (ini == fin) {
        return vec1[ini];
    }

    int mitad = (ini + fin) / 2;

    if (vec1[mitad] == vec2[mitad]) return resolverRec(vec1, vec2, mitad + 1, fin);
    else return resolverRec(vec1, vec2, ini, mitad);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, m;

    cin >> n;
    m = n - 1;
    vector<int> vector1(n);
    vector<int> vector2(m);

    for (int i = 0; i < n; ++i) {
        cin >> vector1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> vector2[i];
    }

    cout << resolverRec(vector1, vector2, 0, n - 1) << endl;


}

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
    system("PAUSE");
#endif

    return 0;
}