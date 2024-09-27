#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& sec, int ini, int fin) {

    //Comprobamos el número de elementos del vector

    int resta = fin - ini;

    if (resta == 0) {   //Solo hay un elemento en el trozo

        //El elemento impar es ese elemento
        if (sec[ini] % 2 != 0) return sec[ini];
        else return 0;
    }

    if (resta == 1) {

        //Comprobamos si uno de los dos es el elemento que buscamos
        if (sec[ini] % 2 != 0) return sec[ini];
        else if (sec[fin] % 2 != 0) return sec[fin];
        else return 0;
    }

    //Si no es ninguno de los dos casos dividimos el vector

    int mid = (ini + fin) / 2;
    int izq = resolver(sec, ini, mid);

    if (izq == 0) { //Si no está en la izquierda, miramos en la derecha
        int der = resolver(sec, mid + 1, fin);
        return der;
    }
    else return izq;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0) return false;

    vector<int> sec(n);
    for (int& e : sec) cin >> e;

    cout << resolver(sec, 0, n - 1) << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}