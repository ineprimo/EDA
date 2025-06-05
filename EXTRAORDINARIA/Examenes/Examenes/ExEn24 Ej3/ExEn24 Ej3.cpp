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
#include <queue>

using namespace std;

// ---- Entidades
using ContadorEntidades = int;
using Nombre = string;
using Vida = int;
using Turno = int;
using Vivo = bool;

struct Entidad
{
    Nombre nombre; // nombre
    Vida vida;     // puntos de vida
    //Turno turno;   // turno
    Vivo vivo = true;     // vivo
};

// ---- Villanos
using VillanoNombre = string;
using VillanoDano = int;
struct Villano : public Entidad
{
    VillanoDano dano;     // daño que hace al atacar
};
using Villanos = std::map<VillanoNombre, Villano>;

// ---- Heroes
using HeroeNombre = string;
using NombreAtaque = string;
using DanoAtaque = int;
using ListaAtaques = std::map<NombreAtaque, DanoAtaque>;

struct Heroe : Entidad
{
    ListaAtaques ataques;
};
using Heroes = std::map<HeroeNombre, Heroe>;

using ColaTurnos = std::queue<Entidad>;

class SistemaBatallas {
private:
    // metodos auxiliares?

    Villanos villanos;
    Heroes heroes;
    ContadorEntidades contadorEntidades = 0;
    ColaTurnos cola;

public:
    // Registra el nuevo villano v en la batalla con s puntos de vida y valor de ataque a.
    // Si el villano no había aparecido en la batalla, se registra.
    // Si el personaje ya había aparecido anteriormente en la batalla,
    // se lanza una excepción del tipo invalid_argument con el mensaje Personaje ya existente.
    // Coste: O(log n) siendo n el tamaño de villanos
    void aparece_villano(VillanoNombre const& v, int puntos, int valor)
	{
        // miras a ver si ha aparecido ya en la batalla
        // Si ha aparecido -> excepcion
        auto itAparecido = villanos.find(v);
        auto itAparecido2 = heroes.find(v);
        if (itAparecido != villanos.end() || itAparecido2 != heroes.end())
        {
            throw invalid_argument("Personaje ya existente");
        }

        // Si no -> se registras
        contadorEntidades++;
        Villano villano;
        villano.nombre = v;
        villano.vida = puntos;
        villano.dano = valor;
        villanos.insert({v, villano});
        cola.push(villano);
    }

    // Registra el nuevo héroe h en la batalla con s puntos de vida.
    // Si el héroe no había aparecido en la batalla, se registra.
    // Si el personaje ya había aparecido anteriormente en la batalla,
    // se lanza una excepción del tipo invalid_argument con el mensaje Personaje ya existente.
    // Coste: O(log n) siendo n el tamaño de heroes
    void aparece_heroe(HeroeNombre const& h, int puntos)
	{
        // miras a ver si ha aparecido ya en la batalla
        // Si ha aparecido -> excepcion
        auto itAparecido = heroes.find(h);
        auto itAparecido2 = villanos.find(h);
        if (itAparecido != heroes.end() || itAparecido2 != villanos.end())
        {
            throw invalid_argument("Personaje ya existente");
        }

        // Si no -> se registra
        contadorEntidades++;
        Heroe heroe;
        heroe.nombre = h;
        heroe.vida = puntos;
        heroes.insert({ h, heroe });
        cola.push(heroe);
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
        ColaTurnos aux = cola;

        for (int i = 0; i < cola.size(); i++)
        {
            auto villSearch = villanos.find(aux.front().nombre);
            if (villSearch != villanos.end())
            {
                aux.front().vida = villSearch->second.vida; // actualiza la cola con su vida
                aux.front().vivo = villSearch->second.vivo;
            }

            auto heroSearch = heroes.find(aux.front().nombre);
            if (heroSearch != heroes.end())
            {
                aux.front().vida = heroSearch->second.vida; // actualiza la cola con su vida
                aux.front().vivo = heroSearch->second.vivo;
            }

            if (aux.front().vivo)
            {
				res.emplace_back( aux.front().nombre,  aux.front().vida );
            }
            aux.pop();
        }

    	return res;
    }

    // El villano v ataca al héroe h, restándole a los puntos de vida del héroe el valor de daño de v.
    // Tras el ataque, v vuelve a pedir turno cuando corresponda.

    // Si el villano o el héroe no están registrados, se lanza una excepción con el mensaje Villano inexistente y Heroe inexistente.

    // Si no es el turno del villano pasado como parámetro, se lanza una excepción con el mensaje No es su turno.

