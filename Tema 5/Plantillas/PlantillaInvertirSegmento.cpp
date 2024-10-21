// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n = 0, pos = 0, longitud = 0, elem = 0;
	list<int> l;
	std::cin >> n;
	if (!std::cin) { return false; }
	std::cin >> pos >> longitud;

	// Leo la lista
	for (int i = 0; i < n; ++i) { std::cin >> elem; l.push_back(elem); }

	// Llamada a la funcion pedida
	invertirSegmento(l, pos, longitud);

	// Muestro la lista
	for (int& e : l) std::cout << e << " ";
	std::cout << std::endl;

	return true;
}

//#define DOMJUDGE
int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("input1.txt");
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