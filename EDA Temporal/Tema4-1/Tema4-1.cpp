// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include "Set.h"
#include <cmath>

using namespace std;

// función que resuelve el problema
void resolver(int num) {
    Set<int> a;
    bool resultadoEncontrado = false;
    bool esFeliz = false;
    bool siguienteNumeroEncontrado = false;
    int numActual = num;
    int numSiguiente = 0;
    a.add(numActual);

    cout << numActual << " ";

    while (!resultadoEncontrado)
    {
        siguienteNumeroEncontrado = false;
        numSiguiente = 0;

        if (numActual == 1) {
            resultadoEncontrado = true;
            siguienteNumeroEncontrado = true;
            numSiguiente = 1;
            cout << 1 << " " ;
        }

        else {
            while (!siguienteNumeroEncontrado)
            {
                numSiguiente += pow(numActual % 10, 2);
                numActual = numActual/ 10;
                if (numActual == 0) {
                    siguienteNumeroEncontrado = true;
                }
            }

            if (numSiguiente == 1) {
                resultadoEncontrado = true;
                esFeliz = true;
                cout << numSiguiente << " 1";
            }

            else if (a.contains(numSiguiente)) {
                resultadoEncontrado = true;
                esFeliz = false;
                cout << numSiguiente << " 0";
            }

            else {
                numActual = numSiguiente;
                a.add(numSiguiente);
                cout << numSiguiente << " ";
            }
        }
    }

    cout << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    if (!std::cin)
        return false;

    resolver(num);

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