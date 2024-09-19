// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
/*
// función que resuelve el problema
bool resolver(std::vector<int>& vect, int p) {
    int maxIzq = vect[p], minDer = vect[vect.size() - 1];

    if (p == vect.size() - 1) return true;

    for (size_t i = 0; i < vect.size(); i++)
    {
        if (i <= p) {
            if (vect[i] > maxIzq)
                maxIzq = vect[i];
        }
        else {
            if (vect[i] < minDer)
                minDer = vect[i];
        }
    }
    return maxIzq < minDer;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    //variabes locales
    int size, p, dato;
    std::vector<int> vect;

    // leer los datos de la entrada
    std::cin >> size >> p;

    for (int i = 0; i < size; i++)
    {
        std::cin >> dato;
        vect.push_back(dato);
    }

    // escribir sol
    if (resolver(vect, p))
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;


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
}*/