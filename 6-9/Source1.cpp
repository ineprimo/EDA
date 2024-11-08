// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

struct tsol {

	int equipos; // numero de equimos de rescate necesarios para rescatar a todos
	int perAtrapados; // numero de excursionistas en la rama
	bool hayExc; // si hay excursionistas en la rama
};
tsol excursionistas(bintree<int> const&arbol) {

	if (arbol.empty()) {
		return { 0, 0, false };
	}

	tsol izq = excursionistas(arbol.left());
	tsol der = excursionistas(arbol.right());

	// si no hay peronas en el nodo actual
	if (arbol.root() == 0) {
		// si hay personas en los nodos de mas abajo 
		if (izq.hayExc || der.hayExc) {
			// devolvemos la suma del numero de equipos de rescate, el maximo entre el numero de personas atrapadas
			// y que hay personas atrapadas
			return { izq.equipos+der.equipos, std::max(izq.perAtrapados, der.perAtrapados) , true};
		}
		else {
			return { 0, 0, false };
		}		
	}
	// si hay personas en el nodo actual
	if (der.hayExc || izq.hayExc) {
		// devolvemos la suma del numero de equipos de rescate, el maximo entre el numero de personas atrapadas mas el actual
		// y que hay personas atrapadas
		return { izq.equipos + der.equipos, std::max(izq.perAtrapados + arbol.root(), der.perAtrapados + arbol.root()) , true };
	}

	return { 1, std::max(izq.perAtrapados + arbol.root(), der.perAtrapados + arbol.root()),true};
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);

	tsol sol = excursionistas(arbol);

	std::cout << sol.equipos << ' ' << sol.perAtrapados << std::endl;

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