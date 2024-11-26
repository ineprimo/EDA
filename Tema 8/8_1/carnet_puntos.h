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

private:
	//Nos guardamos un map de dni??
	map<string, int> conductores;
};
