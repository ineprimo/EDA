//// Nombre completo: Andres Garcia Navarro
//// Usuario del juez: EDA-GDV27
//
//#include <iostream>
//#include <stdexcept>
//#include <fstream>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//#include <utility>
//#include <algorithm>
//
//using namespace std;
//
//using Heroe = string;
//using Villano = string;
//
//class SistemaBatallas {
//private:
//	struct InfoVillano
//	{
//		int vida;
//		int ataque;
//	};
//
//	struct InfoHero
//	{
//		int vida;
//		unordered_map<string, int> ataques;
//	};
//
//	unordered_map< Villano, InfoVillano> villanos;
//	unordered_map< Heroe, InfoHero> heroes;
//
//	queue<string> turns;
//
//public:
//
//	SistemaBatallas() {}
//	~SistemaBatallas() {}
//
//	// Coste: Coste promedio O(1). Es lineal en el peor de los casos O(n), donde n es el numero de elementos de villanos
//	void aparece_villano(Villano const& v, int puntos, int valor) {
//		// Si ya existe el villano, lanza una excepcion
//		if (villanos.count(v))
//			throw invalid_argument("Personaje ya existente");
//
//		// Aniade el villano al map
//		villanos.insert({ v,{puntos, valor} });
//
//		turns.push(v);
//	}
//
//	// Coste: Coste promedio O(1). Es lineal en el peor de los casos O(n), donde n es el numero de elementos de heroes
//	void aparece_heroe(Heroe const& h, int puntos) {
//		// Si ya existe el heroe lanza una excepcion
//		if (heroes.count(h))
//			throw invalid_argument("Personaje ya existente");
//
//		// Aniade el heroe al map
//		heroes.insert({ h,{puntos} });
//
//		turns.push(h);
//	}
//
//	// Coste: Coste promedio O(1). En el peor de los casos el coste es O(n+m) donde n es el numero de elementos de heroes y m el de ataques del heroe h
//	void aprende_ataque(Heroe const& h, string const& ataque, int valor) {
//		// Si no existe el hero al que queremos aniadir el ataque lanza excepcion
//		if (!heroes.count(h))
//			throw invalid_argument("Heroe inexistente");
//		// Cacheamos la informacion del heroe para no tener que buscarla todo el rato
//		InfoHero& info = heroes[h];
//		// Si ya existe el ataque en el heroe lanza excepcion
//		if (info.ataques.count(ataque))
//			throw invalid_argument("Ataque repetido");
//
//		// Aniadimos el ataque a la lista de ataques
//		info.ataques.insert({ ataque,valor });
//	}
//
//	// Coste: el coste lineal O(n) donde n es el numero de ataques que tiene el heroe h
//	vector<pair<string, int>> mostrar_ataques(Heroe const& h) {
//		// Si no existe el hero lanza excepcion
//		if (!heroes.count(h))
//			throw invalid_argument("Heroe inexistente");
//		// Guardamos los ataques en el vector res
//		vector<pair<string, int>> res;
//
//		// O(a) a = elementos en ataques
//		for (auto a : heroes[h].ataques)
//			res.push_back(a);
//
//		// Ordenamos en orden alfabetico
//		sort(res.begin(), res.end(), [](const pair<string, int>& a, const pair<string, int>& b) {return a.second > b.second; });
//
//		return res;
//	}
//
//	// Coste: el coste es lineal O(n) donde n es el numero de elementos de turns.
//	// En el peor de los casos O(n*(V+H)) donde:
//	// n es el numero de elementos de turns
//	// H el de heroes
//	// V el de villanos
//	vector<pair<string, int>> mostrar_turnos() {
//		vector<pair<string, int>> res;
//
//		for (int i = 0; i < turns.size(); i++)
//		{
//			auto it = turns.front();
//			pair <string, int> charac;
//			// guarda los datos del personaje que buscamos
//			if (villanos.count(it))
//				charac = { it,villanos[it].vida };
//			else if (heroes.count(it))
//				charac = { it,heroes[it].vida };
//
//			// Aniade el front al final
//			turns.push(it);
//			turns.pop();
//
//			res.push_back(charac);
//		}
//
//		return res;
//	}
//
//	// Coste: el coste es lineal O(n) n es el numero de elementos en turns.
//	// En el peor de los casos sera O(n+H+V) donde:
//	// n es el numero de elementos de turns
//	// H el de heroes
//	// V el de villanos
//	bool villano_ataca(Villano const& v, Heroe const& h) {
//		if (!villanos.count(v))
//			throw invalid_argument("Villano inexistente");
//		if (!heroes.count(h))
//			throw invalid_argument("Heroe inexistente");
//		if (turns.front() != v)
//			throw invalid_argument("No es su turno");
//		heroes[h].vida -= villanos[v].ataque;
//
//		turns.pop();
//		// aniade el villano al siguiente turno
//		turns.push(v);
//
//		if (heroes[h].vida <= 0)
//		{
//			heroes.erase(h);
//			turnsPersonajeMuerto(h);
//			return true;
//		}
//		return false;
//	}
//
//	// Coste: el coste es lineal O(n) n es el numero de elementos en turns.
//	// En el peor de los casos sera O(n+H+V+A) donde:
//	// n es el numero de elementos de turns
//	// H el de heroes, V el de villanos
//	// A el de los ataques de h
//	bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
//		if (!villanos.count(v))
//			throw invalid_argument("Villano inexistente");
//		if (!heroes.count(h))
//			throw invalid_argument("Heroe inexistente");
//		if (turns.front() != h)
//			throw invalid_argument("No es su turno");
//		if (!heroes[h].ataques.count(ataque))
//			throw invalid_argument("Ataque no aprendido");
//		villanos[v].vida -= heroes[h].ataques[ataque];
//
//		turns.pop();
//		// Aniade el heroe al siguiente turno
//		turns.push(h);
//
//		if (villanos[v].vida <= 0)
//		{
//			villanos.erase(v);
//			turnsPersonajeMuerto(v);
//			return true;
//		}
//		return false;
//	}
//
//	void turnsPersonajeMuerto(string charac) {
//		// Bucle que reconstruye turns sin el personaje muerto coste O(n) donde n es el numero de personajes en turns
//		int siz = turns.size();
//		for (int i = 0; i < siz; i++)
//		{
//			auto c = turns.front();
//
//			if (c != charac)
//				// Aniade el front al final
//				turns.push(c);
//			turns.pop();
//		}
//	}
//
//};
//
//
//bool resuelveCaso() { // No tacar nada de esta función!
//	string comando;
//	cin >> comando;
//	if (!cin) return false;
//
//	SistemaBatallas sistema;
//	Villano v; Heroe h;
//	string ataque; int ptos; int valor;
//	while (comando != "FIN") {
//		try {
//			if (comando == "aparece_villano") {
//				cin >> v >> ptos >> valor;
//				sistema.aparece_villano(v, ptos, valor);
//			}
//			else if (comando == "aparece_heroe") {
//				cin >> h >> ptos;
//				sistema.aparece_heroe(h, ptos);
//			}
//			else if (comando == "aprende_ataque") {
//				cin >> h >> ataque >> valor;
//				sistema.aprende_ataque(h, ataque, valor);
//			}
//			else if (comando == "mostrar_ataques") {
//				cin >> h;
//				auto ataques = sistema.mostrar_ataques(h);
//				cout << "Ataques de " << h << endl;
//				for (auto& a : ataques) {
//					cout << a.first << " " << a.second << "\n";
//				}
//			}
//			else if (comando == "mostrar_turnos") {
//				cout << "Turno: " << endl;
//				auto turnos = sistema.mostrar_turnos();
//				for (auto& t : turnos) {
//					cout << t.first << " " << t.second << "\n";
//				}
//			}
//			else if (comando == "villano_ataca") {
//				cin >> v >> h;
//				bool derrotado = sistema.villano_ataca(v, h);
//				cout << v << " ataca a " << h << endl;
//				if (derrotado) cout << h << " derrotado" << endl;
//			}
//			else if (comando == "heroe_ataca") {
//				cin >> h >> ataque >> v;
//				bool derrotado = sistema.heroe_ataca(h, ataque, v);
//				cout << h << " ataca a " << v << endl;
//				if (derrotado) cout << v << " derrotado" << endl;
//			}
//		}
//		catch (std::exception& e) {
//			cout << "ERROR: " << e.what() << "\n";
//		}
//		cin >> comando;
//	}
//
//	cout << "---\n";
//	return true;
//}
//
////#define DOMJUDGE
//int main() {
//#ifndef DOMJUDGE
//	ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif
//
//	while (resuelveCaso()) {}
//
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//#endif
//	return 0;
//}
