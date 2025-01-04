
#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"
#include "deque_eda.h"

// Clase extendida con operacion interna adelantar que adelante un numero de posiciones dado a un segmento
// (elementos en posiciones consecutivas) de la lista pasada como argumento
template <class T>
class List_eda_plus : public list<T>
{
	using Nodo = typename list<T>::Nodo;

public:

	// Complejidad: O(n) siendo n el numero de elementos de la lista

	// n, pos, lon y k -> datos de entrada
	void adelantar(int n, int pos, int lon, int k)
	{
		// no es valida si:
		// - lista vacia
		// - lo quieres mover el mismo num de posiciones que elementos tiene la lista / lon del segmento a mover = 0
		// - pos mayor que la ultima pos de la lista
		// - k == 0
		if(this->empty() || k == this->size()-1 || pos > this->size()-1 || k == 0 || lon == 0 || pos - k < 0 ) { }
		else
		{
			// si el segmento se sale de la lista
			if (pos + lon > n) 
			{
				// se tomara el segmento de los ultimos n − pos elementos
				lon = n - pos;
			}

			int dest = pos - k;

			// anterior al primer nodo de la lista
			Nodo* act = this->fantasma;

			// iteras hasta quedarte en el anterior al inicio del segmento
			for(int i = 0; i < dest; i++)
			{
				Nodo* sig = act->sig;
				act = sig;
			}

			Nodo* nAntDest = act;	// el anterior al inicio del segmento
			Nodo* nDest = act->sig;	// el siguiente del anterior al inicio del segmento antes del cambio

			for (int i = 0; i < (pos - dest)+1; i++)
			{
				Nodo* sig = act->sig;
				act = sig;
			}

			Nodo* iniSeg = act;
			Nodo* nuevoFin = iniSeg->ant;

			for (int i = 0; i < lon - 1; i++)
			{
				Nodo* sig = act->sig;
				act = sig;
			}

			Nodo* finSeg = act;
			Nodo* antFin = finSeg->sig;

			// para que el anterior a la pos destino apunte al inicio del segmento
			nAntDest->sig = iniSeg;

			// para que el inicio del segmento apunte al anterior de la pos destino
			iniSeg->ant = nAntDest;

			// para que el final del segmento apunte al nodo perdido
			finSeg->sig = nDest;

			// para que se apunte al nuevo final
			nuevoFin->sig = antFin;
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
void resuelveCaso()
{
	// leer datos de entrada
	int n, pos, lon, k = -1;
	char letra = ' ';

	List_eda_plus<char> datos;

	std::cin >> n >> pos >> lon >> k;

	for(int j = 0; j < n; j++)
	{
		std::cin >> letra;

		datos.push_back(letra);
	}

	// resolver problema
	datos.adelantar(n, pos, lon, k);

	// escribir salida
	for(auto e : datos)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int casos = 0;
	std::cin >> casos;

	for (int i = 0; i < casos; i++)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}