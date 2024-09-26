// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// el coste de esta funcion es logaritmico O(n*log(n))
// función que resuelve el problema
/bool parcialmenteOrdenado(vector<int>& datos, int ini, int fin, int& mayor, int& menor) {
	// casos base
	if (fin == ini)
		return true;
	if (fin - ini == 1) {
		if (datos[fin] >= datos[ini])
		{
			mayor = datos[fin]; menor = datos[ini];
			return true;
		}

		mayor = datos[ini]; menor = datos[fin];
		return false;
	}

	// reserva el espacio de la memoria
	int mayorI, menorI, mayorD, menorD;

	// comprueba los lados derecho e izquierdo
	int mid = ini + ((fin - ini) / 2);
	bool ordenadoIzq = parcialmenteOrdenado(datos, ini, mid, mayorI, menorI);
	bool ordenadoDer = parcialmenteOrdenado(datos, mid + 1, fin, mayorD, menorD);

	// Asigna mayor y menor
	mayor = mayorD;
	menor = menorI;

	return ordenadoIzq && ordenadoDer && (mayorD >= mayorI && menorI <= menorD);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	vector<int> datos;
	int dato = 0;

	cin >> dato;

	if (dato == 0)
		return false;

	while (dato != 0)
	{
		datos.push_back(dato);
		cin >> dato;
	}

	int mayor, menor;
	// escribir sol
	if (parcialmenteOrdenado(datos, 0, datos.size() - 1, mayor, menor))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
