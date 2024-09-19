// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <utility>

// función que resuelve el problema
std::pair<int,int> resolver(std::vector<int> datos)
{
    std::pair<int, int> salida = { 0, 0 };

    for(int i = 1; i < datos.size() - 1; i++) // va de 1 a size-1 para no salirse
    {
        // es pico
	    if(datos[i] > datos[i + 1] && datos[i] > datos[i - 1])
	    {
            salida.first += 1;
	    }
        // es valle
        else if(datos[i] < datos[i + 1] && datos[i] < datos[i - 1])
        {
            salida.second += 1;
        }
    }

    return salida;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    std::vector<int> datos;
    int num = 0;
    int temperaturas = 0;

    std::cin >> num;

    for(int i = 0; i < num; i++)
    {
        std::cin >> temperaturas;
        datos.push_back(temperaturas);
    }

    std::pair<int, int> sol = resolver(datos);

    // escribir sol
    std::cout << sol.first << " " << sol.second << std::endl;
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