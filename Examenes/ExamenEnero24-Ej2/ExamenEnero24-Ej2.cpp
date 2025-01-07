// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int, int> resolver(pair<vector<int>, vector<int>> rectas) {

    // casos base


    // 
    pair<int, int> izq;


    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, aux;

    cin >> size;

    if (size == 0)
        return false;
    pair<vector<int>, vector<int>> rectas;

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < size; i++) {
            cin >> aux;
            if (j == 0)
                rectas.first.push_back(aux);
            else
                rectas.second.push_back(aux);
        }
    }



    TipoSolucion sol = resolver(datos);

    // escribir sol

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
