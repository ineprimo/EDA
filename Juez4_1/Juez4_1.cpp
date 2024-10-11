#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

bool esFeliz(int n)
{
	std::set<int> set;
	set.insert(n);
	std::cout << n << " ";
	while (n != 1)
	{
		int sum = 0; 
		while (n != 0) 
		{
			const int dig = n % 10;
			sum = sum + dig * dig; 
			n /= 10;
		}
		n = sum;

		std::cout << n << " ";


		// si la suma ya se encuentra en el set, hemos ciclado una vez
		// y por tanto el numero no puede ser feliz
		if (set.find(sum) != set.end()) 
			return false;

		// si no lo ha encontrado, continua el bucle como de normal y lo anade a la lista
		set.insert(sum);
	}
	// si n acaba siendo 1 es feliz
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	std::cin >> n;
	if (!std::cin)
		return false;

	std::cout << (esFeliz(n) ? "1" : "0") << std::endl;
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


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}