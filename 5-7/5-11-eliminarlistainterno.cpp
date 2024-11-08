// Nuria Bango Iglesias
// VJ04

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;

template <class T>
class list_plus : public list<T> {
	using Nodo = typename list<T>::Nodo;
public:
	// elimina todas las apariciones de un elemento (sin usar iteradores ni crear memoria nueva)
	// O(n) ya que recorre una unica vez la lista
	void eliminaElemento(T elem) {
		Nodo* current = this->fantasma->sig;
		Nodo* siguiente = current->sig;

		while (current != this->fantasma) {
			siguiente = current->sig;
			if (current->elem == elem) {
				this->borra_elem(current);
			}
			current = siguiente;
		}
	}
};

void resuelveCaso() {
	list_plus<int> l;

	int n;
	cin >> n;

	while (n != -1) {
		l.push_back(n);
		cin >> n;
	}

	cin >> n;

	for (int e : l) {
		cout << e << " ";
	}
	cout << '\n';

	l.eliminaElemento(n);

	// Le damos una vuelta para comprobar que la lista está bien formada
	for (int i = 0; i < l.size(); ++i) {
		n = l.back();
		l.pop_back();
		l.push_front(n);
	}

	// Ahora imprimimos la lista y de paso la dejamos vacía (tb para probar su consistencia)
	while (!l.empty()) {
		std::cout << l.front() << " ";
		l.pop_front();
	}

	std::cout << "\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
