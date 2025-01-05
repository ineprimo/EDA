// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void resolver(vector<int>& datos) {

    if (0) {
        escribePolidivisibles()
    }
    else if () {

    }

}

void escribePolidivisibles(long long raiz, int maxDigitos) {

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos(2);
    // Datos[0] --> N  //  Datos[1] --> D
    cin >> datos[0] >> datos[1];
    
    if (!std::cin)
        return false;

    resolver(datos);

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