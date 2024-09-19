


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void comparaListados(std::vector<std::string> const& eda, 
					 std::vector<std::string> const& tpv,
					 std::vector<std::string>& comunes, 
					 std::vector<std::string>& soloEda, 
					 std::vector<std::string>& soloTpv)
{

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