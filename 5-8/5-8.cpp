// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;


// O(n) donde n es el tamano de la lista porque la recorre una vez
void eliminar(list<int>& l, int elem)
{
	auto it = l.begin();

	while (it != l.end())
	{
		if (*it == elem)
			it = l.erase(it); // erase devuelve el iterador tras el elto eliminado
		else
			++it;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	list<int> l;
	int n;

	cin >> n;
	while (n != -1)
	{
		l.push_back(n);
		cin >> n;
	}
	cin >> n;

	for (const int e : l)
		cout << e << " ";
	cout << endl;

	eliminar(l, n);

	// Le damos una vuelta para comprobar que la lista está bien formada
	for (int i = 0; i < l.size(); ++i)
	{
		n = l.back();
		l.pop_back();
		l.push_front(n);
	}

	// Ahora imprimimos la lista y de paso la dejamos vacía (tb para probar su consistencia)
	while (!l.empty())
	{
		std::cout << l.front() << " ";
		l.pop_front();
	}

	std::cout << endl;
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

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
