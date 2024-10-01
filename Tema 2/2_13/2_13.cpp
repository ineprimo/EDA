
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector <int>& v, int ini, int fin) {
    
    //Casos base
    if (ini == fin) return ini;

    if (fin - ini == 2) {

        if (v[ini + 1] == v[ini]) return fin;
        return ini;
    }

    if (fin - ini == 1) {

        //Por si está al final del vector
        if (fin == v.size() - 1) {
            if (v[ini - 1] == v[ini]) return fin;
            return ini;
        }

        if (v[fin] == v[fin + 1]) return ini;
        return fin;
    }

    int mid = 0;
    mid = (ini + fin) / 2;

    //La pareja está a la izquierda
    if (v[mid - 1] == v[mid]) {

        //Vamos hacia la izquierda
        if (mid % 2 == 0) return resolver(v, ini, mid);
        //Vamos a la derecha
        return resolver(v, mid + 1, fin);
    }
    //La pareja está a la derecha
    else if (v[mid] == v[mid + 1]) {

        //Vamos a la derecha
        if (mid % 2 == 0) return resolver(v, mid, fin);

        return resolver(v, ini, mid);
    }

    else return mid;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v) cin >> e;

    // Llamada a la función resolver
    int sol = resolver(v, 0, n - 1);

    // Mostrar el resultado
    cout << sol << endl;
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