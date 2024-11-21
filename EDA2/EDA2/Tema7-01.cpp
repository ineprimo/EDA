//// Andres Garcia Navarro
//// EDA-GDV27
//
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <list>
//using namespace std;
//
//// Tipo de dato que vamos a usar
//using TablaRefs = map<string, list<int>>;
//
//// la complejudad de este metodo es lineal O(n) donde n es el numero de caracteres de palabras de mayor tamanio que 2
//void referencias(int numLineas, TablaRefs& refs) {
//	string palabra;
//	char c;
//	for (int numLinea = 1; numLinea <= numLineas; numLinea++) {
//		cin.get(c);
//		while (c != '\n') {
//			cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
//			cin >> palabra;
//
//			// Si tiene menos tamaño del minimo pasa a la siguiente palabra
//			if (palabra.size() > 2) {
//
//				// Pasamos la palabra a minuscula
//				for (auto& c : palabra)
//					c = tolower(c);
//
//				// si no existe la palabra en el map, la aniade, si no suma 1 al contador
//				if (!refs.count(palabra)) {
//					list<int> list;
//					list.push_back(numLinea);
//					refs.insert({ palabra,list });
//				}
//				// si la palabra no tiene ya aniadida la linea actual la aniade
//				else if (refs[palabra].back() != numLinea) {
//					refs[palabra].push_back(numLinea);
//
//				}
//
//			}
//			cin.get(c);
//		}
//	}
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	char c;
//	cin >> n;
//	cin.get(c); // Me salto el \n de detrás del N
//	if (n == 0)
//		return false;
//
//	TablaRefs refs;
//	referencias(n, refs);
//
//	// escribir sol
//	for (const auto it : refs)
//	{
//		cout << it.first;
//
//		for (const auto n : it.second) {
//			cout << " " << n;
//		}
//
//		cout << endl;
//	}
//	cout << "---\n";
//	return true;
//
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