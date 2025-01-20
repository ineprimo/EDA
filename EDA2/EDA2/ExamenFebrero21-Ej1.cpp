///*
//Nombre completo: Andres Garcia Navarro
//Usuario del juez: EDA-GDV27
//*/
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include "queue_eda.h"
//#include <vector>
//using namespace std;
//
//template <class T>
//class queue_plus : public queue<T> {
//	using Nodo = typename queue<T>::Nodo;
//
//public:
//	// es complejidad lineal O(n+m) siendo n el tamaño de la cola actual y m el numero resultante de la suma del valor de los enteros que componen mult
//	void cuela(const T& a, const T& b)
//	{
//		Nodo* aNodo = nullptr;
//		Nodo* bNodoAnt = nullptr;
//		Nodo* nodoAct = this->prim;
//		Nodo* bNodo = nullptr;
//
//		int i = 0;
//		bool bEncontrado = false;
//		while (i < this->nelems && !bEncontrado) {
//			if (nodoAct->elem == a && aNodo == nullptr)
//				aNodo = nodoAct;
//			else if (nodoAct->elem == b && bNodo == nullptr && aNodo != nullptr)
//			{
//				bNodo = nodoAct;
//				bEncontrado = true;
//			}
//			else
//				bNodoAnt = nodoAct;
//			nodoAct = nodoAct->sig;
//			i++;
//		}
//		// si alguno de los elementos s
//		if (aNodo == nullptr || bNodo == nullptr|| aNodo->sig == bNodo) return;
//		bNodoAnt->sig = nodoAct;
//		bNodo->sig = aNodo->sig;
//		aNodo->sig = bNodo;
//	}
//};
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	int n = 0, a = 0, b = 0;
//	queue_plus<int> q;
//
//	cin >> n;
//	if (!cin) return false;
//
//	// Leemos la secuencia invertida para q 
//	while (n != -1) {
//		q.push(n);
//		cin >> n;
//	}
//
//	cin >> a >> b;
//
//	q.cuela(a, b);
//
//	// Ahora imprimimos la cola
//	while (!q.empty()) {
//		cout << " " << q.front();
//		q.pop();
//	}
//	cout << endl;
//	return true;
//}
//
////#define DOMJUDGE
//int main() {
//	// Para la entrada por fichero.
//	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif
//
//	while (resuelveCaso());
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif
//
//	return 0;
//}
