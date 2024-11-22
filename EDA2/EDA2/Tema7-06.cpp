#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// pelicula, veces emitida
using Pelicula = map<string, float>;
// actor, tiempo en pantalla
using Actor = pair<string, float>;
// pelicula, vector de actores en la pelicula
using RepartosPeliculas = map <string, vector<Actor>>;
// actor, minutos en pantalla
using Actores = map<string, float>;


void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
	string peli; int numActores;
	string actor; int minutos;
	for (int i = 0; i < numPeliculas; ++i) {
		cin >> peli; cin >> numActores;
		vector<Actor> actores;
		for (int j = 0; j < numActores; ++j) {
			cin >> actor >> minutos;
			actores.push_back({ actor, minutos });
		}
		peliculas.insert({ peli, actores });
	}
}

// complejudad del algoritmo O(n*logn) donde n son el numero de elementos de secEmisiones
void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) {
	Pelicula peli;
	for (auto e : secEmisiones) {
		if (!peli.count(e))
			peli.insert({ e,1 });
		else
			peli[e]++;
	}

	string peliMayor;
	auto it = peli.begin();
	peliMayor = (*it).first;
	while (it != peli.end())
	{
		if (peli[peliMayor] < (*it).second) {
			peliMayor = (*it).first;
		}

		it++;
	}

	Actores actores;
	for (int i = 0; i < secEmisiones.size(); i++)
	{
		vector<Actor> vec = (*repartos.find(secEmisiones[i])).second;
		for (auto e : vec)
		{
			if (!actores.count(e.first))
				actores.insert({ e.first,e.second });
			else
				actores[e.first] += e.second;
		}
	}

	// numero de actores 
	vector<string> actoresMayor;
	float tMax = 0;
	auto itA = actores.begin();
	while (itA != actores.end())
	{
		if (tMax < (*itA).second) {
			actoresMayor.clear();
			tMax = (*itA).second;
			actoresMayor.push_back((*itA).first);
		}
		else if (tMax == (*itA).second)
		{
			actoresMayor.push_back((*itA).first);
		}

		itA++;
	}

	sort(actoresMayor.begin(), actoresMayor.end(), [](const string& a, const string& b) {return a < b; /* Orden descendente por valor*/		});
	cout << peli[peliMayor] << " " << peliMayor << endl;
	cout << tMax;

	for (auto a : actoresMayor) {
		cout << " " << a;
	}
	cout << endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada buenos dias
	int numPelis, numEmisiones;
	cin >> numPelis;
	if (numPelis == 0)
		return false;

	// Lectura de los repartos de las peliculas
	RepartosPeliculas repartos;
	leerRepartos(numPelis, repartos);

	// Lectura de la secuencia de peliculas emitidas en vector<string>
	cin >> numEmisiones;
	vector<string> secEmisiones(numEmisiones);
	for (string& s : secEmisiones) cin >> s;

	procesarEmisiones(repartos, secEmisiones);

	return true;
}


//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}