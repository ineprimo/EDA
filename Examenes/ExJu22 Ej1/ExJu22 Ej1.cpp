#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

using preferencias = std::vector<int>;
using alumnos = std::unordered_map<int, preferencias>;

bool esValida(vector<vector<int>>& soluc, int k, int t, vector<int>& asignados, vector<int>& tareasPorAlumno)
{
    // es valida si:
        // no se ha elegido a ese alumno ya en esa tarea
        // y si ese alumno no ha llegado al max de tareas
        // y si esa tarea no esta llena
    return (soluc[k][0] != asignados[k]) && (soluc[k][1] != asignados[k]) && ((tareasPorAlumno[soluc[k][0]] < t) || (tareasPorAlumno[soluc[k][1]] < t));
}

// Tupla solucion: [[a0, a1], [a2,a3], [...,...], ..., [ai,aj]]1->n => ai y aj los alumnos asignados a cada tarea y n el numero de tareas

// Exploracion: En cada etapa / nivel del arbol decidir cuantas monedas de cada tipo voy a elegir
// ej: k = 0 -> cuantas monedas de 1 cent voy a utilizar (probar todas las opciones: 0 -> num monedas 1 cent)

// función que resuelve el problema
// parametros:
// --- entrada
// soluc    -> vector solucion
// k        -> tareas
// i de for -> alumnos por tarea que vas probando
// n        -> num max de tareas por alumno
// monedas  -> numero de monedas de cada tipo que tengo
// precio   -> valor al que tengo que llegar
// --- marcadores
// numMonedas -> cuantas monedas llevo guardadas en el vector solucion
// suma       -> suma acumulada de dinero actual
void resolver(vector<vector<int>>& soluc, int k, int n, int t, int satisfaccion, int& maxSatisfaccion, alumnos alums, vector<int>& asignados, vector<int>& tareasPorAlumno)
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

    // va buscando la tarea con mas satisfaccion para cada alumno
    for (int i = 0; i < n; i++)
    {
        soluc[k].push_back(i); // por la tarea k guardar al alumno i

        // MARCAR
        tareasPorAlumno[i] += 1;

        // i asignado en la tarea k
        asignados[k] = i; // si ya hay dos alumnos tarea k asignada

        // VALIDA
        // es valida si:
        // no se ha elegido a ese alumno ya en esa tarea
        // y si ese alumno no ha llegado al max de tareas
        // y si esa tarea no esta llena
        if(esValida(soluc, k, t, asignados, tareasPorAlumno))
        {
			// satisfaccion acumulada en cada tarea
            satisfaccion += alums[i][k]; // satisfaccion del alumno i por la tarea k

            

            // FINAL DEL ARBOL / SOLUCION
            if()
            {
	            // MEJOR
                if()
                {
	                
                }
            }
            else
            {
                // PODA
	            if()
	            {
                    if (asignadas[k] == true)
                    {
                        // llamada recursiva con k+1
                        resolver(soluc, k + 1, n, ...);
                    }
                    // llamada recursiva con k -> para buscar el segundo alumno
                    resolver(soluc, k, n, ...);
	            }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // tareas, alumnos en clase, max tareas por alumno
    int n, a, t = 0;

    std::cin >> n >> a >> t;

    if(n == 0)
    {
        return false;
    }

    alumnos al(a);
    for(int i = 0; i < a; i++)
    {
		preferencias pr(n);
	    for(int j = 0; j < n; j++)
	    {
            int p = 0;
            std::cin >> p;
            pr.push_back(p);
	    }
        al[i] = pr;
    }

    // resolver
    vector<int> soluc(NUM_MONEDAS);
    resolver(soluc, 0, n, a, t, 0, 0, 0, maxNumMonedas);

    // mostrar salida
    

    return true;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}