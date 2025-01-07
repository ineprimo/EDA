//// Andres Garcia Navarro
//// EDA-GDV27
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//class Horas {
//private:
//	bool valido = true;
//	int horas = 0;
//	int minutos = 0;
//	int segundos = 0;
//public:
//	Horas() { valido = true; }
//	Horas(int hor, int min, int seg) {
//		if (hor >= 0 && hor <= 23) horas = hor;
//		else valido = false;
//		if (min >= 0 && min <= 59) minutos = min;
//		else valido = false;
//		if (seg >= 0 && seg <= 59) segundos = seg;
//		else valido = false;
//	};
//	bool esValido() { return valido; };
//
//	bool operator==(const Horas& other)const {
//
//		return // es igual
//			(horas == other.horas &&
//				minutos == other.minutos &&
//				segundos == other.segundos);
//	}
//	bool operator<(const Horas& other)const {
//
//		return // es menor
//			(horas < other.horas ||
//				(horas == other.horas && minutos < other.minutos) ||
//				(horas == other.horas && minutos == other.minutos && segundos < other.segundos));
//	}
//
//	bool operator<=(const Horas& other)const {
//
//		return *this < other || *this == other;
//	}
//
//	friend istream& operator>>(istream& is, Horas& hor) {
//		int h, m, s;
//		is >> h;
//		is.ignore(1, ':'); is >> m;
//		is.ignore(1, ':'); is >> s;
//
//		hor = Horas(h, m, s);
//		return is;
//	}
//
//	friend ostream& operator<<(ostream& os, const Horas& h) {
//		os << (h.horas < 10 ? "0" : "") << h.horas << ":" << (h.minutos < 10 ? "0" : "") << h.minutos << ":" << (h.segundos < 10 ? "0" : "") << h.segundos;
//		return os; // Devuelve el flujo de salida
//	}
//};
//
//// función que resuelve el problema, complegidad o(n) lineal donde n es el numero de trenes
//void resolver(vector<Horas>const& trenes, Horas hora) {
//	// la hora a comprobar es valida
//	if (!hora.esValido()) {
//		cout << "error" << endl;
//		return;
//	}
//
//	// comprobamos la hora mas cercana por arriba
//	bool encontrada = false;
//	int i = 0;
//	while (i < trenes.size() && !encontrada) {
//		if (hora <= trenes[i]) {
//			encontrada = true;
//			cout << trenes[i] << endl;
//		}
//
//		i++;
//	}
//
//	// la hora a comprobar es mayor que la hora del ultimo tren
//	if (!encontrada) {
//		cout << "no" << endl;
//	}
//}
//
////// función que resuelve el problema, complegidad O(log n) logaritmica donde n es el numero de trenes
////void resolver(vector<Horas>const& trenes, Horas  hora, int ini, int fin) {
////	if (!hora.esValido()) {
////		cout << "ERROR" << endl;
////		return;
////	}
////
////	int diff = fin - ini;
////	if (diff == 1) {
////		if (hora <= trenes[ini])
////			cout << trenes[ini] << endl;
////		else cout << "NO" << endl;
////		return;
////	}if (diff == 2) {
////		if (hora <= trenes[ini])
////			cout << trenes[ini] << endl;
////		else if (hora <= trenes[ini + 1])
////			cout << trenes[ini + 1] << endl;
////		else cout << "NO" << endl;
////		return;
////	}if (diff == 3) {
////		if (hora <= trenes[ini])
////			cout << trenes[ini] << endl;
////		else if (hora <= trenes[ini + 1])
////			cout << trenes[ini + 1] << endl;
////		else if (hora <= trenes[ini + 2])
////			cout << trenes[ini + 2] << endl;
////		else cout << "NO" << endl;
////		return;
////	}
////
////	int mitad = (fin + ini) / 2;
////
////	trenes[mitad] <= hora ?
////		resolver(trenes, hora, mitad, fin) :
////		resolver(trenes, hora, ini, mitad);
////}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	int ntrenes = 0, nhoras = 0;
//	std::cin >> ntrenes >> nhoras;
//	if (ntrenes == 0 && nhoras == 0)
//		return false;
//
//	// guardamos las horas a las que salen los trenes
//	vector<Horas> trenes;
//	for (int i = 0; i < ntrenes; i++)
//	{
//		Horas h;
//		std::cin >> h;
//		trenes.push_back(h);
//	}
//
//	// guardamos las horas a las que salen los trenes
//	for (int i = 0; i < nhoras; i++)
//	{
//		Horas h;
//		std::cin >> h;
//		resolver(trenes, h);
//		//resolver(trenes, h, 0, trenes.size());
//	}
//	cout << "---" << endl;
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