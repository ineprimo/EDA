// Paula Sierra Luque
// GDV-EDA70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int, int> resolver(const vector<int>& asc, const vector<int>& desc, int ini, int fin)
{
    if (ini == fin)
    {
        if (asc[ini] == desc[ini]) return { ini, ini };

        // si el valor asc en un punto es mayor que el valor desc en ese mismo, significa
        // que las lineas ya se habran cruzado
        if (asc[ini] > desc[ini]) return { ini - 1, ini };
        else return { ini, ini + 1 };
    }

    int mitad = (fin + ini) / 2;

    if (asc[mitad] == desc[mitad]) return { mitad, mitad };

    if (asc[mitad] > desc[mitad])
        return resolver(asc, desc, ini, mitad);
    else return resolver(asc, desc, mitad + 1, fin);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> f, g;
    int aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        f.push_back(aux);
    }
    for (int i = 0; i < n; i++) {
        cin >> aux;
        g.push_back(aux);
    }

    pair<int, int> sol = resolver(f, g, 0, n-1);

    // escribir sol
    if (sol.first == sol.second) {
        cout << "SI " << sol.first << endl;
    }
    else {
        cout << "NO " << sol.first << " " << sol.second << endl;
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
