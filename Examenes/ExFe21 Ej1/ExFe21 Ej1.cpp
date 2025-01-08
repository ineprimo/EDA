#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"
#include <vector>

template <class T>
class queue_plus : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;

public:

	// Complejidad: O(n) siendo n el numero de elementos de la cola

	// mueve al elemento b de su pos a la pos inmediatamente detras del elemento a
	// / en caso de haber multiples apariciones de los elementos a y/o b se considerara:
	//		la primera aparicion de a
	//		la primera aparicion de b tras la primera aparicion de a
	// / si alguno de los elementos no se encuentra en la cola / si b no aparece detras de a -> no se hace nada
	void cuela(const T& a, const T& b)
	{
		// si esta vacia
		if (this->empty()) return;

		Nodo* act = this->prim; // nodo para recorrer cola

		bool encontradoA = false;
		bool encontradoB = false;

		Nodo* nA = nullptr;
		Nodo* nB = nullptr;

		int i = 0;
		while (!encontradoB && i < this->size())
		{
			// encuentras a
			if (act->elem == a && !encontradoA)
			{
				encontradoA = true;
				nA = act;
			}

			// encuentras b
			if (encontradoA && (act != this->ult) && act->sig->elem == b)
			{
				encontradoB = true;
				nB = act->sig;

				// se salta b
				act->sig = nB->sig;

				// se pone despues de a, apunta al siguiente del a
				nB->sig = nA->sig;

				// a apunta a b
				nA->sig = nB;
			}

			// avanza
			++i;
			act = act->sig;
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	int e, b, a = 0;
	queue_plus<int> cola;

	std::cin >> e;

	if(!std::cin)
	{
		return false;
	}

	while(e != -1)
	{
		cola.push(e);
		std::cin >> e;
	}
	std::cin >> a >> b;

	cola.cuela(a, b);

	// escribir salida
	// Ahora imprimimos la cola y de paso la dejamos vacía (tb para probar su consistencia)
	if (!cola.empty())
	{
		std::cout << cola.front();
		cola.pop();
	}
	while (!cola.empty())
	{
		std::cout << "  " << cola.front();
		cola.pop();
	}
	std::cout << std::endl;
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

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}