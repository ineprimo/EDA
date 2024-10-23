// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>



// función que resuelve el problema
bool resolver(std::string datos) {

    //Creamos la pila
    std::stack <char> pila;

    //Recorremos la linea
    for (char c : datos) {

        //Si es una abertura lo ponemos en la pila si o si
        if (c == '[' || c == '{' || c == '(') {
            pila.push(c);
        }
        //Con el resto de casos diferenciamos

        else if (c == ']') {
            if (!pila.empty() && pila.top() == '[') pila.pop();  //Ya esta emparejado
            else pila.push(c);
        }
        else if (c == '}') {
            if (!pila.empty() && pila.top() == '{') pila.pop();  //Ya esta emparejado
            else pila.push(c);
        }
        else if (c == ')') {
            if (!pila.empty() && pila.top() == '(') pila.pop();  //Ya esta emparejado
            else pila.push(c);
        }
    }

    //Si esta vacía se han emparejado todosN
    return pila.empty();    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    std::string linea;
    std::getline(std::cin, linea);

    if (!std::cin)
        return false;

    bool sol = resolver(linea);

    // escribir sol
    if (sol) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;

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