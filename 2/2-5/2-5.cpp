// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Divide y vencerás:
// 1) Divide el problema original en un número de subproblemas que son instancias más pequeñas del mismo problema.
// 2) Resuelve cada subproblema recursivamente. Cuando el tamaño del subproblema es suficientemente pequeño se hace directamente.
// 3) Combina las soluciones a los subproblemas para construir la solución al problema original.

// Caucasidad:
// Si el valor absoluto de la diferencia entre el número de elementos pares de sus mitades es, a lo sumo, 2
// Si cada mitad también es caucásica.
// Un vector con un elemento es caucasico.

// Divide y vencerás, no se recorren ambas mitades siempre. Complejidad: O(log n)
bool caucasico(std::vector<int>& sec, int ini, int fin, int& par)
{
    int elems = fin - ini; // num de elems a evaluar entre fin e ini

    if (sec.size() == 1) // caso base / solo un elemento en el vector es siempre caucásico
    {
        return true;
    }
    if (elems == 1) // caso base / 1 elemento a evaluar
    {
        if (sec[ini] % 2 == 0) // es par
        {
            par = 1; // se va sacando uno a uno el valor si es par
        }
        
        else
        {
            par = 0; // si el num que has evaluado no es par
        }
        
        return true;
    }

    int parIzq = 0, parDer = 0; // contador de pares
    int mit = (ini + fin) / 2; // calcula la mitad

    bool izq = caucasico(sec, ini, mit, parIzq); // busca izq, sacará por parIzq el num de pares de esa mitad
    bool der = caucasico(sec, mit, fin, parDer); // busca der, sacará por parDer el num de pares de esa mitad

    // pares totales de la mitad evaluada, NO del vector entero, cuando acabas de evaluar una mitad este par equivale a parIzq o parDer total
    par = parIzq + parDer; 

    // caucasica si ->
    // el valor absoluto de la diferencia entre el num de elems pares de sus mitades es como mucho 2
    // &&
    // cada mitad también es caucásica
    return (abs(parIzq - parDer) <= 2) && (izq && der);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n == 0) return false;
    std::vector<int> sec(n);
    for (int& e : sec) std::cin >> e;
    int par = 0;
    // se llama desde 0 hasta el final
    std::cout << (caucasico(sec, 0, sec.size(), par) ? "SI" : "NO") << std::endl;
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