//Denisa Juarranz Berindea
//EDA-GDV37

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

//Este algoritmo tiene complejidad lineal O(n), siendo n el número de nodos del árbol

template <class T>
pair<int, string> viaje(bintree<T> const& tree) {
	//Si no hay ramas, no hay enanos ni lider
	if (tree.empty()) return { 0, "" };
	
	//Si hay derecha e izquierda vacías, habrá un enano que será el líder
	if (tree.left().empty() && tree.right().empty()) return {1, tree.root()};

	pair<int, string> viajeL, viajeR, final;

	//Ahora comprobaremos cada lado, por separado
	viajeL = viaje(tree.left());
	viajeR = viaje(tree.right());

	//Conseguiremos la solución final
	//Miembros
	final.first = viajeL.first + viajeR.first;
	//Lider
	//Si mismo número de enanos, se mira alfabéticamente
	if (viajeL.first == viajeR.first) {

		if (viajeL.second < viajeR.second) final.second = viajeL.second;
		else final.second = viajeR.second;
	}
	else {
		if (viajeL.first > viajeR.first) {
			final.second = viajeL.second;
		}
		else final.second = viajeR.second;
	}

	//Orcos
	//Si nos encontramos con orcos, se reduce a la mitad
	if (tree.root() == "Orcos") final.first = final.first / 2;
	
	//Si se queda vacío
	if (final.first <= 0) final = { 0, "" };
	return final;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<string> arb;
	arb = leerArbol<string>("."); // . es la repr. de arbol vacio
	pair<int, string> final = viaje(arb);
	if (final.first == 0) cout << "Ninguno" << endl;
	else cout << final.second << " " << final.first << endl;
}

int main()
{
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