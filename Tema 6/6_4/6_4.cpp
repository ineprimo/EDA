
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <utility> 
#include "bintree_eda.h"
using namespace std;



//Probablemente haya que hacerlo más general
bool esPrimo(int num) {

    if (num <= 1) return false;
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}


pair <int,int> accesible(bintree<int> const& tree, int& nivel) {

    
    int num = tree.root();    //De primeras el primer numero es el menor

    pair<int, int> _left (-1, -1);
    pair<int, int> _right (-1, -1);
    pair<int, int> result (-1, -1);
    
    //Vamos comprobando que la raiz tenga las propiedades necesarias
    //Si es primo el camino deja de ser accesible
    nivel++;
    if (!esPrimo(num)) {
        
        //Miramos si el numero actual es multiplo de 7
        if (num % 7 == 0) {
            result.first = num;
            result.second = nivel;
            return result;
        }

        if (!tree.left().empty())
        {
            _left = accesible(tree.left(), nivel);
            nivel--;

        }

        if (!tree.right().empty()) {

            _right = accesible(tree.right(), nivel);
            nivel--;
        }
        

        //vemos con que resultado nos quedamos
        if (_left.first != -1 || _right.first != -1) {

            if (_left.first == -1) {
                
                result = _right;
            }
            else if (_right.first == -1) {
                result = _left;
            }
            else {

                //Nos quedamos con el que esté más cerca de la raiz
                if (_left.second <= _right.second) {   //El de la izquierda esta mas cerca
                    result = _left;
                }
                else {
                    result = _right;
                }
            }

        }
        
    }

    return result;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    pair<int, int> Resultado (-1, -1);
    int nivel = 0;
    bintree<int> tree;

    tree = leerArbol(-1);

    if (!tree.empty()) {
        Resultado = accesible(tree, nivel);
    }

    if (Resultado.first == -1) {
        cout << "NO HAY" << endl;
    }
    else {
        cout << Resultado.first << " " << Resultado.second << endl;
    }
    
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
    //system("PAUSE");
#endif

    return 0;
}


