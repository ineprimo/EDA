// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"
#include <cmath>

struct solution {
    Set<int> a;
    bool esFeliz;
    int lastNun;

};


// función que resuelve el problema
void resolver(int datos) {

    //
    
    Set<int> a;
    bool esFeliz = false, found = false, gotNextNum = false;
    int num = datos, nextnum = 0;
    std::vector<int> b;

    a.add(num);
    std::cout << num << " ";


    while (!found) {
        gotNextNum = false;
        nextnum = 0;


        //if (num == 1) {
        //    found = true;
        //    gotNextNum = true;
        //    nextnum = num;
        //}

        // calcula el siquiente numero 
        while (!gotNextNum) {
            // coge los digitos
       
            nextnum += pow(num % 10, 2);
            num = num / 10;
            if (num == 0) {
                gotNextNum = true;
            }
        }
        // ----------------------------


        // ---------------------------
        // decide
        if (nextnum == 1) {
            std::cout << " 1" << std::endl; //  nextnum <<
            esFeliz = true;
            found = true;

        }
        else if (a.contains(nextnum)) {
            esFeliz = false;
            found = false;

            std::cout << nextnum << " 0" << std::endl;

        }
        else {

            a.add(nextnum);
            num = nextnum;
            std::cout << nextnum << " ";

        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a;
    std::cin >> a;

    if (!std::cin)
        return false;

 

    resolver(a);

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