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

int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
