#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

bool esFeliz(int n)
{
	//Metemos el número en el set (no ordenado, pero sin repes)
	std::set<int> set;
	set.insert(n);
	std::cout << n << " ";
	//Desglosamos los números en sus dígitos (con % y /)
	//Hasta que la suma final no sea 1, seguimos
	while (n != 1)
	{
		//Aquí guardaremos cada suma
		int sum = 0;
		//Vamos mirando dígito por dígito
		while (n != 0)
		{
			int dig = n % 10;
			//Y en sum sumamos su cuadrado
			sum = sum + dig * dig;
			//Cambiamos de dígito
			n /= 10;
		}
		n = sum;

		std::cout << sum << " ";

		// si la suma ya se encuentra en el set, estamos en un bucle
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

	if (esFeliz(n))
	{
		std::cout << "1" << std::endl;
	}
	else
	{
		std::cout << "0" << std::endl;
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


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}