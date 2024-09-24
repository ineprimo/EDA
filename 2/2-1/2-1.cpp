// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// función recursiva que no necesita “trocear” el num que recibe
// -> la única escritura debe hacerse en esta función 
//    (a excepción de los --- que irán en el resuelveCaso)
long long resolver(long long raiz, int max, int size)
{
    long long sol = raiz;
    int tam = size;

    if(size == max) // caso base / se queda igual (?)
    {
        //return sol;
    }
    else if(size < max) // caso recursivo / más dígitos (?)
    {
        // hace cosas
        
        resolver(sol, max, tam++);
    }

    std::cout << sol;
}

// función no recursiva que llame a otra función recursiva
// ESTA NO ESCRIBE
void escribePolidivisibles(long long raiz, int maxDigitos)
{
    int size = 0; // como mucho 18 digitos
    long long num = raiz; // para proteger raiz

    // lo calculo aquí porq me dicen que en la otra no puedo trocear
	while (raiz != 0) // mientras haya digitos que evaluar
	{
		raiz /= 10; // se va reduciendo digito a digito
		size++; // aumento size
	}

    raiz = num; // recupero el valor original de raiz

    resolver(raiz, maxDigitos, size);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    int d;

    std::cin >> n >> d;

    if (!std::cin)
        return false;

    // escribir sol
    escribePolidivisibles(n, d);

    std::cout << std::endl;
    std::cout << "----";

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