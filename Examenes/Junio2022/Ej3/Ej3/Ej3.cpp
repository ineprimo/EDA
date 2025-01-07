// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <fstream>

#include <vector>


// COMPLEJIDAD: O( ... ) siendo n ... .
int serie(const std::vector<int>& datos, int ini, int fin)
{
	int size = fin - ini;

	// Casos base:
	// Caso vector vacio. Tecnicamente no hace falta por enunciado.
	if (size == 0)
	{
		return -1;
	}
	// Caso vector 1 elemento.
	if (size == 1)
	{
		return datos[ini];
	}

	int mid = (fin + ini) / 2;

	if ((datos[mid]) > ((datos[0] + mid))) // Si el elemento de la mitad es mayor al elemento que deberia haber en la mitad dado el primero entonces miramos en la izquierda.
	{
		return serie(datos, ini, mid);
	}
	else
	{
		return serie(datos, mid, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
void resuelveCaso()
{
	int nElems = 0;


	// Lectura:
	std::cin >> nElems;
	std::vector<int> datos(nElems);
	for (size_t i = 0; i < nElems; i++)
	{
		std::cin >> datos[i];
	}


	// Resolucion:
	int sol = 0;
	sol = serie(datos, 0, nElems);


	// Escritura
	std::cout << sol << std::endl;


}

//#define DOMJUDGE
int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int nCasos = 0;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i)
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