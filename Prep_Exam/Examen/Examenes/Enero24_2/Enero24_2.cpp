#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
void resolver(vector<int> linea1, vector<int> linea2, int& posCruce1, int& posCruce2, int& estadoCruce) {

    //Recorremos las dos líneas al mismo tiempo, para comparar punto por punto
    for (int i = 0; i < linea1.size(); i++)
    {
        //si coinciden
        if (estadoCruce == 0 && linea1[i] == linea2[i])
        {
            posCruce1 = i;
            posCruce2 = i;
            estadoCruce = 1;
        }
        else if (estadoCruce == 0 && (i + 1) < linea1.size() && linea1[i] < linea2[i] && linea1[i + 1] > linea2[i + 1])
        {
            posCruce1 = i;
            posCruce2 = i + 1;
            estadoCruce = 2; 
        }
    }

    //Si no se cruza dentro de los datos aportados (estadoCruce sigue siendo 0)
    if (estadoCruce == 0)
    {
        //Si el cruce se ha producido antes de los datos
        if (linea1[0] > linea2[0])
        {
            posCruce1 = -1;
            posCruce2 = 0;
        }
        //Si no, se ha producido después de los datos aportados
        else
        {
            posCruce1 = linea1.size() - 1;
            posCruce2 = linea1.size();
        }

        //Habrá un cruce fuera de límites, inexacto
        estadoCruce = 2; 
    } 

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    //n de datos en las lineas
    int n = 0; 
    cin >> n;
    //Leemos cada linea
    vector<int> linea1(n);
    vector<int> linea2(n);

    if (n == 0)
    {
        return false;
    }
    else
    {
        //Linea 1
        for (int i = 0; i < n; i++) 
        {
            cin >> linea1[i];
        }
        //Linea 2
        for (int i = 0; i < n; i++)
        {
            cin >> linea2[i];
        }
    }

    int posCruce1 = 0, posCruce2 = 0;
    int estadoCruce = 0; //0 - no cruza, 1 - cruce exacto, 2 - cruce inexacto
    resolver(linea1, linea2, posCruce1, posCruce2, estadoCruce);

    // escribir sol
    if (estadoCruce == 1)
    {
        cout << "SI " << posCruce1 << endl;
    }
    else if (estadoCruce == 2)
    {
        cout << "NO " << posCruce1 << " " << posCruce2 << endl;
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
