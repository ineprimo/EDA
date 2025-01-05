// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"


/*// Clase extendida con operacion interna duplicar que reaprovecha nodos existentes
template <class T>
class list_eda_plus : public list<T>
{
	using Nodo = typename list<T>::Nodo;

public:

	//
	// COMPLEJIDAD: O(n) siendo n el numero de elementos de la lista. En el caso peor recorre toda la lista aunque puede que no.
	void adelantar(int nElems, int pos, int lon, int kPos)
	{
		// Caso lista vacia, lon=0 y k=0.
		if (this->empty() || kPos == this->size() - 1 || kPos == 0 || lon == 0 || pos - kPos < 0)
		{
			return;
		}
		// Si el segmento es mas largo que el numero de elementos acortamos el segmento.
		if ((pos + lon) > nElems)
		{
			lon = nElems - pos;
		}

		int dest = pos - kPos; // Posicion de destino.

		Nodo* act = this->fantasma; // Nodo para iterar. Empeiza en el fantasma.

		for (int i = 0; i < dest; i++) // Para llegar al destino.
		{
			Nodo* sig = act->sig;
			act = sig;
		}

		Nodo* nAntDest = act; // El anterior al destino antes del cambio.
		Nodo* nDest = act->sig; // El nodo destino antes del cambio.

		for (int i = 0; i < (pos - dest) + 1; i++) // Para llegar a la pos.
		{
			Nodo* sig = act->sig;
			act = sig;
		}

		Nodo* nAntPos = act->ant; // El anterior al que esta en pos antes del cambio.
		Nodo* nPos = act; // El que esta en el inicio del segmento antes del cambio.

		for (int i = 0; i < lon - 1; i++) // Para llegar al final de la lon.
		{
			Nodo* sig = act->sig;
			act = sig;
		}
		Nodo* nUltLon = act; // El ultimo que esta en el segmento antes del cambio.


		nAntDest->sig = nPos; // b->f
		nPos->ant = nAntDest; // b<-f

		nAntPos->sig = nUltLon->sig; // e->ghost
		nUltLon->sig->ant = nAntPos; // e<-ghost

		nUltLon->sig = nDest; //g->c
		nDest->ant = nUltLon; // g<-c
	}
};*/


list<char> adelantar(const list<char>& datos, int nElems, int pos, int lon, int kPos)
{
	list<char> sol;
	// Caso esta vacia no hace nada.
	if (datos.empty() || kPos == datos.size() - 1 || kPos == 0 || lon == 0 || pos - kPos < 0)
	{
		return datos;
	}
	// Si el segmento es mas largo que el numero de elementos acortamos el segmento.
	if ((pos + lon) > nElems)
	{
		lon = nElems - pos;
	}

	int dest = pos - kPos; // Posicion de destino.

	auto itDest = datos.begin();
	auto itPos = datos.begin();
	auto itLon = datos.begin();

	for (int i = 0; i < pos + lon - 1; i++)
	{
		if (i < dest)
		{
			++itDest;
		}
		if (i < pos)
		{
			++itPos;
		}
		++itLon;
	}

	bool segFin = false;
	auto itAct = datos.begin();
	for (int i = 0; i < nElems-1; i++)
	{
		if ((*itAct) == (*itDest))
		{
			itAct = itPos;
		}
		if ((*itAct) == (*itLon))
		{
			sol.push_back((*itAct));
			itAct = itDest;
			segFin = true;
		}
		if ((*itAct) == (*itPos) && segFin)
		{
			if ((pos + lon) <= nElems - 1)
			{
				itAct = ++itLon;
			}
		}
		sol.push_back((*itAct));
		++itAct;
	}
	return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
void resuelveCaso()
{
	// Lectura:
	int nElems = 0;
	int pos = 0;
	int segLon = 0;
	int kPos = 0;

	//list_eda_plus<char> datos;
	list<char> datos;

	std::cin >> nElems;
	std::cin >> pos;
	std::cin >> segLon;
	std::cin >> kPos;

	for (int i = 0; i < nElems; i++)
	{
		char elem;
		std::cin >> elem;
		datos.push_back(elem);
	}


	// Resolucion:
	//datos.adelantar(nElems, pos, segLon, kPos);
	//std::cout << nElems << " " << pos << " " << segLon << " " << kPos << " " << std::endl;
	list<char> sol;
	sol = adelantar(datos, nElems, pos, segLon, kPos);

	// Escritura:
	for (auto e : sol)
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


	int cases;
	std::cin >> cases;
	for (int i = 0; i < cases; i++)
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