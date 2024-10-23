// Nieves Alonso Gilsanz
// EDAGDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include <vector>
using namespace std;

template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    // Complejidad: lineal O(n+m), siendo n el tamaño de la cola inicial y m el tamaño de la cola resultante con sus multiplicidades
    void replicaElems(vector<int> const& mult) 
    {
        if (this->empty()) return; // si cola vacia no hace nada
        
        Nodo* act = this->prim; // indice para recorrer la cola
        Nodo* ant = nullptr; // el anterior empieza como nullptr luego avanza

        for (int i = 0; i < mult.size(); i++) 
        {
            // multiplicidades
            // 0 -> se elimina de la cola
            if (mult[i] == 0)
            {
                Nodo* sigAux = act->sig;

                // si act es == prim
                if (ant == nullptr) 
                {
                    this->prim = act->sig; // se come prim
                }
                // si el siguiente es nullptr (estamos en el ultimo elemento de la cola)
                else if (act->sig == nullptr)
                {
                    ant->sig = nullptr;
                    this->ult = ant;
                }
                // el siguiente del anterior es el siguiente del actual, se come act
                else 
                {
                    ant->sig = act->sig; 
                }

                // para eliminar el que te queda suelto, lo llevas a prim y pop
                act->sig = this->prim;
                this->prim = act;
                this->pop();

                // avanzas
                act = sigAux;
            }
            // 1 -> se queda como estaba
            else if (mult[i] == 1)
            {
                // avanzas
                ant = act;
                act = act->sig;
            }
            // v > 1 -> se meten v-1 copias
            else 
            {
                Nodo* sigAux = act->sig;
                Nodo* ultAux = this->ult;

                for (int j = 0; j < mult[i]-1; j++) 
                {
                    this->push(act->elem); // se meten los nuevos elementos, luego se reordenan
                }

                ant = this->ult; // guardas en el anterior al actual lo que se acabe de crear (lo que haya en ult)

                if (sigAux != nullptr) // mientras no sea el final de la lista
                {
                    // reorganizar punteros:

                    act->sig = ultAux->sig;  // el siguiente al actual es el siguiente al que acabamos de crear
                    this->ult->sig = sigAux; // metes en el siguiente del ultimo el siguiente del act
                    this->ult = ultAux;      // mete en ult el elemento final
                    this->ult->sig = nullptr;// la cola acaba en nullptr
                }

                // avanzas
                act = sigAux;
            }
        }
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    queue_plus<int> q;

    cin >> n;
    vector<int> mult(n);
    vector<int> aux(n); // Para darle la vuelta a la secuencia de entrada

    // Leemos la secuencia invertida para q y le damos la vuelta
    for (int i = n - 1; i >= 0; --i) cin >> aux[i];
    for (int e : aux) q.push(e);

    // Leemos la secuencia invertida para mult
    for (int i = n - 1; i >= 0; --i) cin >> mult[i];

    // llamada al metodo
    q.replicaElems(mult);

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }

    // Ahora imprimimos la cola y de paso la dejamos vacía (tb para probar su consistencia)
    cout << "[";
    if (!q.empty()) {
        cout << q.front();
        q.pop();
    }
    while (!q.empty()) {
        cout << ", " << q.front();
        q.pop();
    }
    cout << "]" << endl;
    return true;
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