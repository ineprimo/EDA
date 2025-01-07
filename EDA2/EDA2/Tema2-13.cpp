//// Andres Garcia Navarro
//// EDA-GDV27
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//// función que resuelve el problema
//// complejidad logaritmica O(log n) donde n es el numero de elementos que tiene v
//int resolver(vector<int> const& v, int ini, int fin) {
//	int dif = fin - ini;
//	if (dif == 1) {
//		return ini;
//	}if (dif == 2) {
//		return(ini % 2 == 0 ? ini : ini + 1);
//	}
//
//	int mitad = (fin + ini) / 2;
//
//	if (v[mitad] == v[mitad - 1])
//		return mitad % 2 == 0 ?
//		resolver(v, ini, mitad) :
//		resolver(v, mitad, fin);
//	else
//		return mitad % 2 == 0 ?
//		resolver(v, mitad, fin) :
//		resolver(v, ini, mitad);
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int& e : v) cin >> e;
//
//	// Llamada a la función resolver
//	int pos = resolver(v, 0, v.size());
//	// Mostrar el resultado
//	cout << pos << endl;
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