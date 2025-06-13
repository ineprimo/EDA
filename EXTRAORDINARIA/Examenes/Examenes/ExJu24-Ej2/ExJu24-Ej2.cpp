// Ejercicio 2: Combinando sumas y restas (3 puntos)
// Tipo: BACKTRACKING

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// PARAMETROS:
// --- entrada
// soluc    -> vector solucion
// k        -> para la llamada recursiva k+1
// i de for -> lo que vas probando, -> + / -> -
// n        -> elems del vector, para ver si has llegado al final del arbol
// v -> vector de datos
// M -> int al que llegar con las operaciones sobre v

// --- marcadores
// suma       -> conteo de que numero sale con tu solucion actual

// Tupla sol: [0, 1, ... , 1] 0 o 1 en funcion de si sumas o restas, de tamano n del vector

// función que resuelve el problema
void resolver(std::vector<int>& soluc, int k, int n, const int M, int suma, bool& obtenible, std::vector<int>& v)
{
    if (n == 0) obtenible = true;
    else {
    // ---- ESQUEMA DE BACKTRACKING ----

    // !!!! marcar en el mismo ambito en el que se desmarca

    // 1) for de candidatos     -> candidatos = + / -
    // --- 2) guardar el indice del for que se va probando en el vect solucion
    // --- 3) if esValida       -> ver si lo que acabas de guardar ha sido una eleccion valida
    // ------ 4) if esSolucion  -> SOLO PUEDES COMPROBAR LA SOLUCION SI K == n-1
    // --------- 5) if esMejor  -> si la cantidad de monedas que estoy usando es mayor que la ultima mayor cantidad
    // ------ 6) else noSolucion
    // --------- 7) if poda     -> si las monedas que llevo + la estimacion supera el num max de monedas hasta ahora
    // ------------ 8) llamada recursiva k+1
	
	// el primero siempre suma => lo metes al vector

   // por cada elem del vector pruebas dos i -> i = 0 (suma) / i = 1 (resta)
    for (int i = 0; i < 2 && !obtenible; i++)
    {
        soluc[k] = i; // lo que voy a probar ahora...

        // MARCAS
        // asumiendo que i es la sol para esta k, MARCAMOS
        if (i == 0) suma += v[k]; // sumas -> sumas al marcador el dato en esa pos del vector v
        else suma -= v[k]; // lo mismo pero restas

        // solo es valida si para k == 0 estas sumando
        // si estas en k != 0 sumar o restas son igual de validas
        if ((k == 0 && i == 0) || k != 0)
        {
            // antes de comprobar si puede ser solucion -> miras si es final de arbol
            if (k == n - 1)
            {
                // es solucion si suma == M
                if (suma == M) obtenible = true;
            }
            else
            {
                // podar si estas en el penultimo nivel
                if (k == n-2)
                {
                    int optimista = 0;
                    // si M es mayor al numero que llevo acumulado -> calcular optimista sumando
                    if (suma < M) optimista = suma + v[k + 1];
                    // si M es menor al numero que llevo acumulado -> calcular optimista restando
                    else optimista = suma - v[k + 1];

                    // si con optimista llego a M -> llamada recursiva k+1
                    if (optimista == M) resolver(soluc, k + 1, n, M, suma, obtenible, v);
                }
                else
                {
                    // llamada recursiva k+1
                    resolver(soluc, k + 1, n, M, suma, obtenible, v);
                }
            }
        }

        // DESMARCAS
        if (i == 0) suma -= v[k];
        else suma += v[k];

        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int M = 0,
        n = 0;

    std::cin >> M; // numero al que llegar
    std::cin >> n; // elems del vector

    int e = 0;
    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        std::cin >> e;
        v.push_back(e);
    }

    std::vector<int> soluc(n);
    bool obtenible = false;
    resolver(soluc, 0, n, M, 0, obtenible, v);

    // escribir sol
    if (obtenible) std::cout << "SI";
    else std::cout << "NO";
    std::cout << std::endl;
}

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
    system("PAUSE");
#endif

    return 0;
}