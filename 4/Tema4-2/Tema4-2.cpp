// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>


class Hora {
private:
    int s, m, h;

    bool check(int s_, int m_, int h_) {
        return 0 <= s_ <= 59 && 0 <= m_ <= 59 && 0 <= h_ <= 23;
    }

public:


    Hora(int s_, int m_, int h_) : s(s_), m(m_), h(h_) {
        if (check(s_, m_, h_)) {
            throw std::invalid_argument("ERROR");
        }
    };

    Hora(Hora& h) : s(h.s), m(h.m), h(h.h) {
        if (check(h.s, h.m, h.h)) {
            throw std::invalid_argument("ERROR");
        }
    };

    bool operator<(const Hora& hora) const {
        return (h > hora.h) || (h > hora.h && m > hora.m) || (h > hora.h && m > hora.m && s > hora.s);
    }   
    bool operator>(const Hora& hora) const {
        return (h > hora.h) || (h > hora.h && m > hora.m) || (h > hora.h && m > hora.m && s > hora.s);
    }
    bool operator==(const Hora& hora) const {
        return h == hora.h && m == hora.m && s == hora.s;
    }    
    Hora& operator=(const Hora& hora) {
        if (this != &hora)
        {
            if (!check(s, m, h))
                throw std::invalid_argument("ERROR");
            h = hora.h;
            m = hora.m;
            s = hora.s;
;
        }
        return *this;
    }



    friend std::ostream& operator<<(std::ostream& out, const Hora& h);
    friend std::istream& operator>>(std::istream& in, const Hora& h);
    
};

std::ostream& operator<<(std::ostream& out, const Hora& hora)
{
    // para poner un 0 delante de los numeros si hace falta
    out << (hora.h < 10 ? "0" : "") << hora.h << ":"
        << (hora.m < 10 ? "0" : "") << hora.m << ":"
        << (hora.s < 10 ? "0" : "") << hora.s;

    return out;
}

std::istream& operator>>(std::istream& in, Hora& hora)
{
    int aux1, aux2, aux3;
    in >> aux1;
    in.ignore(1, ':');
    in >> aux2;
    in.ignore(1, ':');
    in >> aux3;

    hora = Hora(aux1, aux2, aux3);

    return in;
}


// función que resuelve el problema
void resolver(int datos) {




}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    std::cin >> a;
    std::cin >> a;

    if (a == 0 && b == 0)
        return false;

    std::vector<Hora> trenes(a);
    Hora& aux;

    for (int i = 0; i < a; i++) {
        auto& = std::cin >> aux;
        trenes.push_back(aux);
    }



    resolver(a);

    // escribir sol



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