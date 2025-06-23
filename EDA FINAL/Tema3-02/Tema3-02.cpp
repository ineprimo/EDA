// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void tratarSolucion(vector<char>& sol) {
    for (int i = 0; i < sol.size(); ++i) cout << sol[i];
    cout << endl;
}

bool esSolucion(vector<char>& sol) {
    int i = 0;
    bool noHayRepeticion = true;
    while (i < sol.size() - 1 && noHayRepeticion) {  
        int j = i + 1;
        while (j < sol.size() && noHayRepeticion) {
            if (sol[i] == sol[j]) noHayRepeticion = false;
            ++j;
        }
        ++i;
    }
    return noHayRepeticion;
}

bool esValido(vector<char>& sol, int n) {
    return sol.size() == n;
}

// función que resuelve el problema
void resolver(vector<char>& sol, int ind, int n, vector<char> candidatos)
{
    for (char c : candidatos) {
        sol.push_back(c);

        if (esValido(sol, n)) {
            if (esSolucion(sol)) tratarSolucion(sol);
        }
        else if (ind < n - 1) resolver(sol, ind + 1, n, candidatos);

        sol.pop_back();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int m, n;   // M --> Elementos Totales (a,b,c) // N --> Tamaño Palabra  (c,b)
    cin >> m >> n;

    if (!std::cin)
        return false;

    vector<char> sol;
    vector<char> candidatos;

    for (int i = 0; i < m; ++i) {
        candidatos.push_back('a' + i);
    }

    resolver(sol, 0, n, candidatos);
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