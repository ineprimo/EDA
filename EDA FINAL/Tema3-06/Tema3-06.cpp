// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void tratarSolucion(vector<int>& sol) {
    for (int i = 0; i < sol.size(); ++i) {
        if (sol[i] == 0) cout << "azul ";
        else if (sol[i] == 1) cout << "rojo ";
        else cout << "verde ";
    }
    cout << endl;
}

bool esSolucion(vector<int>& sol, int n, int k) { return k == n - 1; }

bool esValido(vector<int>& sol) {

    bool verdeRepe = false;

    int i = 0;

    while (!verdeRepe && i < sol.size() - 1) {
        if (sol[i] == 2 && sol[i + 1] == 2) verdeRepe = true;
        ++i;
    }
    return !verdeRepe && sol[0] == 1;   // Comprobacion Repeticion de Verde Antes y Rojo al Principio
}

// función que resuelve el problema
void resolver(vector<int>& sol, int n, int k, vector<int>& candidatos) {

    for (int c : candidatos) {
        sol.push_back(c);
        if (esValido(sol)) {
            if (esSolucion(sol, n, k)) tratarSolucion(sol);
            else if (k < n - 1) resolver(sol, n, k + 1, candidatos);
        }
        sol.pop_back();
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;    

    // {0 --> AZUL // 1 --> ROJO // 2 --> VERDE}

    vector<int> candidatos{ 0,1,2 };
    vector<int> sol;

    resolver(sol, n, 0, candidatos);

    cout << endl;

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