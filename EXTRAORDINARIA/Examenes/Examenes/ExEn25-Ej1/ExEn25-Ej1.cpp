// Ejercicio 2: Limpieza DANA (3,5 puntos)
// Tipo: BACKTRACKING

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include <ratio>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, vector<T> const& v)
{
    for (auto& e : v) out << e << " ";
    return out;
}

// función que resuelve el problema
// PARAMETROS:
// --- entrada
// soluc -> vector solucion, lodo retirado por area
// k -> areas
// n -> numero de voluntarios, n >= m
// m -> numero de areas, >= 1
// l -> numero minimo de areas que deben quedar completamente limpias
// kilos/area -> cantidad de lodo en kg presente en cada area
// kilos/voluntario -> v[0] = kilos area 1 vol 0, kilos area 2 vol 0, ... , kilos area n vol 0

// MAXIMIZAR la cantidad de lodo retirado, cumpliendo que al menos l areas queden completamente limpias (0 >= l >= m)
// area completamente limpia si => cantidad de lodo que los voluntarios asignados a ese area pueden retirar es >= a la cantidad presente en ella

// => Una misma area puede ser atendida por varios voluntarios, pero cada voluntario solo puede ser asignado a una unica area

// SALIDA
// Por cada caso de prueba, el programa debe imprimir una linea con la cantidad maxima de lodo retirado.
// Si no es posible cumplir la restriccion de dejar al menos l areas completamente limpias,
// se debe imprimir en su lugar una linea con la cadena IMPOSIBLE.


// TUPLA = soluc(n) // cada i es el area (0 a m-1) que le asignas a ese voluntario
// [2, 1, 1, 1, 0] -> i=0 asignado a area 2, i=1 asignado a area 1

// funcion que resuelve el problema
void resolver(vector<int>& soluc, int k, int n, int m, int l, vector<int>& kilosPorArea, vector<vector<int>> const& kilosPorVoluntario,  // entrada
			  int suma, int limpias, int& maxSuma, vector<int>& kilosPorAreaRestantes, vector<bool>& elegidos, // marcadores
				vector<int>& maxKilosDesde)
{
    // ---- ESQUEMA DE BACKTRACKING ----

    // !!!! marcar en el mismo ambito en el que se desmarca

    // 1) for de candidatos     -> candidatos = num de monedas de valor k
    // --- 2) guardar el indice del for que se va probando en el vect solucion
    // --- 3) if esValida       -> ver si lo que acabas de guardar ha sido una eleccion valida
    // ------ 4) if esSolucion  -> se ha llegado al precio a calcular
    // --------- 5) if esMejor  -> si la cantidad de monedas que estoy usando es mayor que la ultima mayor cantidad
    // ------ 6) else noSolucion
    // --------- 7) if poda     -> si las monedas que llevo + la estimacion supera el num max de monedas hasta ahora
    // ------------ 8) llamada recursiva k+1

    if (k >= n) return;
    for (int area = 0; area < m; ++area) // for de areas
    {
        // es valida
        if (!elegidos[k]) // solo puedes asignarlos a 1 zona
        {
            soluc[k] = area; // k num de voluntario

            elegidos[k] = true;
            // MARCAR
            int kilosRestantes = kilosPorAreaRestantes[area]; 
            int restante = kilosPorAreaRestantes[area] - kilosPorVoluntario[k][area];
            // si con el voluntario en ese area ya la limpias
            if (restante <= 0)
            {
                suma += kilosPorAreaRestantes[area];
                kilosPorAreaRestantes[area] = 0;
                limpias++;
            }
            // si aun queda por limpiar
            else
            {
                suma += kilosPorVoluntario[k][area];
                kilosPorAreaRestantes[area] -= kilosPorVoluntario[k][area];
            }

            // antes de saber si es solucion, comprobar si es final del arbol
            if (k == n-1)
            {
                // es solucion: si ya has limpiado esas areas o mas
                if (limpias >= l)
                {
                    // es mejor
                    if (suma >= maxSuma) maxSuma = suma;
                }
            }
            else
            {
                // si lo que llevo sumado mas los kilos maximos (optimista) van a mejorar mi mejor resultado
                if (suma + maxKilosDesde[k] > maxSuma)
                {
                    // llamada recursiva k+1 -> siguiente voluntario
                    resolver(soluc, k + 1, n, m, l, kilosPorArea, kilosPorVoluntario, suma, limpias, maxSuma, kilosPorAreaRestantes, elegidos, maxKilosDesde);
                }
            }

            // DESMARCAR
            elegidos[k] = false;

            if (restante <= 0)
            {
                limpias--;
                kilosPorAreaRestantes[area] = kilosRestantes;
                suma -= kilosPorAreaRestantes[area];
            }
            // si aun queda por limpiar
            else
            {
                suma -= kilosPorVoluntario[k][area];
                kilosPorAreaRestantes[area] += kilosPorVoluntario[k][area];
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // n -> numero de voluntarios, n >= m
    // m -> numero de areas, al menos 1
    // l -> numero minimo de areas que deben quedar completamente limpias
    // leer los datos de la entrada
    int n, m, l;
    cin >> n >> m >> l;

    // cantidad de lodo en kg presente en cada area
    vector<int> kilosPorArea(m);
    for (int i = 0; i < m; ++i) {
        cin >> kilosPorArea[i];
    }

    // una linea por cada voluntario indicando la cantidad de lodo que ese voluntario puede retirar en cada area
    vector<vector<int>> kilosPorVoluntario(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> kilosPorVoluntario[i][j];

    vector<int> maxKilos(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (maxKilos[i] < kilosPorVoluntario[i][j])
            {
				maxKilos[i] = kilosPorVoluntario[i][j];
            }
        }
    }

    vector<int> maxKilosDesde(n, 0);
    maxKilosDesde[n - 1] = maxKilos[n - 1];
    for (int i = n-2; i >= 0; i--)
    {
        maxKilosDesde[i] += maxKilosDesde[i+1];
        maxKilosDesde[i] += maxKilos[i];
    }

    // Por cada caso de prueba, el programa debe imprimir una linea con la cantidad maxima de lodo retirado.
    // Si no es posible cumplir la restriccion de dejar al menos l areas completamente limpias,
    // se debe imprimir en su lugar una linea con la cadena IMPOSIBLE.
    vector<int> soluc(n, -1);
    int k = 0;
    int maxSuma = 0;
    vector<bool> elegidos(n);
    resolver(soluc, k, n, m, l, kilosPorArea, kilosPorVoluntario, 0, 0, maxSuma, kilosPorArea, elegidos, maxKilosDesde);

    if (maxSuma <= 0) std::cout << "IMPOSIBLE" << std::endl;
    else std::cout << maxSuma << std::endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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
