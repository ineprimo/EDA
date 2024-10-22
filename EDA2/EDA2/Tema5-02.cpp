﻿//// Andres Garcia Navarro
//// EDA-GDV27
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <stack>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//
//// Por lo que la complejidad es lineal O(n) donde n es el numero de elementos de la cola
//void resuelve(queue<int>& cola) {
//
//	queue<int> positivos;
//	stack<int> negativos;
//
//	while (!cola.empty())
//	{
//		if (cola.front() > 0)
//			positivos.push(cola.front());
//		else
//			negativos.push(cola.front());
//
//		cola.pop();
//	}
//
//	while (!negativos.empty())
//	{
//		cola.push(negativos.top());
//		negativos.pop();
//	}
//
//	while (!positivos.empty())
//	{
//		cola.push(positivos.front());
//		positivos.pop();
//	}
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	int n = 0;
//	cin >> n;
//
//	if (n == 0)
//		return false;
//
//	queue<int> cola;
//
//	for (int i = 0; i < n; i++)
//	{
//		int e = 0;
//		cin >> e;
//		cola.push(e);
//	}
//
//	resuelve(cola);
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
//	while (resuelveCaso())
//		;
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//#endif
//
//	return 0;
//}