// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

// función que resuelve el problema
std::pair<int, int> resolver(bintree<int> const& tree, int antepasados) 
{
    if (tree.empty()) return {0, 0};
    
    // Si estoy en las hojas
    if (tree.left().empty() && tree.right().empty()) {

        // Y arriba y abajo tengo 0, primer singular
        if (antepasados == 0) {
            return { 1, tree.root() };
        }
        // Hoja no singular
        else {
            return { 0, tree.root() };
        }        
    }

    std::pair<int, int> hijoIzq = resolver(tree.left(), antepasados + tree.root());
    std::pair<int, int> hijoDer = resolver(tree.right(), antepasados + tree.root());

    int acumuladoHijos = hijoIzq.second + hijoDer.second;
    int singularesHijos = hijoIzq.first + hijoDer.first;

    if (acumuladoHijos == antepasados) singularesHijos++;

    return { singularesHijos, acumuladoHijos + tree.root()};

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> datos;
    int valorAntepasados = 0;
    int valorHijos;
    std::pair<int, int> auxSol;
    datos = leerArbol(-1);

    auxSol = resolver(datos, 0);

    cout << auxSol.first << endl;
    // escribir sol


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