// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool elemento_situado(const std::vector<int>& v, int ini, int fin)
{
    const int elems = fin - ini; // num de elems a evaluar entre fin e ini

    if (elems == 0) return false; // caso base / vector vacio
    if (elems == 1) // caso base / mirar ese elemento
    {
	    if(v[ini] == ini) // está bien situado
	    {
            return true;
	    }
        else
        {
			return false;
        }
    }

    int mit = (ini + fin) / 2;

    bool sitIzq = false;
    bool sitDer = false;

    // buscar en la mitad izq ->
    // si lo que hay en mit es mayor a su índice ya no va a haber nada a la der bien situado
    // porque está ordenado por lo que será aún más grande
    if (v[mit] > mit)
    {
		sitIzq = elemento_situado(v, ini, mit);
    }

    // buscar en la mitad der ->
    // si lo que hay en mit es menor a su indice ya no va a haber nada a la izq bien situado
    // porque está ordenado por lo que será aún más pequeño
    if (v[mit] < mit)
    {
		sitDer = elemento_situado(v, mit, fin);
    }

    return sitIzq || sitDer;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::vector<int> sec(n);
    for (int& e : sec) std::cin >> e;
    std::cout << (elemento_situado(sec, 0, n) ? "SI" : "NO") << std::endl;
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
    //system("PAUSE");
#endif

    return 0;
}
