// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//Complejidad del algoritmo
// 
// La complejidad del logaritmo es O(n) siendo n el número de datos
// Ya que se recorre el vector una única vez buscando el faltante
// función que resuelve el problema
char resolver(vector<char>& datos, char ini, char fin) {

    //No sabemos cual es el que falta
    //Comprobamos que el primero y el último sean los correctos

    if (ini != datos[0]) return ini;
    if (fin != datos[datos.size() - 1]) return fin;

    //Hay que buscar el salto que haya
    char i = ini;
    int j = 0;

    while (j < datos.size() && i == datos[j]) {
        i++;
        j++;
    }

    //Diría que siempre falta uno
    return i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char ini = ' ';
    char fin = ' ';
    char letra = ' ';
    vector<char> datos;

    cin >> ini >> fin;

    for (char i = ini; i < fin; i++) {
        cin >> letra;
        datos.push_back(letra);
    }

    char sol = resolver(datos, ini, fin);

    // escribir sol
    cout << sol << endl;

}

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
    system("PAUSE");
#endif

    return 0;
}