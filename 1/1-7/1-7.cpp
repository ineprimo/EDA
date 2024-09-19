#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// Complejidad: lineal O(n*log(n))
void comparaListados(std::vector<std::string>& eda, 
					 std::vector<std::string>& tpv,
					 std::vector<std::string>& comunes, 
					 std::vector<std::string>& soloEda, 
					 std::vector<std::string>& soloTpv)
{
    sort(eda.begin(), eda.end());
    sort(tpv.begin(), tpv.end());

    int i = 0, j = 0;
    while (i < eda.size() && j < tpv.size())
    {
        // ambas
        if (eda[i] == tpv[j])
        {
            comunes.push_back(eda[i]);
            i++;
            j++;
        }
        // si lo que tenga eda es menor y no lo tiene tpv es que es solo de eda
        else if (eda[i] < tpv[j])
        {
            soloEda.push_back(eda[i]);
            i++;
        }
        // si lo que tenga tpv es menor y no lo tiene eda es que es solo de tpv
        else if (tpv[j] < eda[i])
        {
            soloTpv.push_back(tpv[j]);
            j++;
        }
    }

    // las que sobran de eda
    while (i < eda.size())
    {
        soloEda.push_back(eda[i]);
        i++;
    }

    // las que sobran de tpv
    while (j < tpv.size())
    {
        soloTpv.push_back(tpv[j]);
        j++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::vector<std::string> eda(n);
    std::vector<std::string> comunes;
    std::vector<std::string> soloEda;
    std::vector<std::string> soloTpv;
    for (std::string& e : eda) std::cin >> e;
    std::cin >> n;
    std::vector<std::string> tpv(n);
    for (std::string& e : tpv) std::cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (std::string& e : comunes) std::cout << e << " ";
    std::cout << std::endl;
    for (std::string& e : soloEda) std::cout << e << " ";
    std::cout << std::endl;
    for (std::string& e : soloTpv) std::cout << e << " ";
    std::cout << std::endl;
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
