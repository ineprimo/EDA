// Paula Sierra Luque
// GDV-EDA70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& datos, int ini, int fin) 
{
    if (fin == ini) return datos[ini]; // 1 elem
    if (fin - ini == 1)  return min(datos[ini], datos[fin]); // 2 elem
    
    int mitad = (fin + ini) / 2;

    if (datos[mitad] < datos[mitad + 1])  
    {
        return datos[mitad];
    }

    if (datos[ini] < datos[mitad]) 
        return resolver(datos, ini, mitad);;

    return resolver(datos, mitad + 1, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    vector<int> numeros;
    for (int i = 0; i < n; ++i)
    {
        int aux; cin >> aux;
        numeros.push_back(aux);
    }

    int sol = resolver(numeros, 0, n-1);

    // escribir sol
    cout << sol << endl;

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