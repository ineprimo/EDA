//Daniel Zhu
//EDA-GDV79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//Al no haber bucles anidados podriamos decir que la complejidad de nuestro metodo es lineal
//En cuanto a la cuestion, como para ordenar un vector se necesita una complejidad de O(n ∗ log(n)) y nuestro metodo para
// comparar listas ordenadas es lineal, la complejidad resultante seria O(n * log(n)) + O(m * log(m)) + O(n+m)


// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {

    int i = 0; 
    int j = 0;


    while (i < eda.size() && j < tpv.size())
    {
        if (eda[i] == tpv[j])
        {
            comunes.push_back(eda[i]);
            i++; 
            j++;
        }
        else if (eda[i] < tpv[j]) //Como estan ordenadas si eda[i] < tpv[j] significa que solo esta en el vector eda
        {
            soloEda.push_back(eda[i]);
            i++;
        }
        else
        {
            soloTpv.push_back(tpv[j]);
            j++;
        }
    }


    for (int k = i; k < eda.size(); k++) {
        soloEda.push_back(eda[k]);
    }
    for (int l = j; l < tpv.size(); l++) {
        soloTpv.push_back(tpv[l]);
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
