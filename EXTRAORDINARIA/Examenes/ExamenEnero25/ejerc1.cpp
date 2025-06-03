/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no: 

Tupla solución:

Marcadores:

Ejemplo de aplicación de poda por estimación:

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, vector<T> const& v){
    for (auto& e : v) out << e << " ";
    return out;
}


// función que resuelve el problema
void resolver(vector<int>& soluc, int k, int n, int m, int l, vector<int>& kilosPorArea, vector<vector<int>> const& kilosPorVoluntario, ... ) {

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> kilosPorArea(m);
    for (int i = 0; i < m; ++i) {
        cin >> kilosPorArea[i];
    }
    vector<vector<int>> kilosPorVoluntario(n, vector<int>(m));
    for (int i = 0; i < n ; ++i)
        for (int j = 0; j < m; ++j)
            cin >> kilosPorVoluntario[i][j];

    vector<int> soluc(...);
    int k = 0;
    resolver(soluc, k, n, m, l, kilosPorArea, kilosPorVoluntario, ...);
    if (...) cout << "IMPOSIBLE" << endl;
    else cout << ... << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
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
