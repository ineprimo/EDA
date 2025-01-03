// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Algorimo que calcula que un vector es suficientemente disperos.
// COMPLEJIDAD: O(n) siendo n el numero de elementos del vector el cual solo recorre 1 vez.
bool disperso(const std::vector<int>& datos, int ini, int fin, int dispersion)
{
	// Casos base:
	if (fin - ini == 1) // Un unico valor es disperso.
	{
		return true;
	}
	if (fin - ini == 2) // La diferencia de dos valores deber ser mayor o igual a la dispersion.
	{
		return (abs(datos[ini] - datos[fin - 1]) >= dispersion);
	}

	int mid = ((ini + fin) / 2); // Indice de la mitad.

	bool izq = disperso(datos, ini, mid, dispersion); // Calcular la dispersion de la izquierda.
	bool der = disperso(datos, mid, fin, dispersion); // Calcular la dispersion de la derecha.

	bool sol = (abs(datos[ini] - datos[fin - 1]) >= dispersion) && izq && der;

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// Lectura:
	int tiradas = 0; // Numero de tiradas a considerar.
	int dispersion = 0; // Valor de dispersion deseado.
	std::vector<int> datos; // Vector con las tiradas del dia.

	std::cin >> tiradas >> dispersion;

	if (!std::cin)
	{
		return false;
	}

	for (int i = 0; i < tiradas; i++)
	{
		int e = 0;
		std::cin >> e;
		datos.push_back(e);
	}

	// Resolucion y escritura:
	std::cout << (disperso(datos, 0, tiradas, dispersion) ? "SI" : "NO") << std::endl;

	return true;
}

int main() {
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
	//system("PAUSE");
#endif

	return 0;
}