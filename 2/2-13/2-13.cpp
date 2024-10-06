// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int>& v, int ini, int fin)
{
    int elems = fin - ini;

    if (elems == 0) return ini; // caso base / solo un elemento
    if (elems == 1)
    {
        if (v[ini] != v[ini + 1]) return ini;
    }

    if ((fin == v.size()-1) && v[fin] != v[fin - 1]) return fin; // si es fin del vector

    int mit = (ini + fin) / 2;

    // -> buscar por la pos de la pareja de mit

    if (v[mit - 1] == v[mit])
    {
        // si la pareja esta a la izq y el indice es impar es que esta a la der
        if(mit % 2 != 0) 
        {
            return resolver(v, mit, fin);
        }
        // si la pareja esta a la izq y el indice es par es que esta a la izq
        return resolver(v, ini, mit);
    }
    if (v[mit + 1] == v[mit])
    {
        // si la pareja esta a la der y el indice es par es que esta a la der
        if (mit % 2 == 0)
        {
            return resolver(v, mit, fin);
        }
        // si la pareja esta a la izq y el indice es impar es que esta a la izq
        return resolver(v, ini, mit);
    }
    // si no tiene pareja ni a la izq ni a la der es que es ese
    return mit;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int& e : v) std::cin >> e;

    // Llamada a la función resolver
    int pos = resolver(v, 0, v.size() - 1);

    // Mostrar el resultado
    std::cout << pos << std::endl;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}