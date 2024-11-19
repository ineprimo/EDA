#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int maxDias(vector<int>& datos) {
    //Hacemos un mapa que guarde el capitulo y el indice en el que se encuentra
    map <int, int> caps;
    int maxD = 0;
    int cont = 0;
    int i = 0;

     while (i < datos.size()) {

        //Buscamos el dato actual en el mapa
        auto it = caps.find(datos[i]);

        if (it == caps.end()) {
            //Nos guardamos los datos en el mapa
            caps.insert({ datos[i], i });
        }
        else {

            //Cuando el dato ya se encuentra en el mapa
            //El capitulo se esta repitiendo
            //La cadena se rompe por lo que debe empezar de nuevo
            //Desde el numero que se ha repetido original +1 hasta el numero actual lo añadimos al mapa
            if (caps.size() > maxD) maxD = caps.size();
            i = it->second;
            caps.clear();
        }
        i++;
     }

     if (caps.size() > maxD) maxD = caps.size();


    return maxD;
}

void resuelveCaso() {

    //Leemos los datos de entrada
    int n = 0;
    int d = 0;
    cin >> n;

    vector<int> datos;

    for (int i = 0; i < n; i++) {
        cin >> d;
        datos.push_back(d);
    }
   
    int sol = maxDias(datos);

    //Escribimos la solucion
    cout << sol << endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; char c;
    std::cin >> numCasos;
    cin.get(c);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
