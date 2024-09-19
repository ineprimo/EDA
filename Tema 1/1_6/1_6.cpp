
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

#pragma region Complejidad del algoritmo

///
///
/// El algoritmo recorre ambas listas a la vez una unica vez
/// por lo tanto es lineal para ambas listas
/// Esto quiere decir que la complejidad sería
/// O(n + m) siendo n el tamaño de la primera lista y m el tamaño de la segunda
/// 
/// 

#pragma endregion


// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {

    int i = 0;
    int j = 0;

    while (i < eda.size() && j < tpv.size()) {

        if (eda[i] == tpv[j]) {

            comunes.push_back(eda[i]);
            i++;
            j++;
        }
        else if (eda[i] < tpv[j]) {
            soloEda.push_back(eda[i]);
            i++;
        }
        else if (tpv[j] < eda[i]) {
            soloTpv.push_back(tpv[j]);
            j++;
        }
    }

    //Solo una de las listas llega al final, 
    //lo que sobra de la otra se añade en la suya personal

    while (i < eda.size()) {
        soloEda.push_back(eda[i]);
        i++;
    }

    while (j < tpv.size()) {
        soloTpv.push_back(tpv[j]);
        j++;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada

    //Lee el tamaño de la primera lista y la crea
    int n;
    cin >> n;

    vector<string> eda(n);

    //crea las listas de la solucion
    vector<string> comunes;
    vector<string> soloEda;
    vector<string> soloTpv;

    //Rellena la lista 1
    for (string& e : eda) cin >> e;

    //repite el procedimiento con la lista 2
    cin >> n;

    vector<string> tpv(n);

    for (string& e : tpv) cin >> e;

    //Metodo que resuelve el ejercicio
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);


    //Escritura de la solucion
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
