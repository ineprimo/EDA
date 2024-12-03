/*
Nombre completo: Pablo Iglesias Rodrigo.
DNI: 71043069W.
Usuario del juez: EDA-GDV35.
*/

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>


//using namespace std; // PAIGRO AQUI: quitar luego.
using Respuesta = std::vector<std::pair<std::string, int>>;

using Heroe = std::string; // Nombre del heroe.
using Villano = std::string; // Nombre del villano.


class SistemaBatallas
{
private:

	struct InfoVillano // Struct que contiene la informacion del villano (vida y danyo).
	{
	public:

		int vida; // Vida del villano.
		int danyo; // Danyo que hace el villano.
	};

	struct InfoHeroe // Struct que contiene la informacion del heroe (vida y diferentes ataques que puede hacer).
	{
	public:

		int vida; // Vida del heroe.
		std::unordered_map<std::string, int> ataques; // Mapa no ordenado que contiene los diferentes ataques del heroe.
	};

	std::unordered_map<Villano, InfoVillano> villanos; // Mapa no ordenado con los villanos con su informacion.
	std::unordered_map<Heroe, InfoHeroe> heroes; // Mapa no ordenado que contiene los heroes con su informacion.

	std::queue<std::string> turnos; // Cola para ver a quien le toca el turno.

public:

	// Coste: O(1) en lel caso mejor pero O(n) si hay muchos villanos (n).
	void aparece_villano(Villano const& v, int puntos, int valor)
	{
		// Si no esta el v lo mete.
		if (!villanos.count(v))
		{
			villanos.insert({ v,{puntos, valor } });
			turnos.push(v);
		}
		else // Sino excepcion.
		{
			throw std::invalid_argument("Personaje ya existente");
		}
	}

	// Coste: O(1) en el caso mejor pero O(n) si hay muchos heroes (n).
	void aparece_heroe(Heroe const& h, int puntos)
	{
		// Si no esta el h lo mete.
		if (!heroes.count(h))
		{
			heroes.insert({ h,{puntos} });
			turnos.push(h);
		}
		else // Sino excepcion.
		{
			throw std::invalid_argument("Personaje ya existente");
		}
	}

	// Coste: O(1) en el caso mejor pero O(n+m) si hay muchos heroes (n) y villanos (m).
	void aprende_ataque(Heroe const& h, std::string const& ataque, int valor)
	{
		if (!heroes.count(h)) // Si no esta el heroe no le mete el ataque y excepcion.
		{
			throw std::invalid_argument("Heroe inexistente");
		}
		else // Sino miramos si no lo tiene
		{
			InfoHeroe& inHe = heroes[h]; // Cogemos el struct del heroe.
			if (!inHe.ataques.count(ataque)) // Si no esta el ataque lo metemos.
			{
				inHe.ataques.insert({ ataque, valor });
			}
			else // Sino excepcion. 
			{
				throw std::invalid_argument("Ataque repetido");
			}
		}
	}

	// Coste: O(n) siendo n el numero de ataques de h.
	Respuesta mostrar_ataques(Heroe const& h)
	{
		if (!heroes.count(h)) // Si no existe el heroe excepcion.
		{
			throw std::invalid_argument("Heroe inexistente");
		}

		Respuesta res; // Vector de ataques.

		for (auto a : heroes[h].ataques)
		{
			res.push_back(a);
		}

		// Ordenacion alfabeticamente.
		std::sort(res.begin(), res.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {return a.second > b.second; });

		return res;
	}

	// Coste: O(n) en el caso mejor siendo n el numero de turnos 
	// pero en el caso peor O(n*(h+v)) siendo n el numero de turnos, h el de heroes y v el de villanos.
	Respuesta mostrar_turnos()
	{
		Respuesta res;

		for (int i = 0; i < turnos.size(); i++)
		{
			auto it = turnos.front(); // Iterador al principio para recorrer.
			std::pair<std::string, int> personaje; // Nos guardamos el personaje al que le toca el turno.

			if (villanos.count(it)) // Si el iterador es un villanos que esta lo guardamos.
			{
				personaje = { it, villanos[it].vida };
			}
			else if (heroes.count(it)) // Si es un heroe que esta lo guardamos.
			{
				personaje = { it, heroes[it].vida };
			}

			turnos.push(it); // Pone el principio en el final para que sea ciclico.
			turnos.pop(); // Quita el primero para que no se repita.

			res.push_back(personaje); // Lo mete en la respuesta.
		}

		return res;
	}

