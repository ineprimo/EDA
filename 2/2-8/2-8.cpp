// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Divide y vencerás, búsqueda binaria. Complejidad: O(log n)
int resolver(std::vector<int>& datos, int ini, int fin)
{
    int elems = fin - ini;

    if(elems == 0) return 0; // caso base / vector vacio
    if (elems == 1) return datos[ini]; // caso base / solo un elemento, es ese elemento

    int mit = (ini + fin) / 2;

    // si el dato de la mitad es menor que el inicio
    // significa que el dato menor estará en la mitad derecha
    // ya que ha sido rotado el vector en orden decreciente

    // ej:
    // 8 6 4 2 -> rotado / nada
    // 2 8 6 4 -> rotado / 8 6 4 al final
    // 4 2 8 6 -> rotado / 8 6 al final
    // 6 4 2 8 -> rotado / 8 al final
    // 8 5 3 1 10 -> rotado / 10 al final
	// 5 3 1 10 8 -> rotado / 10 8 al final
	// 70 55 13 4 100 80 -> rotado / 100 80 al final

    // si el de la mitad es menor es que a su derecha aun quedan menores
    if(datos[mit] < datos[ini])
    {
        // busca en la derecha
        return resolver(datos, mit, fin);
    }

    // si el de la mitad es mayor es que a su izquierda aun quedan menores
    // en otro caso busca en la izq
    return resolver(datos, ini, mit);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int elems = 0;

    std::cin >> elems;

    if (!std::cin)
        return false;

    int dato = 0;
    std::vector<int> datos;

    for(int i = 0; i < elems; i++)
    {
        std::cin >> dato;
        datos.push_back(dato);
    }

    int sol = resolver(datos, 0, datos.size());

    // escribir sol
    std::cout << sol << std::endl;

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