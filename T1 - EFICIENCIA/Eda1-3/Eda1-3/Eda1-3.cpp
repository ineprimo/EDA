// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
string resolver(vector<int> datos, int p) {

    string sol = "SI";
    int N = datos[0];

    // recorrer hasta p incluido y quedarme con el numero mas grande N
    for (int i = 0; i < p; i++) {
        if (N < datos[i + 1]) {
            N = datos[i + 1];
        }
    }

    // recorrer desde p+1 y buscar si alguno de los siguientes numeros es menor que N
    int i = p+1;
    while (i < datos.size() && sol == "SI") {
        if (datos[i] <= N) {
            sol = "NO";
        }
        i++;
    }


    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    vector<int> datos(tam);

    int pos;
    cin >> pos;

    for (int i = 0; i < tam; ++i) {
        cin >> datos[i];
    }

    string sol = resolver(datos, pos);

    // escribir sol
    cout << sol << endl;

    return true;

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