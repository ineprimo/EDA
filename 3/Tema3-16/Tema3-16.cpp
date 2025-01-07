

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct Cancion {
    int duracion;
    int puntos;
};


void updateCinta(vector<Cancion> cinta, int i, int k, const vector<Cancion>& canciones, int& espacioCinta) {
    // la mete y la marca como usada
    cinta[k] = canciones[i];

    // la duracion actual se actualiza
    espacioCinta += canciones[i].duracion;
}


void desmarcarCinta(vector<Cancion> cinta, int i, int k, const vector<Cancion>& canciones, int& espacioCinta) {

    // la duracion actual se actualiza
    espacioCinta -= canciones[i].duracion;
}


void resolver(pair<vector<Cancion>, vector<Cancion>>& sol, pair<vector<Cancion>, vector<Cancion>>& mejorSol, const vector<Cancion>& canciones, int k, int duracion,
    pair<int, int>& espacioCinta, pair<bool, bool> cintaUsada, vector<bool> cancionesUsadas, int& rizz, int& mejorRizz) {

    //

    for (int i = 0; i < canciones.size(); i++) {

        // si la cancion no ha sido usada
        if(!cancionesUsadas[i]) {
            bool first = espacioCinta.first + canciones[i].duracion <= duracion;
            bool second = espacioCinta.second + canciones[i].duracion <= duracion;

            // si la primera cara no esta llena
            if ( first || second) {

                if (first) {
                    // actualiza la primera cinta
                    updateCinta(sol.first, i, k, canciones, espacioCinta.first);
                }
                else if (second) {
                    // actualiza la primera cinta
                    updateCinta(sol.second, i, k, canciones, espacioCinta.second);
                }

                // la cancion se marca
                cancionesUsadas[i] = true;

                // se aumenta la puntuacion
                rizz += canciones[i].puntos;

                // si es solucion
                if ((cintaUsada.first && cintaUsada.second)) {
                    if (rizz > mejorRizz) {
                        mejorRizz = rizz;
                        mejorSol = sol;
                    }
                }
                else {
                    // poda

                    // backtracking
                    resolver(sol, mejorSol, canciones, k + 1, duracion, espacioCinta, cintaUsada, cancionesUsadas, rizz, mejorRizz);

                }

                // desmarca todo
                if (first) {
                    desmarcarCinta(sol.first, i, k, canciones, espacioCinta.first);
                }
                else if (second) {
                    desmarcarCinta(sol.second, i, k, canciones, espacioCinta.second);
                }

                // la cancion se marca
                cancionesUsadas[i] = false;

                // se aumenta la puntuacion
                rizz -= canciones[i].puntos;
            }
        }

        


    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, duracion;
    cin >> n; 

    if (n == 0) return false;

    cin >> duracion;
    vector<int> soluc(n);
    vector<Cancion> canciones(n);

    for (int i = 0; i < n; ++i)
        cin >> canciones[i].duracion >> canciones[i].puntos;

    // tupla solucion: 
    pair<vector<Cancion>, vector<Cancion>> sol(n, n);
    pair<vector<Cancion>, vector<Cancion>> mejorSol;
    pair<bool, bool> cintaUsada(false, false); 
    vector<bool> cancionesUsadas(false);


    int rizz = 0;
    int mejorRizz = 0;
    pair<int, int> espacioCinta(0,0);

    resolver(sol, mejorSol, canciones, 0, duracion, espacioCinta, cintaUsada, cancionesUsadas, rizz, mejorRizz);

    cout << mejorRizz << endl;

    // Salida
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

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
