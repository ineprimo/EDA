// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// funcion que resuelve el problema
int resolver(std::vector<int>& vec, int ini, int fin)
{
    int elems = fin - ini;

    if(elems == 1)
    {
        return vec[ini];
    }

    int mit = (ini + fin) / 2;

    int mitElem = vec[0] + mit;

    // izq
    if(vec[mit] != mitElem)
    {
		return resolver(vec, ini, mit);
    }
    // der
    else
    {
        return resolver(vec, mit, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n = 0;
    std::cin >> n;

    std::vector<int> vec(n);

    for(int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }

	int sol = resolver(vec, 0, vec.size());

    // escribir sol
    std::cout << sol << std::endl;
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
    //std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}