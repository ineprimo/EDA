// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Divide y vencerás, búsqueda binaria. Complejidad: O(log n)
bool resolver(std::vector<int> datos, int ini, int fin, int valor)
{
    int elems = fin - ini;

    if (elems == 0) return false; // vector vacio
    if (elems == 1) return datos[ini] == valor;

    int mit = (ini + fin) / 2;

    // si el de la mitad es menor es que a su izq aun pueden quedan menores
    if(datos[mit] < datos[ini])
    {
        // si el dato que busco es mayor o igual que la mitad y menor que el inicio -> está a la der
	    if((datos[mit] <= valor) && (datos[ini] > valor))
	    {
	        // busca en la der
	        return resolver(datos, mit, fin, valor);
	    }
        // -> en otro caso estará a la izq
        else
	    {
	        // busca en la izq
	        return resolver(datos, ini, mit, valor);
	    }
    }

    // si el de la mitad es mayor es que a su der aun quedan menores
	if(datos[mit] >= datos[ini])
	{
        // si el dato que busco es menor que la mitad y mayor o igual que el inicio -> está a la izq
		if((datos[mit] > valor) && (datos[ini] <= valor))
		{
	        // busca en la izq
	        return resolver(datos, ini, mit, valor);
		}
        // -> en otro caso estará a la der
        else
        {
	        // busca en la der
	        return resolver(datos, mit, fin, valor);
        }
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int elems = 0;
    int valor = 0;

    std::cin >> elems >> valor;

    if (elems == -1)
        return false;

    int dato = 0;
    std::vector<int> datos;

    for (int i = 0; i < elems; i++)
    {
        std::cin >> dato;
        datos.push_back(dato);
    }

    bool sol = resolver(datos, 0, datos.size(), valor);

    // escribir sol
    if(sol)
    {
        std::cout << "SI";
    }
    else
    {
        std::cout << "NO";
    }
    std::cout << std::endl;

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