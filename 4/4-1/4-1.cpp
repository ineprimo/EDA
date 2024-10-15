// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"

// función que resuelve el problema

// Decimos que un num entero es feliz si al aplicar repetidamente el proceso de
// sumar los cuadrados de sus digitos se termina llegando al 1
bool resolver(int i, Set<int>& sol)
{
    if(i == 1) return true; // si i es 1 el num es feliz

    int digi = 0; // digito a la der
    int cont = 0; // suma
    while(i > 0)  // vas digito a digito de un num, mientras siga habiendo digitos
    {
        digi = i % 10; // primer digito de la der
        cont += digi*digi;
        i /= 10; // actualizas i, te quedas con el siguiente digito
    }

    std::cout << cont << " "; // escribes la suma final

    if (sol.contains(cont)) return false; // si ya estaba no es feliz

    sol.add(cont); // si no estaba se mete
    return resolver(cont, sol); // se sigue buscando
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int i = 0; // dato
    Set<int> sol; // set de solucion

	std:cin >> i; 

    if (!std::cin)
        return false;

    // escribir sol
    std::cout << i << " "; // escribe el num inicial
    sol.add(i); // mete el numero inicial al set de sol

    bool feliz = resolver(i, sol);

    if(feliz) std::cout << "1" << std::endl;
    else std::cout << "0" << std::endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}