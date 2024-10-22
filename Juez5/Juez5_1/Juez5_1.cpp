#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>


// función que resuelve el problema
// O(n) siendo n la longitud del string
// stack.empty() es de complejidad constante
bool resolver(std::string linea)
{
	std::stack<char> pila;

	for (char c : linea) {
		if (c == '(' || c == '[' || c == '{')
			pila.push(c);
		else if (c == ')')
		{
			if (!pila.empty() && pila.top() == '(')
				pila.pop();
			else
				pila.push(c);
		}
		else if (c == ']')
		{
			if (!pila.empty() && pila.top() == '[')
				pila.pop();
			else
				pila.push(c);
		}
		else if (c == '}')
		{
			if (!pila.empty() && pila.top() == '{')
				pila.pop();
			else
				pila.push(c);
		}
	}

	return pila.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	std::string linea;
	std::getline(std::cin, linea);

	if (!std::cin)
		return false;

	std::cout << (resolver(linea) ? "SI" : "NO") << std::endl;

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