/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
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
    void replicaElems(vector<int> const& mult) {
        Nodo* it = this->prim;
        Nodo* pre_it = nullptr;
        for (const int m : mult)
        {
	        if(m == 0)
            {
                Nodo* aux = it->sig;

                if (pre_it != nullptr)
                    pre_it->sig = it->sig;
                else this->prim = it->sig;

                if (this->ult == it)
                    this->ult = pre_it;

                it->sig = this->prim;
                this->prim = it;
                this->pop();

                it = aux;
            }
            else if(m > 1)
            {
                Nodo* aux = it->sig;
                Nodo* ult_temp = this->ult;

                for(int j = 0; j < m - 1; ++j) this->push(it->elem);

                pre_it = this->ult;

	            if (aux != nullptr)
            	{
		            it->sig = ult_temp->sig;
                	this->ult->sig = aux;

                	this->ult = ult_temp;
                	this->ult->sig = nullptr;
	            }

                it = aux;
            }
            else
            {
		        pre_it = it;
	        	it = it->sig;
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
