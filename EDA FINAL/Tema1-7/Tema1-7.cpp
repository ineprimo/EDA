
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {
    // Ordenar Vectores
    vector<string> auxEDA = eda;
    vector<string> auxTPV = tpv;

    sort(auxEDA.begin(), auxEDA.end());
    sort(auxTPV.begin(), auxTPV.end());

    // Tema 1-6
    int i = 0;
    int j = 0;

    while (i < auxEDA.size() && j < auxTPV.size()) {
        // Solo en EDA
        if (auxEDA[i] < auxTPV[j]) {
            soloEda.push_back(auxEDA[i]);
            ++i;
        }
        // Solo en TPV
        else if (auxEDA[i] > auxTPV[j]) {
            soloTpv.push_back(auxTPV[j]);
            ++j;
        }
        // Comunes
        else {
            comunes.push_back(auxEDA[i]);
            ++i;
            ++j;
        }
    }
    // Sobrantes de EDA
    while (i < auxEDA.size()) {
        soloEda.push_back(auxEDA[i]);
        ++i;
    }
    // Sobrantes de TPV
    while (j < auxTPV.size()) {
        soloTpv.push_back(auxTPV[j]);
        ++j;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<string> eda(n);
    vector<string> comunes;
    vector<string> soloEda;
    vector<string> soloTpv;
    for (string& e : eda) cin >> e;
    cin >> n;
    vector<string> tpv(n);
    for (string& e : tpv) cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (string& e : comunes) cout << e << " ";
    cout << endl;
    for (string& e : soloEda) cout << e << " ";
    cout << endl;
    for (string& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}
