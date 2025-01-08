#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

/*using artistaRec = std::vector<int>;
using artistaCon = std::vector<int>;

using recaudaciones = std::unordered_map<int, artistaRec>;
using consentimientos = std::unordered_map<int, artistaCon>;*/

// Tupla solucion: [Gi, Gi+1, Gi+2, ... , G(i+n)-1]
// siendo n el numero de artistas del concierto y siendo i la posicion en la que toca cada grupo(G)

/*bool esValida(vector<int>& soluc, int k, vector<bool>& vistos, consentimientos con)
{
	// es valida si el grupo no ha salido todavia y si encaja con los consentimientos de ese grupo
	return ((!vistos[soluc[k]]) && (k == 0 || (con[soluc[k]][soluc[k - 1]] == 1)));
}*/

// --- paramatros:
// - soluc -> vector solucion
// - k     -> posiciones de orden en el que tocar
// - i del for -> grupos que vas probando
// - n     -> num max de conciertos
// - rec   -> recaudaciones por artista en x pos
// - con   -> consentimientos por artista
// --- marcadores:
// - ganancias -> ganancias que vas aumulando en una rama
// - vistos    -> almacena si el concierto en la pos i ya ha sido visto

/*void concierto(vector<int>& soluc, int k, int n, int ganancias, int& maxGanancias,
	recaudaciones rec, consentimientos con, vector<bool>& vistos, vector<int> optimistaPorPos)
{
	// 1) for de candidatos     ->
	// --- 2) guardar el indice del for que se va probando en el vect solucion
	// --- 3) if esValida       -> ver si lo que acabas de guardar ha sido una eleccion valida
	// ------ 4) if esSolucion  -> se ha llegado al final del arbol
	// --------- 5) if esMejor  -> si lo recaudado supera la mejor recaudacion anterior
	// ------ 6) else / else if noSolucion (depende de si la condicion de final es llegar al final del arbol)
	// --------- 7) if poda     ->
	// ------------ 8) llamada recursiva k+1

	for (int i = 0; i < n; i++)
	{
		soluc[k] = i;

		if (esValida(soluc, k, vistos, con))
		{
			// marcamos
			ganancias += rec[i][k];
			vistos[i] = true;

			// comprobar final del arbol
			if (k == n - 1)
			{
				if (ganancias > maxGanancias) maxGanancias = ganancias;
			}
			else
			{
				if (ganancias + optimistaPorPos[k] > maxGanancias)
				{
					concierto(soluc, k + 1, n, ganancias, maxGanancias, rec, con, vistos, optimistaPorPos);
				}
			}

			// desmarcamos
			ganancias -= rec[i][k];
			vistos[i] = false;
		}
	}
}*/


bool esValida(const vector<int>& vSol, const int kElem, const vector<bool>& elegidos, const vector<vector<bool>>& vConsentimientos)
{
	// Es valida si el grupo no ha salido todavia y si encaja con los consentimientos de ese grupo
	return ((!elegidos[vSol[kElem]]) && (kElem == 0 || (vConsentimientos[vSol[kElem]][vSol[kElem - 1]])));
}


