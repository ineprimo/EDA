// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <fstream>

#include <vector>

// COMPLEJIDAD: es de complejidad lineal O(n). Primeero se comprueba si son igual de largas las dos palabras. 
// En el primer bucle se hacen n iteraciones siendo n la longitud de la palabra 
// y luego el operador == que comprueba si son iguales los dos vectores (26 iteraciones).
bool anagramas(const std::string& cad1, const std::string& cad2)
{
	// Comprobamos que las palabras son del mismo tamanyo. Si no lo son no pueden ser anagramas.
	if (cad1.length() != cad2.length())
	{
		return false;
	}
	// Hacemos un vector de letras para cada palabra.
	std::vector<int> letras1(26, 0);
	std::vector<int> letras2(26, 0);

	// Sumamos las veces que aparece cada letra.
	for (int i = 0; i < cad1.length(); i++)
	{
		letras1[cad1[i] - 'a']++;
		letras2[cad2[i] - 'a']++;
	}

	return letras1 == letras2; // Comprobamos que son iguales.
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