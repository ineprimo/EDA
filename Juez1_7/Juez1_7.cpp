#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void ordenar(vector<string>& v) {
    if (v.size() > 0) {
        for (int i = 0; i < v.size() - 1; ++i) {
            for (int j = 0; j < v.size() - i - 1; ++j) {
                if (v[j] > v[j + 1]) {
                    string temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }
}
// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {
    
    soloEda = eda;
    soloTpv = tpv;

    //Primero, decidimos cuál es el de menor tamaño
    if (eda.size() <= tpv.size()) {

        for (int i = eda.size() - 1; i >= 0; i--) {

            int j = tpv.size() - 1;
            while (j >= 0) {
                if (eda[i] == tpv[j]) {
                    comunes.insert(comunes.end(), eda[i]);
                    soloEda.erase(soloEda.begin() + i);
                    soloTpv.erase(soloTpv.begin() + j);
                    j = 0;
                }

                j--;
            }
        }
    }
    else {
        for (int i = tpv.size() - 1; i >= 0; i--) {

            int j = eda.size() - 1;
            while (j >= 0) {
                if (eda[j] == tpv[i]) {
                    comunes.insert(comunes.end(), eda[j]);
                    soloEda.erase(soloEda.begin() + j);
                    soloTpv.erase(soloTpv.begin() + i);
                    j = 0;
                }

                j--;
            }
        }

    }

    //Ordenamos
    ordenar(comunes);
    ordenar(soloEda);
    ordenar(soloTpv);

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