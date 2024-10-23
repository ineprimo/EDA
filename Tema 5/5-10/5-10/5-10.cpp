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
	// COMPLEJIDAD: O(n + m) siendo n la longitud del queue en el momento inicial y m la cantidad de elementos que tienes que meter nuevos menos los elementos que tienes que quitar.
	void replicaElems(std::vector<int> const& mult)
	{
		// Comprobamos primero que no este vacia la cola.
		if (this->empty())
		{
			return;
		}

		Nodo* act = this->prim; // Hacemos un nodo para recorrer la lista.
		Nodo* ant = nullptr; // Nodo para tener referencia al anterior al actual.

		for (int i = 0; i < mult.size(); i++)
		{
			if (mult[i] == 0) // Multiplicidad por 0, hay que quitar el elemento.
			{
				Nodo* siguinte = act->sig; // Siguiente al actual en el estado inicial.
				// Mover los nodos:
				if (ant == nullptr) // Si el actual no es el primero.
				{
					this->prim = act->sig;
				}
				else
				{
					if (act->sig != nullptr) // Si el actual no es el ultimo.
					{
						ant->sig = act->sig; // ant -> act -> sig => ant -> (act) -> sig
					}
					else
					{
						ant->sig = nullptr;
						this->ult = ant;
					}
				}
				// Eliminar el elemento:
				act->sig = this->prim; // Queremos que el siguiente al actual sea el primero para no perder la referencia.
				this->prim = act; // El primer elemento se convierte en el que queremos eliminar.
				this->pop(); // Eliminar el primero que es el que hemos multiplicado por 0. Pop() es O(1).
				act = siguinte; // Para avanzar en la cola.
			}
			else if (mult[i] == 1) // Para multiplicidad por 1, solo hay que avanzar la cola.
			{
				ant = act;
				act = act->sig;
			}
			else
			{
				Nodo* siguiente = act->sig; // Siguiente al actual en el estado inicial.
				Nodo* ultimo = this->ult; // Guardamos la referencia al ultimo elemento porque vamos a meter elementos por ahi.

				for (int j = 0; j < mult[i] - 1; j++)
				{
					this->push(act->elem); // Metemos tantos nodos con el elemento que sea necesarios. Push() es O(1).
				}

				ant = this->ult; // El anterior al actual (ant) es el que acabamos de crear.

				if (siguiente != nullptr) // Si el siguiente al actual existe, entonces
				{
					act->sig = ultimo->sig; // Ultimo->sig es el que acabamos de crear.
					this->ult->sig = siguiente; // El siguiente a ult es el nodo que hemos creado, entonces su siguiente tiene que ser el siguiente al actual.

					this->ult = ultimo; // Reestablecemos el ult para que de verdad sea el ultimo.
					this->ult->sig = nullptr; // Fin de cola.
				}

				act = siguiente; // Para avanzar en la cola.

				// VERSION SIN PUSH: ya se vera...creo que se puede hacer pero en otro momento. PAIGRO AQUI.
			}
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	queue_plus<int> q;

	std::cin >> n;
	std::vector<int> mult(n);
	std::vector<int> aux(n); // Para darle la vuelta a la secuencia de entrada

	// Leemos la secuencia invertida para q y le damos la vuelta
	for (int i = n - 1; i >= 0; --i)
	{
		std::cin >> aux[i];
	}
	for (int e : aux)
	{
		q.push(e);
	}

	// Leemos la secuencia invertida para mult
	for (int i = n - 1; i >= 0; --i)
	{
		std::cin >> mult[i];
	}

	// llamada al metodo
	q.replicaElems(mult);

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < q.size(); ++i)
	{
		n = q.front();
		q.pop();
		q.push(n);
	}

	// Ahora imprimimos la cola y de paso la dejamos vacía (tb para probar su consistencia)
	std::cout << "[";
	if (!q.empty())
	{
		std::cout << q.front();
		q.pop();
	}
	while (!q.empty())
	{
		std::cout << ", " << q.front();
		q.pop();
	}
	std::cout << "]" << std::endl;
	return true;
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