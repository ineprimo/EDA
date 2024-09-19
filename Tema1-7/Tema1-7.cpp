//Daniel Zhu
//EDA-GDV79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//En cuanto a la complejidad sera la complejidad lineal de ordenar los vectores ya ordenados (complejidad lineal) 
// mas la complejidad que tenga el sort a la hora de ordenar los vectores



// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {
   

    vector<string> aux1 = eda;
    vector<string> aux2 = tpv;

    //Usamos sort como en el apartado 1-5
    sort(aux1.begin(), aux1.end());
    sort(aux2.begin(), aux2.end());

    //Al tener ordenados los vectores usamos el mismo metodo que en el apartado anterior
    int i = 0;
    int j = 0;


    while (i < aux1.size() && j < aux2.size())
    {
        if (aux1[i] == aux2[j])
        {
            comunes.push_back(eda[i]);
            i++;
            j++;
        }
        else if (aux1[i] < aux2[j]) //Como estan ordenadas si eda[i] < tpv[j] significa que solo esta en el vector eda
        {
            soloEda.push_back(eda[i]);
            i++;
        }
        else
        {
            soloTpv.push_back(aux2[j]);
            j++;
        }
    }


    for (int k = i; k < aux1.size(); k++) {
        soloEda.push_back(aux1[k]);
    }
    for (int l = j; l < aux2.size(); l++) {
        soloTpv.push_back(aux2[l]);
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
