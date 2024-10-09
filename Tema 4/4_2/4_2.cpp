// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Horas.h"
#include "vector"

// función que resuelve el problema
int resolver(std::vector<Horas>& datos, Horas hora) {

    //Tenemos que buscar el tren siguiente más cercano
    //Podemos hacerlo facilmente lineal con un while

    int i = 0;
    while (i < datos.size() && datos[i] < hora) i++;

    if (i == datos.size()) return -1;
    else return i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    int h = 0;

    Horas horas;
    int min = 0;
    int seg = 0;
    std::vector<Horas> horario;

    std::cin >> n >> h;

    if (n == 0 && h == 0)
        return false;

    //Rellenamos el horario de trenes
    for (int i = 0; i < n; i++) {
        std::cin >> horas;

        horario.push_back(horas);
    }

    //vemos que horas tenemos que comprobar
    for (int i = 0; i < h; i++) {

        try {
            std::cin >> horas;

            //Haremos resolver el número de veces de horario que vamos a comprobar
            int sol = resolver(horario, horas);

            //escribir solucion

            //Si devuelve -1 es que no hay
            if (sol == -1) std::cout << "NO" << std::endl;
            else std::cout << horario[sol] << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
        catch (...) {
            std::cout << "ERROR" << std::endl;
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
