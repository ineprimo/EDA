

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;



// función que resuelve el problema
void resolver(vector<int>& soluc, vector<vector<int>> precios, int k, int supers, int productos, int& gasto, int& productosComprados, 
    vector<bool>& productosAdquiridos, vector<int>& comprasPorSuper, vector<int>& mejorSoluc, int& mejorGasto) {

    for (int i = 0; i < supers; i++) {
        // suma a sol
        soluc[k] = i;

        // si es valida 
        if (comprasPorSuper[i]<2) {

            //
            comprasPorSuper[i]++;

            // aumenta el gasto
            gasto += precios[i][k];

            // si es solucion AKA si se han comprado todos los productos que necesita
            if (k == productos - 1) {

                // si la solucion actual es mejor
                if (gasto < mejorGasto) {
                    mejorGasto = gasto;
                    mejorSoluc = soluc;
                }
            }
            else {
                // poda

                // backtracking
                resolver(soluc, precios, k + 1, supers, productos, gasto, productosComprados, productosAdquiridos, comprasPorSuper, mejorSoluc, mejorGasto);
            }

            //
            comprasPorSuper[i]--;

            // aumenta el gasto
            gasto -= precios[i][k];

        }


    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int productos, supers, mejorGasto = INT_MAX;
    cin >> supers >> productos;
    int aux;

    vector<vector<int>> precios(supers, vector<int>(productos));
    // Lectura de datos

    for (int i = 0; i < supers; i++) {
        for (int j = 0; j < productos; j++) {
            cin >> aux;
            precios[i][j] = aux;


        }
    }

    vector<int> soluc(productos);
    vector<int> comprasPorSuper(supers);
    vector<int> mejorSoluc(productos);
    int productosComprados = 0;
    vector<bool> productosAdquiridos(productos);
    int gasto = 0;
    resolver(soluc, precios, 0, supers, productos, gasto, productosComprados, productosAdquiridos, comprasPorSuper, mejorSoluc, mejorGasto);


    cout << mejorGasto << endl;
}

//#define DOMJUDGE
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
