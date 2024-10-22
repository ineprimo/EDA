// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>


// Funcion que resuelve el problema. COMPLEJIDAD: O(n), n es la longitud de la linea. Los metodos push(), empty() y pop() son constantes.
bool equilibrado(std::string line)
{
	std::stack<char> pila;

	for (char c : line) // Recorremos la linea.
	{
		// Primero comprobamos los caracteres de apertura.
		if (c == '(' || c == '[' || c == '{')
		{
			pila.push(c);
		}
		else if (c == ')')
		{
			if (!pila.empty() && pila.top() == '(') // Si la pila no esta vacia y el ultimo caracter es el de apertura de parentesis quitamos ese caracter porque esta equilibrado.
			{
				pila.pop();
			}
			else // Si no lo metemos.
			{
				pila.push(c);
			}
		} // Lo mismo para los cierres de corchetes y llaves:
		else if (c == ']')
		{
			if (!pila.empty() && pila.top() == '[')
			{
				pila.pop();
			}
			else 
			{
				pila.push(c);
			}
		}
		else if (c == '}')
		{
			if (!pila.empty() && pila.top() == '{')
			{
				pila.pop();
			}
			else
			{
				pila.push(c);
			}
		}
	}
	return pila.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
bool resuelveCaso()
{
	std::string line;
	std::getline(std::cin, line);

	if (!std::cin)
	{
		return false;
	}

	std::cout << (equilibrado(line) ? "SI" : "NO") << std::endl;

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