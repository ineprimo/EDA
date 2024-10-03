//// Andres Garcia Navarro
//// EDA-GDV27
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//// El coste de esta funcion es logaritmico O(log n), donde n es el numero de elementos del vector que no es recorrido completamente, si no por mitades
//// función que resuelve el problema
//int minimo(const vector<int>& sec, int ini, int fin) {
//	// Casos base
//	int dif = fin - ini;
//	if (dif == 0) {
//		return 0;
//	}
//	if (dif == 1) {
//		return sec[ini];
//	}
//	if (dif == 2) {
//		return sec[ini] < sec[ini + 1] ? sec[ini] : sec[ini + 1];
//	}
//
//	int mitad = (ini + fin) / 2;
//	return sec[mitad] > sec[mitad - 1] ?
//		minimo(sec, ini, mitad) :
//		minimo(sec, mitad, fin);
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	cin >> n;
//	if (!cin) return false;
//	vector<int> sec(n);
//	for (int& e : sec) cin >> e;
//	cout << minimo(sec, 0, n) << endl;
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
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif
//
//	return 0;
//}