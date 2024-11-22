//// Andres Garcia Navarro
//// EDA-GDV27
//
//#include <iostream>
//#include <fstream>
//#include <cctype>
//#include <map>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//using Listas = map <string, int>;
//using Alumno_Deporte = map<string, string>;
//
//vector<pair<string, int>> resolver(string const& primerDeporte) {
//	string deporte, alumno;
//	Listas listas;
//	Alumno_Deporte personaDeporte;
//
//
//	deporte = primerDeporte;
//	while (deporte != "_FIN_") {
//		int count = 0;
//		listas.insert({ deporte,count });
//
//		cin >> alumno;
//		// diccionario de personas en cada asignatura
//		while (!isupper(alumno[0]) && alumno != "_FIN_") {
//			// buscamos si el alumno esta en la lista para evitar repetidos
//			if (!personaDeporte.count(alumno))
//			{
//				personaDeporte.insert({ alumno, deporte });
//				count++;
//			}
//			else {
//				// si el elemento esta repetido eliminamos de la lista original y seteamos el deporte a nada para que no se elimine varias veces
//				if (personaDeporte[alumno] != deporte && personaDeporte[alumno]!= " ")
//				{
//					listas[personaDeporte[alumno]]--;
//					personaDeporte[alumno] = " ";
//				}
//			}
//			cin >> alumno;
//		}
//		listas[deporte] = count;
//		deporte = alumno;
//	}
//
//	vector<pair<string, int>> vec(listas.begin(), listas.end());
//	sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
//		return a.second > b.second; // Orden descendente por valor
//		});
//	return vec;
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	string primerDeporte;
//	cin >> primerDeporte;
//	if (!cin) return false;
//	vector<pair<string, int>> list = resolver(primerDeporte);
//	for (auto e : list)
//	{
//		cout << e.first << " " << e.second << endl;
//	}
//	cout << "---\n";
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