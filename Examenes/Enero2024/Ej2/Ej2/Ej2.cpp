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

	// Casos base:
	if (elems == 0) // Caso base vector vacio.
	{
		return { false, {0, 0} };
	}
	if (elems == 1) // Caso base vector 1 elemento.
	{
		if (vAsc[ini] == vDes[ini])
		{
			return { true, { ini, 0 } };
		}
		else if (vAsc[ini] > vDes[ini])
		{
			return { false, { ini - 1, ini } };
		}
		else if (vAsc[ini] < vDes[ini])
		{
			return { false,  { ini, ini + 1 } };
		}
	}


	int mid = (ini + fin) / 2;

	if (vAsc[mid] == vDes[mid])
	{
		return { true, {mid, 0} };
	}
	if (vAsc[mid] < vDes[mid]) // Si el numero del ascendente es menor sabemos que el punto de corte estara a la derecha.
	{
		puntoCorte(vAsc, vDes, mid, fin);
	}
	else if (vAsc[mid] > vDes[mid]) // Y viceversa.
	{
		puntoCorte(vAsc, vDes, ini, mid);
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