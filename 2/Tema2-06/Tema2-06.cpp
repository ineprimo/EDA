
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& v, int ini, int fin) {
  
    // caso base
    if (fin - ini == 1) {
        return v[ini] == ini;
    }
    if (fin - ini == 0)
        return false;
    
    // recursion
    int mid = (ini + fin) / 2;


    // si el elemento en mid es mayor que mid todos los elementos de la derecha estan mal
    if(v[mid] > mid)        
        return resolver(v, ini, mid);
    // si el elemento en mid es menor que mid todos los elementos de la izquierda estan mal
    if(v[mid] < mid)       
        return resolver(v, mid, fin);

    // si mid == al elemento entonces devuelve true
    return true;

    // return
    //return izq || der;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << (resolver(sec, 0, n) ? "SI" : "NO") << endl;
}

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
