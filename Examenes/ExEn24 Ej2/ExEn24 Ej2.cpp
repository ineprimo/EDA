// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

std::pair<bool, std::pair<int,int>> cruce(const std::vector<int>& ascendente, const std::vector<int>& descendente, int ini, int fin)
{
    int elems = fin - ini;

    // caso base
    if (elems == 1)
    {
        bool cortan = false;

        if (descendente[ini] == ascendente[ini]) cortan = true;

        // se cortan por la izq
        if (descendente[0] < ascendente[0])
        {
            return { false, { -1, 0 } };
        }

        // se cortan por la der
        if (descendente[ascendente.size() - 1] > ascendente[ascendente.size() - 1])
        {
            return { false, { ascendente.size() - 1, ascendente.size() } };
        }

        // si es false nos interesan los dos valores del pair indice si no solo el primero
        return { cortan, {ini, fin} };
    }

    int mit = (ini + fin) / 2;

    // si coinciden en la mitad
    if(descendente[mit] == ascendente[mit])
    {
        return { true, {mit, mit} };
    }
    // mirar izq
    if(descendente[mit] < ascendente[mit])
    {
        return cruce(ascendente, descendente, ini, mit);
    }
    // mirar der
    if(descendente[mit] > ascendente[mit])
    {
        return cruce(ascendente, descendente, mit, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int tam;

    std::cin >> tam;

    if (tam == 0) return false;

    std::vector<int> ascendente(tam);
    std::vector<int> descendente(tam);

    int elem = 0;
    for(int i = 0; i < tam; i++)
    {
        std::cin >> ascendente[i];
    }

    for (int i = 0; i < tam; i++)
    {
        std::cin >> descendente[i];
    }

    const std::pair<bool, std::pair<int, int>> sol = cruce(ascendente, descendente, 0, tam);

    if(sol.first)
    {
        std::cout << "SI" << " " << sol.second.first << std::endl;
    }
    else
    {
        std::cout << "NO" << " " << sol.second.first << " " << sol.second.second << std::endl;
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
    //system("PAUSE");
#endif

    return 0;
}