/*
Nombre completo: Nieves Alonso Gilsanz
DNI: 54696982S
Usuario del juez: 03
Puesto de laboratorio: pto 02 lab 1
Qué has conseguido hacer y qué no: El ejercicio se resuelve correctamente para los casos de prueba
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// reciba un vector no vacío de salarios y un incremento de salario >= 0 a buscar,
// devuelva el primer año en que el empleado ha obtenido dicho incremento de salario 
// con respecto al anterior, o un −1 si dicho incremento no se ha obtenido.
// Los años se cuentan desde el año en que comenzó el contrato del empleado, que se considera el año 0,
// en el cual se considera que el incremento es 0 porque no ha trabajado antes en esa empresa.
// Complejidad: O(log(n))
int salarios(vector<int>& sals, int ini, int fin, int& incremento) 
{
    int tam = fin - ini;

    // si no hay incremento antes de empezar ya lo tienes
    if (incremento == 0) return 0;

    if (tam == 1) 
    {
        if (fin == sals.size() && (sals[fin - 1] - sals[ini - 1] != incremento)) // para no salirnos, al estar ordenado siempre acabarias buscando en el extremo derecho
        {
            return -1;
        }

        return fin;
    }

    int mit = (fin + ini) / 2;

    // si lo encuentras a la mitad
    if (sals[mit] - sals[ini] == incremento)
    {
        return mit;
    }
    // si en la mitad es mayor -> buscas a la izq
    if (sals[mit] - sals[ini] > incremento)
    {
        return salarios(sals, ini, mit, incremento);
    }
    // si en la mitad es menor -> buscas a der
    if (sals[mit] - sals[ini] < incremento) 
    {
        return salarios(sals, mit, fin, incremento);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, inc;
    cin >> inc >> n;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;

    // Llamada a función y escritura de la salida
    int sol = salarios(sec, 0, n, inc);

    std::cout << sol << std::endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
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
