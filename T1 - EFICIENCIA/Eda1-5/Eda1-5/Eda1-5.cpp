// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
string resolver(const string& pal1, const string& pal2) {
    
    string sol = "SI";

    // si son de distinto tam esq no son anagramas
    if (pal1.size() != pal2.size()) return "NO";

    // auxiliar para contar letras
    vector<int> contador(26, 0);

    // por cada letra en pal1 sumar
    for (char letra : pal1) {
        contador[letra - 'a']++;
    }

    // por cada letra q haya en pal2 restar
    for (char letra : pal2) {
        contador[letra - 'a']--;
    }

    // si es 0 son anagramas
    int i = 0;
    while(sol == "SI" && i < contador.size()){
        if (contador[i] != 0) {
            sol = "NO";
        }
        i++;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string palabra1, palabra2;
    cin >> palabra1 >> palabra2;

    string sol = resolver(palabra1, palabra2);

    // escribir sol
    cout << sol << endl;

    return true;
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