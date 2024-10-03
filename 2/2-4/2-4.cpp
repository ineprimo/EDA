// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Suficientemente disperso si:
// - La diferencia entre el primer valor que se saca y el último sea mayor o igual que una cantidad K
// - Los datos que salieron en la primera mitad de la noche y los datos que salieron en la segunda mitad sean también suficientemente dispersos
//      esto es que la diferencia entre el primer valor y el último tanto de la primera mitad como de la segunda sea mayor que K 
//      y que cada una de sus mitades sea también suficientemente dispersa

// Estudia únicamente secuencias con un número de elementos que sea potencia de dos para poder
// dividirlas siempre en dos partes iguales
// Considera que un solo valor siempre es suficientemente disperso

bool resolver(const std::vector<int>& datos, int k, int ini, int fin)
{
    int elems = fin - ini;
    int dif = 0;

    if (elems == 0) return true;
    if (elems == 1)
    {
        dif = abs(datos[fin] - datos[ini]);

        return dif >= k;
    }

    int mit = (ini + fin) / 2;

    bool izq = resolver(datos, k, ini, mit);
    bool der = resolver(datos, k, mit + 1, fin);



    return izq && der;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int num = 0; // num tiradas que considera
    int k = 0;   // dispersion

    std::cin >> num >> k;

    std::vector<int> datos;
    int tirada = 0;

    for (int i = 0; i < num; i++) 
    {
        std::cin >> tirada;
        datos.push_back(tirada);
    }

    if (!std::cin)
        return false;

    bool sol = resolver(datos, k, 0, (datos.size())-1);

    // escribir sol
    if (sol) {
        std::cout << "SI" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

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
    system("PAUSE");
#endif

    return 0;
}