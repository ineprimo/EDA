#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

// Tupla solucion: [Gi, Gi+1, Gi+2, ... , G(i+n)-1]
// siendo n el numero de artistas del concierto y siendo i la posicion en la que toca cada grupo(G)

bool esValida(vector<int>& soluc, int k, const vector<bool>& elegidos, const vector<vector<bool>>& consentimientos)
{
    // es valida si el grupo no ha salido todavia y si encaja con los consentimientos de ese grupo
    return ((!elegidos[soluc[k]]) && (k == 0 || (consentimientos[soluc[k]][soluc[k - 1]])));
}

// --- paramatros:
// - soluc -> vector solucion
// - k     -> posiciones de orden en el que tocar
// - i del for -> grupos que vas probando
// - n     -> num max de conciertos
// - rec   -> recaudaciones por artista en x pos
// - con   -> consentimientos por artista
// --- marcadores:
// - ganancias -> ganancias que vas aumulando en una rama
// - vistos    -> almacena si el concierto en la pos i ya ha sido visto

void concierto(vector<int>& soluc, int k, int n, int ingresos, int& mejoresIngresos, vector<bool>& elegidos, 
    const vector<vector<int>>& beneficios, const vector<vector<bool>>& consentimientos, const vector<int>& mejoresBeneficios)
{
    // 1) for de candidatos     -> 
    // --- 2) guardar el indice del for que se va probando en el vect solucion
    // --- 3) if esValida       -> ver si lo que acabas de guardar ha sido una eleccion valida
    // ------ 4) if esSolucion  -> se ha llegado al final del arbol
    // --------- 5) if esMejor  -> si lo recaudado supera la mejor recaudacion anterior
    // ------ 6) else / else if noSolucion (depende de si la condicion de final es llegar al final del arbol)
    // --------- 7) if poda     ->
    // ------------ 8) llamada recursiva k+1

    for (int i = 0; i < n; ++i)
    {
        soluc[k] = i;

        if (esValida(soluc, k, elegidos, consentimientos))
        {
            // marcamos
            ingresos += beneficios[i][k];
            elegidos[i] = true;

            // comprobar final del arbol
            if (k == n - 1)
            {
                if (ingresos > mejoresIngresos) mejoresIngresos = ingresos;
            }
            else
            {
                if (ingresos + mejoresBeneficios[k+1] > mejoresIngresos)
                {
                    concierto(soluc, k + 1, n, ingresos, mejoresIngresos, elegidos, beneficios, consentimientos, mejoresBeneficios);
                }
            }

            // desmarcamos
            ingresos -= beneficios[i][k];
            elegidos[i] = false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	int n = 0;
	cin >> n;

    vector<vector<int>> beneficios(n, vector<int>(n) );
    vector<vector<bool>> consentimientos(n, vector<bool>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> beneficios[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int b;
            std::cin >> b;
            consentimientos[i][j] = b;
        }
    }

    // poda calculada desde fuera
    std::vector<int> maxBenefs(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (beneficios[j][i] > maxBenefs[i])
            {
                maxBenefs[i] = beneficios[j][i];
            }
        }
    }

    std::vector<int> mejoresBeneficiosDesde(n);

    mejoresBeneficiosDesde[n - 1] = maxBenefs[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        mejoresBeneficiosDesde[i] += maxBenefs[i + 1];
        mejoresBeneficiosDesde[i] += maxBenefs[i];
    }

    vector<int> soluc(n);
    int k = 0;
    int ingresos = 0;
    int mejoresIngresos = -1;
    vector<bool> elegidos(n);
    concierto(soluc, k, n, ingresos, mejoresIngresos, elegidos, beneficios, consentimientos, mejoresBeneficiosDesde);

    if (mejoresIngresos == -1) std::cout << "NEGOCIA CON LOS ARTISTAS" << std::endl;
    else std::cout << mejoresIngresos << std::endl;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}