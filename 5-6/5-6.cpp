// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

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
	void cuela(const T& a, queue<T>& b)
	{
		// Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult

		if (this->empty()) return;
		if (b.empty()) return;

		Nodo* actual = this->prim;

		while (actual != nullptr && actual->elem != a)
			actual = actual->sig;

		if (actual == nullptr) return; // no esta a

		Nodo* colega = b.prim;
		int i = 0;
		while (colega != nullptr)
		{
			i++;
			colega = colega->sig;
		}

		//// si esta a, a partir de actual se inserta b
		b.ult->sig = actual->sig;
		actual->sig = b.prim;

		this->nelems += i;

		while (!b.empty()) b.pop();
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n, a;
	queue_plus<int> q; // cola normal
	queue_plus<int> c; // colegas
	cin >> n; // n casos

	for (int i = 0; i < n; i++)
	{
		int m = 0;
		cin >> m;
		while (m != -1)
		{
			q.push(m);
			cin >> m;
		}
		cin >> a;
		cin >> m;
		while (m != -1)
		{
			c.push(m);
			cin >> m;
		}

		// llamada a metodo
		q.cuela(a, c);

		// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
		for (int j = 0; j < q.size(); ++j)
		{
			m = q.front();
			q.pop();
			q.push(m);
		}
		// Ahora imprimimos la cola y de paso la dejamos vacía
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

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
