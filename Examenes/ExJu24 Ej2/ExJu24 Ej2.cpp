// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void sumasyrestas(std::vector<int>& soluc, int k, const int n, const int M, int suma, std::vector<int>& datos, bool& encontrado)
{
    if(encontrado)
    {
        return;
    }
    if(n == 0)
    {
        encontrado = true;
    }
    else
    {
		for (int i = 0; i < 2; i++)
	    {
            if(!encontrado)
            {
		        // si i = 0 -> + / si i = 1 -> -
		        if (i == 0) soluc[k] = 1;
		        else soluc[k] = -1;

		        // MARCAR
		        suma += (soluc[k] * datos[k]);

		        // es valida solo si:
		        // si k == 0 -> + || cualquier otro caso
		        if ((k == 0 && i == 0) || (k != 0))
		        {
		            // final del arbol
		            if (k == n - 1)
		            {
		                // si llegas al final y has conseguido llegar a M -> SI
		                if (suma == M)
		                {
		                    encontrado = true;
		                }
		            }
		            else
		            {
		                // llamada recursiva k+1
		                sumasyrestas(soluc, k + 1, n, M, suma, datos, encontrado);
		            }
		        }

		        suma -= (soluc[k] * datos[k]);
            }
	    }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int M, n = 0;

    std::cin >> M >> n;

    std::vector<int> datos(n);

    for(int i = 0; i < n; i++)
    {
        std::cin >> datos[i];
    }

    std::vector<int> soluc(n);
    bool encontrado = false;
    sumasyrestas(soluc, 0, n, M, 0, datos, encontrado);

    if (encontrado) std::cout << "SI";
    else std::cout << "NO";
    std::cout << '\n';

    /*
    for (int j = 0; j < n; j++)
    {
        std::cout << soluc[j] << " ";
    }
    std::cout << '\n';
    */
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
    //std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}