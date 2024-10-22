// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include <queue>
#include <stack>


// Funcion que resuelve el problema. COMPLEJIDAD: O(n), n es la longitud de la linea. Los metodos push(), empty() y pop() son constantes.
void reordenar(std::queue<int>& datos)
{
	std::queue<int> pos; // Cola de numeros positivos, los positivos estan bien ordenados entonces queremos que al sacarlos de aqui los primeros en haber entrado sean los primeros en salir. (FiFo).
	std::stack<int> neg; // Pila de numeros negativos, se van metiendo y los que se van quitando son los ultimos en haber entrado entones srive para los negativos porque estan ordenados al reves al estar por valor absoluto. (LiFo).

	// Vaciamos la cola inicial en positivos y negativos.
	while (!datos.empty())
	{
		if (datos.front() > 0) // Positivos a la cola.
		{
			pos.push(datos.front());
			datos.pop();
		}
		else // Negativos a la pila.
		{
			neg.push(datos.front());
			datos.pop();
		}
	}

	// Ahora hay que volver a meter los numeros en orden.
	// Negativos.
	while (!neg.empty()) 
	{
		datos.push(neg.top());
		neg.pop();
	}
	// Positivos.
	while (!pos.empty()) 
	{
		datos.push(pos.front());
		pos.pop();
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
bool resuelveCaso()
{
	//------Leemos:
	int elems = 0;
	int elem = 0;

	std::queue<int> datos;

	std::cin >> elems;
	if (elems == 0)
	{
		return false;
	}

	for (int i = 0; i < elems; i++)
	{
		std::cin >> elem;
		datos.push(elem);
	}

	//------Resolvemos:
	reordenar(datos);

	//------Escribimos:
	while (!datos.empty())
	{
		std::cout << datos.front() << " "; // Escribimos el primer elemento.
		datos.pop(); // Quitamos el primer elemetno.
	}
	std::cout << std::endl;

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