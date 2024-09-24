// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema

// recibe int y devuelve numero formado por digitos complementarios
//  123 -> 876
int complementario(const int& num) {
    int comp = 0;
    int offset;
    // caso base -> solo hay 1 digito
    if (num < 10) {
        comp = 9 - num;
    }
    // caso recursivo -> el numero es mayor que 10
    else if (num >= 10) {
        comp = complementario(num / 10);
        offset = 9 - num % 10;
    }
    
    return comp;
}

vector<int> vectComp(int n) {
    vector<int> a;
    a.push_back(n);

    return a;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;


    int sol = complementario(num);
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