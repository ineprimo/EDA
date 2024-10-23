// Nuria Bango Iglesias
// VJ04

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void invierte() {
		if (this->nelems == 0)
			return;

		Nodo* act = this->prim;
		Nodo* prev = nullptr;
		Nodo* next = nullptr;

		this->ult = this->prim; // El ultimo nodo sera el primero
		
		while (act != nullptr) {
			next = act->sig;
			act->sig = prev;
			prev = act;
			act = next;
		}

		this->prim = prev; // El primer nodo es el ultimo
	}
};


bool resuelveCaso() {
	int n;
	queue_plus<int> q;
	cin >> n;
	if (!cin) return false;
	while (n != 0) {
		q.push(n);
		cin >> n;
	}

	q.invierte();

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < q.size(); ++i) {
		n = q.front();
		q.pop();
		q.push(n);
	}
	// ahora imprimimos la cola y de paso la dejamos vacía
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
