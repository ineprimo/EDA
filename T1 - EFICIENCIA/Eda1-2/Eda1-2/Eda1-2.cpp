// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> datos) {

    vector<int> sol(2);
    int picos = 0;
    int valles = 0;
    
    for (int i = 1; i < datos.size()-1; i++) {
        if (datos[i - 1] < datos[i] && datos[i] > datos[i + 1]) {
            picos++;
        }
        else if(datos[i - 1] > datos[i] && datos[i] < datos[i + 1]) {
            valles++;
        }
    }

    sol[0] = picos;
    sol[1] = valles;

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    vector<int> datos(tam);

    for (int i = 0; i < tam; ++i) {
        cin >> datos[i];
    }

    vector<int> sol = resolver(datos);

    // escribir sol
    for (int i = 0; i < 2; ++i) {
        cout << sol[i] << " ";
    }
    cout << endl;

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