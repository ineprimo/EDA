// Ejercicio 3: Juego de batallas (4 puntos)
// Tipo: APLICACIONES DE TADs

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

using ContadorEntidades = int;
using Turno = int;

// ---- Villanos
using VillanoNombre = string;
using VillanoVida = int;
using VillanoDaño = int;

struct Villano
{
    VillanoNombre nombre; // nombre
	VillanoVida vida;     // puntos de vida
    VillanoDaño daño;     // daño que hace al atacar
    Turno turno;
};
using Villanos = std::map<VillanoNombre, Villano>;

// ---- Heroes
using HeroeNombre = string;
using HeroeVida = int;
using NombreAtaque = string;
using DañoAtaque = int;
using ListaAtaques = std::map<NombreAtaque, DañoAtaque>;

struct Heroe
{
    HeroeNombre nombre;
    HeroeVida vida;
    Turno turno;
    ListaAtaques ataques;
};
using Heroes = std::map<HeroeNombre, Heroe>;

class SistemaBatallas {
private:
    // metodos auxiliares?

    Villanos villanos;
    Heroes heroes;
    ContadorEntidades contadorEntidades = 0;

public:
    // Registra el nuevo villano v en la batalla con s puntos de vida y valor de ataque a.
    // Si el villano no había aparecido en la batalla, se registra.
    // Si el personaje ya había aparecido anteriormente en la batalla,
    // se lanza una excepción del tipo invalid_argument con el mensaje Personaje ya existente.
    // Coste: O(log n) siendo n el tamaño de villanos
    void aparece_villano(VillanoNombre const& v, int puntos, int valor)
	{
        // miras a ver si ha aparecido ya en la batalla
        auto itAparecido = villanos.find(v);

        // Si ha aparecido -> excepcion
        if (itAparecido != villanos.end())
        {
            throw invalid_argument("Personaje ya existente");
        }
        // Si no -> se registra
        contadorEntidades++;
        villanos.insert({v, {v, puntos, valor, contadorEntidades}});
    }

    // Registra el nuevo héroe h en la batalla con s puntos de vida.
    // Si el héroe no había aparecido en la batalla, se registra.
    // Si el personaje ya había aparecido anteriormente en la batalla,
    // se lanza una excepción del tipo invalid_argument con el mensaje Personaje ya existente.
    // Coste: O(log n) siendo n el tamaño de heroes
    void aparece_heroe(HeroeNombre const& h, int puntos)
	{
        // miras a ver si ha aparecido ya en la batalla
        auto itAparecido = heroes.find(h);

        // Si ha aparecido -> excepcion
        if (itAparecido != heroes.end())
        {
            throw invalid_argument("Personaje ya existente");
        }
        // Si no -> se registra
        contadorEntidades++;
        heroes.insert({ h, {h, puntos, contadorEntidades} });
    }

    // Añade el ataque a con daño v a la lista de ataques del héroe h.
    // Si el héroe no está en la batalla, se lanza una excepción del tipo invalid_argument con el mensaje Heroe inexistente.
    // Si el héroe conoce ya ese ataque, se lanza una excepción del tipo invalid_argument con el mensaje Ataque repetido.
    // Coste: O(log n)
    void aprende_ataque(HeroeNombre const& h, string const& ataque, int valor)
	{
        // Si el heroe no esta en batalla
        auto itAparecido = heroes.find(h);
        if (itAparecido == heroes.end())
        {
            throw invalid_argument("Heroe inexistente");
        }

        // Si el heroe ya conoce ese ataque
        auto itAtaque = itAparecido->second.ataques.find(ataque);
        if (itAtaque != itAparecido->second.ataques.end())
        {
            throw invalid_argument("Ataque repetido");
        }
        itAparecido->second.ataques.insert({ataque, valor});
    }

    // Devuelve un vector de pares (nombre, daño) ordenadados lexicográficamente con aquellos ataques aprendidos por el héroe h.
    // Si el héroe no está registrado, se lanza una excepción del tipo invalid_argument con el mensaje Heroe inexistente.
    // Coste: O(n)
    vector<pair<string, int>> mostrar_ataques(HeroeNombre const& h)
	{
        // Si el heroe no esta registrado
        auto itAparecido = heroes.find(h);
        if (itAparecido == heroes.end())
        {
            throw invalid_argument("Heroe inexistente");
        }

        vector<pair<string, int>> res;
        // como map esta ya ordenado simplemente vamos llenando el vector
        auto it = itAparecido->second.ataques.begin();
        while (it != itAparecido->second.ataques.end())
        {
            res.push_back({it->first, it->second});
            ++it;
        }
        
        return res;
    }

