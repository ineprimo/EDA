
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& v, int ini, int fin) {

    //Casos base
    if (v.size() == 0) return false;
    if (ini == fin) { return v[ini] == ini; }

    if (v[ini] == ini) return true;

    //Dividimos el vector a la mitad
    int mid = 0;
    mid = (ini + fin) / 2;

    //Según el resultado de mid lo que buscamos estará a la derecha o a la izquierda
    //Puede que el numero que buscamos sea el del medio
    if (v[mid] == mid) return true;

    //Si no es así comparamos v[mid] con Ini
    if (v[mid] <= ini) {
        //Los números de la mitad izquierda no pueden ser el que buscamos 
        // por lo que lo hacemos a partir de ahí

        return resolver(v, mid + 1, fin);
    }
    else {
        //Si es mayor hacemos una llamada con i++?
        ini++;
        return resolver(v, ini, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << (resolver(sec, 0, n - 1) ? "SI" : "NO") << endl;
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
