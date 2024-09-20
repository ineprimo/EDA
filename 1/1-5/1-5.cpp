// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <fstream>
#include <vector>
#include <array>

// Complejidad: lineal O(n), n iteraciones del bucle for en funcion de la
// longitud de la palabra
bool anagramas(const std::string& cad1, const std::string& cad2)
{
    // primero comprobamos que las dos cadenas tengan el mismo tamaño
    // ya que si no lo tienen no pueden ser anagramas
    if (cad1.size() != cad2.size()) return false;

    // hacemos dos abecedarios auxiliares para llevar el registro
    // de que y cuantas letras hay por palabra
    std::vector<int> abecedario1(26);
    std::vector<int> abecedario2(26);

    // recorremos las cadenas
    for(int i = 0; i < cad1.size(); i++)
    {
        // incrementamos el contador en la posicion del abecedario
        // correspondiente a la letra que estamos evaluando
        // sabemos que posicion ocupa en el abecedario (a->z, 0->25)
        // haciendo la conversion de char a int
        abecedario1[toupper(cad1[i]) - 65]++;
        abecedario2[toupper(cad2[i]) - 65]++;
    }

    // si una a una las posiciones del vector son iguales
    // significa que es una cadena y otra tienen las mismas letras
    // el mismo numero de veces por lo que sera anagrama
    return abecedario1 == abecedario2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    std::string word1, word2;
    std::cin >> word1 >> word2;
    std::cout << (anagramas(word1, word2) ? "SI" : "NO") << std::endl;
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