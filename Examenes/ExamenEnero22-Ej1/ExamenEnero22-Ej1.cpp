// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;

// función que resuelve el problema
list<char> resolver(list<char> datos, int pos, int lon, int k) {

    // caso lista vacia
    if (datos.empty()) return datos;    

    // si es segmento vacio o 0 posiciones
    if (lon == 0 || k == 0) return datos;

    // si la posicion de origen es mayor que el size
    if (pos >= datos.size()) return datos;

    // si lo que hay que mover es mayor que la posicion de origen
    if (k > pos) return datos;

    // si el segmento es mas grande que lo que se puede mover
    if (pos + lon > datos.size()) 
        lon = datos.size() - pos;

    // iterador con el nodo del dato que mover (la posicion anterior)
    list<char>::iterator currIT = datos.begin();
    for (int i = 0; i < pos - 1; i++) ++currIT;

    // iterador con la posicion nueva para el iterador anterior
    int mov = pos - k;
    list<char>::iterator posIT = datos.begin();
    for (int i = 0; i < mov; i++) ++posIT;

    list<char>::iterator auxIT = currIT++;
    list<char>::iterator eraseIT = currIT;

    for (int i = 0; i < lon; i++) {
        datos.insert(posIT, *currIT++);     // pone el dato

        datos.erase(eraseIT++);             // borra el dato
        eraseIT = currIT;                   // recoloca el iterador que borrar
        currIT = auxIT;                     // recoloca el iterador a la posicion anterior
        currIT++;                           // recoloca el iterador que insertar
    }

    //
    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, pos, lon, k;
    list<char> datos;
    
    cin >> n >> pos >> lon >> k;
    for (int i = 0; i < n; i++) {
        char aux;
        cin >> aux;
        datos.push_back(aux);
    }

    list<char> sol = resolver(datos, pos, lon, k);
    // escribir sol

    list<char>::iterator it = sol.begin();
    for (int i = 0; i < n; i++) {
        cout << *it++ << " ";
    }
    cout << endl;
}

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
    system("PAUSE");
#endif

    return 0;
}