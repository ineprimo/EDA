// Javier Tirado Ríos
// EDA-GDV72

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// La complejidad es de O(n)
bool anagramas(const string& cad1, const string& cad2) {

    if (cad1.size() != cad2.size()) {
        return false;
    }

    // 0 de todas las letras
    vector<int> letras(26, 0);

    // Pos 0 para "a", 1 para "b".....
    for (int i = 0; i < cad1.size(); ++i) {
        letras[cad1[i] - 'a']++;    // Offset de ASCII para el vector de letras
        letras[cad2[i] - 'a']--;
    }

    // Comprobar que todas las letras estan a 0
    for (int i = 0; i < 26; ++i) {
        if (letras[i] != 0) {
            return false;
        }
    }

    return true;
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