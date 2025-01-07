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
//using Monomio = pair<int, int>;
//class Polinomio {
//private:
//	vector<Monomio> elems;
//
//	int elevar(int x, int expo) {
//		if (expo == 0) return 1;  // Caso especial: x^0 = 1
//		int sol = 1;
//		for (int i = 0; i < expo; i++) {
//			sol *= x;
//		}
//		return sol;
//	}
//
//	int encontrarPos(Monomio mon) {
//		int pos = 0;
//		bool encontrada = false;
//		while (pos < elems.size() && !encontrada)
//		{
//			if (elems[pos].second >= mon.second) {
//				encontrada = true;
//			}
//			else
//			{
//				pos++;
//			}
//		}
//		return pos;
//	}
//
//public:
//	Polinomio() {}
//	~Polinomio() = default;
//
//	void addMonomio(Monomio mon) {
//		int pos = encontrarPos(mon);
//		// si el nuevo monomio debe ir entre medias del vector
//		if (pos < elems.size()) {
//			// si en esa posicion ya hay un monomio del mismo grado
//			if (elems[pos].second == mon.second)
//				elems[pos].first += mon.first;
//			else {
//				vector<Monomio> nuevoElems;
//				// volvemos a recorrer aniadiendo el monomio nuevo
//				int elem = 0;
//				for (int i = 0; i <= elems.size(); i++)
//				{
//					if (i == pos) {
//						nuevoElems.push_back(mon);
//					}
//					else
//					{
//						nuevoElems.push_back(elems[elem]);
//						elem++;
//					}
//				}
//
//				elems = nuevoElems;
//			}
//		}
//		else
//			elems.push_back(mon);
//	}
//
//	int resolver(int x) {
//		int sol = 0;
//		for (const auto& mon : elems) {
//			sol += mon.first * elevar(x, mon.second);
//		}
//		return sol;
//	}
//};
//
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int coef = 0, exp = 0;
//	std::cin >> coef >> exp;
//	// el archivo ha acabado
//	if (!cin)
//		return false;
//	Polinomio poli;
//	while (coef != 0 || exp != 0) {
//		poli.addMonomio({ coef, exp });
//		cin >> coef >> exp;
//	}
//
//	int nX = 0, x = 0;
//	cin >> nX;
//	for (int i = 0; i < nX; i++)
//	{
//		cin >> x;
//		cout << poli.resolver(x) << " ";
//	}
//	cout << endl;
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
//
//	while (resuelveCaso())
//		;
//
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif
//
//	return 0;
//}