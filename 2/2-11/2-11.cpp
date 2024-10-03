/*
Nombre completo: Nieves Alonso Gilsanz
DNI: 54696982S
Usuario del juez: EDA-GDV03
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Divide y vencerás. Búsqueda binaria, complejidad -> O(log(n)) siendo n el tamaño del vector
char resolver(const std::vector<char>& sec, int ini, int fin, char prim, char ult)
{
    int elems = (fin - ini);

    if (elems == 0) return '0'; // caso base / no hay presos en el recuento
    if (elems == 1)
    {
        if (sec[ini] != prim) // caso base
        {
            return sec[ini] - 1;
        }
        return sec[ini] + 1;
    }

    if (sec[ini] != prim)  return prim;
    if (sec[fin - 1] != ult) return ult;

    int mit = (ini + fin) / 2;
    char charMit = prim + (mit - ini);

    // si el que está a la mitad es igual que el que debería estar -> buscar derecha
    if (sec[mit] == charMit)
    {
        return resolver(sec, mit, fin, charMit, ult);  
    }
    else  // la mitad izq está ordenada -> busca izq
    {
        return resolver(sec, ini, mit, prim, charMit);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    char prim, ult, n;

    std::cin >> prim >> ult;

    n = ult - prim;

    std::vector<char> sec(n);

    for (char& e : sec) std::cin >> e;

    int i = 0;

    int f = sec.size();

    std::cout << resolver(sec, i, f, prim, ult) << std::endl;
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