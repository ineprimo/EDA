// Javier Tirado Ríos
// GDV-EDA72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "stack_eda.h"

using namespace std;

// función que resuelve el problema
bool resolver(string datos) {
	stack<char> pila;
    for (int i = 0; i < datos.length(); ++i) {
        if (datos[i] == '(' || datos[i] == '[' || datos[i] == '{') {
            pila.push(datos[i]);
        }
        else if (datos[i] == ')') {
            if (!pila.empty() && pila.top() == '(') pila.pop();
            else return false;
        }
        else if (datos[i] == ']') {
            if (!pila.empty() && pila.top() == '[') pila.pop();
            else return false;
        }
        else if (datos[i] == '}') {
            if (!pila.empty() && pila.top() == '{') pila.pop();
            else return false;
        }
    }

	return pila.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string datos;
	getline(cin, datos);

    if (!std::cin)
        return false;

    bool sol = resolver(datos);

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