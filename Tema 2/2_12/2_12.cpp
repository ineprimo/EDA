#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) {

    //Caso base. 
    // El vector tiene un unico elemento
    if (fin == ini) {
        return ini;
    }

    // En el vector quedan 2 elementos
    if (fin - ini == 1) {

        if (v1[ini] == v2[ini]) return fin;
        else return ini;
    }

    int mid = 0;

    mid = (ini + fin) / 2;

    if (v1[mid] == v2[mid]) {   //El número faltante está a la derecha del vector
        return resolver(v1, v2, mid, fin);
    }
    else {  //El número faltante está a la izquierda del vector
        return resolver(v1, v2, ini, mid);
    }
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