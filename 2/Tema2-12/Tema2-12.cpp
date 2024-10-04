#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int resolver2(int v1, vector<int> const& v2, int ini, int fin) {

    // base
    if (fin - ini == 1) {
        if (v2[ini] == v1) return -1;
        return ini;
    }

    // 
    int mid = (ini + fin) / 2;
    int izq = resolver2(v1, v2, ini, mid);
    int der = resolver2(v1, v2, mid, fin);

    // return

    if (izq == -1 || der == -1)
        return -1;
    else if (izq != -1)
        return izq;
    else if (der != -1)
        return der;

}

// función que resuelve el problema
int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) {

    // base
    if (fin - ini == 1) {
        int a = resolver2(v1[ini], v2, 0, v2.size());
        if (a != -1)
            return ini;
        return -1;
    }

    // 
    int mid = (ini + fin) / 2;
    int izq = resolver(v1, v2, ini, mid);
    int der = resolver(v1, v2, mid, fin);


    // return
    if (izq == 0 && der == 0)
        return der;
    else if (izq != 0)
        return izq;
    else
        return der;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos;
    cin >> numElementos;
    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);
    for (int& e : v1) cin >> e;
    for (int& e : v2) cin >> e;
    int sol = resolver(v1, v2, 0, v1.size() - 1);
    cout << v1[sol] << endl;
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
