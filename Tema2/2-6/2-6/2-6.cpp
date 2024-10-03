// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// funcioon que resuelve el problema
bool resolver(const std::vector<int>& v, int ini, int fin)
{

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	std::vector<int> sec(n);
	for (int& e : sec)
	{
		std::cin >> e;
	}

	std::cout << (resolver(sec, 0, sec.size()) ? "SI" : "NO") << std::endl;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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
