// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include "LinkedListStack.h"	
#include "stack_eda.h"


// Funcion que resuelve el problema. COMPLEJIDAD: O(n), en verdad O(2n) siendo n la longitud de la pila inicial (aux tiene n elementos tambien).
void duplicar(stack<int> datos)
{
	stack<int> aux; // Pila auxiliar.

	// Vaciamos la pila en una pila auxiliar.
	while (!datos.empty())
	{
		aux.push(datos.top());
		datos.pop();
	}

	// Metemos los elementos de aux dos veces en datos.
	while (!aux.empty())
	{
		datos.push(aux.top());
		datos.push(aux.top());
		aux.pop();
	}
}

// Clase extendida con operación interna duplicar que reaprovecha nodos existentes
template <class T>
class LinkedListStack_plus : public LinkedListStack<T>
{
	using Nodo = typename LinkedListStack<T>::Nodo;

public:
	void duplicar()
	{
		// Comporbamos primero que no este vacia la pila.
		if (this->empty())
		{
			return;
		}

		Nodo* act = this->cima; // Hacemos un nodo para recorrer la lista.

		// Recorremos hasta el final.
		while (act != nullptr)
		{
			Nodo* dup = new Nodo(act->elem, act->sig); // Nodo con el elemento duplicado. Hacemos que apunte al siguiente del actual para que no pierda la referencia al siguiente que queremos.
			act->sig = dup; // El siguiente del actual es el dup que hemos creado.
			act = dup->sig; // Para seguir recorriendo la lista.
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
bool resuelveCaso()
{
	//------Leemos:
	int elem = 0;
	LinkedListStack_plus<int> datos;

	std::cin >> elem;
	if (!std::cin)
	{
		return false;
	}

	while (elem != 0)
	{
		datos.push(elem);
		std::cin >> elem;
	}

	//------Resolvemos:

	datos.duplicar();

	//------Escribimos:

	while (!datos.empty())
	{
		std::cout << datos.top() << " ";
		datos.pop();
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
	system("PAUSE");
#endif

	return 0;
}