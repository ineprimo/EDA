#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema
void simetrico(bintree<char> treeIzq, bintree<char> treeDcha, bool& sim)
{
    // Daremos por hecho que desde un inicio es simetrico hasta que se demuestre lo contrario
    
    // Si los dos estan vacios, es simetrico - no la contemplamos porque lo damos por hecho

    // Si uno está vacío y el otro no, no es simetrico
    if ((treeIzq.empty() && !treeDcha.empty()) ||
        (!treeIzq.empty() && treeDcha.empty()))
    {
        sim = false;
    }
    else if (!treeIzq.empty() && !treeDcha.empty())
    {
        // Miramos el siguiente nivel
        simetrico(treeIzq.left(), treeDcha.right(), sim);
        simetrico(treeIzq.right(), treeDcha.left(), sim);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.'); // . es vacío

    bool simetria = true;
    simetrico(tree.left(), tree.right(), simetria);

    // Si esta vacio es true
    if (tree.empty())
    {
        simetria = true;
    }

    // escribir sol
    if (simetria)  cout << "SI" << endl;  
    else  cout << "NO" << endl;

}

int main() {
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
    system("PAUSE");
#endif

    return 0;
}