#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
	// Mueve al elemento b de su posicion a la posicion inmediatamente detras del elemento a
	// => En caso de haber multiples apariciones de los elementos a y/o b se consideraran:
	//      - La primera aparicion de a, y la primera aparicion de b tras la primera aparicion de a
	// Si alguno de los elementos no se encuentra en la cola, si b no aparece detras de a -> No se hace nada
	// Requisitos: No se puede crear ni destruir memoria dinamica, ni tampoco modificar los valores almacenados en la cola.
    // Coste: 
    void cuela(const T& a, const T& b)
	{
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult

        // si esta vacia
        if (this->empty()) return;

        // buscar A
        Nodo* actA = this->prim;
        while (actA->elem != a && actA != this->ult) actA = actA->sig;
        // si has encontrado A
        if (actA->elem != a) return;

        // buscar B -> buscar a partir de a
        bool esUlt = false;
        Nodo* actB = actA;
        while (actB->elem != b && actB != this->ult) actB = actB->sig;
        // si has encontrado B
        if (actB->elem != b) return;
        // si B es el ult
        if (actB == this->ult) esUlt = true;

        Nodo* sigB = actA->sig; // nos guardamos el que va a ser siguiente a B
        Nodo* sigAntB = actB->sig; // el que va a ser el siguiente al anterior a B

        // encontrar anterior a B
        Nodo* antB = actA->sig;
        while (antB->sig != actB && antB != this->ult) antB = antB->sig;

        // REORGANIZAR LAS FLECHAS
        actA->sig = actB; // el siguiente de A es B
        actB->sig = sigB; // el siguiente de B es que era siguiente de A
        antB->sig = sigAntB; // el siguiente de lo que era el anterior de B es el siguiente del antiguo B

        if (esUlt) this->ult = antB; // actualizar ult
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    queue_plus<int> q;
    cin >> n;
    if (n == -1) return false;
    while (n != -1) {
        q.push(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
    q.cuela(a, b);

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return true;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}
