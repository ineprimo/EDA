//// Andres Garcia Navarro
//// EDA-GDV27
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <stack>
//#include "queue_eda.h"
//#include <string>
//
//using namespace std;
//
//template <class T>
//class queuePlus : public queue<T>
//{
//	using Nodo = typename queue<T>::Nodo;
//
//public:
//
//	// La complejidad es lineal O(n) donde n es el numero de elementos de la cola
//	void colarse(T pringao, queue<T>& colegas) {
//		// si no esta pringao en la cola
//		if (pringao >= this->ult->elem) return;
//
//		Nodo* nodPring = this->prim;
//		Nodo* ant = nullptr;
//		// cogemos el nodo pringao
//		while (nodPring->elem != pringao)
//		{
//			ant = nodPring;
//			nodPring = nodPring->sig;
//		}
//		ant = nodPring;
//		nodPring = nodPring->sig;
//
//		Nodo* colega = colegas.prim;
//		int i = 0;
//		while (colega != nullptr)
//		{
//			i++;
//			colega = colega->sig;
//		}
//
//		colegas.ult->sig = nodPring->sig;
//		ant->sig = colegas.prim;
//
//		this->nelems += i;
//	}
//};
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	int n = 0, pringao = 0;
//	std::cin >> n;
//
//	if (!std::cin)
//		return false;
//
//	queuePlus<int> cola, colegas;
//
//	while (n != -1)
//	{
//		cola.push(n);
//		std::cin >> n;
//	}
//
//	std::cin >> pringao;
//
//	std::cin >> n;
//	while (n != -1)
//	{
//		cola.push(n);
//		std::cin >> n;
//	}
//
//	cola.colarse(pringao, colegas);
//
//	while (!cola.empty())
//	{
//		cout << cola.front() << " ";
//		cola.pop();
//	}
//	cout << endl;
//
//	return true;
//}
//
//int main() {
//	// Para la entrada por fichero.
//	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif
//
//
//	int numCasos;
//	std::cin >> numCasos;
//	for (int i = 0; i < numCasos; ++i)
//		resuelveCaso();
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//#endif
//
//	return 0;
//}