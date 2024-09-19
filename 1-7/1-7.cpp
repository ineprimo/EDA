// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

// función que resuelve el problema
// La complejidad es O(n * log n) siendo n eda.size + tpv.size
// la función find tiene complejidad log n:
// https://en.cppreference.com/w/cpp/container/set/find
void comparaListados(const vector<string>& eda, const vector<string>& tpv,
                     vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv)
{
    set<string> setEda(eda.begin(), eda.end());
    set<string> setTpv(tpv.begin(), tpv.end());
    
    for (const string& alumno : eda) 
        if (setTpv.find(alumno) != setTpv.end()) 
            comunes.push_back(alumno);
    
    for (const string& alumno : eda)
        if (setTpv.find(alumno) == setTpv.end()) 
            soloEda.push_back(alumno);
    
    for (const string& alumno : tpv) 
        if (setEda.find(alumno) == setEda.end()) 
            soloTpv.push_back(alumno);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	cin >> n;
	vector<string> eda(n);
	vector<string> comunes;
	vector<string> soloEda;
	vector<string> soloTpv;
	for (string& e : eda) cin >> e;
	cin >> n;
	vector<string> tpv(n);
	for (string& e : tpv) cin >> e;
	comparaListados(eda, tpv, comunes, soloEda, soloTpv);
	for (string& e : comunes) cout << e << " ";
	cout << endl;
	for (string& e : soloEda) cout << e << " ";
	cout << endl;
	for (string& e : soloTpv) cout << e << " ";
	cout << endl;
}


//#define DOMJUDGE
int main()
{
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
