// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <stack>


// función que resuelve el problema
// O(2n) = O(n)  siendo n el tamaño de la colas
void resolver(std::queue<int>& datos) {
    std::queue<int> positivos; // es queue porque es fifo y los numeros van a venir ordenados de menos a mayor
    std::stack<int> negativos; // es stack porque es lifo y los numeros van a venir ordenados de menor a mayor

    while (!datos.empty())
    { // se divide la cola en dos tads y se vacia
        if (datos.front() < 0) 
            negativos.push(datos.front());
        else positivos.push(datos.front());
	    datos.pop(); 
    }

    // se vuelve a rellenar la cola pero ordenada
    while (!negativos.empty())
    {
        datos.push(negativos.top());
	    negativos.pop();
    }

    while (!positivos.empty())
    {
	    datos.push(positivos.front());
        positivos.pop();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    std::cin >> n;

    if (n == 0)
        return false;

    std::queue<int> cola;
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        std::cin >> m;
        cola.push(m);
    }

    resolver(cola);

	while (!cola.empty()) {
		std::cout << cola.front() << " ";
		cola.pop();
	}
    std::cout << '\n';

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
