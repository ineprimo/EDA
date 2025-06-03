// Ejercicio 2: Cruce de lineas (3 puntos) 
// Tipo: DIVIDE ET IMPERA

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//*******************************
// Explicacion del algoritmo empleado
// Coste del algoritmo. Incluye recurrencia y desplegado de la recurrencia
//
// Y no olvides poner comentarios en el codigo
//*******************************

/*
Tenemos dos series de numeros enteros de la misma longitud (n > 0):
	1ª) la primera ordenada en orden creciente
	2ª) la segunda en orden estrictamente decreciente
	=> valores de dos funciones f(x) para 0 <= x < n

Implementar:
	Algoritmo que determine las posiciones entre las que se encontraria el punto de corte de dichas funciones
	y justificar su coste.
Ejemplo:
	La figura muestra las funciones para las series del primer caso de prueba.
    El punto de corte estaria entre las posiciones 1 y 2.
*/
bool cruce(const std::vector<int>& ascendente, const std::vector<int>& descendente, int ini, int fin, std::pair<int,int>& corte)
{
    int elems = fin - ini;

    // caso base
    if (elems == 1)
    {
        if (ascendente[ini] == descendente[ini])
        {
            corte = { ini, 0 };
            return true;
        }

        if (ascendente[ini] > descendente[ini])
        {
            corte = { -1, 0 };
        }
        else
        {
			corte = { ini, fin };
        }

        return false;
    }

    int mit = (ini + fin) / 2;

    // encuentras el corte
    if (ascendente[mit] == descendente[mit])
    {
        corte = {mit, 0};
        return true;
    }
    // el corte esta a la izq
    if (ascendente[mit] > descendente[mit])
    {
        return cruce(ascendente, descendente, ini, mit, corte);
    }
    // el corte esta a la der
    if (ascendente[mit] < descendente[mit])
    {
        return cruce(ascendente, descendente, mit, fin, corte);
    }

    return false;
}

bool resuelveCaso()
{
    // numero de elementos de las dos series
    int numElem;
    std::cin >> numElem;

    if (numElem == 0) return false; // termina entrada

    // valores de la serie ASCENDENTE
    std::vector<int> v1(numElem);
    // valores de la serie DESCENDENTE
    std::vector<int> v2(numElem);

    for (int& i : v1) std::cin >> i;
    for (int& i : v2) std::cin >> i;

    // Salida
    /*
    Para cada caso:
		SI) Si existe una posicion en la que coinciden los valores de las dos series,
		seguido de la posicion en la que coincide el valor
		NO) Si no existe dicha posicion,
		seguido de las posiciones entre las que se deberia encontrar el valor comun
			=> Si el punto virtual en el que se cruzan es anterior al comienzo de las series -> pos: -1, 0
			=> Si es posterior al ultimo valor -> pos: n-1, n
	*/

    std::pair<int, int> corte;
    bool resultado = cruce(v1, v2, 0, numElem, corte);
    std::cout << (resultado ? "SI " : "NO ")
        << corte.first << " "
        << (!resultado ? std::to_string(corte.second) : "")
        << "\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}