// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// COMPLEJIDAD: 
int resolver(std::vector<int>& vec, int ini, int fin)
{
	int size = fin - ini;

	// Casos base:
	if (size == 0) // Caso base 0 elementos edvolvemos 0.
	{
		return 0;
	}
	if (size == 1) // Caso base 1 elemento devolvemos el elemento.
	{
		return vec[ini];
	}

	int mitad = (fin + ini) / 2; // Calculamos el indice de la mitad.

	// Comprobamos en que lado esta el menor para hacer la busqueda a ese lado. 
	// (El vector esta ordenadoa su manera, si mitad > ini el minimo estara a al izquierda y viceversa)
	if (vec[mitad] > vec[ini])
	{
		return resolver(vec, ini, mitad); // Mitad izquierda.
	}
	else
	{
		return resolver(vec, mitad, fin); // Mitad derecha.
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	std::cin >> n;
	if (n == -1)
	{
		return false;
	}

	std::vector<int> datos(n);
	for (int& d : datos)
	{
		std::cin >> d;
	}

	std::cout << resolver(datos, 0, datos.size()) << std::endl;
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