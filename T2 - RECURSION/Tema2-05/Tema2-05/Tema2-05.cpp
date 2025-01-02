// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& datos, int ini, int fin, int& pares) 
{
    // caso base: 1 elem
    if (fin - ini == 1) 
    {
        if (datos[ini] % 2 == 0) {
            pares = 1;
        }
        else pares = 0;

        return true;
    }

    int paresIzquierda = 0;
    int paresDerecha = 0;

    int mitad = (fin + ini) / 2;

    // quedaria
    // [2    3    1    4]   .
    // ini       mit       fin

    bool izq = resolver(datos, ini, mitad, paresIzquierda); // comprueba de posicion 0 a 2
    bool dch = resolver(datos, mitad, fin, paresDerecha);   // posicion 2 a 4

    pares = paresIzquierda + paresDerecha;

    return izq && dch && abs(paresIzquierda - paresDerecha) <= 2; // condicion
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> numeros;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        numeros.push_back(a);
    }

    int pares = 0;
    bool sol = resolver(numeros, 0, numeros.size(), pares);

    // escribir sol
    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;

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
