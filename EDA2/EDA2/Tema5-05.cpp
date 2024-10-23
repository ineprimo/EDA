//// Andres Garcia Navarro
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
//queue<int> resuelve(queue<int>& cola) {
//
//	queue<int> duplicados;
//	int i = 0;
//
//	while (!cola.empty())
//	{
//		if (i >= 1) {
//			i = 0;
//			duplicados.push(cola.front());
//			cola.pop();
//		}
//		else
//		{
//			duplicados.push(cola.front());
//			i++;
//		}
//	}
//	return duplicados;
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	int n = 0;
//	std::cin >> n;
//
//	if (!std::cin)
//		return false;
//
//	queue<int> cola;
//
//	while (n != 0)
//	{
//		cola.push(n);
//		std::cin >> n;
//	}
//
//	cola = resuelve(cola);
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