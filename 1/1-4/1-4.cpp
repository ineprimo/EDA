// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
std::vector<int> resolver(std::vector<int> datos)
{
    std::vector<int> resul;

    for(int i = 0; i < datos.size(); i++)
    {
	    if(datos[i] % 2 == 0)
	    {
            resul.push_back(datos[i]);
	    }
    }

    return resul;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    std::vector<int> datos;
    int valores = 0;
    int num = 0;

    std::cin >> num;

    for(int i = 0; i < num; i++)
    {
        std::cin >> valores;
        datos.push_back(valores);
    }

    std::vector<int> sol = resolver(datos);

    // escribir sol
    for(int i = 0; i < sol.size(); i++)
    {
        std::cout << sol[i] << " ";
    }

    std::cout << std::endl;
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
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}