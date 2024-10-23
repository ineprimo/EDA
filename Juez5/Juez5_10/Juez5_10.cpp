/*
Nombre completo: Denisa Juarranz Berindea
Usuario del juez: EDA-GDV37
*/

//Complejidad O(n) siendo n el número de instrucciones que se realizan según las incidencias. 
//Siendo en el caso de 0 incidencias 1, y en las demás, el valor determinado

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
    void replicaElems(vector<int> const& mult) {
        
        // En caso de ser vacío
        if (this->empty()) {
            return;
        }

        // Puntero al primer elemento de la cola para recorrerla (iterador)
        Nodo* act = this->prim;
        // Auxiliar (anterior)
        Nodo* ant = nullptr;

        // Recorremos el vector y hacemos la acción correspondiente al valor de cada índice
        for (int i = 0; i < mult.size(); i++) {

            // Cero apariciones : Eliminamos el elemento de la cola
            if (mult[i] == 0) {

                if (act == this->prim) {
                    act = act->sig;
                    this->pop();
                }

                else {
                    act = act->sig;
                    ant->sig = act;
                    this->nelems--;
                }

            }
            // Una sola aparición : Lo dejamos como está
            else if (mult[i] == 1) {
                ant = act;
                act = act->sig;
            }
            // Múltiples apariciones : push act i-1 veces
            else if (mult[i] > 1) {
                Nodo* auxsig = act->sig;

                for (int j = 0; j < mult[i] - 1; j++) {

                    Nodo* auxnew = new Nodo(act->elem);
                   
                    ant = act;

                    act = auxnew;
                    
                    ant->sig = act;

                    this->nelems++;
        
                }

                act->sig = auxsig;

                ant = act;
                act = act->sig;
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
  /*  for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }*/

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
