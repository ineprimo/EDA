
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



void resolver(vector<int>& sol, const int n, const int k, vector<int>&regalosDados, const vector<vector<int>>& regalos,
    int valor, int& mejorValor, vector<int>& mejorSol) {

    // k son los chavales

    for (int i = 0; i < n; i++) {
        // se añade un regalo a la solucion
        sol[k] = regalos[k][i];

        if (regalosDados[i] == -1) {     // valida si ese chaval tiene regalo o no
            // marca
            valor += sol[k];
            regalosDados[i] = k;

            if (k == sol.size() - 1) {       // si se ha completado sol
                // mira si es mejor solucion que la que ya hay
                if (valor > mejorValor) {
                    mejorValor = valor;
                    mejorSol = sol;
                }
            }
            else if (k < n - 1) {
                // poda 

                // mira el siguiente juguete
                resolver(sol, n, k + 1, regalosDados, regalos, valor, mejorValor, mejorSol);
            }
            // desmarca
            regalosDados[i] = -1;
            valor -= sol[k];

        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a;   // num juguetes
    cin >> b;   // num chavales
    int num;

    if (!cin) return false;

    vector<vector<int>> regalos;

    for (int i = 0; i < b; i++) {
        vector<int> aux;
        for (int j = 0; j < a; j++) {
            cin >> num;
            aux.push_back(num);
        }
        regalos.push_back(aux);
    }

    vector<int> regalosDados(a, -1);     // guarda la posicion (k) del regalo a ese chaval
    vector<int> mejorSol(b);
    vector<int> soluc(b);
    int mejorValor = 0;

    resolver(soluc, a, 0, regalosDados, regalos, 0, mejorValor, mejorSol);

    cout << mejorValor << endl;
    // Salida
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
    //system("PAUSE");
#endif

    return 0;
}