    // Si el héroe atacado es derrotado, es decir, pierde todos sus puntos de vida, desaparece completamente de la batalla y
    // la función devuelve el valor cierto
    // Coste:
    bool villano_ataca(VillanoNombre const& v, HeroeNombre const& h)
	{
        bool derrotado = false;

        // Si el heroe no esta en batalla
        auto itHAparecido = heroes.find(h);
        if (itHAparecido == heroes.end())
        {
            throw invalid_argument("Heroe inexistente");
        }

        // Si el villano no esta en batalla
        auto itVAparecido = villanos.find(v);
        if (itVAparecido == villanos.end())
        {
            throw invalid_argument("Villano inexistente");
        }

        // actualiza cola
        auto it = villanos.find(cola.front().nombre);
        if (it != villanos.end())
        {
            cola.front().vida = it->second.vida;
            cola.front().vivo = it->second.vivo;
            if (!cola.front().vivo) cola.pop();
        }

        // Si no es el turno del villano
        if (cola.front().nombre != itVAparecido->first)
        {
            throw invalid_argument("No es su turno");
        }

        // Si villano esta vivo
        if (itVAparecido->second.vivo)
        {
            // actualiza su vida
            cola.front().vida = itVAparecido->second.vida;
            cola.front().vivo = itVAparecido->second.vivo;

            // Si heroe esta vivo
            if (itHAparecido->second.vivo)
            {
                // Ataca
                itHAparecido->second.vida -= itVAparecido->second.dano;

                // Si heroe muerto
                if (itHAparecido->second.vida <= 0)
                {
                    itHAparecido->second.vivo = false;
                    heroes.erase(itHAparecido);
                    derrotado = true;
                }

                // Vuelve a pedir turno
                cola.push(itVAparecido->second);
            	cola.pop();
            }
            else derrotado = true;
        }
        else {
            cola.pop(); // se elimina al villano de la cola
        }

        return derrotado;
    }

    // El héroe h ataca al villano v, restándole a los puntos de vida del villano el valor de daño del ataque a.
    // Tras el ataque, h vuelve a pedir turno cuando corresponda.

    // Si el villano o el héroe no están registrados, se lanza una excepción con el mensaje Villano inexistente y Heroe inexistente.

    // Si no es el turno del héroe pasado como parámetro, se lanza una excepción con el mensaje No es su turno.

    // Si el héroe h no conoce el ataque a, se lanza una excepción con el mensaje Ataque no aprendido.

    // Si el villano atacado es derrotado, desaparece completamente de la batalla y la función devuelve el valor cierto.
    // Coste:
    bool heroe_ataca(HeroeNombre const& h, string const& ataque, VillanoNombre const& v)
	{
        bool derrotado = false;

        // Si el heroe no esta en batalla
        auto itHAparecido = heroes.find(h);
        if (itHAparecido == heroes.end())
        {
            throw invalid_argument("Heroe inexistente");
        }

        // Si el villano no esta en batalla
        auto itVAparecido = villanos.find(v);
        if (itVAparecido == villanos.end())
        {
            throw invalid_argument("Villano inexistente");
        }

        // actualiza cola
        auto it = heroes.find(cola.front().nombre);
        if (it != heroes.end())
        {
	        cola.front().vida = it->second.vida;
	        cola.front().vivo = it->second.vivo;
	        if (!cola.front().vivo) cola.pop();
        }

        // Si no es el turno del heroe
        if (cola.front().nombre != itHAparecido->first)
        {
            throw invalid_argument("No es su turno");
        }

        // Si heroe esta vivo
        if (itHAparecido->second.vivo)
        {
            // actualiza su vida
            cola.front().vida = itHAparecido->second.vida;
            cola.front().vivo = itHAparecido->second.vivo;

            // Si villano esta vivo
            if (itVAparecido->second.vivo)
            {
                // Ataca
				// Si no conoce ese ataque
            	auto itAtaque = itHAparecido->second.ataques.find(ataque);
                if (itAtaque == itHAparecido->second.ataques.end())
                {
                    throw invalid_argument("Ataque no aprendido");
                }

                itVAparecido->second.vida -= itAtaque->second;

                // Si villano muerto
                if (itVAparecido->second.vida <= 0)
                {
                    itVAparecido->second.vivo = false;
                    villanos.erase(itVAparecido);
                    derrotado = true;
                }

                // Vuelve a pedir turno
                cola.push(itHAparecido->second);
                cola.pop();
            }
            else derrotado = true;
        }
        else {
            cola.pop(); // se elimina al heroe de la cola
        }

        return derrotado;
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
    ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
