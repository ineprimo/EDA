// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

#include "LinkedListStack.h"

using namespace std;

void duplicar(stack<int>& datos)
{
	stack<int> aux;

	while (!datos.empty())
	{
		aux.push(datos.top());
		datos.pop();
	}

	while (!aux.empty())
	{
		datos.push(aux.top());
		datos.push(aux.top());
		aux.pop();
	}
}

template <class T>
class LinkedListStackP : public LinkedListStack<T>
{
	using Nodo = typename LinkedListStack<T>::Nodo;

public:
	void duplicar()
	{
		if (this->empty()) return;

		Nodo* actual = this->cima;
		while (actual != nullptr)
		{
			Nodo* aux = new Nodo(actual->elem, actual->sig);
			actual->sig = aux;
			actual = aux->sig;
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int e;
	cin >> e;

	if (!cin)
		return false;

	//stack<int> lista;
	LinkedListStackP<int> lista;

	while (e != 0)
	{
		lista.push(e);
		cin >> e;
	}

	//duplicar(lista);
	lista.duplicar();

	while (!lista.empty())
	{
		cout << lista.top() << " ";
		lista.pop();
	}
	cout << endl;

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