void concierto(vector<int>& vSol, const int kElem, const int nElems, int ingresos, int& mejoresIngresos, vector<bool>& elegidos,
	const vector<vector<int>>& vBeneficios, const vector<vector<bool>>& vConsentimientos,
	const vector<int>& mejoresBeneficios)
{
	// 1) for de candidatos     -> 
	// --- 2) guardar el indice del for que se va probando en el vect solucion
	// --- 3) if esValida       -> ver si lo que acabas de guardar ha sido una eleccion valida
	// ------ 4) if esSolucion  -> se ha llegado al final del arbol
	// --------- 5) if esMejor  -> si lo recaudado supera la mejor recaudacion anterior
	// ------ 6) else / else if noSolucion (depende de si la condicion de final es llegar al final del arbol)
	// --------- 7) if poda     ->
	// ------------ 8) llamada recursiva k+1

	for (int i = 0; i < nElems; ++i)
	{
		vSol[kElem] = i;

		if (esValida(vSol, kElem, elegidos, vConsentimientos))
		{
			// Marcamos.
			ingresos += vBeneficios[i][kElem];
			elegidos[i] = true;

			// Comprobar final del arbol.
			if (kElem == nElems - 1)
			{
				if (ingresos > mejoresIngresos) mejoresIngresos = ingresos;
			}
			else
			{
				if (ingresos + mejoresBeneficios[kElem + 1] > mejoresIngresos)
				{
					concierto(vSol, kElem + 1, nElems, ingresos, mejoresIngresos, elegidos, vBeneficios, vConsentimientos, mejoresBeneficios);
				}
			}

			// Desmarcamos.
			ingresos -= vBeneficios[i][kElem];
			elegidos[i] = false;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	int nElems = 0;
	cin >> nElems;

	vector<vector<int>> vBeneficios(nElems, vector<int>(nElems));
	vector<vector<bool>> vConsentimientos(nElems, vector<bool>(nElems));

	for (int i = 0; i < nElems; i++)
	{
		for (int j = 0; j < nElems; j++)
		{
			std::cin >> vBeneficios[i][j];
		}
	}
	for (int i = 0; i < nElems; i++)
	{
		for (int j = 0; j < nElems; j++)
		{
			int b;
			std::cin >> b;
			vConsentimientos[i][j] = b;
		}
	}

	// poda calculada desde fuera
	std::vector<int> maxBenefs(nElems);

	for (int i = 0; i < nElems; i++)
	{
		for (int j = 0; j < nElems; j++)
		{
			if (vBeneficios[j][i] > maxBenefs[i])
			{
				maxBenefs[i] = vBeneficios[j][i];
			}
		}
	}

	std::vector<int> mejoresBeneficiosDesde(nElems);

	mejoresBeneficiosDesde[nElems - 1] = maxBenefs[nElems - 1];


	for (int i = nElems - 2; i >= 0; i--)
	{
		mejoresBeneficiosDesde[i] += maxBenefs[i + 1];
		mejoresBeneficiosDesde[i] += maxBenefs[i];
	}

	vector<int> soluc(nElems);
	int k = 0;
	int ingresos = 0;
	int mejoresIngresos = -1;
	vector<bool> elegidos(nElems);
	concierto(soluc, k, nElems, ingresos, mejoresIngresos, elegidos, vBeneficios, vConsentimientos, mejoresBeneficiosDesde);

	if (mejoresIngresos == -1)
	{
		std::cout << "NEGOCIA CON LOS ARTISTAS" << std::endl;
	}
	else
	{
		std::cout << mejoresIngresos << std::endl;
	}




	/*int n = 0;

	cin >> n;

	artistaCon aCon(n);

	recaudaciones rec;
	consentimientos con;

	for (int i = 0; i < n; i++)
	{
		artistaRec aRec(n);
		for (int j = 0; j < n; j++)
		{
			std::cin >> aRec[j];
		}

		rec.insert({ i, aRec });
	}
	for (int i = 0; i < n; i++)
	{
		artistaCon aCon(n);
		for (int j = 0; j < n; j++)
		{
			std::cin >> aCon[j];
		}

		con.insert({ i, aCon });
	}

	std::vector<int> maxGananciasPos(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (con[i][j] > maxGananciasPos[i])
			{
				maxGananciasPos[i] = rec[i][j];
			}
		}
	}

	std::vector<int> optimistaPorPos(n);

	optimistaPorPos[n - 1] = maxGananciasPos[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		optimistaPorPos[i] += optimistaPorPos[i + 1];
	}

	vector<int> soluc(n);
	vector<bool> vistos(n);
	int maxGanancias = -1;
	concierto(soluc, 0, n, 0, maxGanancias, rec, con, vistos, optimistaPorPos);
	if (maxGanancias == -1) std::cout << "NEGOCIA CON LOS ARTISTAS" << std::endl;
	else std::cout << maxGanancias << std::endl;*/
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