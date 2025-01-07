// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void tratarSolucion(int& soluciones) {
    ++soluciones;
}

bool esSolucion(vector<int>& sol, int k, int n) {
    return k == n - 1;
}

bool esValido(vector<int>& sol, int k, int n) {
    bool valida = true;

    int i = 0;
    while (valida && i < k) {
        if (sol[k] == sol[i] || (k - i == abs(sol[k] - sol[i]))) valida = false;
        else ++i;
    }

    return valida;
}

// función que resuelve el problema
void resolver(vector<int>& sol, int n, int k, vector<int> candidatos, int& soluciones) {
    
    for (int c : candidatos) {
        sol.push_back(c);
        if (esValido(sol, k, n)) {
            if (esSolucion(sol, k, n)) tratarSolucion(soluciones);
            else if (k < n - 1) resolver(sol, n, k + 1, candidatos, soluciones);
        }
        sol.pop_back();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    int solucionesDiferentes = 0;
    vector<int> sol;
    vector<int> candidatos;
    for (int i = 0; i < n; ++i) candidatos.push_back(i);

    resolver(sol, n, 0, candidatos, solucionesDiferentes);

    cout << solucionesDiferentes << endl;
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