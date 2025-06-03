// Ejercicio 1: Orcos (3 puntos)
// Tipo: ARBOLES

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// devuelve nombre de jefe, numero de enanos en el grupo
std::pair<std::string, int> enanos(const bintree<std::string>& tree)
{
    // arbol vacio
    if (tree.empty()) return { "ninguno", 0 };

    // caso hoja
    if (tree.left().empty() && tree.right().empty()) return {tree.root(), 1};

    // guardarte hojas
    std::pair<std::string, int> left = enanos(tree.left());
    std::pair<std::string, int> right = enanos(tree.right());

    std::string lider = "";
    int amigos = 0;

    // --- dos grupos se encuentran
    // recuento de amigos
    amigos = left.second + right.second;
    // nuevo lider -> grupo mas numeroso
    if (left.second > right.second) lider = left.first;
    else if (left.second < right.second) lider = right.first;
    // si son iguales -> jefe alfabeticamente menor
    else
    {
        if (left.first > right.first) lider = right.first;
        else lider = left.first;
    }

    // --- ataque de orcos
    if (tree.root() == "Orcos") amigos = amigos / 2;
    // resetea jefe si se han muerto todos
    if (amigos <= 0) lider = " ";

    return { lider, amigos };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<std::string> tree;

    tree = leerArbol((std::string)"."); // . es arbol vacio

    std::pair<std::string, int> sol = enanos(tree);

    /*
    Para cada caso de prueba se escribira en una linea el nombre del lider del grupo que llega,
    seguido de un espacio y del numero de enanos del grupo.
    Si no consigue llegar ningun grupo, se escribira la cadena Ninguno
    */

    if (sol.second > 0) std::cout << sol.first << " " << sol.second << std::endl;
    else std::cout << "Ninguno" << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}