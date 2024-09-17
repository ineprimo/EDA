// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// funcioon que resuelve el problema
void resolver(std::vector<int> datos)
{
	int nPicos = 0;
	int nValles = 0;

	for (int i = 1; i < datos.size() - 1; i++)
	{
		int ant = datos[i - 1];
		int num = datos[i];
		int sig = datos[i + 1];

		bool pico = (ant < num && num > sig);
		bool valle = (ant > num && num < sig);

		if (pico) { nPicos++; }
		if (valle) { nValles++; }
	}
	std::cout << nPicos << " " << nValles << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int size = 0;
	std::cin >> size;

	std::vector<int> datos;
	int dato = 0;

	for (int i = 0; i < size; i++)
	{
		std::cin >> dato;
		datos.push_back(dato);
	}

	resolver(datos);
	// escribir sol


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
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}