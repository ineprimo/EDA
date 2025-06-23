// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& vec1, vector<int>& vec2, int ini, int fin) {
    if (ini > fin) return vec1[ini];
    if (fin == ini) {
        if (vec2[ini] == vec1[ini]) return vec1[ini + 1];
        else return vec1[ini];
    }

    int mitad = (ini + fin) / 2;

    if (vec2[mitad] > vec1[mitad]) return resolver(vec1, vec2, ini, mitad);
    else return resolver(vec1, vec2, mitad + 1, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, auxNum;
    cin >> n;
    vector<int> vec1;
    vector<int> vec2;

    for (int i = 0; i < n; ++i) {
        cin >> auxNum;
        vec1.push_back(auxNum);
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> auxNum;
        vec2.push_back(auxNum);
    }

    int sol = resolver(vec1, vec2, 0, n - 2);
    
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