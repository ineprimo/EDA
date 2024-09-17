// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// funcion que resuelve el problema
bool resolver(std::vector<int> datos, int pos)
{
	bool bienOrdenado = true;
	int i = 0;
	int tempMaxIzq = datos[0];
	int	tempMinDer = datos[datos.size() - 1];

	// Lado izquierdo del vector. Cojemos la temperatura maxima.
	while (i <= pos)
	{
		if (datos[i] > tempMaxIzq)
		{
			tempMaxIzq = datos[i];
		}
		i++;
	}

	// Lado derecho del vector. Comprobamos que la temperatura maxima del lado derecho sea mayor a la menor del lado izquierdo.
	while (i < datos.size() && bienOrdenado)
	{
		if (datos[i] <= tempMaxIzq)
		{
			bienOrdenado = false;
		}
		i++;
	}

	return bienOrdenado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// escribir sol

	// leer los datos de la entrada

	int size = 0;
	std::cin >> size;
	int pos = 0;
	std::cin >> pos;

	std::vector<int> datos;
	int dato = 0;

	for (int i = 0; i < size; i++)
	{
		std::cin >> dato;
		datos.push_back(dato);
	}


	bool sol = resolver(datos, pos);

	// escribir sol

	if (sol)
	{
		std::cout << "SI" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}