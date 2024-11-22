// Nieves Alonso Gilsanz

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

using Pelicula = string;
using Peliculas = map<Pelicula, int>; // pelicula y las veces que se repiten
using Nombre = string;
using Actor = pair<string, float>;    // nombre, min por peli
using Actores = map<string, float>;   // nombre, min totales
using RepartosPeliculas = map<Pelicula, vector<Actor>>;

// Complejidad: lineal O(n) siendo n el num de palabras del txt
void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) 
{
    Pelicula peli;  // titulo
    int numActores; // num de actores por peli

    Actor actor;    // nombre de actor y minutos

    vector<Actor> actores; // vector auxiliar de actores

    for (int i = 0; i < numPeliculas; ++i) 
    {
        cin >> peli; cin >> numActores;
        
        for (int j = 0; j < numActores; ++j) 
        {
            cin >> actor.first >> actor.second;
            actores.push_back(actor);
        }

        peliculas.insert({ peli,actores }); // llena map
    }
}

// calcula la informacion solicitada a partir de RepartosPeliculas 
// SALIDA:
// linea 1) el max num de veces que se ha emitido una peli + " " + titulo de la peli
// (si varias pelis que se han emitido el mismo num max de veces, se muestra la ultima emitida)
// linea 2) el max tiempo que ha aparecido un actor en pantalla + " " + actores que han aparecido ese tiempo max en orden alfabetico

// Complejidad: 
void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) 
{
    // ---- pelis y num de emisiones
    Peliculas pelis;
    for (int i = 0; i < secEmisiones.size(); ++i)
    {
        if (!pelis.count(secEmisiones[i]))
        {
            pelis.insert({secEmisiones[i], 1});
        }
        else 
        {
            pelis[secEmisiones[i]]++;
        }
    }

    // ---- num max de emisiones de una misma peli
    int maxPeli = 0; // mayor num de veces de emisiones de una misma peli
    Pelicula maxPeliTit;
    auto itP = pelis.begin();
    while (itP != pelis.end()) 
    {
        if (pelis[maxPeliTit] < itP->second)
        {
            maxPeli = itP->second;
            maxPeliTit = itP->first;
        }
        itP++;
    }

    // ---- actores
    Actores actores;
    auto itA = actores.begin();

    for (int i = 0; i < secEmisiones.size(); i++)
    {
        vector<Actor> vec = (*repartos.find(secEmisiones[i])).second;

        for (auto v : vec)
        {
            if (!actores.count(v.first))
            {
                actores.insert({ v.first , v.second}); // mete al actor
            }
            else
            {
                actores[v.first] += v.second; // suma minutos al actor
            }
        }
    }

    // ---- num max de minutos
    float maxActor = 0; // num max de min de un actor
    vector<Nombre> vecNom; // vector de actores con el num max de minutos
    itA = actores.begin();
    while (itA != actores.end())
    {
        if (maxActor < itA->second) 
        {
            vecNom.clear();
            maxActor = itA->second;
            vecNom.push_back(itA->first);
        }
        else if (maxActor == itA->second)
        {
            vecNom.push_back(itA->first);
        }

        itA++;
    }

    // ---- salida
    cout << maxPeli << " " << maxPeliTit << endl;
    cout << maxActor << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}

//#define DOMJUDGE
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
#endif

    return 0;
}