// Pablo Iglesias Rodrigo.
// EDA-GDV37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// 
//
std::pair<bool, std::pair<int, int>> puntoCorte(const std::vector<int>& vAsc, const std::vector<int>& vDes, int ini, int fin, int& min, int& max)
{
	int elems = fin - ini;

	if (elems == 0)
	{
		return { false, {0, 0} };
	}
	if (elems == 1)
	{

	}

	int mid = (ini + fin) / 2;

	if (vAsc[mid] == vDes[mid])
	{

	}



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// LEctura:
	int nElems = 0;
	std::cin >> nElems;

	if (nElems == 0) return false;

	std::vector<int> ascendentes(nElems);
	std::vector<int> descendentes(nElems);

	for (int i = 0; i < nElems; i++)
	{
		std::cin >> ascendentes[i];
	}

	for (int i = 0; i < nElems; i++)
	{
		std::cin >> descendentes[i];
	}


	// Resolucion:



	// Escritura:



	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}