// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> datos)
{
	bool dalton = true;
	int i = 1;

	while (dalton && i < datos.size() - 1)
	{
		int ant = datos[i - 1];
		int num = datos[i];
		int sig = datos[i + 1];

		bool mayorMenor = (ant > num && num > sig);
		bool menorMayor = (ant < num && num < sig);

		if (!(menorMayor || mayorMenor))
		{
			dalton = false;
		}
		i++;
	}
	return dalton;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int size = 0;
	std::cin >> size;

	if (size == 0)
	{
		return false;
	}

	std::vector<int> datos;
	int dato = 0;

	for (int i = 0; i < size; i++)
	{
		std::cin >> dato;
		datos.push_back(dato);
	}

	bool sol = resolver(datos);

	// escribir sol
	if (sol)
	{
		std::cout << "DALTON" << std::endl;
	}
	else
	{
		std::cout << "DESCONOCIDOS" << std::endl;
	}

	return true;
}

int main()
{
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
	system("PAUSE");
#endif

	return 0;
}
