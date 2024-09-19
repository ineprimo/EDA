// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <vector>


// función que resuelve el problema
// complejidad lineal ya que depende de la longitud de las palabras que se comparen
bool resolver(const std::string w1, const std::string w2) {
    bool anagramas = false;

    // si no son igual de largas ya esta
    if (w1.size() != w2.size())
        return anagramas;


    std::vector<int> p1(26);
    std::vector<int> p2(26);

    // recuento de las letra que tiene cada palabra en un array,
    // si los arrays son iguales son anagramas
    for (int i = 0; i < w1.size(); i++) {

        // toupper para hacerlas mayusculas y que funquen los codigos <3
        int a = toupper(w1[i]) - 65;
        int b = toupper(w2[i]) - 65;

        p1[a]++;
        p2[b]++;
    }

    anagramas = (p1 == p2);

    return anagramas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string word1, word2;
    std::cin >> word1;
    std::cin >> word2;

    bool sol = resolver(word1, word2);
    // escribir sol

    if (sol)
        std::cout << "SI";
    else
        std::cout << "NO";
    std::cout << std::endl;

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