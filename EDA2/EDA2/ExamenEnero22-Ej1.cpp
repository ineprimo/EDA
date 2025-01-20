//// Andres Garcia Navarro
//// EDA - GDV27
//
//#include <list>
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//using namespace std;
//
//// función que resuelve el problema
//void resolver(list<char>& l, int n, int pos, int lon, int k) {
//	//auto itAnt = l.begin();
//	//auto itsig = l.begin();
//	//auto itElem = l.begin();
//
//	//if (pos + lon > nelems) lon = (pos + lon) - nelems - 1;
//
//
//	//int nuevapos = (pos + k) % (nelems);
//
//	//// avanza los iteradores
//	//for (int i = 0; i <= nuevapos; i++) {
//	//	itAnt++;
//	//	if (itAnt == l.end()) itAnt = l.begin();
//	//	itsig++;
//	//	if (itsig == l.end()) itsig = l.begin();
//	//}
//	//for (int i = 0; i < pos; i++) itElem++;
//
//	//list<char> aux;
//	//for (int i = 0; i < abs(nelems); i++)
//	//{
//	//	if (i < pos && i >pos + lon)
//	//		aux.push_back(*itAnt);
//	//	if (i < lon) {
//	//		*itAnt = *itElem;
//	//		itElem++;
//	//	}
//	//	itAnt++;
//	//	if (itAnt == l.end()) itAnt = l.begin();
//	//}
//	//for (auto e : aux)
//	//{
//	//	*itsig = e;
//	//	itsig++;
//	//}
//
//	   // Validaciones iniciales
//	if (lon == 0 || k == 0 || pos >= n || l.empty()) return;
//
//	// Ajustar la longitud del segmento si excede los límites
//	if (pos + lon > n) {
//		lon = n - pos;
//	}
//
//	// Encontrar iteradores de inicio y fin del segmento
//	auto itInicio = std::next(l.begin(), pos);
//	auto itFin = std::next(itInicio, lon);
//
//	// Extraer el segmento
//	std::list<char> segmento(itInicio, itFin);
//	l.erase(itInicio, itFin);
//
//	// Calcular nueva posición de inserción
//	int nuevaPos = (pos + k) % (n - lon); // Lista original menos el segmento extraído
//	auto itNuevaPos = std::next(l.begin(), nuevaPos);
//
//	// Insertar el segmento en la nueva posición
//	l.insert(itNuevaPos, segmento.begin(), segmento.end());
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	// leer los datos de la entrada
//	int n = 0, k = 0, pos = 0, lon = 0;
//	// n= elementos, k= desplazamiento, pos = pos a partir de la cual se desplaza, lon = longitud de la cadena
//	std::cin >> n >> pos >> lon >> k;
//
//	char c = ' ';
//	list<char> l;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> c;
//		l.insert(l.end(), c);
//	}
//	resolver(l, n, pos, lon, k);
//
//	// escribir sol
//	for (auto e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
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
//	int numCasos;
//	std::cin >> numCasos;
//	for (int i = 0; i < numCasos; ++i)
//		resuelveCaso();
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