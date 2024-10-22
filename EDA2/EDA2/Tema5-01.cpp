//// Andres Garcia Navarro
//// EDA-GDV27
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//// pila.top() Complejidad constante
//// pila.push() Complejidad constante
//// pila.empty() Complejidad constante
//// Por lo que la complejidad es lineal O(n) donde n es el numero de elementos del stack
//bool resuelve(const string& line) {
//
//	stack<char> pila;
//
//	for (auto c : line) {
//
//		if (c == '(' || c == '[' || c == '{') {
//			pila.push(c);
//		}
//		else if (c == ')') {
//			!pila.empty() ?
//				pila.top() == '(' ? pila.pop() : pila.push(c) :
//				pila.push(c);
//		}
//		else if (c == ']') {
//			!pila.empty() ?
//				pila.top() == '[' ? pila.pop() : pila.push(c) :
//				pila.push(c);
//		}
//		else if (c == '}') {
//			!pila.empty() ?
//				pila.top() == '{' ? pila.pop() : pila.push(c) :
//				pila.push(c);
//		}
//
//
//	}
//
//	return pila.empty();
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	string line;
//	getline(std::cin, line);
//
//	if (!std::cin)
//		return false;
//
//	cout << (resuelve(line) ? "SI" : "NO") << endl;
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