// Ejercicio 1: REPETIR ELEMENTOS (3 puntos)
// Tipo: TADs (cola)

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    // Coste: 
    void repetir(vector<int>& multiplicidades, int& n)
    {
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult

        // si esta vacia
        if (this->empty()) return;

        int i = 0;
        while (i < n)
        {
            if (multiplicidades[i] == 0)
            {
                ++i;
                this->pop();
            }
            else
            {
                multiplicidades[i] -= 1;
                this->push(this->front());
            }
        }
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    queue_plus<int> q;
    cin >> n;

    int e = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> e;
        q.push(e);
    }

    vector<int> multiplicidades;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> m;
        multiplicidades.push_back(m);
    }

    // llamada a metodo
    q.repetir(multiplicidades, n);

    int j = q.size();
    for (int i = 0; i < j; i++)
    {
        std::cout << q.front() << ' ';
        q.pop();
    }

    std::cout << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input.txt");
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