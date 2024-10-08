/*
Nombre completo: Pablo Iglesias Rodrigo.
Usuario del juez: EDA-GDV35
COMPLEJIDAD: tiene complejidad O(log n) porque es busqueda binaria. n es el numero de elementos del vector sec.
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
		return prim;
	}
	else if (n == 1) // Caso base size 1.
	{
		if (prim == sec[ini]) // Si el caracter es y es y esta en su posicion es el siguiente caracter asci.
		{
			return sec[ini] + 1;
		}
		else // Sino es el anterior asci.
		{
			return sec[ini] - 1;
		}
	}

	if (sec[ini] != prim) // Caso de que el primero no sea el primero.
	{
		return prim;
	}
	if (sec[fin - 1] != ult) // Caso de que el ultimo no sea el ultimo.
	{
		return ult;
	}


	int med = (ini + fin) / 2;
	char esperado = prim + (med - ini); // Numero que se espera que este en la mitad para poder hacer la division de ambos casos. char esperado = prim + (mitad - ini)

	if (esperado == sec[med])
	{
		return resolver(sec, sec[med], sec[fin - 1], med, fin); // Lado derecho del vector.
	}
	else
	{
		return resolver(sec, sec[ini], sec[med - 1], ini, med); // Lado izquierdo del vector.
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