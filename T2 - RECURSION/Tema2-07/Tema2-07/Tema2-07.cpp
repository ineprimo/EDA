// Paula Sierra Luque
// GDV-EDA70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& nums, int ini, int fin) 
{
    /// ---- trata de busqueda binaria ya que sabemos que 100% el numero va a estar en uno de los lados 
    ///     porque se reducen llamadas recursivas:
    /// -> coste O(log n)

    // caso base
    if (ini == fin) 
    {
        return nums[ini]; // 1 elem -> devolvemos elem
    }
    
    int mitad = (ini + fin) / 2;

    if (nums[mitad] < nums[mitad + 1]) // izda
    {
        return resolver(nums, ini, mitad); 
    }
    else // dcha
    { 
        return resolver(nums, mitad + 1, fin);
    }

    /// ---- asi no se haria porque el coste seria mayor:
    /// -> coste O(n)
    
    //if (ini == fin) return nums[ini]; // 1 elem -> devolvemos elem
    //if (fin - ini == 1) // 2 elem -> devolvemos el peq
    //{
    //    if (nums[fin] < nums[ini]) return nums[fin];
    //    else return nums[ini];
    //}

    //// mas de dos elem: dividimos
    //int mitad = (ini + fin) / 2;

    //int m1 = resolver(nums, ini, mitad);
    //int m2 = resolver(nums, mitad + 1, fin);

    //if (m1 < m2) return m1;
    //else return m2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> nums; 
    int aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        nums.push_back(aux);
    }

    int sol = resolver(nums, 0, n-1);

    // escribir sol
    cout << sol << endl;

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