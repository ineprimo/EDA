// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
// O(log n) siendo n el tamaño del vector
// esto es porque es una búsqueda binaria
int resolver(vector<int>& v, int ini, int fin)
{
	const int n = fin - ini;

	if (n == 0) // seccion nula
		return ini;
	if (n == 1) // inmediato
		return ini;

	const int mit = (ini + fin) / 2;

	if (mit % 2 == 0) // si el elto en la mitad esta en una pos par
	{
		if (v[mit] == v[mit - 1]) // si es igual al de su izq 
			return resolver(v, ini, mit); // esta en la izq
		return resolver(v, mit, fin); // si no esta a la derecha
	}

	// si esta en una posicion impar
	if (v[mit] == v[mit - 1]) // si es igual a su izq
		return resolver(v, mit, fin); // esta a la derecha
	return resolver(v, ini, mit); // si no, esta a la izq
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& e : v) cin >> e;

	// Llamada a la función resolver
	cout << resolver(v, 0, n) << endl;
	// Mostrar el resultado
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

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
