// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// funcioon que resuelve el problema
std::vector<int> resolver(std::vector<int> datos)
{
    // recorre el vector de datos 
    for(int i = 0; i < datos.size(); i++)
    {
        // reescribe cada elemento multiplicado x 2
        datos[i] = datos[i] * 2;
    }

    // devuelve el vector solucion
    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// -> esto se va a ejecutar una vez por caso
void resuelveCaso() 
{
    // leer los datos de la entrada
    std::vector<int> datos;
    int elementos;
    int elem;

    // Cada caso tiene dos lineas:
    // La primera tiene un unico entero con el numero elementos de la secuencia de entrada
    std::cin >> elementos;

    // recorres esos elementos
    for(int i = 0; i < elementos; i++)
    {
        // guardas el siguiente elemento del caso en elem
        std::cin >> elem;

        // lo metes en el vector de datos a multiplicar
        datos.push_back(elem);
    }

    // guardas en el sol el vector ya modificado
    std::vector<int> sol = resolver(datos);

    // escribir sol

    for(int i = 0; i < elementos; i++)
    {
        std::cout << sol[i] << " ";
    }

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