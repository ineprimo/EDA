#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

void sumaAscendientes(bintree<int> tree, int& sumaAnt, bool& primeraVez) 
{



}

void sumaDescendientes(bintree<int> tree, int& sumaDes, bool& primeraVez)
{
	//Si no hay raiz
	if (tree.empty()) {
		return;
	}
	else 
	{
		if (primeraVez) {
			primeraVez = false;
		}
		else 
		{
			sumaDes += tree.root();
		}

	}

	sumaDescendientes(tree.left(), sumaDes, primeraVez);
	sumaDescendientes(tree.right(), sumaDes, primeraVez);
}

// función que resuelve el problema
void resolver(bintree<int> tree, int& singulares, int& sumaAnt, int& sumaDes, bool& primeraVez) {
	//Si no hay raiz
	if (tree.empty()) 
	{
		//sumaAnt = 0; 
		return;
	}

	//Si hay derecha e izquierda vacías
	/*if (tree.left().empty() && tree.right().empty()) {

		return;
	}*/

	sumaDescendientes(tree, sumaDes, primeraVez);

	//sumaAscendientes(tree, sumaAnt, primeraVez);
	// escribir sol
	cout << "despues: " << sumaDes << ", antes: " << sumaAnt << endl;
	
	sumaDes = 0; 
	primeraVez = true;
	
	resolver(tree.left(), singulares, sumaAnt, sumaDes, primeraVez);
	//Si no hay raiz
	if (tree.left().empty())
	{
		sumaAnt -= tree.root();

	}
	else sumaAnt += tree.root();
	
	sumaDes = 0;
	primeraVez = true;

	resolver(tree.right(), singulares, sumaAnt, sumaDes, primeraVez);
	//Si no hay raiz
	if (tree.right().empty())
	{
		sumaAnt -= tree.root();

	}
	else sumaAnt += tree.root();



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1); // -1 es vacío

	int singulares = 0;
	//Sumatorios de los nodos anteriores y posteriores, para comparar luego
	int sumaAnt = 0, sumaDes = 0;
	bool primeraVez = true;
	resolver(tree, singulares, sumaAnt, sumaDes, primeraVez);

	// escribir sol
	//cout << sumaDes << endl;
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
	//for (int i = 0; i < numCasos; ++i) resuelveCaso();
	resuelveCaso();
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}