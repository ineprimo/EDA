// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool resolver(vector<int>& datos, int ini, int fin, int k) {
    if (fin - ini == 0) return true;

    else if (fin - ini == 1) return abs(datos[ini] - datos[fin]) >= k;

    else {
        int mitad = (ini + fin) / 2;

        bool suficientementeDispersos = false;
        if ((abs(datos[ini] - datos[fin]) >= k)) suficientementeDispersos = true;

        if (suficientementeDispersos) return (resolver(datos, ini, mitad, k) && resolver(datos, mitad + 1, fin, k));
        else return false;
    }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;  // nº elementos
    cin >> n;
    int k;  // dispersión
    cin >> k;

    if (!std::cin)
        return false;

    vector<int> datos(n);
    for (int i = 0; i < n; ++i) {
        cin >> datos[i];
    }

    bool sol = resolver(datos, 0, n - 1, k);

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