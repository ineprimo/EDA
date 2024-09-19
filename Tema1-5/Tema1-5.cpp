// Daniel Zhu
// EDA-GDV79

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//La complejidad depende del sort, el cual tiene una complejidad de O(n * log(n))
//donde n es el número de elementos que se están ordenando.


bool anagramas(const string& cad1, const string& cad2) {
   
    // Si las longitudes no son iguales, no pueden ser anagramas
    if (cad1.size() != cad2.size()) {
        return false;
    }

    // Creamos strings auxiliares para poder ordenarlas
    string aux1 = cad1;
    string aux2 = cad2;

    sort(aux1.begin(), aux1.end());
    sort(aux2.begin(), aux2.end());

    return aux1 == aux2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string word1, word2;
    cin >> word1 >> word2;
    cout << (anagramas(word1, word2) ? "SI" : "NO") << endl;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}