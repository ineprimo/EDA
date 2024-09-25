
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
/*
// La funcion tiene complejidad lineal O(n) ya que depende del numero de elementos (n) las iteraciones que realiza en los bucles
// recorriendose una unica vez ambos.
// CUESTION: el coste de la funcion para cadenas desordenadas deberá ser logaritmico O(n*log(n)) ya que primero habria que ordenar los vectores 
// y luego realizar el codigo propuesto en este ejercicio
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {

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
*/