// Pablo Iglesias Rodrigo.
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Tupla solucion:
void sumasYRestas(std::vector<int>& vSol, int kElem, const int nElems, const int objM, int suma, const std::vector<int>& datos, bool& encontrado)
{
	if (encontrado)
	{
		return;
	}
	if (nElems == 0)
	{
		encontrado = true;
	}
	else
	{
		for (int i = 0; i < 2; i++) // Solo hay dos candidatos por nivel: '-' y '+'.
		{
			// i = 0 == '+' / i = 1 == '-'
			if (!encontrado)
			{
				vSol[kElem] = (i == 0) ? +1 : -1;

				// Marcar:
				suma += vSol[kElem] * datos[kElem];

				// Elemento 0 siempre va sumando o cualquierdo otro caso.
				if ((kElem == 0 && i == 0) || (kElem != 0))
				{
					if (kElem == nElems - 1)
					{
						if (suma == objM)
						{
							//std::cout << "Sumita: " << suma << std::endl;
							encontrado = true;
						}
					}
					else
					{
						// Llamada recursiva.
						sumasYRestas(vSol, kElem + 1, nElems, objM, suma, datos, encontrado);
					}
				}
				suma -= vSol[kElem] * datos[kElem];
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// Lectura:
	int objM = 0; // Objetivo de la suma.
	int nElems = 0; // Numero de elementos del vector.

	std::cin >> objM >> nElems;

	std::vector<int> datos(nElems); // Vector con los datos.

	for (int i = 0; i < nElems; i++)
	{
		std::cin >> datos[i];
	}

	// Resolucion:
	bool sol = false;
	std::vector<int>vSol(nElems);
	sumasYRestas(vSol, 0, nElems, objM, 0, datos, sol);

	// Escribir:
	(sol) ? std::cout << "SI" : std::cout << "NO";
	std::cout << std::endl;
	/*// Tupla solucion.
	for (auto e : vSol)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;*/
}

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
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}