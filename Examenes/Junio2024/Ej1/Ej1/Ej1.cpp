// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"


// Clase extendida con operacion interna duplicar que reaprovecha nodos existentes
template <class T>
class list_eda_plus : public list<T>
{
	using Nodo = typename list<T>::Nodo;

public:

	//
	// COMPLEJIDAD: O(n) siendo n el numero de elementos de la lista. En el caso peor recorre toda la lista aunque puede que no.
	void partition(int pivot)
	{
		// Caso lista vacia.
		if (this->empty() || this->size() == 1)
		{
			return;
		}

		Nodo* act = this->fantasma->sig; // Nodo para iterar. Empieza en el siguiente al fantasma.
		Nodo* actSig = act->sig; // Siguiente al actual.
		Nodo* actAnt = act->ant; // Anterior al actual.

		Nodo* ult = this->fantasma->ant; // El ultimo de la lista.


		for (int i = 0; i < this->size(); i++)
		{
			// Cambia si el elemento
			if (act->elem > pivot)
			{
				if (act != ult) // No mueve al final el nodo si ya es el final.
				{
					// Cierra el hueco.
					actAnt->sig = actSig;
					actSig->ant = actAnt;
					act->sig = this->fantasma;
					// Conexion con fantasma.
					this->fantasma->ant = act;
					// Conexion con el ultimo.
					ult->sig = act;
					act->ant = ult;
				}
			}
			act = actSig;
			actAnt = act->ant;
			actSig = act->sig;
			ult = this->fantasma->ant;
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
bool resuelveCaso()
{
	// Lectura:
	int nElems = 0; // Numero de elementos de la lista.
	int pivot = 0; // Pivote.

	std::cin >> nElems;
	if (!std::cin)
	{
		return false;
	}

	std::cin >> pivot;
	list_eda_plus<int> datos; // Lista con los datos.

	for (size_t i = 0; i < nElems; i++)
	{
		int elem = 0;
		std::cin >> elem;
		datos.push_back(elem);
	}


	// Resolucion:
	datos.partition(pivot);


	// Escritura:
	for (auto e : datos)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;


	return true;
}

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