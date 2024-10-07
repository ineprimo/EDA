// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// O(log n) - busqueda binaria
bool elemento_situado(const vector<int>& v, int ini, int fin)
{
	int diff = fin - ini;

	if (diff == 0) return false;
	if (diff == 1)
	{
		if (v[ini] == ini)
			return true;
		return false;
	}

	int mit = (ini + fin) / 2;
	
	if (v[mit] > mit) // si el elto a la mitad es mayor que el indice mitad, ningun elto a la derecha esta bien situado
		return elemento_situado(v, ini,  mit); // busca a la izq
	if (v[mit] < mit) // si el elto a la mitad es menor que el indice mitad, ningun elto a la izq esta bien situado
		return elemento_situado(v, mit, fin); // busca a la der
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	cin >> n;
	vector<int> sec(n);
	for (int& e : sec) cin >> e;
	cout << (elemento_situado(sec, 0, n) ? "SI" : "NO") << endl;
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
	//system("PAUSE");
#endif

	return 0;
}
