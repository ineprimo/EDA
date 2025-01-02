// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

using namespace std;
// función que resuelve el problema
//deque<int> resolver(deque<int>& datos) 
//{
// nada q no hace falta
//
//}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    cin >> n;
    if (n == 0)
        return false;

    deque<int> colacola;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            colacola.push_back(a);
        }
        else colacola.push_front(a);
        
    }

    //deque<int> sol = resolver(colacola);

    // escribir sol
    for (int i = 0; i < n; i++) {
        cout << colacola.back() << " ";
        colacola.pop_back();
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
