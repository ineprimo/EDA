/*
Nombre completo: Andres Garcia Navarro
Usuario del juez:
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include <vector>
using namespace std;

template <class T>
class queue_plus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:
	// es complejidad lineal O(n+m) siendo n el tamaño de la cola actual y m el numero resultante de la suma del valor de los enteros que componen mult
	void replicaElems(vector<int> const& mult) {
		Nodo* nodoActual = this->prim;
		Nodo* nodoAnterior = nullptr;
		for (int i = 0; i < mult.size(); i++)
		{
			if (mult[i] == 0) {
				Nodo* nodoSiguiente = nodoActual->sig;

				nodoAnterior != nullptr ? 
					nodoAnterior->sig = nodoActual->sig :
					this->prim = nodoActual->sig;

				if (nodoActual == this->ult)
					this->ult = nodoAnterior;

				nodoActual->sig = this->prim;
				this->prim = nodoActual;
				this->pop();

				nodoActual = nodoSiguiente;

			}
			else if (mult[i] > 1) {

				Nodo* nodoSiguiente = nodoActual->sig;
				Nodo* nodoUltimotmp = this->ult;

				for (int j = 0; j < mult[i] - 1; ++j) this->push(nodoActual->elem);

				nodoAnterior = this->ult;

				if (nodoSiguiente != nullptr)
				{
					nodoActual->sig = nodoUltimotmp->sig;
					this->ult->sig = nodoSiguiente;

					this->ult = nodoUltimotmp;
					this->ult->sig = nullptr;
				}

				nodoActual = nodoSiguiente;
			}
			else {
				nodoAnterior = nodoActual;
				nodoActual = nodoActual->sig;
			}
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	queue_plus<int> q;

	cin >> n;
	vector<int> mult(n);
	vector<int> aux(n); // Para darle la vuelta a la secuencia de entrada

	// Leemos la secuencia invertida para q y le damos la vuelta
	for (int i = n - 1; i >= 0; --i) cin >> aux[i];
	for (int e : aux) q.push(e);

	// Leemos la secuencia invertida para mult
	for (int i = n - 1; i >= 0; --i) cin >> mult[i];

	// llamada al metodo
	q.replicaElems(mult);

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < q.size(); ++i) {
		n = q.front();
		q.pop();
		q.push(n);
	}

	// Ahora imprimimos la cola y de paso la dejamos vacía (tb para probar su consistencia)
	cout << "[";
	if (!q.empty()) {
		cout << q.front();
		q.pop();
	}
	while (!q.empty()) {
		cout << ", " << q.front();
		q.pop();
	}
	cout << "]" << endl;
	return true;
}

//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos=0;
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
