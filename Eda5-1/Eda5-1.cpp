/// 5.1 PILAS 
// Si en una pila metes las aperturas, al encontrar los cierres puedes comprobar si es el mismo caracter.
// String como parametro y una pila de caracteres


/// 5.2 Reordenando una cola DEQUE
// Insertas los elems en la cola. Estan ordenados los numeros absolutos, ordenarlos sin absoluto.
// -1 1 -3 4 5 ...
// Los positivos se colocan en el mismo orden en el que estan
// Los negativos se tienen que ir colocando en la izquierda. Usar deque para insertar por ambos lados.
// Tenemos un queue. hay q invertir numeros negativos, usando PILA. 
// Vamos procesando y metemos positivos en una pila y negativos en otra. 
// reordena(queue<int>& q) ?¿??¿

/// 5.3 duplica elems de una pila (LA VERSION MAS FACIL ES LA 3.)
// si tengo una pila 3-5-7 con cima 3. cada vez que avanzas creas nuevo nodo 3' lo enlazas a 5 y borro el anterior.
// 3'-5-7

/// 5.4 igual q el de antes pero cola
// 

/// 5.5 invertir una cola (+ dificil)
// podria ser pila tb. no vale meterlos en otra pila y sacarlo invertido porq crea y destruye memoria.
// 1->2->3->4
// mover punteros.
// tenemos prim 1 y ult 4. hay q dar la vuelta a las flechas.
// siempre llevar puntero al anterior y al actual. 
// si solo hay un elem ya esta invertido.
// puntero auxiliar para el avance.
// cambiar prim y ult, y el resto de flechas, acordarse de q ult tiene q apuntar a nullptr

/// 5.6 eliminar apariciones de un elem en una lista
// operacion borraElem
// recorrer lista y cuando encuentre el elem a borrar usar la operacion
// miki plantea si fuera un queue. 
// eliminar pares. 1->2->3->4 q 1 apunte a 3

#include <iostream>

#include "stack_eda.h"

// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (!std::cin)
        return false;

    TipoSolucion sol = resolver(datos);

    // escribir sol


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
    system("PAUSE");
#endif

    return 0;
}