// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v1, vector<int> const& v2, int iniV1, int finV1, int iniV2, int finV2)
{
    int elemsV1 = finV1 - iniV1;
    int elemsV2 = finV2 - iniV2;

    if(elemsV2 == 0) return v1[iniV1];
    if(elemsV1 == 1)
    {
        //if (v1[iniV1] != v2[iniV2]) return v1[iniV1] - 1;
        //return v1[iniV1] + 1;
    }
    if (v1[finV1-1] != v2[finV2-1]) return v1[finV1-1];
    if (v1[iniV1] != v2[iniV2]) return v1[iniV1];

    int mitV1 = (finV1 + iniV1) / 2;
    int mitV2 = (finV2 + iniV2) / 2;

    // si el que está a la mitad es igual que el que debería estar -> buscar derecha
    if (v2[mitV2] == v1[mitV1])
    {
        return resolver(v1, v2, mitV1, finV1, mitV2, finV2);
    }
    else  // la mitad der está ordenada -> busca izq
    {
        return resolver(v1, v2, iniV1, mitV1, iniV2, mitV2);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    long long int numElementos;
    cin >> numElementos;
    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);
    for (int& e : v1) cin >> e;
    for (int& e : v2) cin >> e;
    int sol = resolver(v1, v2, 0, v1.size(), 0, v2.size());
    cout << sol << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}