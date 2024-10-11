// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Set.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n, elem;
	Set<int> set1, set2;

	cin >> n;
	if (!cin) { return false; }

	for (int i = 0; i < n; i++)
	{
		cin >> elem;
		set1.add(elem);
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> elem;
		set2.add(elem);
	}

	cout << (set1 - set2) << endl;

	return true;
}

int main()
{
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
	system("PAUSE");
#endif

	return 0;
}