// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void funcAux(int num, int& ac) {
    // caso base -> solo hay 1 digito
    if (num < 10) {
        
    }
    // caso recursivo -> el numero es mayor que 10
    else if (num >= 10) {
        
    }
}


vector<int> resolver(int n) { // funcion principal
    vector<int> sol;

    int acumulador = 0;
    //funcAux(?¿, acumulador);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    // resuelvo
    vector<int> sol = resolver(num);

    // escribir sol
    cout << sol[0] << " " << sol[1] << endl;


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