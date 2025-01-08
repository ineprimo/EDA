// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> datos) {

    //Buscamos donde se rompe la cadena
    if (datos.size() == 1) return datos[0]; //Si solo hay un elemento devolvemos ese

    int i = 1;
    while (i < datos.size() &&
        datos[i] - 1 == datos[i - 1]) {  //Si esto se cumple son consecutivos
        i++;
    }

    return datos[i - 1];

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int n = 0;
    int d = 0;
    vector<int> datos;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d;
        datos.push_back(d);
    }

    int sol = resolver(datos);
    // escribir sol

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