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

		int i = 0;
		bool encontradoA = false;
		Nodo* nA = nullptr;
		while(!encontradoA && i < this->size())
		{
			if(act->elem == a)
			{
				encontradoA = true;
				nA = act;
			}

			Nodo* sig = act->sig;
			act = sig;
			i++;
		}

		Nodo* despA = nullptr;
		if (encontradoA) despA = nA->sig;

		bool encontradoB = false;
		Nodo* nB = nullptr;
		Nodo* antB = nullptr; // te lo vas guardando por si acaso para cuando aparezca
		while (!encontradoB && i < this->size())
		{
			if (act->elem == b)
			{
				encontradoB = true;
				nB = act;
			}
			else
			{
				antB = act; // lo guardas siempre mientras no hayas encontrado b
			}

			Nodo* sig = act->sig;
			act = sig;
			i++;
		}

		Nodo* despB = nullptr;
		if(encontradoB) despB = nB->sig;

		// reordenar nodos
		if(encontradoA && encontradoB)
		{
			nA->sig = nB;
			nB->sig = despA;
			antB->sig = despB;
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