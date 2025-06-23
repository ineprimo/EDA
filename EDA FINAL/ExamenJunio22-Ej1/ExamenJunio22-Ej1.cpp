#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto e : v) out << e;
    return out;
}

bool esSolucion(vector<int>& sol, int n, int k) {
    return k == n - 1;
}

bool esValido(vector<int>& sol, int n, int k, int t, int c, vector<int>& candidatosUsados) {
    if (candidatosUsados[c] > t) return false;
    
    if (k % 2 != 0 && sol[k] == sol[k-1]) return false;

    return true;
}

// función que resuelve el problema
//  n --> nº tareas  // k --> ind  // t --> tareasMaximas/Alumno
void resolver(vector<int>& sol, int n, int k, int t, int& comboActual,
    int& comboMejor, const vector<vector<int>> preferencias, const vector<int> candidatos, vector<int>& candidatosUsados) {

    for (int c : candidatos) {
        sol.push_back(c);
        comboActual += preferencias[c][k];
        candidatosUsados[c]++;

        if (esValido(sol, n, k, t, c, candidatosUsados)) {
            if (esSolucion(sol, n, k)) {
                comboMejor = max(comboActual, comboMejor);
            }
            else if (k < n - 1) {
                resolver(sol, n, k + 1, t, comboActual, comboMejor, preferencias, candidatos, candidatosUsados);
            }
        }

        comboActual -= preferencias[c][k];
        candidatosUsados[c]--;
        sol.pop_back();
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

    vector<int> sol;
    vector<int> candidatos(a);
    for (int i = 0; i < a; ++i) candidatos[i] = i;

    int comboActual = 0;
    int comboMejor = 0;
    vector<int> candidatosUsados(a, 0);

    resolver(sol, n, 0, t, comboActual, comboMejor, preferencias, candidatos, candidatosUsados);
    // Imprimir solucion
    cout << comboMejor << endl;
    return true;
}

//#define DOMJUDGE
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