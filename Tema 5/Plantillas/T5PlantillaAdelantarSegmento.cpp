// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"


template <class T>
class list_plus : public list<T>
{
	using Nodo = typename list<T>::Nodo;

public:
	void adelantar(int pos, int length, int newPos)
	{

	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	char e;
	int n = 0, pos = 0, length = 0, dif = 0;
	list_plus<char> l;

	// leer los datos de la entrada
	std::cin >> n >> pos >> length >> dif;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> e;
		l.push_back(e);
	}

	l.adelantar(...);

	// Le damos una vuelta para comprobar que la lista está bien formada
	for (int i = 0; i < l.size(); ++i)
	{
		e = l.back();
		l.pop_back();
		l.push_front(e);
	}

	// Ahora imprimimos la lista y de paso la dejamos vacía (tb para probar su consistencia)
	while (!l.empty()) {
		std::cout << l.front() << " ";
		l.pop_front();
	}
	std::cout << std::endl;
}


//#define DOMJUDGE
int main() 
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("input1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
