// Javier Tirado Ríos
// EDA-GDV72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// EL coste de la función es log(n) siendo n el tamaño del vector de presos
char resolverRec(const vector<char>& presos, int ini, int fin, char inicioPresos) {
    // Caso base
    if (ini > fin) {
        return inicioPresos + ini;
    }

    int mitad = (ini + fin) / 2;

    if (presos[mitad] == inicioPresos + mitad) {
        return resolverRec(presos, mitad + 1, fin, inicioPresos);
    }

    else {
        return resolverRec(presos, ini, mitad - 1, inicioPresos);
    }
}

// Función que resuelve el problema para un caso
char resolver(const vector<char>& presos, char inicioPresos) {
    return resolverRec(presos, 0, presos.size() - 1, inicioPresos);
}

// Resuelve un caso de prueba
void resuelveCaso() {
    char inicio, fin;
    cin >> inicio >> fin;

    int n = fin - inicio;  // La cantidad de presos presentes debe ser fin - inicio, menos el que falta
    vector<char> presos(n);

    for (int i = 0; i < n; ++i) {
        cin >> presos[i];
    }

    cout << resolver(presos, inicio) << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
