// Nuria Bango Iglesias
// VJ04

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;

// funcion externa al TAD List que recorre la lista eliminando de ella los elementos cuyo valor es estrictamente menor que el elemento anterior
// no crea memoria (llamando a push_back ni push_front)
// O(n) donde n=l.size() ya que recorre una unica vez la lista con iteradores
void ordenacionLineal(list<int>& lista) {
	if (lista.empty())
		return;

	list<int>::iterator it = lista.begin();
	list<int>::iterator sig = it;
	sig++;

	while (sig != lista.end()) {
		// (*it) -> el elemento apuntado por it
		// erase devuelve el iterador tras eliminar el elemento apuntado por el iterador pasado por argumento
		if ((*it) > (*sig))
			sig = lista.erase(sig);
		else {
			++it;
			++sig;
		}

	}
}

void resuelveCaso() {
	list<int> l;

	int n;
	cin >> n;

	while (n != -1) {
		l.push_back(n);
		cin >> n;
	}

	ordenacionLineal(l);

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
