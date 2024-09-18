// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> datos)
{
    int i = 0;
    bool ordenadoMenMay = true;
    bool ordenadoMayMen = true;

    while((i < datos.size() - 1) && (ordenadoMenMay || ordenadoMayMen))
    {
        if(datos[i] >= datos[i + 1])
        {
            ordenadoMenMay = false;
        }

        if (datos[i] <= datos[i + 1])
        {
            ordenadoMayMen = false;
        }

        i++;
    }

    return ordenadoMenMay || ordenadoMayMen;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    std::vector<int> datos;
    int pjs; // numero de personajes en viñeta
    int alturas; // alturas de cada pj

    std::cin >> pjs;

    if (pjs == 0) // cuando lea 0 se para
        return false;

    // recorremos cada altura de cada personaje y la metemos en el vector datos
    for (int i = 0; i < pjs; i++)
    {
        std::cin >> alturas;
        datos.push_back(alturas);
    }

    bool sol = resolver(datos); // guarda en sol si es DALTON o DESCONOCIDOS

    // escribir sol
    if(sol) // si sol es true -> DALTON
    {
        std::cout << "DALTON" << std::endl;
    }
    else // si sol es false -> DESCONOCIDO
    {
        std::cout << "DESCONOCIDOS" << std::endl;
    }

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