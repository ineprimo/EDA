// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool isSolution(int indiceTareasCompletas, int t) {
    // es solucion cuando es un vector de size n de vectores de size t
    // aka cuando el indice de tareas completa sea igual a n
    if (indiceTareasCompletas == t) {
        return true;
    }
    return false;
}

// función que resuelve el problema
void resolver(vector<vector<int>>& sol, const vector<vector<int>>& datos, int k, int n, int t, int felicidad, vector<int>& tareasPorChaval, vector<int>& tareasComlpetas, 
    int indiceTareasCompletas, vector<vector<int>>& mejorSol, int& mejorFelicidad) {

    // n (i) -> tareas
    // k -> chavales, cada vez que baja de nivel en el arbol de opciones
    // t -> max por chaval

    for (int i = 0; i < n; i++) {
        // suma a sol
        sol[i][k] = datos[k][i];    // PLACEHOLDER

        // si es valida
        if (tareasPorChaval[k] < t) {

            // marca para probar la solucion


            // si es solucion
            if (isSolution(indiceTareasCompletas, t)) {
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

            // desmarca la solucion anterior


        }

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


    vector<vector<int>> datos;
    vector<int> tareasPorChaval(n);     // vector auxiliar para contar el numero de tareas de cada chaval
    vector<int> tareasComlpetas(n);     // tareas completadas


    int felicidad = 0;
    vector<vector<int>> soluc(a);
    vector<vector<int>> mejorSoluc(a);
    // tupla solucion: vector<vector<int>>
    // para guardar que tareas tiene cada estudiante

    resolver(soluc, datos, 0, n, t, 0, tareasPorChaval, tareasComlpetas, 0, mejorSoluc, felicidad);

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
