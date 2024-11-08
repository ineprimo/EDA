// NIEVES ALONSO GILSANZ
// EDA-GDV03
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// lineal O(n) n son los elementos del del arbol
template <class T>
pair<int, string> ruta(bintree<T> const& tree) {
	// casos base
	if (tree.empty()) {
		return { 0,"Ninguno" };
	}
	if (tree.left().empty() && tree.right().empty()) {
		return { 1, tree.root() };
	}

	// variables auxiliares
	pair<int, string> rutal = ruta(tree.left()),
		rutar = ruta(tree.right()),
		rutaCorrecta;

	// mira las rutas de los datos
	rutaCorrecta.first = rutal.first + rutar.first;
	if (rutal.first == rutar.first) {
		if (rutar.second < rutal.second)
			rutaCorrecta.second = rutar.second;
		else
			rutaCorrecta.second = rutal.second;
	}
	else {
		if (rutal.first < rutar.first)
			rutaCorrecta.second = rutar.second;
		else
			rutaCorrecta.second = rutal.second;
	}

	// combate con orcos
	if (tree.root() == "Orcos") {
		rutaCorrecta.first = rutaCorrecta.first / 2;
	}
	if (rutaCorrecta.first <= 0) {
		rutaCorrecta = { 0, "Ninguno" };
	}

	return rutaCorrecta;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<string> arb;
	arb = leerArbol<string>("."); // . es la repr. de arbol vacio
	pair<int, string> sol = ruta(arb);
	cout << sol.second;
	if (sol.first != 0) {
		cout << " " << sol.first;
	}
	cout << endl;
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
	//system("PAUSE");
#endif

	return 0;
}

