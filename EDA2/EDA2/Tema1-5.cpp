// Andres Garcia Navarro
// EDA - GDV27

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*
//Tiene una complejidad O(n), donde n es el numero de caracteres que tiene cada cadena, 
//ambas cadenas son recorridas completamente y ademas se hace un for con un numero constante
//de iteraciones (26)
bool anagramas(const string& cad1, const string& cad2) {
    vector<int> palabra1(26,0), palabra2(26,0);

    for (char c : cad1)
        palabra1[c - 'a']++;

    for (char c : cad2)
        palabra2[c - 'a']++;

    int j = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if (palabra1[i] == palabra2[i])
        {
            j++;
        }
    }

    return j == 26;
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
}*/