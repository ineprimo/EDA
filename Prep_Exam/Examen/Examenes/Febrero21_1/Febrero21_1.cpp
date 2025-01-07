#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    queue<int> cola;
    int dato = 0;
    cin >> dato;

    do
    {
        if (dato != -1)
        {
            cola.push(dato);
            cin >> dato;
        }
    } 
    while (dato != -1);

    //Condicion salida
    if (cola.empty()) return false;

    //Leemos a y b
    int a = 0, b = 0;
    cin >> a >> b;
    
    cola.cuela(a, b);

    // Ahora imprimimos la cola y de paso la dejamos vacía 
    if (!cola.empty())
    {
        cout << cola.front();
        cola.pop();
    }
    while (!cola.empty()) {
        cout << " " << cola.front();
        cola.pop();
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

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
