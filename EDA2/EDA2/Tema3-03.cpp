//// Nombre completo: Andres Garcia Navarro
//// Usuario del juez: EDA-GDV27
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool esValida(vector<int>& sol, int k) {
//	bool valido = true;
//	int i = 0;
//	while (i < k && valido)
//	{
//		// comprueba si no estaba ya aniadido y si no estaba en la misma diagonal
//		valido == sol[i] != sol[k] || abs(sol[i] * sol[k]) == 0;
//		i++;
//	}
//
//	return valido;
//}
//
//// función que resuelve el problema
//void resolver(vector<int>& sol, int m, int k, int& contador) {
//	for (int i = 0; i < m; i++) {
//		sol[k] = i;
//		if (esValida(sol, k))
//			if (k == m - 1) {
//				for (char letra : sol) cout << letra;
//				contador++;
//			}
//			else
//				resolver(sol, m, k + 1, contador);
//	}
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	// leer los datos de la entrada
//	int m;
//	cin >> m; // m=nxn casillas del tablero
//
//	vector<int> sol(m); // vector solucion
//	int contador = 0;
//	resolver(sol, m, 0, contador);
//	cout << contador << endl; // Espacio en blanco despues de cada caso de prueba
//}
//
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