// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"

using namespace std;

// función que resuelve el problema
bool resolver(Set<int> set1, Set<int> set2) {
	return set1 <= set2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, m, k;
    cin >> n;

    if (!std::cin)
        return false;

	Set<int> set1;
    for (int i = 0; i < n; ++i) {
        cin >> k;
		set1.add(k);
    }

    cin >> m;
	Set<int> set2;
	for (int i = 0; i < m; ++i) {
		cin >> k;
		set2.add(k);
	}
    bool sol = resolver(set1, set2);

	if (sol) cout << "1" << endl;
	else cout << "0" << endl;

    // escribir sol


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