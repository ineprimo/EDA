// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


// función que resuelve el problema
void resolver(int raiz, int dig, int maxDigitos)
{
	raiz *= 10;
		
	for (int i = 0; i < 10; i++)
	{
		raiz += i;
		if (raiz % dig == 0)
		{
			std::cout << raiz << std::endl;
			if (dig < maxDigitos)
				resolver(raiz, dig + 1, maxDigitos);
		}
		raiz -= i;
	}
}

void escribePolidivisibles(long long raiz, int maxDigitos)
{
	std::string longitud = std::to_string(raiz);
	int d = longitud.length();
	std::cout << raiz << "\n";
	if (d < maxDigitos)
		resolver(raiz, d + 1, maxDigitos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	std::cin >> n;
	if (!std::cin)
		return false;

	int d = 0;
	std::cin >> d;

	escribePolidivisibles(n, d);
	std::cout << "---\n";
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
