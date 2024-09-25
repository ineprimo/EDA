
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// La funcion tiene complejidad logaritmica O(n*log(n)), esta es la complejidad del metodo sort.
// El metodo tiene complejidad lineal igual que en el ejercicio 1-6 sin embargo uso el metodo sort 
// para ordenar los vectores que tiene coste logaritmico, por lo tanto, la funcion tiene coste logaritmico
void comparaListados(vector<string>& eda, vector<string>& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {

    std::sort(eda.begin(), eda.end());
    std::sort(tpv.begin(), tpv.end());

    int contEda = 0, contTpv = 0;
    while (contEda < eda.size() && contTpv < tpv.size())
    {
        if (eda[contEda] == tpv[contTpv]) {
            comunes.push_back(eda[contEda]);
            contEda++;
            contTpv++;
        }
        else if (eda[contEda] > tpv[contTpv]) {
            soloTpv.push_back(tpv[contTpv]);
            contTpv++;
        }
        else if (eda[contEda] < tpv[contTpv])
        {
            soloEda.push_back(eda[contEda]);
            contEda++;
        }
    }


    for (size_t i = contTpv; i < tpv.size(); i++)
    {
        soloTpv.push_back(tpv[i]);
    }

    for (size_t i = contEda; i < eda.size(); i++)
    {
        soloEda.push_back(eda[i]);
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
