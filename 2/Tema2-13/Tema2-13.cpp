
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> vec, int ini, int fin) {
    
    // base
    if (fin - ini == 0) return ini;
    else if (fin - ini == 1) {
        // TODO
        if (fin == vec.size() - 1) {
            if (vec[ini] == vec[ini - 1])
                return fin;
            return ini;
        }
        
        if (vec[fin] == vec[fin + 1])
            return ini;
        return fin;
    }
    if (fin - ini == 2) {
        if (vec[ini + 1] == vec[fin]) return ini;
        else return fin;
    }


    // rec
    int mid = (ini + fin) / 2;
    ////                      [1 1 2 9 9] -> [1 2 [2] 9 9] -> [1 2 2 9 9]
    //// esta a la izquierda  [1 1 2 2 9] -> [1 1 [2] 2 9] -> [mid == mid - 1] == [2 == 1]
    //if (vec[mid] != vec[mid - 1]        // si el valor del medio no es igual al anterior y el medio esta
    //    && mid % 2 == 1) {              // en una posicion impar, todo lo de la izquierda tiene que coincidir
    //                                
    //    // esta en la derecha
    //    return resolver(vec, mid, fin);
    //}
    //else if (vec[mid] != vec[mid + 1]   // si el valor del medio no es igual al sigueinte y el medio esta en 
    //    && mid % 2 == 1) {              // una posicionimpar,

    //}


    // ---------------
    if (vec[mid] == vec[mid - 1]) {
        // si el medio es par, a la derecha hay impares
        if (mid % 2 == 0) return resolver(vec, ini, mid);   //
        return resolver(vec, mid, fin);

    }
    // esta a la derecha
    else if (vec[mid] == vec[mid + 1]) {
        // si el medio es par, a la derecha hay impares
        if (mid % 2 == 0) return resolver(vec, mid, fin);
        return resolver(vec, ini, mid);
    }
    // esta en el medio
    else return mid;

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v) cin >> e;

    // Llamada a la función resolver
    int a = resolver(v, 0, n-1);

    // Mostrar el resultado
    std::cout << a << std::endl;
}


//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}