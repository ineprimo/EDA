// Pablo Iglesias Rodrigo.
// EDA-GDV035


#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>


const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1, 2, 5, 10, 20, 50, 100, 200 };


using Recaudacion = std::vector<int>; // Vector de las donaciones que recibe un artista.
using Consentimiento = std::vector<int>; // Vector de los consentimientos de un artista.
using Recaudaciones = std::unordered_map<int, Recaudacion>; // Mapa con el indice del artista y sus recaudacion.
using Consentimientos = std::unordered_map<int, Consentimiento>; // Mapa con el indice del artista y sus consentimientos.


bool esValida(std::vector<int>& sol, int candidatos, std::vector<bool>& vistos, Consentimientos& cons)
{
	return ((!vistos[sol[candidatos]]) && (candidatos == 0 || (cons[sol[candidatos]][sol[candidatos - 1]] == 1)));
}

// función que resuelve el problema
// parametros:
// --- entrada:
// sol				-> vector solucion.
// candidatos(k)    -> posiciones del orden de tocar.
//  la i del for los grupos que vas probando.
// nArtistas(n)     -> numero de artistas.
// recs				-> mapa con las recaudaciones.
// cons				-> mapa con los consenitimientos.
// --- marcadores:
// ganancias		-> ganancias de cada rama.
// vistos			-> vector de los artistas que ya han sido vistos.

// TUPLA SOLUCION: [Ai, Ai+1, Ai+2, ... , A(i+n)-1] 
// siendo n el numero de artistas en i el indice del artista
void concierto(std::vector<int>& sol, int candidatos, int nArtistas, int ganancias, int& maxGanancias,
	Consentimientos& cons, Recaudaciones& recs, std::vector<bool>& vistos,
	std::vector<int> estimacionPorPosicion)
{
	// ---- ESQUEMA DE BACKTRACKING ----

	// !!!! marcar en el mismo ambito en el que se desmarca

	// 1) for de candidatos     -> candidatos = num de monedas de valor k
	// --- 2) guardar el indice del for que se va probando en el vect solucion
	// --- 3) if esValida       -> ver si lo que acabas de guardar ha sido una eleccion valida
	// ------ 4) if esSolucion  -> se ha llegado al precio a calcular
	// --------- 5) if esMejor  -> si la cantidad de monedas que estoy usando es mayor que la ultima mayor cantidad
	// ------ 6) else noSolucion (si tienes que llegar al final solo else)
	// --------- 7) if poda     -> si las monedas que llevo + la estimacion supera el num max de monedas hasta ahora
	// ------------ 8) llamada recursiva k+1

	for (int i = 0; i < nArtistas; i++)
	{
		sol[candidatos] = i;

		if (esValida(sol, candidatos, vistos, cons))
		{
			// Esto para marcar.
			ganancias += recs[i][candidatos];
			vistos[i] = true;
			// Para comprobar si es solucion.
			if (candidatos == nArtistas - 1)
			{
				// Para actualizar las ganancias si son mayores que las ganancias acumuladas.
				if (ganancias > maxGanancias)
				{
					maxGanancias = ganancias;
				}
				else
				{
					// Solo si merece la pena hacemos la llamada.
					if ((ganancias + estimacionPorPosicion[candidatos]) > maxGanancias)
					{
						// Llamada recursiva.
						concierto(sol, candidatos + 1, nArtistas, ganancias, maxGanancias, cons, recs, vistos, estimacionPorPosicion);
					}
				}
				// Desmarcar.
				ganancias -= recs[i][candidatos];
				vistos[i] = false;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	int nArtistas = 0; // Numero de artistas del festival.
	std::cin >> nArtistas;

	Recaudaciones recs; // Mapa con las recaudaciones de los artistas.
	Consentimientos cons; // Mapa con los consentimientos de los artistas.

	// Lectura:
	for (int i = 0; i < nArtistas; i++)
	{
		Recaudacion rec(nArtistas);
		for (int j = 0; j < nArtistas; j++)
		{
			std::cin >> rec[j];
		}
		recs.insert({ i, rec });
	}
	for (int i = 0; i < nArtistas; i++)
	{
		Consentimiento con(nArtistas);
		for (int j = 0; j < nArtistas; j++)
		{
			std::cin >> con[j];
		}
		cons.insert({ i, con });
	}

	// Estimacion optimista antes de llamar al algoritmo.
	int max = 0;
	std::vector<int> maxGananciasPorPos(nArtistas);
	// Nos guardamos las maximas ganancias posibles de cada hueco.
	for (int i = 0; i < nArtistas; i++)
	{
		for (int j = 0; j < nArtistas; j++)
		{
			if (recs[i][j] > max)
			{
				maxGananciasPorPos[i] = recs[i][j];
			}
		}
	}
	std::vector<int> estimacionOptimista(nArtistas);
	estimacionOptimista[nArtistas - 1] = maxGananciasPorPos[nArtistas - 1];
	for (int i = nArtistas - 2; i >= 0; i--)
	{
		estimacionOptimista[i] += estimacionOptimista[i + 1];
	}


	// Resolucion:
	std::vector<int>sol(nArtistas);
	int maxGanancias = -1;
	std::vector<bool>vistos(nArtistas);
	concierto(sol, 0, nArtistas, 0, maxGanancias, cons, recs, vistos, estimacionOptimista);


	// Escritura:
	if (maxGanancias == -1)
	{
		std::cout << "NEGOCIA CON LOS ARTISTAS" << std::endl;
	}
	else
	{
		std::cout << maxGanancias << std::endl;
	}
}

//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i)
	{
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}