// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include <string>


void procesaEnvios(... resultados)
{
	std::string equipo, problema, veredicto;
	int minuto;

	std::cin >> equipo;
	while (equipo != "FIN") {
		cin >> problema >> minuto >> veredicto;

		...

			std::cin >> equipo;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	...
		procesaEnvios(resultados);

	// Se imprime la salida
	...
		std::cout << "---\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("input.txt");
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