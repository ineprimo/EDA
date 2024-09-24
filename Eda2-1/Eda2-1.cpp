// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(int N, int D) {
    
    if (D == 0) return 1;
    return resolver(N, D - 1);
    //miro 2016 4; 201 3; 20 2; 2, 1


}
void escribePolidivisibles(long long raiz, int maxDigitos) {

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int poli;
    cin >> poli;

    int dig;
    cin >> dig;

    if (!std::cin)
        return false;

    int sol = resolver(poli, dig);

    // escribir sol
    // escribo vector de polidivisibles
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    cout << "---" << endl;

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