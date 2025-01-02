// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>


// Algoritmo recursivo que calcula el complementario a un numero y el inverso al complementario.
// COMPLEJIDAD: O(n) siendo n el numero de digitos del numero dado.
void comp(int num, int& com, int& inv)
{
	// Caso base:
	if (num < 10)
	{
		com = 9 - num;
		inv = (inv * 10) + (9 - num);
	}
	else
	{
		inv *= 10;
		inv += 9 - (num % 10);
		comp(num / 10, com, inv);
		com *= 10;
		com += 9 - (num % 10);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	int num = 0; // Numero dado en el enunciado.
	int com = 0; // Complementario al numero.
	int inv = 0; // Inverso al complementario.


	// Lectura:
	std::cin >> num;


	// Resolver:
	comp(num, com, inv);


	// Escribir solucion:
	std::cout << com << " " << inv << std::endl;
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
	//system("PAUSE");
#endif

	return 0;
}
