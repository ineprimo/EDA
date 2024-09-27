
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

//Coste log(n)
char resolver(const vector<char>& sec, int ini, int fin, char prim, char ult) {

    int diferencia = fin - ini;

    //Caso base: No hay presos
    if (diferencia == 0) {
        return '0';
    }
    //Hay un preso
    else if (diferencia == 1) {
        if (sec[ini] != prim) {
            return sec[ini] - 1;
        }

        return sec[ini] + 1;
    }
    if (sec[ini] != prim) {
        return prim;
    }
    if (sec[fin] != ult) {
        return ult;
    }

    int mitad = (ini + fin) / 2;
    char medio = prim + (mitad - ini);

    //Búsqueda en la primera mitad
    if (medio == sec[mitad]) {
        return resolver(sec, mitad, fin, sec[mitad], ult);
    }
    //Búsqueda en la segunda mitad
    else {
        return resolver(sec, ini, mitad, prim, sec[mitad - 1]);
    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char prim, ult, n;
    int ini, fin;
    cin >> prim >> ult;
    n = ult - prim;
    ini = 0;
    fin = n;
    vector<char> sec(n);
    for (char& e : sec) cin >> e;
    cout << resolver(sec, ini, fin, prim, ult) << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
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