	// Coste: O(n) en el caso mejor siendo n el numero de turnos
	// pero en el caso peor O(n+h+n) siendo n el numero de turnos, h el numero de heroes y v el de villanos.
	bool villano_ataca(Villano const& v, Heroe const& h)
	{
		if (!villanos.count(v)) // Si no esta el villano excepcion.
		{
			throw std::invalid_argument("Villano inexistente");
		}
		if (!heroes.count(h)) // Si no esta el heroe excepcion.
		{
			throw std::invalid_argument("Heroe inexistente");
		}
		if (turnos.front() != v) // Si no es el turno del villano excepcion.
		{
			throw std::invalid_argument("No es su turno");
		}

		heroes[h].vida -= villanos[v].danyo; // Realizamos el ataque.


		// Siguiente turno.
		turnos.pop();
		turnos.push(v);


		// Si el heroe se ha muerto.
		if (heroes[h].vida <= 0)
		{
			heroes.erase(h); // Quitamos h de heroes.
			death(h); // Reseteamos turnos.
			return true;
		}
		return false;
	}

	// Coste: O(n) en el caso mejor siendo n el numero de turnos
	// pero en el caso peor O(n+h+n+a) siendo n el numero de turnos, h el numero de heroes, v el de villanos y a el de ataques.
	bool heroe_ataca(Heroe const& h, std::string const& ataque, Villano const& v)
	{
		if (!villanos.count(v)) // Si no existe el villano excepcion.
		{
			throw std::invalid_argument("Villano inexistente");
		}
		if (!heroes.count(h)) // Si no existe el heroe excepcion.
		{
			throw std::invalid_argument("Heroe inexistente");
		}
		if (turnos.front() != h) // Si no es el turno del heroe excepcion.
		{
			throw std::invalid_argument("No es su turno");
		}
		if (!heroes[h].ataques.count(ataque)) // Si el heroe no tiene el ataque excepcion.
		{
			throw std::invalid_argument("Ataque no aprendido");
		}

		villanos[v].vida -= heroes[h].ataques[ataque];


		// Siguiente turno.
		turnos.pop();
		turnos.push(h);


		// Si el villano se ha muerto.
		if (villanos[v].vida <= 0)
		{
			villanos.erase(v); // Quitamos v de villanos.
			death(v); // Reseteamos turnos.
			return true;
		}

		return false;
	}

	// Coste: O(n) siendo n el numero de turnos.
	void death(std::string p)
	{
		int siz = turnos.size();
		for (int i = 0; i < siz; i++)
		{
			auto c = turnos.front();
			if (c != p)
			{
				turnos.push(c);
			}
			turnos.pop();
		}
	}
};

bool resuelveCaso() { // No tacar nada de esta funcion!
	std::string comando;
	std::cin >> comando;
	if (!std::cin) return false;

	SistemaBatallas sistema;
	Villano v; Heroe h;
	std::string ataque; int ptos; int valor;
	while (comando != "FIN") {
		try {
			if (comando == "aparece_villano") {
				std::cin >> v >> ptos >> valor;
				sistema.aparece_villano(v, ptos, valor);
			}
			else if (comando == "aparece_heroe") {
				std::cin >> h >> ptos;
				sistema.aparece_heroe(h, ptos);
			}
			else if (comando == "aprende_ataque") {
				std::cin >> h >> ataque >> valor;
				sistema.aprende_ataque(h, ataque, valor);
			}
			else if (comando == "mostrar_ataques") {
				std::cin >> h;
				auto ataques = sistema.mostrar_ataques(h);
				std::cout << "Ataques de " << h << std::endl;
				for (auto& a : ataques) {
					std::cout << a.first << " " << a.second << "\n";
				}
			}
			else if (comando == "mostrar_turnos") {
				std::cout << "Turno: " << std::endl;
				auto turnos = sistema.mostrar_turnos();
				for (auto& t : turnos) {
					std::cout << t.first << " " << t.second << "\n";
				}
			}
			else if (comando == "villano_ataca") {
				std::cin >> v >> h;
				bool derrotado = sistema.villano_ataca(v, h);
				std::cout << v << " ataca a " << h << std::endl;
				if (derrotado) std::cout << h << " derrotado" << std::endl;
			}
			else if (comando == "heroe_ataca") {
				std::cin >> h >> ataque >> v;
				bool derrotado = sistema.heroe_ataca(h, ataque, v);
				std::cout << h << " ataca a " << v << std::endl;
				if (derrotado) std::cout << v << " derrotado" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "ERROR: " << e.what() << "\n";
		}
		std::cin >> comando;
	}

	std::cout << "---\n";
	return true;
}

//#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