    // Devuelve un vector de pares con el nombre de todos los héroes y villanos acompañados de su cantidad correspondiente
    // de puntos de vida, ordenados según su turno
    // Coste:
    vector<pair<string, int>> mostrar_turnos()
	{
        vector<pair<string, int>> res;

    	return res;
    }

    // El villano v ataca al héroe h, restándole a los puntos de vida del héroe el valor de daño de v.
    // Tras el ataque, v vuelve a pedir turno cuando corresponda.
    // Si el villano o el héroe no están registrados, se lanza una excepción con el mensaje Villano inexistente y Heroe inexistente.
    // Si no es el turno del villano pasado como parámetro,
    // se lanza una excepción con el mensaje No es su turno.
    // Si el héroe atacado es derrotado, es decir, pierde todos sus puntos de vida, desaparece completamente de la batalla y
    // la función devuelve el valor cierto
    // Coste:
    bool villano_ataca(VillanoNombre const& v, HeroeNombre const& h)
	{
        ...
            throw invalid_argument("Villano inexistente");
        ...
            throw invalid_argument("Heroe inexistente");
        ...
            throw invalid_argument("No es su turno");
        ...
    }

    // El héroe h ataca al villano v, restándole a los puntos de vida del villano el valor de daño del ataque a.
    // Tras el ataque, h vuelve a pedir turno cuando corresponda.
    // Si el villano o el héroe no están registrados, se lanza una excepción con el mensaje Villano inexistente y Heroe inexistente.
    // Si no es el turno del héroe pasado como parámetro, se lanza una excepción con el mensaje No es su turno.
    // Si el héroe h no conoce el ataque a, se lanza una excepción con el mensaje Ataque no aprendido.
    // Si el villano atacado es derrotado, desaparece completamente de la batalla y la función devuelve el valor cierto.
    // Coste:
    bool heroe_ataca(HeroeNombre const& h, string const& ataque, VillanoNombre const& v) {
        ...
            throw invalid_argument("Villano inexistente");
        ...
            throw invalid_argument("Heroe inexistente");
        ...
            throw invalid_argument("No es su turno");
        ...
            throw invalid_argument("Ataque no aprendido");
        ...
    }
};


bool resuelveCaso() { // No tacar nada de esta función!
    string comando;
    cin >> comando;
    if (!cin) return false;

    SistemaBatallas sistema;
    VillanoNombre v; HeroeNombre h;
    string ataque; int ptos; int valor;
    while (comando != "FIN") {
        try {
            if (comando == "aparece_villano") {
                cin >> v >> ptos >> valor;
                sistema.aparece_villano(v, ptos, valor);
            }
            else if (comando == "aparece_heroe") {
                cin >> h >> ptos;
                sistema.aparece_heroe(h, ptos);
            }
            else if (comando == "aprende_ataque") {
                cin >> h >> ataque >> valor;
                sistema.aprende_ataque(h, ataque, valor);
            }
            else if (comando == "mostrar_ataques") {
                cin >> h;
                auto ataques = sistema.mostrar_ataques(h);
                cout << "Ataques de " << h << endl;
                for (auto& [ataque, valor] : ataques) {
                    cout << ataque << " " << valor << "\n";
                }
            }
            else if (comando == "mostrar_turnos") {
                cout << "Turno: " << endl;
                auto turnos = sistema.mostrar_turnos();
                for (auto& [pers, puntos] : turnos) {
                    cout << pers << " " << puntos << "\n";
                }
            }
            else if (comando == "villano_ataca") {
                cin >> v >> h;
                bool derrotado = sistema.villano_ataca(v, h);
                cout << v << " ataca a " << h << endl;
                if (derrotado) cout << h << " derrotado" << endl;
            }
            else if (comando == "heroe_ataca") {
                cin >> h >> ataque >> v;
                bool derrotado = sistema.heroe_ataca(h, ataque, v);
                cout << h << " ataca a " << v << endl;
                if (derrotado) cout << v << " derrotado" << endl;
            }
        }
        catch (std::exception& e) {
            cout << "ERROR: " << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

//#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
    ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
