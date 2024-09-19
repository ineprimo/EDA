// Daniel Zhu
// EDA-GDV79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
vector<int> resolver(vector<int> datos, int num) {

    vector<int> sol(datos.size());
    int picos = 0;
    int valles = 0;

    for (int i = 0; i < sol.size() - 2; ++i) {
        if (datos[i] < datos[i + 1] && datos[i + 1] > datos[i + 2])
            picos++;
        else if (datos[i] > datos[i + 1] && datos[i + 1] < datos[i + 2])
            valles++;
    }

    sol[0] = picos;
    sol[1] = valles;
    
 

    
    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    vector<int> v(num);
    for (int i = 0; i < num; ++i) {
        cin >> v[i];
    }

    vector<int> sol = resolver(v, num);
    
    // escribir sol
    cout << sol[0] << " " << sol[1] << endl;


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