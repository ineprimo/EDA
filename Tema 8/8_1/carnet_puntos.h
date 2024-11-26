#pragma once
#include <map> 

class carnet_puntos {

public:

	void nuevo(const string dni) {
		//Comprobamos si ya tenemos el dni
		if (conductores.count(dni) == 0) {	//El dni es nuevo
			conductores.insert({ dni, 15 });
		}
		else throw std::domain_error("Conductor duplicado");
	}

	void quitar(const string dni, int puntos) {
		//Comprobamos si el conductor existe
		auto it = conductores.find(dni);
		if (it != conductores.end()) {	//El dni existe

			it->second -= puntos;

			if (it->second < 0) it->second = 0;
		}
		else throw std::domain_error("Conductor inexistente");
	}

	int consultar(string dni) {
		//Comprobamos si el conductor existe
		auto it = conductores.find(dni);

		//El dni existe
		if (it != conductores.end()) { return it->second; }
		else throw std::domain_error("Conductor inexistente");
	}

	int cuantos_con_puntos(int puntos) {

		if (puntos >= 0 && puntos <= 15)	//Los puntos estan dentro del rango
		{
			//Recorremos el mapa viendo los puntos y nos guardamos los que tengan los puntos con un contador
			int cont = 0;

			for (auto par : conductores) if (par.second == puntos) cont++;
			return cont;
		}
		else throw std::domain_error("Puntos no validos");
	}

private:
	//Nos guardamos un map de dni??
	map<string, int> conductores;
};
