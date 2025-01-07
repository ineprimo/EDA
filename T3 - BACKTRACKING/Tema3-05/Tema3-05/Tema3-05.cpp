// paula sierra
// eda gdv 70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


bool esValida(vector<int>& sol, int n) {
    return sol.size() == n;
}

bool esSolucion() {
    return true;
}

void trataSolucion(vector<int>& sol) 
{
    for (int i = 0; i < sol.size(); ++i) {
        if (sol[i] == 0) cout << "azul";
        if (sol[i] == 1) cout << "rojo";
        if (sol[i] == 2) cout << "verde";

        cout << " ";
    }
    cout << endl;
}

// función que resuelve el problema
void resolver(vector<int>& sol, int n, int k, vector<int> candidatos)
{
    for (int i : candidatos) // n = 2; k = 1
    {
        sol.push_back(i); // { , }

        if (esValida(sol,n)) 
        {
            if (esSolucion()) {
                trataSolucion(sol);
            }
        }
        else if(k < n-1) // 1 < 1
        {
            resolver(sol, n, k + 1, candidatos);
            //
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

    vector<int> candidatos; // 0, 1, 2
    for (int i = 0; i < 3; ++i) {
        candidatos.push_back(i);
    }

    vector<int> sol;

    resolver(sol, n, 0, candidatos);

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
