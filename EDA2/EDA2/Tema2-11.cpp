
/*
Nombre completo: Andres Garcia Navarro
Usuario del juez: EDA-GDV27
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// la complejidad del algoritmo es logaritmica O(logn) porque se recorre tan solo cierta parte del vector de forma recursiva
// función que resuelve el problema
char resolver(const vector<char>& sec, int prim, int ult, int ini, int fin) {
	//casos base:
	int dif = fin - ini;
	if (dif == 0) {
		return prim;
	}
	if (dif == 1) {
		return sec[ini] == prim ? 
			sec[ini] + 1 : 
			sec[ini] - 1;
	}

	if (sec[ini] != prim) return prim;
	if (sec[fin-1] != ult) return ult;

	int mitad = (fin + ini) / 2;
	char esperado = prim + (mitad - ini);
	if (esperado == sec[mitad])
	{
		return resolver(sec, sec[mitad], ult, mitad, fin);
	}
	else
	{
		return resolver(sec, prim, sec[mitad - 1], ini, mitad);

	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char prim, ult, n;
	cin >> prim >> ult;
	n = ult - prim;
	vector<char> sec(n);
	for (char& e : sec) cin >> e;
	cout << resolver(sec, prim, ult, 0, n) << endl;
}

//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("input2.txt");
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