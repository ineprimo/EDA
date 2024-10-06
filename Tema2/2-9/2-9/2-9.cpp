// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// COMPLEJIDAD: logartimica O(log n) siendo n el numero de elementos del vector, el cual no recorre entero.
bool buscar(std::vector<int>& vec, int ini, int fin, int elem)
{
	int size = fin - ini;

	// Casos base:
	if (size == 0) // Caso base 0 elementos edvolvemos 0.
	{
		return 0;
	}
	if (size == 1) // Caso base 1 elemento devolvemos el elemento.
	{
		return vec[ini] == elem;
	}

	int mitad = (fin + ini) / 2; // Calculamos el indice de la mitad.

	// Comprobamos que la mitad de la izquierda esta ordenada.
	if (vec[mitad] >= vec[ini])
	{
		if (vec[ini] <= elem && vec[mitad] > elem) // Comprobamos que el valor este en la izquierda.
		{
			return buscar(vec, ini, mitad, elem); // Mitad izquierda.
		}
		else // Y si no esta en la derecha.
		{
			return buscar(vec, mitad, fin, elem); // Mitad derecha.
		}
	}
	else // Si no esta ordenada la izquierda lo estara la derecha.
	{
		if (vec[ini] > elem && vec[mitad] <= elem) // Comprobamos que el valor este en la derecha.
		{
			return buscar(vec, mitad, fin, elem); // Mitad derecha.
		}
		else // Y si no esta en la izquierda.
		{
			return buscar(vec, ini, mitad, elem); // Mitad izquierda.
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	int elem = 0;
	std::cin >> n >> elem;
	if (n == -1)
	{
		return false;
	}

	std::vector<int> datos(n);
	for (int& d : datos)
	{
		std::cin >> d;
	}

	if (buscar(datos, 0, datos.size(), elem))
	{
		std::cout << "SI" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
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