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
//bool esValida(vector<char> const& sol, int k) {
//	bool valido = true;
//	int i = 0;
//	while (i < k && valido)
//	{
//		valido = !(sol[i] == sol[k]);
//		i++;
//	}
//	return valido;
//}
//
//// función que resuelve el problema
//// @param sol vector solucion actual
//// @param n numero de letras usables empezando por 'a'
//// @param k letra actual 'a' + k
//// @param letras vector letras utiles
//void resolver(vector<char>& sol, int n, int k, vector<char>const& letras) {
//	for (char c : letras) {
//		sol[k] = c;
//		if (esValida(sol, k))
//			if (k == n - 1) {
//				for (char letra : sol) cout << letra;
//				cout << endl;
//			}
//			else
//				resolver(sol, n, k + 1, letras);
//	}
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n, m;
//	cin >> m; //cojo numero de letras que se consideran
//
//	if (!std::cin)
//		return false;
//	cin >> n; //cojo numero de letras que contiene una palabra
//
//	vector<char> letras(m);
//	for (int i = 0; i < m; i++) letras[i] = 'a' + i;
//
//	vector<char> sol(n); // vector solucion
//	resolver(sol, n, 0, letras);
//	cout << endl; // Espacio en blanco despues de cada caso de prueba
//
//	return true;
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
//	while (resuelveCaso());
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