// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;

// O(n) donde n es el tamano de la lista que es recorrida una sola vez
void resuelve(list<int>& lista)
{
	if (lista.empty())
		return;

	auto it = lista.begin();
	auto sig = it;
	++sig;

	while (sig != lista.end())
	{
		if (*it > *sig)
			sig = lista.erase(sig); // erase devuelve el iterador tras el elto eliminado
		else
		{
			++it;
			++sig;
		}
	}
}

void resuelveCaso()
{
	int n;
	list<int> l;
	cin >> n;

	while (n != -1)
	{
		l.push_back(n);
		cin >> n;
	}

	resuelve(l);

	// Le damos una vuelta para comprobar que la lista est� bien formada
	for (int i = 0; i < l.size(); ++i)
	{
		n = l.back();
		l.pop_back();
		l.push_front(n);
	}

	// Ahora imprimimos la lista y de paso la dejamos vac�a (tb para probar su consistencia)
	while (!l.empty())
	{
		std::cout << l.front() << " ";
		l.pop_front();
	}

	std::cout << endl;
}

int main()
{
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
