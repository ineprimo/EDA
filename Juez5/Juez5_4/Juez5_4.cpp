#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;

public:
	void duplica()
	{
		// Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult
		if (this->empty()) return;

		Nodo* actual = this->prim;
		Nodo* duplicado = nullptr;
		while (actual != nullptr)
		{
			duplicado = new Nodo(actual->elem, actual->sig);
			actual->sig = duplicado;
			actual = duplicado->sig;
			++this->nelems;
		}
		this->ult = duplicado;
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	queue_plus<int> q;
	cin >> n;
	if (!cin) return false;
	while (n != 0)
	{
		q.push(n);
		cin >> n;
	}

	// llamada a metodo
	q.duplica();

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < q.size(); ++i)
	{
		n = q.front();
		q.pop();
		q.push(n);
	}
	// Ahora imprimimos la cola y de paso la dejamos vacía
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
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