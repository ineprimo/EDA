//// Nombre completo: Andres Garcia Navarro
//// Usuario del juez: EDA-GDV27
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <climits>
//using namespace std;
//
//// Función recursiva de backtracking
//void resolver(int k, int n, vector<vector<int>>& donaciones, vector<vector<bool>>& consentimientos,
//	vector<bool>& usados, vector<int>& orden, int sumaActual, int& mejorSuma) {
//	// Caso base: si todos los artistas han sido asignados
//	if (k == n) {
//		mejorSuma = max(mejorSuma, sumaActual);
//		return;
//	}
//
//	// Probar cada artista como el k-ésimo en el orden
//	for (int i = 0; i < n; ++i) {
//		if (!usados[i]) { // Si el artista i no ha sido usado
//			if (k == 0 || consentimientos[orden[k - 1]][i]) { // Si respeta los consentimientos
//				// Marcar como usado y agregar al orden
//				usados[i] = true;
//				orden[k] = i;
//
//				// Llamada recursiva
//				resolver(k + 1, n, donaciones, consentimientos, usados, orden,
//					sumaActual + donaciones[i][k], mejorSuma);
//
//				// Deshacer cambios
//				usados[i] = false;
//			}
//		}
//	}
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	cin >> n;
//	vector<vector<int>> beneficios(n, vector<int>(n));
//	vector<vector<bool>> consentimientos(n, vector<bool>(n));
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j)
//			cin >> beneficios[i][j];
//
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j) {
//			int b;
//			cin >> b;
//			consentimientos[i][j] = b;
//		}
//	vector<int> orden(n);
//	vector<bool> usados(n);
//	int donacionMax = -1;
//	resolver(0, n, beneficios, consentimientos, usados, orden, 0, donacionMax);
//	// salida
//	if (donacionMax == -1) {
//		cout << "NEGOCIA CON LOS ARTISTAS" << endl;
//	}
//	else {
//		cout << donacionMax << endl;
//	}
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
//	int numCasos;
//	std::cin >> numCasos;
//	for (int i = 0; i < numCasos; ++i)
//		resuelveCaso();
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif
//
//	return 0;
//}
