// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

// función que resuelve el problema
char resolver(vector<char>& datos, int ini, int fin, char prim) {

    int mitad = (ini + fin) / 2;
    char esperado = prim + mitad;
    if (fin == ini) {
        if (datos[ini] == esperado) return esperado + 1;
        else return esperado;
    }

    if (datos[mitad] == esperado) return resolver(datos, mitad + 1, fin, prim);
    else return resolver(datos, ini, mitad, prim);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    char letraInicial, letraFinal, auxL;
    cin >> letraInicial >> letraFinal;
    int n = letraFinal - letraInicial;

    vector<char> datos;
    for (int i = 0; i < n; ++i) {
        cin >> auxL;
        datos.push_back(auxL);
    }
    char sol = resolver(datos, 0, n - 1, letraInicial);
    cout << sol << endl;
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