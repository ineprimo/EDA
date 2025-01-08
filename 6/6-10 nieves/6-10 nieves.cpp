#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// COMPLEJIDAD:

// devuelve el par <nombre de jefe,cantidad de enanos>
std::pair<std::string,int> enanos(const bintree<std::string>& tree)
{
	// caso arbol vacio
	if (tree.empty()) { return { "ninguno", 0 }; }

	// caso hoja
	if(tree.left().empty() && tree.right().empty())
	{
		std::string jefe = tree.root();
		return {jefe, 1};
	}

	// llamada recursiva
	std::pair<std::string, int> left = enanos(tree.left());
	std::pair<std::string, int> right = enanos(tree.right());

	// left
	std::string jefeL = left.first;
	int grupoL = left.second;
	// right
	std::string jefeR = right.first;
	int grupoR = right.second;

	// --- se forma nuevo grupo
	// nuevo
	std::string jefe = " ";
	int grupo = grupoL + grupoR;

	if(grupoL == grupoR)
	{
		if (jefeL > jefeR) jefe = jefeR;
		else  jefe = jefeL;
	}
	else
	{
		if(grupoL > grupoR) jefe = jefeL;
		else jefe = jefeR;
	}

	// --- ataque orco
	if(tree.root() == "Orcos")
	{
		grupo = grupo / 2;
	}

	// si no quedan enanos despues del ataque
	if (grupo <= 0) jefe = " ";

	return { jefe, grupo };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<std::string> tree;

	tree = leerArbol((std::string) "."); // "." es la repr. de arbol vacio.

	std::pair<std::string, int> sol = enanos(tree);

	// si no hay enanos
	if (sol.second == 0) std::cout << "Ninguno" << std::endl;
	else std::cout << sol.first << " " << sol.second << std::endl;
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
	{
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}