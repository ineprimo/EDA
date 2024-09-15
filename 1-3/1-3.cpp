// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
// O(n) siendo n el tamaño del vector, lo recorre una vez
bool resolver(std::vector<int> datos, int p)
{
	if (p >= datos.size() - 1 || p < 0) return true;
	
	int i = 0;
	int maxIzq = datos[p], minDer = datos[datos.size() - 1];

	while (i <= p)
	{
		if (maxIzq < datos[i]) maxIzq = datos[i];
		i++;
	}

	while (i < datos.size()) // aqui i = p
	{
		if (minDer > datos[i]) minDer = datos[i];
		i++;
	}

	if (maxIzq < minDer)
		return true;
	return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	int n = 0, p = 0;
	std::cin >> n >> p;

	std::vector<int> datos(n);
	for (int i = 0; i < n; i++)
		std::cin >> datos[i];

	resolver(datos, p) ? std::cout << "SI\n" : std::cout << "NO\n";
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
