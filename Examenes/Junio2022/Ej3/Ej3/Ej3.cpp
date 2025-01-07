// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <fstream>

#include <vector>


// COMPLEJIDAD: O( ... ) siendo n ... .
int serie(const std::vector<int>& datos, int ini, int fin)
{





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
	serie()



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