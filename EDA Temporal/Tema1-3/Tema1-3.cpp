// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> datos, int p) {

    bool menor;
    int mayorIzq = -51;
    int menorDer = 61;
    bool cambio = false;

    for (int i = 0; i < datos.size(); ++i) {
        if (i == p + 1) cambio = true;

        if (datos[i] > mayorIzq && !cambio) mayorIzq = datos[i];
        else if (datos[i] < menorDer && cambio) menorDer = datos[i];
    }

    if (mayorIzq < menorDer) menor = true;
    else menor = false;

    return menor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, p;
    cin >> n;
    cin >> p;

    vector<int> datos(n);

    for (int i = 0; i < n; ++i) {
        cin >> datos[i];
    }

    bool sol = resolver(datos, p);
    // escribir sol

    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;
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