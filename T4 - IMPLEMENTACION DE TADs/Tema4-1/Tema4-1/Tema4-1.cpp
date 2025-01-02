// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>

#include "Set.h"

using namespace std;

// función que resuelve el problema
Set<int> resolver(int num, Set<int>& set) 
{
    // caso base
    if (num == 1) { // si el numero es 1, es feliz
        return set;
    }
    
    // hacemos la cuenta (sumar cuadrados de los digitos)

    int sumaDigitos = 0;
    int digito;                         // -vuelta 1                  -vuelta 2  
    while (num > 0) {                   // num=49 ->                  num=4
        digito = num % 10;              // resto -> 9                 resto=0
        sumaDigitos += digito * digito; // s = s + 9*9 = 81           81+0*0=81
        num /= 10;                      // num = 4 (el otro digito)   num = 0
    }

    cout << sumaDigitos << " ";

    // comprobamos si ya ha salido
    if (set.contains(sumaDigitos)) {
        return set;
    }

    set.add(sumaDigitos);
    
    resolver(sumaDigitos, set);

    return set;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    cin >> n;
    if (!std::cin)
        return false;

    cout << n << " "; // imprime primer numero

    Set<int> sol;
    sol.add(n);
    
    resolver(n, sol);

    // escribir sol
    if (!sol.contains(1)) cout << 0 << endl;
    else cout << 1 << endl;

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