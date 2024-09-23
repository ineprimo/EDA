// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


// función que resuelve el problema
bool resolver(long long raiz, int numDigits) {

    if (numDigits == 1 && raiz % numDigits == 0) return true;
    //Comprobamos si el número es polidivisible
    else if (raiz % numDigits == 0) resolver(raiz / 10, numDigits - 1);
    
    else return false;

}

void escribePolidivisibles(long long raiz, int d) {

    //Función NO recursiva

    int num = 0;
    long long limit = 9;

    //Si el numero de digitos es igual a d devolvemos el propio numero

    long long datos = raiz;
    int i = 1;

    //Quiero contar el número de digitos que tenemos en la raiz
    // /-> Quito el de la derecha del todo
    // %-> Me quedo el de la derecha del todo
    while (raiz > 10)
    {
        raiz = raiz / 10;
        i++;
    }

    raiz = datos;

    //Mantiene que no se pase de digitos
    //aquí faltaría comprobar la propia raiz
    if (resolver(datos, i)) cout << datos << endl;

    while (i <= d) {

        //Esto hay que hacerlo de alguna manera que la i no se incremente al principio
         if (num == 0) {
             datos *= 10;
             i++;
         }


         //Vamos comprobando si el número es polidivisible
         if (resolver(datos, i) && i <= d ) cout << datos << endl;

         if (num == limit) {
             //Para que se quede en la siguiente posición y terminado en 9
             limit *= 10;
             limit += 9;

             datos -= num;
             num = 0;  //Probamos del 0 al 9
         }
         else {
             num++;
             datos += 1;
         }
    }
    

    cout << "---" << endl;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    long long N = 0;
    int D = 0;

    cin >> N >> D;

    if (!std::cin)
        return false;

    escribePolidivisibles(N, D);


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