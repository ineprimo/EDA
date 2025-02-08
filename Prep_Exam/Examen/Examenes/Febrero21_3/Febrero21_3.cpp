#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esSolucion(vector<int>& solucion, int n, int k, int& beneficioActual) {
    if (k != n - 1) return false;

    for (int i = 0; i < n; i++)
    {
        beneficioActual += solucion[i];
    }
    return true;
}

bool esValida(vector<int>& solucion, int n, int k, const vector<vector<bool>>& consentimientos) {
    bool quieroTocar = true;

    int i = 0;
    while (quieroTocar && i < solucion.size()) {
        if (consentimientos[i][k]) quieroTocar = false;
        ++i;
    }
    return quieroTocar;
}

// función que resuelve el problema
void resolver(vector<int>& solucion, int k, int n, int ingresos, int& mejoresIngresos, 
    const vector<vector<int>>& beneficios, const vector<vector <bool>>& consentimiento) {
    for (int i = 0; i < n; i++) {
        solucion[k] = i;
        if (esValida(solucion, n, k, consentimiento)) {
            if (esSolucion(solucion, n, k, ingresos)) {
                if (ingresos > mejoresIngresos) mejoresIngresos = ingresos;
            }
            else if (k < n - 1) resolver(solucion, k + 1, n, ingresos, mejoresIngresos, beneficios, consentimiento);
        }
        solucion.pop_back();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nGrupos = 0;
    cin >> nGrupos;
    vector<vector<int>> beneficios(nGrupos, vector<int>(nGrupos));
    vector<vector<bool>> consentimientos(nGrupos, vector<bool>(nGrupos));
   
    for (int i = 0; i < nGrupos; i++)
    {
        for (int j = 0; j < nGrupos; j++)
        {
            cin >> beneficios[i][j];
        }
    }

    for (int i = 0; i < nGrupos; i++)
    {
        for (int j = 0; j < nGrupos; j++)
        {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }
    }

    vector<int> solucion(nGrupos);
    int k = 0;
    int ingresos = 0;
    int mejoresIngresos = -1;
    vector<bool> elegidos(nGrupos);

    resolver(solucion, k, nGrupos, ingresos, mejoresIngresos, beneficios, consentimientos);
    // escribir sol
    if (mejoresIngresos == -1) cout << "NEGOCIA CON LOS ARTISTAS" << endl;
    else cout << mejoresIngresos << endl;


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