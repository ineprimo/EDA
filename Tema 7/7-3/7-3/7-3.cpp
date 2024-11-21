// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include <cctype>


void resolver(std::string const& primerDeporte, ...)
{
	std::string deporte, alumno;
	deporte = primerdeporte;
	while (deporte != "_FIN_") {
		...
			std::cin >> alumno;
		while (!isupper(alumno[0]) && alumno != "_FIN_") {
			...
				std::cin >> alumno;
		}
		deporte = alumno;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	std::string primerDeporte;
	std::cin >> primerDeporte;
	if (!std::cin)
	{
		return false;
	}

	resolver(primerDeporte, ...);
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