// Nombre completo: Denisa Juarranz Berindea
// Usuario del juez: EDA-GDV37

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

using Heroe = string;
using Villano = string;

class SistemaBatallas {
private:
	struct InfoVillano
	{
		int vida;
		int ataque;
	};

	struct InfoHero
	{
		int vida;
		unordered_map<string, int> ataques;
	};

	unordered_map< Villano, InfoVillano> villanos;
	unordered_map< Heroe, InfoHero> heroes;

	vector<string> turns;
	int turnoActual = 0;

public:

	SistemaBatallas() {}
	~SistemaBatallas() {}

	// Es lineal, O(n), donde n es el numero de elementos de villanos. 
	// Pero, normalmente nos encontraremos con un coste promedio O(1).
	void aparece_villano(Villano const& v, int puntos, int valor) {
		// Si ya existe el villano, lanza excepcion
		if (villanos.count(v))
			throw invalid_argument("Personaje ya existente");

		// Anadimos el villano al map
		villanos.insert({ v,{puntos, valor} });

		turns.push_back(v);
	}

	// Es lineal, O(n), donde n es el numero de elementos de heroes. 
	// Pero, normalmente nos encontraremos con un coste promedio O(1).
	void aparece_heroe(Heroe const& h, int puntos) {
		// Si ya existe el heroe lanza una excepcion
		if (heroes.count(h))
			throw invalid_argument("Personaje ya existente");

		// Aniade el heroe al map
		heroes.insert({ h,{puntos} });

		turns.push_back(h);
	}

	// Es coste O(n+m), donde n es el numero de elementos de heroe, y m el número de ataques del heroe h. 
	// Pero, normalmente nos encontraremos con un coste promedio O(1).
	void aprende_ataque(Heroe const& h, string const& ataque, int valor) {
		// Si no existe el heroe para aprender el ataque lanza excepcion
		if (!heroes.count(h))
			throw invalid_argument("Heroe inexistente");
		// Cacheamos la informacion del heroe 
		InfoHero& info = heroes[h];
		// Si el heroe ya conoce el ataque lanza excepcion
		if (info.ataques.count(ataque))
			throw invalid_argument("Ataque repetido");

		// Anadimos el ataque a la lista de ataques
		info.ataques.insert({ ataque,valor });
	}

	// Es lineal, O(n) donde n es el numero de ataques que tiene el heroe h
	vector<pair<string, int>> mostrar_ataques(Heroe const& h) {
		// Si no existe el heroe lanza excepcion
		if (!heroes.count(h))
			throw invalid_argument("Heroe inexistente");
		// Guardamos los ataques en el vector atq
		vector<pair<string, int>> atq;

		// O(a), siendo a los elementos en ataques
		for (auto a : heroes[h].ataques)
			atq.push_back(a);

		return atq;
	}

	// Es lineal, O(n) donde n es el numero de elementos de turns. En el peor de los casos O(n*(V+H)) donde:
	// n es el numero de elementos de turns, H el de heroes y V el de villanos
	vector<pair<string, int>> mostrar_turnos() {
		vector<pair<string, int>> turn;

		pair <string, int> charac;
		for (auto c : turns)
		{
			// si no hay nombre en el turno lo salta
			if (c == "")
				continue;

			// guarda los datos del personaje que buscamos
			if (villanos.count(c))
				charac = { c,villanos[c].vida };
			else if (heroes.count(c))
				charac = { c,heroes[c].vida };

			// anade el front al final
			turnoActual++;

			turn.push_back(charac);
		}

		return turn;
	}

	// Es lineal, O(n) n es el numero de elementos en turns. En el peor de los casos sera O(n+H+V) donde:
	// n es el numero de elementos de turns, H el de heroes y V el de villanos
	bool villano_ataca(Villano const& v, Heroe const& h) {
		if (!villanos.count(v))
			throw invalid_argument("Villano inexistente");
		if (!heroes.count(h))
			throw invalid_argument("Heroe inexistente");
		if (turns.front() != v)
			throw invalid_argument("No es su turno");
		heroes[h].vida -= villanos[v].ataque;

		// avanza turno
		turnoActual++;
		if (turnoActual >= turns.size())
			turnoActual = 0;

		// acaba con heroe
		if (heroes[h].vida <= 0)
		{
			heroes.erase(h);
			turnsPersonajeMuerto(h);
			return true;
		}
		return false;
	}

	// Es lineal, O(n) n es el numero de elementos en turns. En el peor de los casos sera O(n+H+V+A) donde:
	// n es el numero de elementos de turns, H el de heroes, V el de villanos y A el de los ataques de h
	bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
		if (!villanos.count(v))
			throw invalid_argument("Villano inexistente");
		if (!heroes.count(h))
			throw invalid_argument("Heroe inexistente");
		if (turns.front() != h)
			throw invalid_argument("No es su turno");
		if (!heroes[h].ataques.count(ataque))
			throw invalid_argument("Ataque no aprendido");
		villanos[v].vida -= heroes[h].ataques[ataque];

		// avanza turno
		turnoActual++;
		if (turnoActual >= turns.size())
			turnoActual = 0;

		// acaba con villano
		if (villanos[v].vida <= 0)
		{
			villanos.erase(v);
			turnsPersonajeMuerto(v);
			return true;
		}
		return false;
	}

	// Es constante, O(1) al eliminar el personaje en el turno
	void turnsPersonajeMuerto(string charac) {

		int turno = turnoActual--;
		if (turno < 0) turno = turns.size() - 1;

		turns[turno] = "";
	}

};

bool resuelveCaso() { 
	string comando;
	cin >> comando;
	if (!cin) return false;

	SistemaBatallas sistema;
	Villano v; Heroe h;
	string ataque; int ptos; int valor;
	while (comando != "FIN") {
		try {
			if (comando == "aparece_villano") {
				cin >> v >> ptos >> valor;
				sistema.aparece_villano(v, ptos, valor);
			}
			else if (comando == "aparece_heroe") {
				cin >> h >> ptos;
				sistema.aparece_heroe(h, ptos);
			}
			else if (comando == "aprende_ataque") {
				cin >> h >> ataque >> valor;
				sistema.aprende_ataque(h, ataque, valor);
			}
			else if (comando == "mostrar_ataques") {
				cin >> h;
				auto ataques = sistema.mostrar_ataques(h);
				cout << "Ataques de " << h << endl;
				for (auto& a : ataques) {
					cout << a.first << " " << a.second << "\n";
				}
			}
			else if (comando == "mostrar_turnos") {
				cout << "Turno: " << endl;
				auto turnos = sistema.mostrar_turnos();
				for (auto& t : turnos) {
					cout << t.first << " " << t.second << "\n";
				}
			}
			else if (comando == "villano_ataca") {
				cin >> v >> h;
				bool derrotado = sistema.villano_ataca(v, h);
				cout << v << " ataca a " << h << endl;
				if (derrotado) cout << h << " derrotado" << endl;
			}
			else if (comando == "heroe_ataca") {
				cin >> h >> ataque >> v;
				bool derrotado = sistema.heroe_ataca(h, ataque, v);
				cout << h << " ataca a " << v << endl;
				if (derrotado) cout << v << " derrotado" << endl;
			}
		}
		catch (std::exception& e) {
			cout << "ERROR: " << e.what() << "\n";
		}
		cin >> comando;
	}

	cout << "---\n";
	return true;
}

//#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}