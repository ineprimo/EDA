// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <fstream>
#include <vector>


bool anagramas(const std::string& cad1, const std::string& cad2)
{
	bool anagrama = true;
	int i = 0;
	int j = 0;
	int k = 0;






	while (anagrama && i < cad1.length())
	{
		if (cad1[i] == cad2[j])
		{
			i++;
			j = 0;
			k++;
		}
		else
		{
			j++;
		}

		
	}

	anagrama = k == cad1.length();
	//std::cout << anagrama;
	return anagrama;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	std::string word1, word2;
	std::cin >> word1 >> word2;
	std::cout << (anagramas(word1, word2) ? "SI" : "NO") << std::endl;
}

//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}