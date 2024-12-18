//// Nombre completo: Andres Garcia Navarro
//// Usuario del juez: EDA-GDV27
//
//#include <iostream>
//#include <stdexcept>
//#include <fstream>
//#include <vector>
//#include <utility>
//#include <unordered_map>
//#include <map>
//#include <list>
//
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
//		list<pair<string, int>>::iterator it;
//		int vida;
//		int ataque;
//	};
//
//	struct InfoHero
//	{
//		list<pair<string, int>>::iterator it;
//		int vida;
//		map<string, int> ataques;
//	};
//
//	unordered_map< Villano, InfoVillano> villanos;
//	unordered_map< Heroe, InfoHero> heroes;
//
//	// nombre del personaje || vida del personaje
//	list<pair<string, int>> turns; // lista para saber el orden de los turnos
//
//public:
//
//	SistemaBatallas() {}
//	~SistemaBatallas() {}
//
//	// Coste: Coste promedio O(1).
//	void aparece_villano(Villano const& v, int puntos, int valor) {
//		// Si ya existe el villano, lanza una excepcion
//		if (villanos.find(v) != villanos.end())
//			throw invalid_argument("Personaje ya existente");
//
//		turns.emplace_back(v, puntos);
//
//		// Aniade el villano al map
//		villanos[v].vida = puntos;
//		villanos[v].ataque = valor;
//		villanos[v].it = --turns.end();
//	}
//
//	// Coste: Coste promedio O(1).
//	void aparece_heroe(Heroe const& h, int puntos) {
//		// Si ya existe el heroe lanza una excepcion
//		if (heroes.find(h) != heroes.end())
//			throw invalid_argument("Personaje ya existente");
//
//		turns.emplace_back(h, puntos);
//
//		// Aniade el heroe al turns
//		heroes[h].vida = puntos;
//		heroes[h].it = --turns.end();
//	}
//
//	// Coste: Coste promedio O(log n) donde n es el numero de ataques del heroe h.
//	void aprende_ataque(Heroe const& h, string const& ataque, int valor) {
//		// Si no existe el hero al que queremos aniadir el ataque lanza excepcion
//		if (!heroes.count(h))
//			throw invalid_argument("Heroe inexistente");
//		// Cacheamos la informacion del heroe para no tener que buscarla todo el rato
//		auto& info = heroes[h].ataques;
//		// Si ya existe el ataque en el heroe lanza excepcion
//		if (info.count(ataque))
//			throw invalid_argument("Ataque repetido");
//
//		// Aniadimos el ataque a la lista de ataques
//		info.insert({ ataque,valor });
//	}
//
//	// Coste: el coste lineal O(n) donde n es el numero de ataques que tiene el heroe h.
//	vector<pair<string, int>> mostrar_ataques(Heroe const& h) {
//		// Si no existe el hero lanza excepcion
//		if (heroes.find(h) == heroes.end())
//			throw invalid_argument("Heroe inexistente");
//		// Guardamos los ataques en el vector res
//		vector<pair<string, int>> res;
//		auto ataquesH = heroes[h].ataques; // mapa ordenado
//
//		for (auto& a : ataquesH)
//			res.emplace_back(a.first, a.second);
//
//		return res;
//	}
//
//	// Coste: el coste es lineal O(n) donde n es el numero de elementos de turns.
//	vector<pair<string, int>> mostrar_turnos() {
//		vector<pair<string, int>> res;
//
//		for (auto c : turns)
//		{
//			res.emplace_back(c.first, c.second);
//		}
//
//		return res;
//	}
//
//	// Coste: el coste es lineal O(1) gracias al uso de iteradores.
//	bool villano_ataca(Villano const& v, Heroe const& h) {
//		const auto villano = villanos.find(v);
//		if (villano == villanos.end())
//			throw invalid_argument("Villano inexistente");
//		const auto heroe = heroes.find(h);
//		if (heroe == heroes.end())
//			throw invalid_argument("Heroe inexistente");
//		if (v != turns.front().first)
//			throw invalid_argument("No es su turno");
//
//		// actualizacion de turnos
//		turns.pop_front();
//		heroe->second.vida -= villano->second.ataque;
//		heroe->second.it->second = heroe->second.vida; // hace danio
//		turns.emplace_back(v, villano->second.vida);
//		villano->second.it = --turns.end();
//
//		if (heroe->second.vida <= 0)
//		{
//			// coste de eliminacion de heroe constante
//			turns.erase(heroe->second.it);
//			heroes.erase(heroe);
//			return true;
//		}
//
//		return false;
//	}
//
//	// Coste: el coste es lineal O(log n) n es el numero de ataques del heroe h.
//	bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
//		const auto villano = villanos.find(v);
//		if (villano == villanos.end())
//			throw invalid_argument("Villano inexistente");
//		const auto heroe = heroes.find(h);
//		if (heroe == heroes.end())
//			throw invalid_argument("Heroe inexistente");
//		if (h != turns.front().first)
//			throw invalid_argument("No es su turno");
//		const auto ataqueHeroe = heroe->second.ataques.find(ataque);
//		if (ataqueHeroe == heroe->second.ataques.end())
//			throw invalid_argument("Ataque no aprendido");
//
//		// actualizacion de turnos
//		turns.pop_front();
//		villano->second.vida -= ataqueHeroe->second;
//		villano->second.it->second = villano->second.vida; // hace danio
//		turns.emplace_back(h, heroe->second.vida);
//		heroe->second.it = --turns.end();
//
//		if (villano->second.vida <= 0)
//		{
//			// coste de eliminacion de heroe constante
//			turns.erase(villano->second.it);
//			villanos.erase(villano);
//			return true;
//		}
//
//		return false;
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
