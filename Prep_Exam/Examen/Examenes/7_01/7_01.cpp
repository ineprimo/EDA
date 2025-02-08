#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
using namespace std;

using TablaRefs = map < string, list<int>>;

void referencias(int numLineas, TablaRefs& refs) {
	std::string palabra;
	char c;
	for (int numLinea = 1; numLinea <= numLineas; numLinea++) {
		std::cin.get(c);
		while (c != '\n') {
			cin.unget(); // Se vuelve a dejar c en cin (por si era la letra de la linea)
			cin >> palabra;

			if (palabra.size() > 2) // Solo palabras con mas de 2 letras.
			{
				// Todo en minusculas.
				for (auto& l : palabra)
				{
					l = tolower(l);
				}

				// Para ver si la palabra esta ya o no en el mapa.
				auto it = refs.find(palabra);

				// Casos si esta o no esta:
				if (it == refs.end()) // No esta si el it apunta al final de refs asi que la metemos junto con la linea.
				{
					list<int>aux;
					aux.push_back(numLinea);
					refs.insert({ palabra,aux });
				}
				else // Si ya esta le metemos la linea en la que se ha repedito si esa informacion no esta ya metida.
				{
					if (refs[palabra].back() != numLinea)
					{
						refs[palabra].push_back(numLinea);
					}
				}
			}
			cin.get(c);
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	char c;
	cin >> n;
	cin.get(c); // Me salto el \n de detras del N
	if (n == 0)
	{
		return false;
	}

	TablaRefs refs;
	referencias(n, refs);

	// escribir sol
	for (auto par : refs)
	{
		cout << par.first << " ";

		for (auto lis : par.second)
		{
			cout << lis << " ";
		}

		cout << endl;
	}
	cout << "---" << endl;
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
#endif

    return 0;
}