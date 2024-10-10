// Nombre del alumno ..... Cynthia Tristan
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Set.h"

// O(n log m) donde n es el tamano del vector
// y m el num de elementos pedidos
Set<int> resolver(int n, std::vector<int> v)
{
	Set<int> set;
	set.add(v[0]);

	for (int i = 1; i < v.size(); i++) // O(n)
	{
		if (set.size() + 1 <= n)
			set.add(v[i]);
		else
		{
			if (v[i] < set.getMax() && v[i] != set.getMin() || v[i] < set.getMin())
			{ 
				set.removeMax(); // O(log m)
				set.add(v[i]);
			}
		}
	}

	return set;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	std::cin >> n;

	if (n == 0)
		return false;

	int m;
	vector<int> v;
	cin >> m;
	while (m != -1)
	{
		v.push_back(m);
		cin >> m;
	}

	Set<int> sol = resolver(n, v);

	for (int i = 0; i < sol.size(); i++) 
		cout << *(sol.toArray() + i) << " ";
	cout << "\n";

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
