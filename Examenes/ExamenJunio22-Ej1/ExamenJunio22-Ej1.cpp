// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool isSolution(int indiceTareasCompletas, int t, int n) {
    // es solucion cuando es un vector de size n de vectores de size t
    // aka cuando el indice de tareas completa sea igual a n
    if (indiceTareasCompletas == t*n) {
        return true;
    }
    return false;
}

// función que resuelve el problema
void resolver(vector<pair<int, int>>& sol, const vector<vector<int>>& datos, int k, int n, int t, int felicidad, vector<int>& tareasPorChaval, vector<int>& tareasComlpetas,
    int indiceTareasCompletas, vector<pair<int, int>>& mejorSol, int& mejorFelicidad) {

    // vector<(chavales)vector<tareas>>
    // n -> chavales
    // k -> tareas
    // tupla solucion: vector<(tareas)<pair<chaval, chaval>>>

    for (int i = 0; i < 2; i++) {   // bucle de dos porque cada tarea tiene que tener dos chavales

        // suma a sol
        if (i == 0)
            sol[k].first = i + 1;
        else
            sol[k].second = i + 1;

        tareasPorChaval[i]++;

        // si es valida
        if (tareasPorChaval[i] <= t) {

            indiceTareasCompletas++;

            // si es solucion
            if (isSolution(indiceTareasCompletas, t, n)) {
                // si mejora solucion
                if (felicidad > mejorFelicidad) {
                    mejorFelicidad = felicidad;
                    mejorSol = sol;
                }
            }
            else {
                // poda
                    
                // backtracking
                resolver(sol, datos, k + 1, n, t, felicidad, tareasPorChaval, tareasComlpetas, indiceTareasCompletas, mejorSol, mejorFelicidad);
            }

            indiceTareasCompletas--;
        }

        // desmarca la solucion anterior
            // suma
        if (i == 0)
            sol[k].first = 0;
        else
            sol[k].second = 0;

        tareasPorChaval[i]--;
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, t;
    cin >> n >> a >> t;
    if (n == 0 && a == 0 && t == 0) return false;
    vector<vector<int>> preferencias(a, vector<int>(n));
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> preferencias[i][j];
        }

    vector<int> tareasPorChaval(a);     // vector auxiliar para contar el numero de tareas de cada chaval
    vector<int> tareasComlpetas(n);     // tareas completadas


    int felicidad = 0;
    vector<pair<int, int>> soluc(a);
    vector<pair<int, int>> mejorSoluc(a);
    // tupla solucion: vector<vector<int>>
    // para guardar que tareas tiene cada estudiante

    resolver(soluc, preferencias, 0, n, t, 0, tareasPorChaval, tareasComlpetas, 0, mejorSoluc, felicidad);

    // escribir sol

    cout << felicidad << endl;

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
