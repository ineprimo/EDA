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
//// El coste de esta funcion es logaritmica O(log n) se recorre el vector por mitades y nunca completas
//// función que resuelve el problema
//int buscar(const vector<int>& secA, const vector<int>& secB, int ini, int fin) {
//	// division por mitades
//	int mitad = (ini + fin) / 2;
//	// Num elementos
//	int dif = fin - ini;
//
//	// ------ casos base ------
//	if (dif == 0) {
//		return 0;
//	}
//	if (dif == 1) {
//		return secA[ini];
//	}
//	if (dif == 2) {
//		return secA[ini] == secB[ini] ? secA[ini + 1] : secA[ini];
//	}
//
//	// ------ Busqueda binaria ------
//	// si el numero de la mitad A es diferente del la mitad de B, significa que el numero esta a la izquierda
//	if (secA[mitad] != secB[mitad]) {
//		return buscar(secA, secB, ini, mitad + 1);
//	}
//	return 	buscar(secA, secB, mitad, fin);
//
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	cin >> n;
//	vector<int> secA(n), secB(n - 1);
//	for (int& e : secA) cin >> e;
//	for (int& e : secB) cin >> e;
//	cout << buscar(secA, secB, 0, n) << endl;
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
//	int numCasos;
//	std::cin >> numCasos;
//	for (int i = 0; i < numCasos; ++i)
//		resuelveCaso();
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