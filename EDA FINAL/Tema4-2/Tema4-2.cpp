// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "vector"
#include "Horas.h"


// función que resuelve el problema
void resolver(std::vector<Horas> horario, std::vector<Horas> consultadas)
{
    int j = 0;
    bool encontrado = false;

    for (int i = 0; i < consultadas.size(); ++i) {
        while (j < horario.size() && !encontrado) {
            if (consultadas[i] < horario[j] || consultadas[i] == horario[j]) {
                encontrado = true;
                std::cout << horario[j] << std::endl;
            }
            ++j;
        }
        if (!encontrado) std::cout << "NO" << std::endl;
    }
    std::cout << "---" << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int trenes;
    int horas;
    std::cin >> trenes >> horas;

    if (trenes == 0 && horas == 0)
        return false;

    std::vector<Horas> horario;
    std::vector<Horas> horasConsultadas;

    for (int i = 0; i < trenes; ++i) {
        Horas h = Horas();
        std::cin >> h;
        horario.push_back(h);
    }

    for (int i = 0; i < horas; ++i) {
        
        try
        {
            Horas h = Horas();
            std::cin >> h;
            horasConsultadas.push_back(h);
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
        catch (...) {
            std::cout << "ERROR" << std::endl;
        }
    }

    resolver(horario, horasConsultadas);

    // escribir sol

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
