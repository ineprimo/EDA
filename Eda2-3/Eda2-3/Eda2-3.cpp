// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcion que resuelve el problema
bool resolver(vector<int>& datos, int ini, int fin) {

    // caso base
    if (fin - ini <= 1 && datos[fin] >= datos[ini]) {
        return true;
    }

    // caso recursivo

    int mitad = (fin + ini) / 2;

    int minIzda = datos[ini],
        maxIzda = datos[mitad],
        minDcha = datos[ini],
        maxDcha = datos[mitad];

    //actualizacion de la izquierda
    for (int i = ini+1; i <= mitad; i++) {
        if (datos[i] < minIzda) {
            minIzda = datos[i];
        }
        else if (datos[i] > maxIzda) {
            maxIzda = datos[i];
        }
    }

    //actualizacion de la derecha
    for (int i = mitad+1; i <= fin; i++) {
        if (datos[i] < minDcha) {
            minDcha = datos[i];
        }
        else if(datos[i] > maxDcha){
            maxDcha = datos[i];
        }
    }


    if (maxDcha >= maxDcha && minIzda <= minDcha) {
            
        return resolver(datos, ini, mitad) && resolver(datos, mitad+1, fin);
    }
    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    // si el primer n es 0 salimos
    if (n == 0)
        return false;

    // guardamos el vector
    vector<int> vec;
    while (n != 0) {
        vec.push_back(n);
        cin >> n;
    }


    bool sol = resolver(vec, 0, vec.size()-1);

    // escribir sol
    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;


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
