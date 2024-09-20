#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Este algoritmo tiene coste lineal, porque a más letras tengan las palabras a analizar, se mantendrá de forma directamente proporcional la duración del algoritmo

bool anagramas(const string& cad1, const string& cad2) {
    
    bool anagrama = false;
    string palabra = cad2;

    for (int i = 0; i < cad1.length(); i++) {
        int j = 0;
        //Vamos a buscar las letras de cad1 en cad2 
        while (j < palabra.length() && palabra[j] != cad1[i]) {
            
            j++;
        }

        //Si la encuentra la borra, y resetea la búsqueda
        if (palabra[j] == cad1[i] && palabra.length() > 1) {
            palabra.erase(palabra.begin()+j);
        }
        else if (palabra[j] == cad1[i] && palabra.length() == 1)
        {
            anagrama = true;
        }

    }

    return anagrama;
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