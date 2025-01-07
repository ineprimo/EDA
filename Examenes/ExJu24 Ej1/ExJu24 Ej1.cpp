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
	// recibe un entero pivote y reorganiza los nodos dinámicos de la lista enlazada de tal forma que al
	// principio aparezcan aquellos que contengan enteros menores o iguales que el pivote y al final
	// aparezcan los que contengan enteros mayores que el pivote
	void partition(int pivote)
	{
		// lista vacia
		if(this->empty() || this->size() == 1)
		{
			return;
		}

		Nodo* act = this->fantasma->sig; // primer nodo de la lista
		Nodo* actAnt = act->ant;
		Nodo* actSig = act->sig;
		Nodo* ult = this->fantasma->ant; // ultimo nodo de la lista

		for(int i = 0; i < this->size(); i++)
		{
			if(act->elem > pivote)
			{
				if(act != ult)
				{
					// lo coloca al final
					actAnt->sig = actSig;
					actSig->ant = actAnt;

					act->sig = this->fantasma;
					this->fantasma->ant = act;

					ult->sig = act;
					act->ant = ult;
				}
			}

			// itera
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
	int n, p = 0;

	std::cin >> n;
	std::cin >> p;

	if (!std::cin)
		return false;

	list_eda_plus<int> lista;

	for (int i = 0; i < n; i++)
	{
		int e = -1;
		std::cin >> e;
		lista.push_back(e);
	}

	// escribe salida
	lista.partition(p);

	for(auto e : lista)
	{
		std::cout << e << " ";
	}
	std::cout << '\n';

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
