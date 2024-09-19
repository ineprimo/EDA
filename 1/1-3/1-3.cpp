// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> datos, int p)
{
    if (p >= datos.size() - 1 || p < 0) return true;

    // basta con saber si la posicion mas alta de la parte de izq es
    // estrictamente menor que la menor de la parte mas alta

    int max = datos[0];

    for(int i = 1; i <= p; i++)
    {
	    if(max < datos[i])
	    {
            max = datos[i];
	    }
    }

    int min = datos[p + 1];

    for(int i = p + 2; i < datos.size(); i++)
    {
        if (min > datos[i])
        {
            min = datos[i];
        }
    }

    return max < min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    std::vector<int> datos;
    int num = 0;
    int p = 0;
    int temperaturas = 0;

    std::cin >> num >> p;

    for(int i = 0; i < num; i++)
    {
        std::cin >> temperaturas;
        datos.push_back(temperaturas);
    }

    bool sol = resolver(datos, p);

    // escribir sol
    if(sol)
    {
        std::cout << "SI" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
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