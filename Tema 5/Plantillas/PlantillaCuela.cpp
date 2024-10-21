// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"


template <class T>
class queue_plus : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;

public:
	void cuela(const T& a, const T& b)
	{
		// Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult.
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n = 0, a = 0, b = 0;
	queue_plus<int> q;
	std::cin >> n;
	if (n == -1) { return false; }
	while (n != -1)
	{
		q.push(n);
		std::cin >> n;
	}
	std::cin >> a >> b;

	// llamada a metodo
	q.cuela(a, b);

	// escribir sol (pero antes dar una vuelta para comprobar que la cola esta bien formada)
	for (int i = 0; i < q.size(); ++i)
	{
		n = q.front();
		q.pop();
		q.push(n);
	}
	// Ahora imprimimos la cola y de paso la dejamos vacia
	while (!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
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