/*
Nombre completo: Ines Olimpia Primo Lopez
DNI: 71313341R
Usuario del juez: EDA-GDV61
*/

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


    // Complejidad: en el peor de todos los casos 0(nelems*mult.size()), ya que tendria que hacer un bucle para recorrer el vector de multiplicacion
    // y otro para las generar cada numero
    void replicaElems(vector<int> const& mult) {

        Nodo* it = this->prim;    // nodo auxiliar con el nodo actual
        Nodo* ant = nullptr;  // nodo auxiliar con el anterior

        // recorre el vector mult
        for (int i = 0; i < mult.size(); i++) {
            if (mult[i] == 0) {
                // borra elem de la cola
                Nodo* aux = it->sig;

                // une el nodo anterior al que queremos borrar con el siguiente al que queremos borrar,
                // "sacandolo" de la cola
                if(ant != nullptr)         // si no es el primero
                    ant->sig = it->sig;
                // si it era el primero, sig se settea como primero
                else
                    this->prim = it->sig;

                // si el ultimo es it, se settea el anterior como ultimo
                if (this->ult == it)
                    this->ult == ant;

                // intercambia el primero y el siguiente
                it->sig = this->prim;
                this->prim = it;

                // elimina el primero (anterior it)
                this->pop();

                it = aux;   // pasa al siguiente nodo

            }
            else if (mult[i] > 1) {
                // multiplica

                Nodo* aux = it->sig;
                Nodo* temp = this->ult; // para intercambiar de sitio

                // mete el valor de it en la cola
                for (int j = 0; j < mult[i]-1; ++j) {
                    this->push(it->elem);
                }

                // los cambia de sitio, como estan conectados solo hace falta modificar los nodos de los extremos
                ant = this->ult;
                if (aux != nullptr) {

                    // cambia sig y ult de sitio
                    it->sig = temp->sig;
                    this->ult->sig = aux;

                    this->ult = temp;
                    this->ult->sig = nullptr;
                }

                it = aux;
            }
            else {

                ant = it;
                it = it->sig;   // pasa al siguiente nodo
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
    std::ifstream in("input1.txt");
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
