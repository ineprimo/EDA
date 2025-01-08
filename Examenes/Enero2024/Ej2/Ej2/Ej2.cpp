// Pablo Iglesias Rodrigo.
// EDA-GDV37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// Sease pair.first si hay un punto de corte entre los valores y pari.second un par que es pair.fist la primera coordenada y pair.second la segunda den entre que valores esta.
// COMPLEJIDAD: O(log n) siendo n de elementos de ambos vectores pues es el mismo, va recorriendo por mitades.
// Metodo que dado dos vectores de igual tamanyo uno ascendente y otro descendente dice entre que valores hay un punto de corte.
std::pair<bool, std::pair<int, int>> puntoCorte(const std::vector<int>& vAsc, const std::vector<int>& vDes, int ini, int fin)
{
	int elems = fin - ini;

	// caso base
	if (elems == 1)
	{
		bool cortan = false;

		if (vDes[ini] == vAsc[ini]) cortan = true;

		// se cortan por la izq
		if (vDes[0] < vAsc[0])
		{
			return { false, { -1, 0 } };
		}

		// se cortan por la der
		if (vDes[vAsc.size() - 1] > vAsc[vAsc.size() - 1])
		{
			return { false, { vAsc.size() - 1, vAsc.size() } };
		}

		// si es false nos interesan los dos valores del pair indice si no solo el primero
		return { cortan, {ini, fin} };
	}

	int mit = (ini + fin) / 2;

	// Si coinciden en la mitad
	if (vDes[mit] == vAsc[mit])
	{
		return { true, {mit, mit} };
	}
	// Mirar izq
	if (vDes[mit] < vAsc[mit])
	{
		return puntoCorte(vAsc, vDes, ini, mit);
	}
	// Mirar der
	if (vDes[mit] > vAsc[mit])
	{
		return puntoCorte(vAsc, vDes, mit, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	// Lectura:
	int nElems = 0; // Numero de elementos de ambos vectores.
	std::cin >> nElems;

	if (nElems == 0)
	{
		return false;
	}

	std::vector<int> ascendentes(nElems); // Vector con valores ascendentes.
	std::vector<int> descendentes(nElems); // Vector con valores descendentes.

	// Vector 1:
	for (int i = 0; i < nElems; i++)
	{
		std::cin >> ascendentes[i];
	}
	// Vector 2:
	for (int i = 0; i < nElems; i++)
	{
		std::cin >> descendentes[i];
	}


	// Resolucion:
	std::pair<bool, std::pair<int, int>> sol;
	sol = puntoCorte(ascendentes, descendentes, 0, nElems);


	// Escritura:
	if (sol.first)
	{
		std::cout << "SI" << " " << sol.second.first << std::endl;
	}
	else
	{
		std::cout << "NO" << " " << sol.second.first << " " << sol.second.second << std::endl;
	}


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