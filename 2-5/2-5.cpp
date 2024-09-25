// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// O(log n)
bool caucasico(const vector<int>& v, int ini, int fin, int& n) {
	const int diff = fin - ini;

	if (diff == 1) { // unidad
		if (v[ini] % 2 == 0) // si es par
			n = 1; // levar cuenta
		else
			n = 0;
		return true; // volver
	}

	int nIzq = 0, nDer = 0;
	int mitad = (fin + ini) / 2; // indice mitad

	bool cauIzq = caucasico(v, ini, mitad, nIzq);
	bool cauDer = caucasico(v, mitad, fin, nDer);

	n = nIzq + nDer; // llevar cuenta

	return cauIzq && cauDer && abs(nIzq - nDer) <= 2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    int p = 0;
    cout << (caucasico(sec, 0, sec.size(), p) ? "SI" : "NO") << endl;
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
    //system("PAUSE");
#endif

    return 0;
}