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
		Nodo* ant = nullptr; // Nodo para tener referencia al anterior al actual.

		Nodo* nA = nullptr; // Nodo donde esta A.
		Nodo* nB = nullptr; // Nodo donde esta B.

		// Buscamos el A.
		int i = 0;
		bool encontradoA = false;
		while (!encontradoA && i < this->nelems)
		{
			if (act->elem == a)
			{
				encontradoA = true;
				nA = act;
			}
			else
			{
				Nodo* sig = act->sig;
				act = sig;
				i++;
			}
		}
		// Buscamos al B.
		bool encontradoB = false;
		while (!encontradoB && i < this->nelems)
		{
			if (act->elem == b)
			{
				encontradoB = true;
				nB = act;
			}
			else
			{
				Nodo* sig = act->sig;
				ant = act; // Nos guardamos el anterior por si acaso.
				act = sig;
				i++;
			}
		}

		if (encontradoA && i >= this->nelems)
		{
			return;
		}

		// Nuevos nodos auxiliares para mover las cosas.
		Nodo* nASig = nA->sig; // El siguiente al A.
		Nodo* nBSig = (nB->sig == nullptr) ? nBSig = nullptr : nBSig = nB->sig; // El siguiente al B.
		Nodo* nBAnt = ant; // El anterior al B.

		// Reordenar nodos.
		nA->sig = nB;
		nB->sig = nASig;
		nBAnt->sig = nBSig;

		// Por si acaso hay que cambiar el ultimo.
		this->ult = (nB->sig == nullptr) ? this->ult = nBAnt : this->ult = nBSig;
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