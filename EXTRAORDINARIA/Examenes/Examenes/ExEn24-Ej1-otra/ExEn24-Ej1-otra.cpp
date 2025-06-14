// Ejercicio 1: Dragones (3 puntos)
// Tipo: ARBOLES

// Nieves Alonso Gilsanz
// EDA-GDV03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "bintree_eda.h"

// grupo<jefe,numero enanos>
using grupo = std::pair<std::string, int>;

// Por el camino se encuentran y van formando grupos, cada uno liderado por uno de los enanos.
// Cuando dos grupos se encuentran, el nuevo lider es el del grupo mas numeroso.
// Si los dos grupos tienen el mismo numero de enanos, eligen al que tiene nombre menor en orden alfabetico
// Durante su marcha pueden sufrir ataques de los orcos que invariablemente reducen a la mitad el grupo (en los grupos de tamaño impar se redondeará por abajo).
// Todos los enanos están dispuestos a morir antes que su líder. Éste solo muere si el grupo desaparece completamente.

// => determine cuantos enanos consiguen llegar a La Comarca y quien llega liderando el grupo

grupo resolver(const bintree<std::string>& tree)
{
    // caso arbol vacio
    if (tree.empty())
    {
        return {"Ninguno", 0};
    }

    // caso hoja
    if (tree.left().empty() && tree.right().empty())
    {
        return { tree.root(), 1 };
    }

    grupo izq = resolver(tree.left());
    grupo der = resolver(tree.right());

    // jefes
    std::string jefeIzq = izq.first;
    std::string jefeDer = der.first;
    std::string jefe = "";

    // enanos
    int enanosIzq = izq.second;
    int enanosDer = der.second;
    int enanos = 0;

    // ----- se forma un grupo
    // -- nueva suma de enanos
    enanos = enanosDer + enanosIzq; 
    // -- nuevo jefe
    if (enanosDer == enanosIzq)
    {
	    if (jefeIzq < jefeDer) jefe = jefeIzq;
	    else jefe = jefeDer;
    }
    else
    {
        if (enanosIzq > enanosDer) jefe = jefeIzq;
        else jefe = jefeDer;
    }

    // ----- se encuentran con un orco
    if (tree.root() == "Orcos")
    {
        enanos = enanos / 2;
    }
    // si mueren todos
    if (enanos <= 0)
    {
        jefe = "Ninguno";
    }

    return {jefe, enanos};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada

    bintree<std::string> tree;

    tree = leerArbol((std::string)".");
    grupo sol = resolver(tree);

    // escribir sol
    std::cout << sol.first << " ";
    if (sol.second > 0) std::cout << sol.second;
    std::cout << "\n";
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