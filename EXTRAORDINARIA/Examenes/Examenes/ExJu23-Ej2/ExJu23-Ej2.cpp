// Ejercicio 1: FUGA DE PRISION (3 puntos)
// Tipo: DIVIDE ET IMPERA

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funcion que resuelve el problema
char resolver(const vector<char>& sec, char prim, char ult, int ini, int fin)
{
    int tam = fin - ini;

    if (tam == 1)
    {
        if (sec[ini] == prim) return ult;
        return prim;
    }

    char charMit = (ult + prim) / 2; // char que deberia estar en el centro
    int indMit = (fin + ini) / 2; // indice del que deberia estar en el centro

    // buscar derecha -> si el que tiene que estar esta
    if (sec[indMit] == charMit) return resolver(sec, charMit, ult, indMit, fin);
    // buscar izq -> si no esta
    else  return resolver(sec, prim, charMit, ini, indMit);
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
    cout << resolver(sec, prim, ult, 0, n) << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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
