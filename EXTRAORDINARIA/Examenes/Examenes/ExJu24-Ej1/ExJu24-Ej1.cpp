// Ejercicio 1: Partition (3 puntos)
// Tipo: TADs (extender list)

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"

template <class T>
class list_eda_plus : public list<T>
{
	using Nodo = typename list<T>::Nodo;

public:
    // Recibe un entero pivote y reorganiza los nodos dinamicos de la lista enlazada de tal forma que
    // al principio aparezcan aquellos que contengan enteros menores o iguales que el pivote y
    // al final aparezcan los que contengan enteros mayores que el pivote

    // ---> Ej: lista[5, 10, 4, 7, 9, 3] => partition(8) => lista[5, 4, 7, 3, 10, 9]
    // !!!! No puede crearse ni destruirse memoria dinamica ni copiar los enteros de un nodo a otro
    // Complejidad: 
	 void partition(int pivote)
	 {
        if (!this->empty() && this->nelems > 1)
        {
            Nodo* act = this->fantasma->sig; // primer nodo de la lista
            Nodo* antAct = act->ant;
            Nodo* sigAct = act->sig;
            Nodo* ult = this->fantasma->ant;

            for (int i = 0; i < this->size(); i++)
            {
                // va metiendo los que sean mayores al final
                if (act->elem > pivote && act != ult) // se comprueba tambien si has acabado la lista
                {
                    act->sig = this->fantasma;
                    act->ant = this->fantasma->ant;

                    antAct->sig = sigAct;
                    sigAct->ant = antAct;

                    this->fantasma->ant = act;
                    act->ant->sig = act;
                }

                // avanzamos
                act = sigAct;
                sigAct = act->sig;
                antAct = act->ant;
                ult = this->fantasma->ant;
            }
        }
	 }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int elems = 0,
        pivote = 0;

    std::cin >> elems;

    if (!std::cin)
        return false;

    std::cin >> pivote;

    int e = 0;
    list_eda_plus<int> lista;
    for (int i = 0; i < elems; i++)
    {
        std::cin >> e;
        lista.push_back(e);
    }

    // escribir sol
    lista.partition(pivote);

    for (int i : lista)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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