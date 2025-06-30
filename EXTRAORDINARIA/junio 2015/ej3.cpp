/*
/*
Nombre completo: Nieves Alonso Gilsanz
DNI: 54696982S
Usuario del juez: 03
Puesto de laboratorio: pto 02 lab 1
Qué has conseguido hacer y qué no: eliminaKMenores para el mapa ordenado, 
                                    eliminaKMenores para el mapa desordenado cuando k >= map.size(),
                                    la salida por consola para ambos mapas

Cuestión extra: ¿Cuál sería la menor complejidad en tiempo que podría tener una función que elimine los k pares clave-valor con menor valor para cada caso (map y unordered_map)? Justifica tu respuesta.
Si tenemos en cuenta la comprobacion inicial que vacie los mapas en caso de pasarnos de k que hace cuello de botella, en ambos casos
la mejor complejidad sera lineal para el tamaño de cada mapa O(n) siendo n el tamaño
Sin tener en cuenta esto (en los casos en los que no se pase k) para el mapa ordenado, al estar ordenado,
con eliminar los primeros dentro de un rango lo mejor es log(n + la distancia entre el primero y el ultimo);
para el mapa desordenado 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Complejidad:
template <class K, class V>
void eliminaKMenores(map<K, V>& map, int k) 
{
    if (k >= map.size()) map.clear(); // O(n)

    else 
    {
        auto itPri = map.begin();
        auto itFin = map.begin();

        int i = 0;
        while (itFin != map.end() && i < k) // O(n) en el peor de los casos
        {
            ++itFin;
            ++i;
        }

        map.erase(itPri, itFin); // log(n + (pos fin - pos pri))
    }
}

// Complejidad:
template <class C, class V>
void eliminaKMenores(unordered_map<C, V>& map, int k) 
{
    if (k >= map.size()) map.clear(); // O(n)

    else
    {
        auto itMen = map.begin(); // el que vas comparando
        auto itAct = map.begin(); // para recorrer


    }
}

void resuelveCaso() {
    map<string, int> map1;
    unordered_map<string, int> map2;
    int n, k;

    // Lectura de datos
    cin >> n >> k;
    string clave;
    int valor;
    for (int i = 0; i < n; ++i) {
        cin >> clave >> valor;
        map1.insert({ clave, valor });
        map2.insert({ clave, valor });
    }

    // Llamada a funciones
    eliminaKMenores(map1, k);
    eliminaKMenores(map2, k);

    // Escritura de la salida

    // Imprimir map1 ordenado por claves -> ordenado
    auto itMap1 = map1.begin();
    while (itMap1 != map1.end()) 
    {
        std::cout << itMap1->first << " " << itMap1->second << "\n";
        ++itMap1;
    }
    cout << "-\n";

    // Imprimir map2 ordenado por claves (para ello debes volcarlo a un vector, ordenarlo e imprimirlo)
    vector<pair<string, int>> vec(map2.size());
    auto itMap2 = map2.begin();
    int i = 0;
    while (itMap2 != map2.end())
    {
        vec[i].first = itMap2->first;
        vec[i].second = itMap2->second;
        ++i;
        ++itMap2;
    }

    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) 
    {
        std::cout << vec[i].first << " " << vec[i].second << "\n";
    }

    cout << "---\n";
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
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