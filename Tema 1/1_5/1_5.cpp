// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

#pragma region Coste del algoritmo

///
///
/// La complejidad de "sort" es O(n log n)
/// La complejidad de la comparación de string es O(n)
/// Por lo tanto la complejidad del algoritmo sería O(n log n)
/// 
/// 
#pragma endregion



// función que resuelve el problema
bool resolver(string& p1, string& p2) {

    //Recordatorio de que los strings funcionan como arrays de char
    if (p1.size() != p2.size()) return false;

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    return p1 == p2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    string p1 = "";
    string p2 = "";


    // leer los datos de la entrada
    cin >> p1 >> p2;


    bool sol = resolver(p1, p2);

    // escribir sol
    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;

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