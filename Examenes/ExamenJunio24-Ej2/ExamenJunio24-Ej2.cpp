// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// con backtracking (WIP)
void resolverBacktracking(const vector<int>& datos, bool& existe, int i, int& sum, const int& sumDeseada) {

    int j = 0;
    // 
    while (j<2 && !existe) {
        if (i < datos.size()) {
            if (j == 0)
                sum += datos[i];
            else
                sum += datos[i] * -1;

            if (i == datos.size() - 1) {    // si ha llegado al final
                if (sum == sumDeseada) {
                    existe = true;
                }
            }
            else {

                // backtracking
                resolverBacktracking(datos, existe, i + 1, sum, sumDeseada);
            }

            if (j == 0)
                sum -= datos[i];
            else
                sum -= datos[i] * -1;
        }

        j++;
        
    }
}


// con divide et impera
bool resolver(const vector<int>& datos, int i, int sum, const int& final, bool& existe) {

    if (existe) return true;

    // caso del vector con 1 solo dato
    if (datos.size() == 1) {
        sum += datos[i];
        i++;
    }

    // caso base
    if (i == datos.size()) {
        if (sum == final){
            existe = true;
            return true;
        }
        return false;
    }

    // primer caso (para no poner signo delante)
    if (i == 0) {
        sum = datos[0];
        i++;
    }

    int izq = resolver(datos, i+1, sum - datos[i], final, existe);
    int der = resolver(datos, i+1, sum + datos[i], final, existe);

    return izq || der;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int sum, size;
    cin >> sum >> size;
    vector<int> datos(size);

    for (int i = 0; i < size; i++) {
        cin >> datos[i];
    }

    bool existe = false;

    int suma = 0;
    //resolver(datos, 0, 0, sum, existe);
    resolverBacktracking(datos, existe, 0, suma, sum);
    // escribir sol

    if (existe)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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