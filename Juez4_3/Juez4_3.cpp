#include <iostream>
#include <iomanip>
#include <fstream>
#include "Polinomio.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
bool resuelveCaso()
{
	Polinomio p;
	int n = 0, m = 0;
	std::cin >> p;
	if (!std::cin)
		return false;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> m;
		std::cout << p.evaluar(m) << " ";
	}
	std::cout << std::endl;
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