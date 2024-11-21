// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<map>

using Diccionario = std::map<std::string, int>;

// Struct que guarda los cambios del viejo diccionario al nuevo.
struct Changes
{
public:
	std::vector <std::string> additions; // Guarda las claves que estan en el nuevo diccionario y no en el viejo.
	std::vector <std::string> deletions; // Guarda las claves que estaban en el viejo diccionario y no en el nuevo.
	std::vector <std::string> changes; // Guarda las claves que han modificado su valor del viejo al nuevo.
};

void leerDiccionario(Diccionario& diccionario)
{
	char c;
	std::string clave;
	int valor;
	std::cin.get(c);
	while (c != '\n')
	{
		std::cin.unget();
		std::cin >> clave >> valor;

		// Todo en minusculas.
		for (auto& l : clave)
		{
			l = tolower(l);
		}

		diccionario.insert({ clave, valor });

		std::cin.get(c);
	}
}

Changes checkDifferences(Diccionario dccOld, Diccionario dccNew)
{
	auto itOld = dccOld.begin(); // Iterador para recorrer el viejo.
	auto itNew = dccNew.begin(); // Iterador para comorbar el nuevo.

	Changes changes;

	// Los recorremos:
	while (itOld != dccOld.end() && itNew != dccNew.end())
	{
		// Caso las claves son iguales:
		if (itOld->first == itNew->first)
		{
			// Si los valores han cambiado guardamos la clave.
			if (itOld->second != itNew->second)
			{
				changes.changes.push_back(itOld->first);
			}

			// Sumamos its.
			itOld++;
			itNew++;
		}
		else
		{
			// old:   a  b          // old:  a  c
			//
			// new:   a  c          // new:  a  b  c

			// Si el valor del viejo es mayor al del nuevo entonces es que se ha metido un elemento.
			if (itOld->first > itNew->first)
			{
				changes.additions.push_back(itNew->first);
				itNew++;
			}
			else // En caso contrario es que se ha eliminado un elemento.
			{
				changes.deletions.push_back(itOld->first);
				itOld++;
			}
		}
	}

	// Acabamos de recorrer los diccionarios:

	// El viejo. Si este no se ha acabado de recorrer es que se han quitado valores.
	while (itOld != dccOld.end())
	{
		changes.deletions.push_back(itOld->first);
		itOld++;
	}
	// El nuevo. Si este no se ha acabado de recorrer es que se han metido valores.
	while (itNew != dccNew.end())
	{
		changes.additions.push_back(itNew->first);
		itNew++;
	}


	return changes;
}

void resuelveCaso()
{
	// Leer diccionarios:
	Diccionario antiguo;
	Diccionario nuevo;
	leerDiccionario(antiguo);
	leerDiccionario(nuevo);

	// Comprobar las diferencias:
	Changes sol = checkDifferences(antiguo, nuevo);

	// Escribir solucion:

	// Iguales.
	if (sol.additions.size() == 0 && sol.deletions.size() == 0 && sol.changes.size() == 0)
	{
		std::cout << "Sin cambios\n";
	}
	else // Diferentes.
	{
		// Metidas:
		if (sol.additions.size() > 0)
		{
			std::cout << "+";
			for (auto a : sol.additions)
			{
				std::cout << " " << a;
			}
			std::cout << std::endl;
		}
		// Sacadas:
		if (sol.deletions.size() > 0)
		{
			std::cout << "-";
			for (auto d : sol.deletions)
			{
				std::cout << " " << d;
			}
			std::cout << std::endl;
		}
		// Cambiadas:
		if (sol.changes.size() > 0)
		{
			std::cout << "*";
			for (auto c : sol.changes)
			{
				std::cout << " " << c;
			}
			std::cout << std::endl;
		}
	}
	std::cout << "---" << std::endl;
}


int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos = 0;
	char c;
	std::cin >> numCasos;
	std::cin.get(c);
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}