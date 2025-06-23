// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector<char> sol, int n) {
    return sol.size() == n;
}

bool esSolucion(vector<char> sol) {
    return true;
}

void trataSolucion(vector<char> sol) {
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i];
    }
    cout << endl;
}
// función que resuelve el problema
void resolver(vector<char>& sol, int k, int n, vector<char> candidatos) 
{
    for (char candidato : candidatos) {
        sol.push_back(candidato);

        if (esValida(sol, n)) {
            if (esSolucion(sol)) {
                trataSolucion(sol);
            }
        }
        else if (k < n - 1) {
            resolver(sol, k + 1, n, candidatos);
        }

        sol.pop_back();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m; // num letras
    int n; // tam 
    cin >> m;
    cin >> n;
    if (!std::cin)
        return false;

    // crea candidatos (a,b,c)
    vector<char> candidatos;
    for (int i = 0; i < m; ++i) {
        candidatos.push_back('a' + i);
    }

    vector<char> sol;
    resolver(sol, 0, n, candidatos);

    // escribir sol
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