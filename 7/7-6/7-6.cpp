// Nieves Alonso Gilsanz

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

using Pelicula = string;
using Peliculas = map<Pelicula, pair<int, int>>; // pelicula y las veces que se repiten y la antiguedad
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

    for (int i = 0; i < numPeliculas; ++i) 
    {
		vector<Actor> actores; // vector auxiliar de actores
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

// Complejidad: N*(logP+logA)+A*logA
// N -> num de peliculas emitidas en total (tam secEmisiones)
// P -> num de peliculas ofertadas
// A -> num de actores en plantilla
void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) 
{
    // ---- pelis y num de emisiones
    Peliculas pelis;
    for (int i = 0; i < secEmisiones.size(); ++i)
    {
        if (!pelis.count(secEmisiones[i]))
        {
            pelis.insert({secEmisiones[i], {1, i}});
        }
        else 
        {
            pelis[secEmisiones[i]].first++;
            pelis[secEmisiones[i]].second = i;
        }
    }

    // ---- num max de emisiones de una misma peli
    int maxPeli = 0; // mayor num de veces de emisiones de una misma peli
    Pelicula maxPeliTit;
    auto itP = pelis.begin();
    while (itP != pelis.end()) 
    {
        if ((pelis[maxPeliTit].first < itP->second.first) || (pelis[maxPeliTit].first == itP->second.first && itP->second.second > pelis[maxPeliTit].second))
        {
            maxPeli = itP->second.first;
            maxPeliTit = itP->first;
        }
        itP++;
    }

    // ---- actores
    Actores actores;

    auto itA = actores.begin();
    for (int i = 0; i < secEmisiones.size(); ++i)
    {
        vector<Actor> vec = repartos.find(secEmisiones[i])->second;

        for (int j = 0; j < vec.size(); j++)
        {
            if (!actores.count(vec[j].first))
            {
                actores.insert({ vec[j].first , vec[j].second }); // mete al actor
            }
            else
            {
                actores[vec[j].first] += vec[j].second; // suma minutos al actor
            }
        }
    }

    // ---- num max de minutos
    int maxActor = 0; // num max de min de un actor
    vector<Nombre> vecNom; // vector de actores con el num max de minutos
    itA = actores.begin();
    for (auto a : actores)
    {
        if (itA->second > maxActor)
        {
            maxActor = itA->second;
        }
        itA++;
    }

    itA = actores.begin();
    for (auto a : actores)
    {
        if (itA->second == maxActor)
        {
            vecNom.push_back(itA->first);
        }
        itA++;
    }

    sort(vecNom.begin(), vecNom.end());

    // ---- salida
    cout << maxPeli << " " << maxPeliTit << endl;
    cout << maxActor << " ";

    for(int i = 0; i < vecNom.size(); i++)
    {
        cout << vecNom[i] << " ";
    }
    cout << endl;
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