// Pablo Iglesias Rodrigo
// EDA-GDV35

/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
*/

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
	// COMPLEJIDAD: O(n) siendo n el numero de elementos de la cola la cual en el caso peor la recorre entera.
	void cuela(const T& a, const T& b)
	{
		// Comprobamos primero que no este vacia la cola.
		if (this->empty())
		{
			return;
		}

		Nodo* act = this->prim; // Hacemos un nodo para recorrer la lista.

		Nodo* nA = nullptr; // Nodo donde esta A.
		Nodo* nB = nullptr; // Nodo donde esta B.

		bool encontradoA = false;
		bool encontradoB = false;

		int i = 0;
		while (!encontradoB && i < this->nelems)
		{
			// Para encontrar A.
			if (act->elem == a && !encontradoA)
			{
				encontradoA = true;
				nA = act;
			}
			// Para encontrar B. Solo si se ha encotrado A, no se ha llegado al ultimo elemento y el siguiente al actual es el que buscamos. Nos quedamos antes del que buscamos.
			if (encontradoA && act != this->ult && act->sig->elem == b)
			{
				// Reordenar los nodos. (Para caso 1)
				nB = act->sig; // nB = 3. // act = 1
				act->sig = nB->sig; // 2->4
				nB->sig = nA->sig; // 3->2
				nA->sig = nB; // 1->3
				encontradoB = true;
			}
			++i;
			act = act->sig;
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	// Lectura:
	int elem = 0; // Para guardar elementos.
	int a = 0; // Elemento a.
	int b = 0; // Elemento b.
	queue_plus<int> cola; // Cola del ejercicio.

	std::cin >> elem;

	if (!std::cin)
	{
		return false;
	}

	while (elem != -1)
	{
		cola.push(elem);
		std::cin >> elem;
	}
	std::cin >> a >> b;


	// Resolucion:
	cola.cuela(a, b);


	// Escritura:
	while (!cola.empty())
	{
		std::cout << cola.front() << " ";
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