//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;
//
//using Diccionario = map<string, int>;
//
//void leerDiccionario(Diccionario& diccionario) {
//	char c;
//	string clave;
//	int valor;
//	cin.get(c);
//	while (c && c != '\n') {
//		cin.unget();
//		cin >> clave >> valor;
//		if (!diccionario.count(clave))
//			diccionario.insert({ clave,valor });
//		else
//			diccionario[clave] = valor;
//		cin.get(c);
//	}
//}
//
//void comparaDiccionario(Diccionario& antiguo, Diccionario& nuevo, vector<string>& aniadidos, vector<string>& eliminados, vector<string>& modificados) {
//
//	auto it = nuevo.begin();
//	while (it != nuevo.end())
//	{
//		// si antiguo contiene el elemento it del nuevo 
//		// si el elemento id de antiguo tiene un valor diferente al nuevo va a modificados
//		if (antiguo.count((*it).first))
//		{
//			if (antiguo[(*it).first] != (*it).second)
//				modificados.push_back((*it).first);
//			antiguo.erase((*it).first);
//		}
//		// si el elemento nuevo no esta en el diccionario antiguo lo aniade a aniadidos
//		else
//			aniadidos.push_back((*it).first);
//
//		it++;
//
//	}
//
//	// aniadimos los elementos restantes de antiguo a eliminados
//	for (auto e : antiguo)
//		eliminados.push_back(e.first);
//
//
//}
//
//void resuelveCaso() {
//	Diccionario antiguo;
//	Diccionario nuevo;
//	leerDiccionario(antiguo);
//	leerDiccionario(nuevo);
//
//	vector<string> aniadidos, eliminados, modificados;
//	comparaDiccionario(antiguo, nuevo, aniadidos, eliminados, modificados);
//
//	// imprimimos el resultado
//	if (aniadidos.size() == 0 && eliminados.size() == 0 && modificados.size() == 0) {
//		cout << "Sin cambios" << endl;
//		cout << "---" << endl;
//		return;
//	}
//	if (aniadidos.size() > 0) {
//		cout << "+";
//		for (auto e : aniadidos)
//			cout << " " << e;
//		cout << endl;
//	}
//	if (eliminados.size() > 0) {
//		cout << "-";
//		for (auto e : eliminados)
//			cout << " " << e;
//		cout << endl;
//	}
//	if (modificados.size() > 0) {
//		cout << "*";
//		for (auto e : modificados)
//			cout << " " << e;
//		cout << endl;
//	}
//	cout << "---" << endl;
//}
//
//
//int main() {
//	// Para la entrada por fichero.
//	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif
//
//	int numCasos; char c;
//	std::cin >> numCasos;
//	cin.get(c);
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
