// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Horas.h"

// función que resuelve el problema
void resolver(std::vector<Horas> horario, Horas consultada) {
    //mirar si consultada esta en el horario, y si hay alguna menor que, ponerla a encontrada
    int i = 0;
    bool encontrada = false;
    while (i < horario.size() && !encontrada) 
    {
        if (!(horario[i] < consultada)) {
            encontrada = true;
            std::cout << horario[i] << std::endl;
        }
        i++;
    }
    if (!encontrada) std::cout << "NO" << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numTrenes, numConsultas;
    std::cin >> numTrenes >> numConsultas;

    if (numTrenes == 0 && numConsultas == 0)
        return false;

    std::vector<Horas> horario;
    for (int i = 0; i < numTrenes; i++) 
    {
        Horas h;
        std::cin >> h;

        horario.push_back(h);
    }

    for (int i = 0; i < numConsultas; i++){
        Horas h;

        // escribe sol
        try {
            std::cin >> h;
            resolver(horario, h);
        }
        catch (std::invalid_argument& a) 
        {
            // devuelve "ERROR"
            std::cout << a.what() << std::endl; 
        }
    }

    std::cout << "---" << std::endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
