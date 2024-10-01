// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
// función que resuelve el problema
bool resolver(const vector<int>& sec, int ini, int fin, int x) {

    if (sec[ini] == x || sec[fin] == x) return true;

    //casos base, tenemos solo dos elementos
    if (fin == ini) return sec[ini] == x;
    if (fin - ini == 1) return false;

    int mid = 0;
    mid = (ini + fin) / 2;

    if (sec[mid] == x) return true;

    //habría que notar si se ha hecho una rotación
    if (x > sec[mid]) {
        //mira la parte derecha
        return resolver(sec, mid + 1, fin, x);
    }
    else {
        //mira la parte izquierda
        return resolver(sec, ini, mid - 1, x);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n = 0;
    int x = 0;

    cin >> n;

    if (n == -1)
        return false;

    cin >> x;
    vector<int> datos(n);
    for (int& e : datos) cin >> e;

    bool sol = resolver(datos, 0, n - 1, x);

    // escribir sol

    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;

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
    system("PAUSE");
#endif

    return 0;
}
