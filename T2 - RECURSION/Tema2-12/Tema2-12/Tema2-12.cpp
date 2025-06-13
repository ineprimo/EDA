// Paula Sierra Luque
// EDA-GDV70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> datos, vector<int> other, int ini, int fin) 
{
    if (ini == fin) return datos[ini];

    // mas de dos elems
    int mitad = (ini + fin) / 2;

    if (datos[mitad] == other[mitad])
        return resolver(datos, other, mitad+1, fin);
    else 
        return resolver(datos, other, ini, mitad);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;
    
    vector<int> og, other; 
    int aux;
    for (int i = 0; i < n; ++i)
    {
        cin >> aux;
        og.push_back(aux);
    }
    for (int i = 0; i < n-1; ++i)
    {
        cin >> aux;
        other.push_back(aux);
    }

    int sol = resolver(og, other, 0, n-1);
    
    // escribir sol
    cout << sol << endl;
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