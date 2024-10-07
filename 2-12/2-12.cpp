// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
// O(log n) siendo n el tamaño del primer vector
// esto es porque es una búsqueda binaria
int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) {
    int n = fin - ini;

	if (n == 0) // vector nulo 
		return ini;
    if (v1[ini] != v2[ini]) // comparaciono de primeros
        return ini;
	if (n == 1) // inmediato a la derecha
		return ini + 1;

    int mit = (ini + fin) / 2;

    if (v1[mit] == v2[mit]) // si es correcto busca a la derecha
		return resolver(v1, v2, mit, fin);
		
	return resolver(v1, v2, ini, mit);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos = 0;
    cin >> numElementos;
    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);
    for (int& e : v1) cin >> e;
    for (int& e : v2) cin >> e;
    int sol = resolver(v1, v2, 0, v1.size()-1);
    cout << v1[sol] << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
