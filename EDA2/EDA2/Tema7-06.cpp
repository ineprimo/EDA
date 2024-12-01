//// Andres Garcia Navarro
//// EDA-GDV27
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//// Nombre pelicula | veces emitida | antiguedad
//using Pelicula = map<string, pair<int, int>>;
//// Nombre actor | tiempo en pantalla
//using Actor = map<string, float>;
//// Nombre pelicula | vector de actores en la pelicula
//using RepartosPeliculas = map <string, Actor>;
//
//// complejidad O(n*m) donde n es el numero de peliculas y m el numero de actores
//void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
//	string peli; int numActores;
//	string actor; int minutos;
//	for (int i = 0; i < numPeliculas; ++i) {
//		cin >> peli; cin >> numActores;
//		Actor actores;
//		for (int j = 0; j < numActores; ++j) {
//			cin >> actor >> minutos;
//			actores.insert({ actor, minutos });
//		}
//		peliculas.insert({ peli, actores });
//	}
//}
//
//// complejidad del algoritmo es O(n*(logp+loga)+a*loga)
//// donde "n" es el numero de emisiones, 
//// "p" son las peliculas totales sin repeticiones,
//// y "a" la cantidad de actores sin repeticiones
//void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) {
//	// calculo de peliculas, veces que se repiten y antiguedad
//	Pelicula peli;
//	for (int i = 0; i < secEmisiones.size(); i++) {
//		if (!peli.count(secEmisiones[i]))
//		{
//			peli.insert({ secEmisiones[i],{1,i} });
//		}
//		else
//		{
//			peli[secEmisiones[i]].first++;
//			peli[secEmisiones[i]].second = i;
//		}
//	}
//
//	// escoge pelicula mas emitida y mas recientemente emitida
//	string peliMayor;
//	auto it = peli.begin();
//	peliMayor = (*it).first;
//	while (it != peli.end())
//	{
//		if (peli[peliMayor].first < (*it).second.first || (peli[peliMayor].first == (*it).second.first && peli[peliMayor].second < (*it).second.second)) {
//			peliMayor = (*it).first;
//		}
//
//		it++;
//	}
//
//	// Guardamos en un mapa de actores la cantidad de minutos que han salido en pantalla
//	Actor actores;
//	for (int i = 0; i < secEmisiones.size(); i++)
//	{
//		for (auto e : (*repartos.find(secEmisiones[i])).second)
//		{
//			if (!actores.count(e.first))
//				actores.insert({ e.first,e.second });
//			else
//				actores[e.first] += e.second;
//		}
//	}
//
//	// Escogemos al actor con mas minutos, a varios actores si todos tienen los mismos minutos
//	vector<string> actoresMayor;
//	float tMax = 0;
//	auto itA = actores.begin();
//	while (itA != actores.end())
//	{
//		if (tMax < (*itA).second) {
//			actoresMayor.clear();
//			tMax = (*itA).second;
//			actoresMayor.push_back((*itA).first);
//		}
//		else if (tMax == (*itA).second)
//		{
//			actoresMayor.push_back((*itA).first);
//		}
//
//		itA++;
//	}
//
//	// ordenamos alfabeticamente si hay varios actores con el mismo minutaje
//	sort(actoresMayor.begin(), actoresMayor.end(), [](const string& a, const string& b) {return a < b; /* Orden descendente por valor*/		});
//	
//	// imprimimos por consola la solucion
//	cout << peli[peliMayor].first << " " << peliMayor << endl;
//	cout << tMax;
//
//	for (auto a : actoresMayor) {
//		cout << " " << a;
//	}
//	cout << endl;
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada buenos dias
//	int numPelis, numEmisiones;
//	cin >> numPelis;
//	if (numPelis == 0)
//		return false;
//
//	// Lectura de los repartos de las peliculas
//	RepartosPeliculas repartos;
//	leerRepartos(numPelis, repartos);
//
//	// Lectura de la secuencia de peliculas emitidas en vector<string>
//	cin >> numEmisiones;
//	vector<string> secEmisiones(numEmisiones);
//	for (string& s : secEmisiones) cin >> s;
//
//	procesarEmisiones(repartos, secEmisiones);
//
//	return true;
//}
//
//
////#define DOMJUDGE
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