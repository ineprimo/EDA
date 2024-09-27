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
char resolver(vector<char>& datos, char ini, char fin, int emp, int acb) {

    //No sabemos cual es el que falta
    if (ini == fin) { return fin++; }

    //Comprobamos que el primero y el último sean los correctos

    if (ini != datos[emp]) return ini;
    if (fin != datos[acb]) return fin;

    if (acb - emp == 1) {

        ini++;
        if (ini == fin) return ' ';
        else return ini;
        
        /*if (ini < fin) return ' ';
        else if (ini != datos[emp]) return ini;
        else return fin;*/
    }
    

    //Buscamos la mitad
    char mid = (ini + fin) / 2;
    int index = emp + (datos.size() / 2);

    
    //Comprobamos que el valor central no es el que estamos buscando
    if (datos[index] == mid) {

        char der = resolver(datos, mid + 1, fin, index + 1, acb);
        return der;

    }
    else {
        char izq = resolver(datos, ini, mid, emp, index - 1);
        return izq;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char ini = ' ';
    char fin = ' ';
    char letra = ' ';
    int emp = 0;
    int acb;
    vector<char> datos;

    cin >> ini >> fin;

    for (char i = ini; i < fin; i++) {
        cin >> letra;
        datos.push_back(letra);
    }

    acb = datos.size() - 1;
    char sol = resolver(datos, ini, fin, emp, acb);

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