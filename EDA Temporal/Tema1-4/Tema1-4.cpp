// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<long long int> resolver(vector<long long int>& datos) {

    int pos = 0;

    for (int i = 0; i < datos.size(); ++i) {
        if (datos[i] % 2 == 0) {
            datos[pos] = datos[i]; // Sobreescribimos el valor par en la posición "pos"
            pos++; // Avanzamos el puntero de los elementos pares
        }
    }

    // Redimensionamos el vector
    datos.resize(pos);

    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<long long int> datos(n);
    for (int i = 0; i < n; ++i) {
        cin >> datos[i];
    }

    vector<long long int> sol = resolver(datos);
    // escribir sol

    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i] << " ";
    }
    cout << endl;
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
    system("PAUSE");
#endif

    return 0;
}