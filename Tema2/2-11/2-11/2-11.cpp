/*
Nombre completo: Pablo Iglesias Rodrigo.
Usuario del juez: EDA-GDV35
COMPLEJIDAD:
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
char resolver(const std::vector<char>& sec, char prim, char ult, int ini, int fin)
{
	// Casos base:
	int n = fin - ini; // Lo que ocupa.

	if (n == 0) // Caso base size 0 nadie se ha escapado.
	{
		return ' ';
	}
	else if (n == 1) // Caso base size 1.
	{
		if (prim == sec[ini])
		{
			return sec[ini + 1];
		}
	}
	else if (n == 2) // Caso base size 2.
	{
		// return
	}


	int med = (ini + fin) / 2;
	char esperado = prim + (med - ini); // char esperado = prim + (mitad - ini)

	if (esperado == sec[med])
	{
		return resolver(sec, prim, ult, med, fin);
	}
	else
	{
		return resolver(sec, prim, ult, ini, med);
	}



	// a b c e                         a  b   |   c  e
	// 
	// med = c
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada

	char prim, ult, n;
	std::cin >> prim >> ult;

	n = ult - prim;
	std::vector<char> sec(n);

	for (char& e : sec)
	{
		std::cin >> e;
	}

	std::cout << resolver(sec, prim, ult, 0, n) << std::endl;
}

//#define DOMJUDGE
int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("input2.txt");
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
	//system("PAUSE");
#endif

	return 0;
}