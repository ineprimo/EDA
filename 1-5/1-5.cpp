// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <fstream>
//#include <vector>
using namespace std;

// complejidad constante (26, explicado en clase), cuenta cada aparición de cada letra

bool anagramas(const string& cad1, const string& cad2) {
    bool anagrama = false;
    int alfa1[26]{ 0 };
    int alfa2[26]{ 0 };

    for (unsigned int i = 0; i < cad1.length(); i++)
        alfa1[toupper(cad1[i]) - 65]++;

    for (unsigned int i = 0; i < cad2.length(); i++)
        alfa2[toupper(cad2[i]) - 65]++;

    unsigned int j = 0;
    while (j < 26 && alfa1[j] == alfa2[j])
        j++;

    if (j == 26)
        anagrama = true;

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
