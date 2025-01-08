// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void tratarSolucion(vector<int>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

bool esSolucion(int n, int k) {
    return k == n - 1;
}

bool esValido(vector<int>& sol, int n, int k, vector<int>& bombillasActuales, int& bombillasColocadas,
    int& consumoActual, const int maxConsumo) {
    
    if (k >= 2) {
        for (int i = 0; i < sol.size() - 2; ++i) {
            if (sol[i] == sol[i + 1] && sol[i] == sol[i + 2]) return false;
        }
    }   

    int i = 0;
    while (i < bombillasActuales.size()) {
        if (bombillasColocadas - bombillasActuales[i] < bombillasColocadas / 2) return false;

        ++i;
    }

    if (consumoActual > maxConsumo) return false;

    return true;
}

// función que resuelve el problema
void resolver(vector<int>& sol, int n, int k, vector<int>& candidatos, int& consumoActual,
    const int maxConsumo, vector<int>& bombillasActuales, const vector<int> consumos, int& soluciones, int& bombillasColocadas) {

    for (int c : candidatos) {
        sol.push_back(c);
        bombillasActuales[c]++;
        bombillasColocadas++;
        consumoActual += consumos[c]; // 2

        if (esValido(sol, n, k, bombillasActuales, bombillasColocadas, consumoActual, maxConsumo)) {
            if (esSolucion(n, k)) {
                //tratarSolucion(sol);
                soluciones++;
            }
            else if (k < n - 1) {
                resolver(sol, n, k + 1, candidatos, consumoActual, maxConsumo, bombillasActuales, consumos, soluciones, bombillasColocadas);
            }
        }

        sol.pop_back();
        bombillasActuales[c]--;
        bombillasColocadas--;
        consumoActual -= consumos[c];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int longitud, numColores, maxConsumo;
    cin >> longitud;
    if (longitud == 0)
        return false;
   
    cin >> numColores >> maxConsumo;

    vector<int> consumos;

    vector<int> sol;
    vector<int> candidatos(numColores);

    int cons;
    for (int i = 0; i < numColores; ++i) {
        cin >> cons;
        consumos.push_back(cons); //{2,1}

        candidatos[i] = i; //{0,1}
    }
    
    int consumoActual = 0;
    int soluciones = 0;
    int bombillasColocadas = 0;
    vector<int> bombillasActuales(numColores);
    
    resolver(sol, longitud, 0, candidatos, consumoActual, maxConsumo, bombillasActuales, consumos, soluciones, bombillasColocadas);
    cout << soluciones << endl;
    // escribir sol

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
    system("PAUSE");
#endif

    return 0;
}
