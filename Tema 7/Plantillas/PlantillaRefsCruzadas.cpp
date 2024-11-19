// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>


using TablaRefs = ...

void referencias(int numLineas, TablaRefs& refs)
{
	std::string palabra;
	char c;
	for (int numLinea = 1; numLinea <= numLineas; numLinea++) {
		std::cin.get(c);
		while (c != '\n') {
			std::cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
			std::cin >> palabra;
			...
				std::cin.get(c);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	char c;
	std::cin >> n;
	std::cin.get(c); // Me salto el \n de detrás del N
	if (n == 0)
	{
		return false;
	}

	TablaRefs refs;
	referencias(n, refs);

	// escribir sol
	...
		std::cout << "---\n";
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
#endif

	return 0;
}