// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
#include <vector>

using namespace std;

// función que resuelve el problema
deque<int> resolver(vector<int>& datos) {
	deque<int> aux;

    for (int i = 0; i < datos.size(); ++i) {
        if (datos[i] == 0) aux.push_back(datos[i]);
        else if (datos[i] < 0) aux.push_front(datos[i]);
		else aux.push_back(datos[i]);
    }

    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;
	vector<int> datos(n);
	for (int i = 0; i < n; ++i) {
		cin >> datos[i];
	}

    deque<int> sol = resolver(datos);

    while (!sol.empty()) {
		cout << sol.front() << " ";
		sol.pop_front();
    }
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
