// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include <vector>
using namespace std;

template <class T>
class queue_plus : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;

public:
	// O(2n) = O(n) siendo n el tamano tando de mult como de la cola
	void replicaElems(const vector<int>& mult)
	{
		Nodo* actual = this->prim;
		Nodo* siguiente = actual->sig;
		Nodo* anterior = nullptr;
		Nodo* ultimo = this->ult;

		for (int i = 0; i < mult.size(); i++)
		{ // Si mult[i] = 0 entonces el elemento i-ésimo se elimina de la cola q.
			if (mult[i] == 0)
			{
				siguiente = actual->sig;

				anterior != nullptr ? // si no es el primero
					anterior->sig = actual->sig
				: this->prim = actual->sig; // si es el primero

				if (this->ult == actual) // si es el ultimo
					this->ult = anterior;

				actual->sig = this->prim;
				this->prim = actual;
				this->pop();

				actual = siguiente;
			}
			else if (mult[i] == 1)
			{ // Si mult[i] = 1 entonces el elemento i-ésimo de q se queda como estaba.
				anterior = actual;
				actual = actual->sig;
			}
			else if (mult[i] > 1)
			{ // Si mult[i] = v, siendo v > 1, entonces se añaden v - 1
				// copias tras el elemento i-ésimo de q.
				siguiente = actual->sig;
				ultimo = this->ult;

				for (int j = 0; j < mult[i] - 1; ++j) 
					this->push(actual->elem); // se anaden al final

				anterior = this->ult;
				if (siguiente != nullptr)
				{ // se actualizan las relaciones
					actual->sig = ultimo->sig;
					this->ult->sig = siguiente;
					this->ult = ultimo;
					this->ult->sig = nullptr;
				}
				actual = siguiente;
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
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
	for (int i = 0; i < q.size(); ++i)
	{
		n = q.front();
		q.pop();
		q.push(n);
	}

	// Ahora imprimimos la cola y de paso la dejamos vacía (tb para probar su consistencia)
	cout << "[";
	if (!q.empty())
	{
		cout << q.front();
		q.pop();
	}
	while (!q.empty())
	{
		cout << ", " << q.front();
		q.pop();
	}
	cout << "]" << endl;
	return true;
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
