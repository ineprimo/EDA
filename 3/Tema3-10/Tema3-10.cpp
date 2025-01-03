
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



void resolver(vector<int>& sol, const int n, const int k, vector<int>& estimacionOptimista, vector<int>&regalosDados, const vector<vector<int>>& regalos,
    int valor, int& mejorValor, vector<int>& mejorSol) {

    // k son los chavales

    for (int i = 0; i < n; i++) {
        // se añade un regalo a la solucion
        sol[k] = regalos[k][i];

        if (regalosDados[i] == -1) {     // valida si ese chaval tiene regalo o no
            // marca el regalo y suma al valor la felicidad
            valor += sol[k];
            regalosDados[i] = k;

            if (k == sol.size() - 1) {       // si se ha completado sol
                // mira si es mejor solucion que la que ya hay
                if (valor > mejorValor) {
                    mejorValor = valor;
                    mejorSol = sol;
                }
            }
            else if (k < n - 1) {   // si aun quedan chavales que regalar
                // poda super divertida que 100% no me ha llevado 1h entender <3
                // aka si el valor actual + el valor que tenemos en la estimacion en la sigueinte posicion a la actual es mejor
                // que el mejor valor actrual seguimos ya que si el valor actual +  la estimacion da que es peor, y sabiendo que 
                // la estimacion ignora los detalles del problema, imagina lo mierda que va a ser teniendo en cuenta los detalles
                // del problema
                if (valor + estimacionOptimista[k + 1] > mejorValor) {
                    // mira el siguiente juguete
                    resolver(sol, n, k + 1, estimacionOptimista, regalosDados, regalos, valor, mejorValor, mejorSol);
                }
            }

            // desmarca y desfeliza
            regalosDados[i] = -1;
            valor -= sol[k];
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a;   // num juguetes
    cin >> b;   // num chavales

    // para que salga cuando no haya mas que leer
    if (!cin) return false;

    vector<vector<int>> regalos;
    int num;
    for (int i = 0; i < b; i++) {
        vector<int> aux;
        for (int j = 0; j < a; j++) {
            cin >> num;
            aux.push_back(num);
        }
        regalos.push_back(aux);
    }

    // vectores para el problema
    vector<int> regalosDados(a, -1);     // guarda la posicion (k) del regalo a ese chaval
    vector<int> mejorSol(b);
    vector<int> soluc(b);
    int mejorValor = 0;


    // PARA LA PODA
    vector<int> maxFelicidad(b);
    // calcula la felicidad maxima acumulada
    for (int i = 0; i < b; i++) {   // cada chaval
        for (int j = 0; j < a; j++) {   // cada juguete
            if (regalos[i][j] > maxFelicidad[i]) maxFelicidad[i] = regalos[i][j];
        }
    }
    vector<int> maxFelicidadAcc(b);
    maxFelicidadAcc[b - 1] =  maxFelicidad[b - 1];
    // calcula el acumulado
    for (int i = maxFelicidad.size() - 2; i >= 0; i--) {
        maxFelicidadAcc[i] = maxFelicidadAcc[i+1] + maxFelicidad[i];
    }

    // la poda (al menos esta) calcula el maximo de felicidad por chaval y luego la version acumulada.
    // la version acumulada es para tenerla ya hecha pero realmente lo importante es la idea de lo primero
    // porque calculas el mayor nivel de felicidad sin importar que se repitan regalos para tener la 
    // estimacion aproximada.


    // -------------
    resolver(soluc, a, 0, maxFelicidadAcc, regalosDados, regalos, 0, mejorValor, mejorSol);

    cout << mejorValor << endl;

    // Salida
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
    //system("PAUSE");
#endif

    return 0;
}