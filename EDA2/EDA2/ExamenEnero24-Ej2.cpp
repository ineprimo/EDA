//// Andres Garcia Navarro
//// EDA - GDV27
//
//#include <vector>
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//using namespace std;
//
////// función que resuelve el problema, complejidad lineal O(n) donde n es nelems
////bool resolver(list<int>& lCreciente, list<int>& lDecreciente, int nelems, int& posCrec, int& posDecr) {
////	auto itCrec = lCreciente.begin();
////	auto itDecr = lDecreciente.begin();
////
////	// si el valor minimo del creciente es menor que el maximo del creciente, la interseccion esta por la izquierda
////	if (*itCrec > *lDecreciente.begin())
////	{
////		posCrec = -1;
////		posDecr = 0;
////		return false;
////	}
////
////	int i = 0;
////	int j = 0;
////	bool encontrado = false;
////	while (i < nelems && j < nelems && !encontrado)
////	{
////		// si el elemento de creciente es igual que el de decreciente, hemos encontrado el numero
////		if (*itCrec != *itDecr) {
////			i++;
////			posCrec++;
////			j++;
////			posDecr++;
////		}
////		else {
////			posCrec = i;
////			posDecr = j;
////			encontrado = true;
////		}
////		//	si el creciente es menor que el decreciente aumentamos el creciente para comprobarlo en la siguiente iteracion
////		//else if (*itCrec < *itDecr) {
////		//	j--;
////		//	itDecr--;
////		//}
////		//else {
////		//	i++;
////		//	itCrec++;
////		//}
////
////		if (*itCrec > *itDecr) {
////			encontrado = true;
////		}
////
////
////	}
////
////	// asignamos las posiciones de la interseccion dependiendo de si ha sido encontrado o no
////	if (i == nelems && j == 0 && !encontrado) {
////		posCrec = nelems - 1;
////		posDecr = nelems;
////	}
////	else {
////		posCrec = i;
////		posDecr = j;
////	}
////
////	return encontrado;
////}
//
//// complejidad logaritmica O(log n)
//bool resolver(const vector<int>& vCreciente, const vector<int>& vDecreciente, int ini, int fin, int& posCrec, int& posDecr, int nelems) {
//	int diff = fin - ini;
//	if (vCreciente[0] > vDecreciente[0]) {
//		posCrec = -1;
//		posDecr = 0;
//		return false;
//	}
//	if (vCreciente[nelems - 1] < vDecreciente[nelems - 1]) {
//		posCrec = nelems - 1;
//		posDecr = nelems;
//		return false;
//	}
//	if (diff == 1) {
//		if (vCreciente[ini] == vDecreciente[ini]) {
//			posCrec = ini;
//			posDecr = ini;
//			return true;
//		}
//		else {
//			posCrec = ini;
//			posDecr = fin;
//			return  false;
//		}
//	}
//
//	int mitad = (fin + ini) / 2;
//
//
//	if (vCreciente[mitad] == vDecreciente[mitad])
//	{
//		posCrec = mitad;
//		posDecr = mitad;
//		return true;
//	}
//	else if (vCreciente[mitad] > vDecreciente[mitad])
//	{
//		return resolver(vCreciente, vDecreciente, ini, mitad , posCrec, posDecr, nelems);
//	}
//	else
//	{
//		return resolver(vCreciente, vDecreciente, mitad, fin, posCrec, posDecr, nelems);
//	}
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int n = 0, posCrec = 0, posDecr = 0;
//	std::cin >> n;
//	if (n == 0) return false;
//	int c = 0;
//	vector<int> vCrec;
//	vector<int> vDecr;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> c;
//		vCrec.push_back(c);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> c;
//		vDecr.push_back(c);
//	}
//	// escribir sol
//	bool sol = resolver(vCrec, vDecr, 0, n, posCrec, posDecr, n);
//	cout << (sol ? "SI" : "NO");
//	if (!sol)
//		cout << " " << posCrec;
//	cout << " " << posDecr << endl;
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
//
//	while (resuelveCaso());
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif
//
//	return 0;
//}