

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1,2,5,10,20,50,100,200 };

bool isValid(vector<int>& soluc, int precio) {
    int sum = 0;

    return sum == precio;
}

bool isSolution(vector<int>& soluc, int precio) {
    int sum = 0;
    for (int n = 0; n < NUM_MONEDAS; n++) {
        sum += soluc[n] * valores[n];
    }
    return sum == precio;
}

bool isBetter() {
    return true;
}

void treatSol() {

}

// función que resuelve el problema
void resolver(vector<int>& soluc, int k, int n, int* monedas, int precio, int valor, int mayorCant) {
    for (int i = n; i >= 0; i--) {
        soluc.push_back(monedas[i]);
        if (isValid(soluc, precio)) {
            if (isSolution(soluc, precio)) {
                if (isBetter()) {
                    mayorCant = soluc.size();
                }
            }
        }
        else if (k < n - 1) {
            resolver(soluc, k + 1, NUM_MONEDAS, monedas, precio, valor, 0);
        }
    }


}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int precio;
    int monedas[NUM_MONEDAS];
    cin >> precio;
    for (int i = 0; i < NUM_MONEDAS; ++i)
        cin >> monedas[i];
    vector<int> soluc(NUM_MONEDAS);
    resolver(soluc, 0, NUM_MONEDAS, monedas, precio, 0, 0);
    
    // Mostrar salida

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
