
/*
Nombre completo: Denisa Juarranz Berindea
DNI: 03504447Y
Usuario del juez: EDA-GDV37
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// (log n) donde n es la cantidad de elementos del vector sec
// porque es una busqueda binaria
char resolver(const vector<char>& sec, char ini, char fin, char prim, char ult)
{
    int n = fin - ini;

    // casos base
    if (n == 0) // ningun elto
        return prim;
    if (n == 1) // un solo elto
        // si coincide esta justo despues, si no esta inmediatamente antes
        return sec[ini] == prim ? sec[ini] + 1 : sec[ini] - 1;
    if (sec[ini] != prim)
        return prim; // extremo izq
    if (sec[fin - 1] != ult)
        return ult; // extremo der

    int mitad = (ini + fin) / 2;
    char esperado = prim + (mitad - ini);

    if (esperado == sec[mitad]) // si el de la mitad es el que corresponde 
        return resolver(sec, mitad, fin, sec[mitad], ult); // el fugado esta a la derecha
    return resolver(sec, ini, mitad, prim, sec[mitad - 1]); // si no a la izquierda
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char prim, ult, n;
    cin >> prim >> ult;
    n = ult - prim;
    vector<char> sec(n);
    for (char& e : sec) cin >> e;
    cout << resolver(sec, 0, n, prim, ult) << endl;
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