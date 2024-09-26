// Nieves Alonso Gilsanz
// EDA-GDV03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include <math.h>

int complementarios(int num, int &final, int size, int &i)
{
    int cociente = num / 10;
    int resto = num % 10;
    int digi = 0;

    digi = 9 - resto; // calculo el siguiente digito complementario

    // meto el digito en el num final multiplicado en su posicion
    final += (digi * std::pow(10, size - (size - i)));

    i += 1; // para pasar a la siguiente posicion en orden ascendente

    if (num < 10) // caso base / se llega al final, no hay mas que calcular
    {
        return final;
    }
    else // aun queda num que evaluar, se vuelve a llamar
    {
        complementarios(cociente, final, size, i);
    }
}

int complementariosInv(int num, int &final)
{
    int cociente = num / 10;
    int resto = num % 10;
    int digi = 0;

    final *= 10; // amplio el num final
    digi = 9 - resto; // calculo el siguiente digito complementario
    final += digi; // meto el digito en el num final
    
    if (num < 10) // caso base / se llega al final, no hay mas que calcular
    {
        return final;
    }
    else // aun queda num que evaluar, se vuelve a llamar
    {
        complementariosInv(cociente, final);
    }
}

// función que resuelve el problema
std::pair<int, int> resolver(int dato)
{
    std::pair<int, int> salida = { 0, 0 };

    int size = 0; // longitud del dato
    int num = dato; // para proteger dato

    while (dato != 0) // mientras haya digitos que evaluar
    {
        dato /= 10; // se va reduciendo digito a digito
        size++; // aumento size
    }

    size -= 1;
    dato = num;

    int finalC = 0;
    int finalI = 0;
    int i = 0;

    int comp = complementarios(dato, finalC, size, i);
    int compInv = complementariosInv(dato, finalI);

    salida.first = comp;
    salida.second = compInv;

    return salida;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int dato = 0;

    std::cin >> dato;

    std::pair<int, int> sol = resolver(dato);

    // escribir sol
    std::cout << sol.first << " " << sol.second << std::endl;
}

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
    system("PAUSE");
#endif

    return 0;
}