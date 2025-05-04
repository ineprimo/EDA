// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

char resolverRec(vector<char>& presos, int ini, int fin, char inicioPresos){
    if (ini == fin) return inicioPresos + ini;

    int mitad = (ini + fin) / 2;

    if (presos[mitad] == inicioPresos + mitad) return resolverRec(presos, mitad + 1, fin, inicioPresos);
    else return resolverRec(presos, ini, mitad, inicioPresos);
}

// función que resuelve el problema
char resolver(vector<char>& sol, char ini) {
    return resolverRec(sol, 0, sol.size() - 1, ini);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    char ini, fin;
    cin >> ini >> fin;

    int n = fin - ini;
    vector<char> presos(n);

    for (int i = 0; i < n; ++i) {
        cin >> presos[i];
    }

    cout << resolver(presos, ini) << endl;


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