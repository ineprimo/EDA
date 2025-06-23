// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

using namespace std;

// función que resuelve el problema
void resolver(queue<int>& cola, int const& pringao, queue<int>& colegas) 
{
    cola.colarse(colegas, pringao);

    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int aux;
    queue<int> cola;
    int pringao;
    queue<int> colegas;

    cin >> aux;
    if (aux != -1) cout << aux << " ";
    while (aux != -1) {
        cola.push(aux);
        cin >> aux;
        if(aux != -1) cout << aux << " ";
    }
    cout << endl;

    cin >> pringao;

    cin >> aux;
    while (aux != -1) {
        colegas.push(aux);
        cin >> aux;
    }

    resolver(cola, pringao, colegas);
    
    
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