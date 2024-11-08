// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;
using Par = std::pair<string, int>; // lider y fieles
//struct Par
//{
//	string lider;
//	int fieles;
//};

// O(n) siendo n el numero de nodos del arbol; dos llamadas recursivas una por cada mitad
//template <class T>
Par regreso(const bintree<std::string>& tree)
{
	// casos base
	if (tree.empty()) return {"Ninguno", 0}; // vacio
	if (tree.left().empty() && tree.right().empty())
		// si es arbol de un solo nodo
		//if (tree.root() == "Orcos") // ataque hoja no tiene mucho sentido esto pero bueno
		//	return {"Ninguno", 0};
		return {tree.root(), 1}; // si no lo es

	// recursividad mitad mitad
	const Par izq = regreso(tree.left());
	const Par der = regreso(tree.right());

	///// lider
	//string lider;
	//if (izq.fieles == der.fieles) // si tienen igual n de fieles
	//	lider = min(izq.lider, der.lider); // lider es el primero alfabeticamente
	//else if (izq.fieles > der.fieles) // el de la izq gana
	//	lider = izq.lider;
	//else // el de la derecha gana
	//	lider = der.lider;

	///// fieles
	//int fieles = izq.fieles + der.fieles;
	//if (tree.root() == "Orcos") // ataque!!!!
	//	fieles /= 2;
	//return {lider, fieles};

	/// lider
	string lider;
	if (izq.second == der.second) // si tienen igual n de fieles
		lider = min(izq.first, der.first); // lider es el primero alfabeticamente
	else if (izq.second > der.second) // el de la izq gana
		lider = izq.first;
	else // el de la derecha gana
		lider = der.first;

	/// fieles
	int fieles = izq.second + der.second;
	if (tree.root() == "Orcos") // ataque!!!!
		fieles /= 2;
	return {lider, fieles};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	const bintree<string> tree = leerArbol<string>(".");
	const Par sol = regreso(tree);

	//cout << sol.lider;
	//if (sol.lider == "Ninguno" || sol.fieles == 0)
	//	cout << endl;
	//else
	//	cout << " " << sol.fieles << endl;

	//cout << sol.first;
	if (sol.first == "Ninguno" || sol.second == 0)
		cout << "Ninguno" << endl;
	else
		cout << sol.first << " " << sol.second << endl;
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
