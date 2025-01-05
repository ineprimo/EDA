// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int numComplementario(int datos, int unidad, bool& ult, int& cum) {
    int digito = datos % 10;
    if (digito == 9) ++cum;
    else cum = 0;

    if (datos < 10) {
        if (datos == 9) ult = true;
        return (9 - datos) * unidad;
    }

    int complementario = 9 - digito;

    return numComplementario(datos / 10, unidad * 10, ult, cum) + complementario * unidad;
}

int numInverso(int datos, int inverso, bool ult, int cum) {
    if (datos == 0) {
        if (ult) inverso = inverso * std::pow(10, cum);
        return inverso;
    }

    int digito = datos % 10;

    return numInverso(datos / 10, inverso * 10 + digito, ult, cum);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int datos;
    cin >> datos;

    bool ultNum = false;
    int acumFinal = 0;

    int complemento = numComplementario(datos, 1, ultNum, acumFinal);

    int inverso = numInverso(complemento, 0, ultNum, acumFinal);
    // escribir sol

    cout << complemento << " " << inverso << endl;
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