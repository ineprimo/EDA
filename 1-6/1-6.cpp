// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// complejidad asintotica: O(n), no hay bucles anidados

// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {
    unsigned int i = 0, j = 0;

    while (i < eda.size() && j < tpv.size())
    {
        if (eda[i] < tpv[j]) // operadores lexicograficos (importante pq los arrays estan ordenados)
        {
            soloEda.push_back(eda[i]); // inserción final, se supone ordenada
            i++;
        }
        else if (eda[i] > tpv[j])
        {
            soloTpv.push_back(tpv[j]);
        	j++;
        }
        else
        {
            comunes.push_back(eda[i]);
            i++;
            j++;
        }
    }

    while (i < eda.size()) // el restos
    {
        soloEda.push_back(eda[i]);
    	i++;
    }
    while (j < tpv.size())
    {
        soloTpv.push_back(tpv[j]);
        j++;
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
