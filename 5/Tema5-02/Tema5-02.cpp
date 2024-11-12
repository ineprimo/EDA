// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include <stack>



// función que resuelve el problema
queue<int> resolver(queue<int> datos) {
    queue<int> pos;
    std::stack<int> neg;
    int size = datos.size(), i = 0;

    while (i < size) {
        // si es positivo
        if (datos.front() >= 0)
            pos.push(datos.front());
        // si es negaitivo
        else
            neg.push(datos.front());
        datos.pop();
        i++;
    }

    queue<int> sol;

    while (!neg.empty()) {
        sol.push(neg.top());
        neg.pop();

    }
    while (!pos.empty()) {
        sol.push(pos.front());
        pos.pop();
    }


    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, a;
    std::cin >> size;
    queue<int> aux;

    if (size == 0)
        return false;

    for (int i = 0; i < size; i++) {
        std::cin >> a;
        aux.push(a);
    }

    queue<int> sol = resolver(aux);

    
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