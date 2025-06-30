/*
Nombre completo: Nieves Alonso Gilsanz
DNI: 54696982S
Usuario del juez: 03
Puesto de laboratorio: pto 02 lab 1
Qué has conseguido hacer y qué no: Falla en el tercer caso de los casos de prueba, en el resto la salida es correcta
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    // Complejidad:
    void reordena() 
    {
        // Para acceder a los atributos de queue hay que escribir this->...

        Nodo* act = this->prim;
        Nodo* antAct = this->prim;
        Nodo* despAct = this->prim->sig;
        Nodo* antiguoPri = this->prim;

        int tam = this->nelems;
        int i = 0; 

        // vas recorriendo la lista:
        // - los positivos los llevas al final
        // - los negativos los llevas al frente
        while (i < tam) 
        {
            // si es positivo
            if (act->elem > 0)
            {
                this->push(act->elem);

                // si no era el primero
                if (this->prim != act)
                {
                    antAct->sig = despAct;
                    act = despAct;
                    despAct = act->sig;
                }
                else 
                {
                    this->pop();
                    act = this->prim;
                    despAct = act->sig;
                }
            }
            // si es negativo
            else
            {
                // si no era el primero
                if (this->prim != act) 
                {
                    // lo llevas al frente
                    antiguoPri = this->prim;
                    antAct->sig = despAct;
                    this->prim = act;
                    act->sig = antiguoPri;

                    // avanzas
                    act = despAct;
                    despAct = act->sig; // en el tercer caso el acceso a act es nullptr
                }
                else 
                {
                    // avanzamos
                    antAct = act;
                    act = despAct;
                    despAct = act->sig;
                }
            }

            i++;
        }

        this->nelems = tam;
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, e;
    queue_plus<int> q;
    std::cin >> n;
    if (n == 0) return false;
    for (int i = 0; i < n; ++i) {
        std::cin >> e;
        q.push(e);
    }

    q.reordena();

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) 
    {
        n = q.front();
        q.pop();
        q.push(n);
    }

    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
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

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}