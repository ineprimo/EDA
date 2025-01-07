
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esSolucion(vector<int>& sol, int n, int k, int& beneficioActual) {
    if (k != n - 1) return false;
    
    for (int i = 0; i < n; i++)
    {
        beneficioActual += sol[i];
    }
    return true;
}

bool esValido(vector<int>& sol, int n, int k, const vector<vector<bool>> consentimientos) {
    bool quieroTocar = true;

    int i = 0;
    while (quieroTocar && i < sol.size()) {
        if (consentimientos[i][k]) quieroTocar = false;        
        ++i;
    }

    return quieroTocar;
}

// función que resuelve el problema
void resolver(vector<int>& sol, int n, int k, int& maxBeneficio, int& beneficioActual, const vector<vector<bool>> consentimientos) {
    for (int i = 0; i < n; i++)
    {
        sol[k] = i;
        if (esValido(sol, n, k, consentimientos)) {
            if (esSolucion(sol, n, k, beneficioActual)) {
                if (beneficioActual > maxBeneficio) maxBeneficio = beneficioActual;
            }
            else if (k < n - 1) resolver(sol, n, k + 1, maxBeneficio, beneficioActual, consentimientos);
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
    vector<vector<int>> beneficios(n, vector<int>(n));
    vector<vector<bool>> consentimientos(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> beneficios[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }
    vector<int> sol;
    int maxBeneficio = -1;
    int beneficioActual = 0;

    resolver(sol, n, 0, maxBeneficio, beneficioActual, consentimientos);

    if (maxBeneficio != -1) cout << maxBeneficio << endl;
    else cout << "NEGOCIA CON LOS ARTISTAS";
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
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
