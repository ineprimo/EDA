// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"

using namespace std;


// función que resuelve el problema
Set<int> resolver(vector<int>& datos, int n) {

	Set<int> aux;
	aux.add(datos[0]);

	for (int i = 1; i < datos.size(); ++i) {
		if (aux.size() < n) {
			aux.add(datos[i]);
		}
		else {
			if ((datos[i] < aux.getMax() && datos[i] != aux.getMin()) || datos[i] < aux.getMin()) {
				aux.removeMax();
				aux.add(datos[i]);
			}
		}
	}

	return aux;
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

	Set<int> sol = resolver(v, n);

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