// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool elemento_situado(const vector<int>& v, int ini, int fin) {

    // caso base
    if (fin - ini == 1)
        return v[ini] == ini;
    
    if (fin - ini == 0)
        return false;

    int mitad = (fin + ini) / 2;

    
    if (v[mitad] > mitad) { // sabemos que estara a la izda
        return elemento_situado(v, ini, mitad);
    }
    else { //dcha
        return elemento_situado(v, mitad, fin); // cuando quedan 2 elems
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int elems;
    cin >> elems;

    vector<int> v(elems);
    for (int i = 0; i < elems; i++) {
        cin >> v[i];
    }

    bool sol = elemento_situado(v, 0, elems);

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