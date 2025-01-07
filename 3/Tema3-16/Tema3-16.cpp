

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct Cancion {
    int duracion;
    int puntos;
};


void updateCinta(vector<Cancion>& cinta, const int i, const int k, const vector<Cancion>& canciones, int& espacioCinta) {
    // la mete y la marca como usada
    cinta[k] = canciones[i];

    // la duracion actual se actualiza
    espacioCinta += canciones[i].duracion;
}


void desmarcarCinta(vector<Cancion> cinta, const int i, const int k, const vector<Cancion>& canciones, int& espacioCinta) {

    // la duracion actual se actualiza
    espacioCinta -= canciones[i].duracion;
}


void resolver(vector<vector<int>>& sol, vector<vector<int>>& mejorSol, const vector<Cancion>& canciones, int k, const int duracion,
    vector<int>& espacioCinta, vector<bool>& cancionesUsadas, int& rizz, int& mejorRizz) {

    // i cancion
    // k cinta

    for (int i = 0; i < canciones.size(); i++) {

        // si la cancion no ha sido usada
        if(!cancionesUsadas[i]) {

            // la mete y la marca como usada
            sol[k][i] = canciones[i].puntos;

            // la duracion actual se actualiza
            espacioCinta[k] += canciones[i].duracion;

            // la cancion se marca
            cancionesUsadas[i] = true;

            // se aumenta la puntuacion
            rizz += canciones[i].puntos;

            // si la cinta cara no esta llena
            if (espacioCinta[k] <= duracion) {
                // si es solucion
                if (k == 1) {
                    if (rizz > mejorRizz) {
                        mejorRizz = rizz;
                        mejorSol = sol;
                    }
                }
                else {
                    // poda

                    // backtracking
                    resolver(sol, mejorSol, canciones, k + 1, duracion, espacioCinta, cancionesUsadas, rizz, mejorRizz);

                }
            }

            // la mete y la marca como usada
            sol[k][i] = 0;

            // la duracion actual se actualiza
            espacioCinta[k] -= canciones[i].duracion;

            // la cancion se marca
            cancionesUsadas[i] = false;

            // se aumenta la puntuacion
            rizz -= canciones[i].puntos;
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
    int cinta = 2;

    // tupla solucion: 
    vector<vector<int>> sol(cinta, vector<int>(n));
    vector<vector<int>> mejorSol(cinta, vector<int>(n));
    vector<bool> cancionesUsadas(n);


    int rizz = 0;
    int mejorRizz = 0;
    vector<int> espacioCinta(cinta);

    resolver(sol, mejorSol, canciones, 0, duracion, espacioCinta, cancionesUsadas, rizz, mejorRizz);
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
