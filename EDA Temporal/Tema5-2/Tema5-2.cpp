// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include "stack_eda.h"

using namespace std;

// función que resuelve el problema
queue<int> resolver(queue<int>& datos) 
{
    int v = datos.size();
    stack<int> negativo;
    queue<int> positivo;

    for (int i = 0; i < v; ++i) {
        if (datos.front() < 0) {
            negativo.push(datos.front());
            datos.pop();
        }
        else {
            positivo.push(datos.front());
            datos.pop();
        }
    }

    int vNegativo = negativo.size();
    int vPositivo = positivo.size();

    queue<int> solucion;
    for (int i = 0; i < vNegativo; ++i) {
        solucion.push(negativo.top());
        negativo.pop();
    }
    for (int i = 0; i < vPositivo; ++i) {
        solucion.push(positivo.front());
        positivo.pop();
    }

    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;

    if (tam == 0)
        return false;

    queue<int> pepsicola;
    int n;
    for (int i = 0; i < tam; ++i) {
        cin >> n;
        pepsicola.push(n);
    }

    queue<int> sol = resolver(pepsicola);

    // escribir sol
    while (!sol.empty()) {
        std::cout << sol.front() << " ";
        sol.pop();
    }
    std::cout << std::endl;

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
