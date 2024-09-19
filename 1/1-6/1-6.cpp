// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Complejidad: 
void comparaListados(std::vector<std::string> const& eda, 
					 std::vector<std::string> const& tpv,
					 // estos son los que hay que modificar (push_back)
					 std::vector<std::string>& comunes, 
					 std::vector<std::string>& soloEda, 
					 std::vector<std::string>& soloTpv)
{
    // que devuelva otros tres listados tambien ordenados,
    // el primero con los elementos presentes en ambos listados,
    // el segundo con los elementos presentes en el primero y no en el segundo,
    // y el tercero con los presentes en el segundo y no en el primero

    std::vector<int> abecedario1(26);

    int i = 0;
    while(i < abecedario1.size())
    {
        // ambas
        if(eda.size() >= i && tpv.size() >= i)
        {
	        if(eda[i] == tpv[i])
	        {
	            comunes.push_back(eda[i]);
	        }
	        else if()
	        {
		        
	        }
	        else
	        {
		        
	        }
        }
        // las que sobran de eda
        else if(eda.size() >= i && tpv.size() < i)
        {
            soloEda.push_back(eda[i]);
        }
        // las que sobran de tpv
        else if(tpv.size() >= i && eda.size() < i)
        {
            soloTpv.push_back(tpv[i]);
        }

        i++;
    }

    // vas evaluando cada letra del abecedario
    for(int j = 0; j < abecedario1.size(); i++)
    {
	    
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