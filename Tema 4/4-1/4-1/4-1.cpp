// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Set.h"


// funcion que resuelve el problema
Set <int> feliz(int num, Set<int>& datos)
{
	if (num == 1) // El numero es feliz.
	{
		return datos;
	}

	int aux1 = 0; // Auxiliar para sacar los digitos.
	int aux2 = 0; // Auxiliar para sacar el nuevo numero.

	while (num > 0) // Suma de los cuadrados de sus digitos.
	{
		aux1 = num % 10; // Cogemos el primer digito.
		aux2 += aux1 * aux1; // Hacemos su cuadrado.
		num /= 10; // Reducimos el numero.
	}
	num = aux2;

	std::cout << num << " "; // Escribimos el numero que ha salido.

	if (datos.contains(num)) // Si datos ya tiene el numero entonces no llegara nunca a ser feliz entonces no seguimos.
	{
		return datos;
	}

	datos.add(num); // Si no esta lo metemos.
	feliz(num, datos); // Volvemos a llamar para que siga buscando digitos.
	return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int num = 0;

	std::cin >> num;
	Set <int> datos(1);

	if (!std::cin)
	{
		return false;
	}

	std::cout << num << " ";
	datos.add(num);
	feliz(num, datos);

	// escribir sol

	if (datos.contains(1)) // Ponemos al final si es feliz o no.
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