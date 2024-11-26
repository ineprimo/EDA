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

private:
	//Nos guardamos un map de dni??
	map<string, int> conductores;
};
