
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "LinkedListStack.h"
using namespace std;


// función externa que resuelve el problema sobre stack
void duplicar(stack<int>& s){
}

// Clase extendida con operación interna duplicar que reaprovecha nodos existentes
template <class T>
class LinkedListStack_plus : public LinkedListStack<T> {
    using Nodo = typename LinkedListStack<T>::Nodo;

public:
    void duplicar() {
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int e;
    //stack<int> s;
    LinkedListStack_plus<int> s;
    cin >> e;
    if (!cin) return false;
    while (e != 0){
        s.push(e);
        cin >> e;
    }
    //duplicar(s);
    s.duplicar();

    // Ahora imprimimos la pila de cima a base y de paso la dejamos vacía
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
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

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}