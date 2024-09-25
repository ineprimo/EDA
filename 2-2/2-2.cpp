// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <iomanip>
#include <fstream>

// O(1)
int digito(int n)
{
	return 9 - n;
}

// función que resuelve el problema
// O(log n) al ser recursivo, siendo n el número de dígitos del número
// si el número de dígitos crece exponencialmente, el coste lo hace linealmente
int complementario(int n)
{
	if (n < 10)
		return digito(n);

	return complementario(n / 10) * 10 + digito(n % 10); // reduce hasta la unidad y luego anyade la siguiente
}

std::pair<int, int> inverso(int n)
{
	if (n < 10)
		return { digito(n), 10 };

	std::pair<int, int> inv = inverso(n / 10);

	int comp = inv.first; 
	int pos = inv.second;

	return { digito(n % 10) * pos + comp, pos * 10 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	// escribir sol
	std::cout << complementario(n) << " " << inverso(n).first << "\n";
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
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
