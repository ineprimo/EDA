// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "stack_eda.h"
//#include <stack>

using namespace std;

// función que resuelve el problema
bool resolver(string dato) {
    stack<char> aux;
    int i = 0;
    //bool feo = false;

    //if (dato.empty()) feo = true;

    while (i < dato.length()) {
        
        if (dato[i] == '(' || dato[i] == '{' || dato[i] == '[') {
            aux.push(dato[i]);
        }
        else if (dato[i] == ')') {
            if (!aux.empty() && aux.top() == '(') aux.pop();
            else aux.push(dato[i]);
        }
        else if (dato[i] == '}') {
            if (!aux.empty() && aux.top() == '{') aux.pop();
            else aux.push(dato[i]);
        }
        else if (dato[i] == ']') {
            if (!aux.empty() && aux.top() == '[') aux.pop();
            else aux.push(dato[i]);
        }
        
        ++i;
    }

    return aux.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    string dato;
    getline(cin, dato);

    if (!std::cin)
        return false;

    bool sol = resolver(dato);

    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;
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