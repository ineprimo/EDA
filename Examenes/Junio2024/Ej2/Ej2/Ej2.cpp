// Pablo Iglesias Rodrigo.
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// Lectura:
	int M = 0;
	int n = 0;

	std::cin >> M >> n;

	std::vector<int> datos(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> datos[i];
	}


	TipoSolucion sol = resolver(datos);
	// escribir sol

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}