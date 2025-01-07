#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> datos)
{
    int i = 0;
    //Mientras que no se salga de los límites y el siguiente digito sea justamente el consecutivo
    while (i < datos.size() - 1 && (datos[i + 1] == datos[i] + 1)) {
        i++;
    }
    return datos[i];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nElems, n;
    cin >> nElems;
    vector<int> datos;

    for (int i = 0; i < nElems; i++) {
        cin >> n;
        datos.push_back(n);
    }

    int solucion = resolver(datos);

    // escribir sol
    cout << solucion << endl;
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