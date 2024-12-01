/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
*/

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <stack>
#include <deque>

using namespace std;

using Heroe = string;
using Villano = string;

struct Attack {
    string name;
    int dmg;
};

struct Character {
    int hp;
    string name;
    bool dead;

    // set para gestionar los ataques, no tienen prioridad pero no se pueden suplicar
    unordered_map<string, Attack> attacks;
    stack<Attack> attack_stack;

};

struct Villain : public Character {

};

struct Hero : public Character {
    // ??

};

class SistemaBatallas {
private:
    // ...

    // cola para la gestion de turnos
    deque<Character> turns;

    // set no ordenado para la gestion de personajes activos
    //unordered_set<string> characters;
    unordered_map<string, Character> characters;



public:
    // Coste:
    void aparece_villano(Villano const& v, int puntos, int valor) {

        if (characters.size() > 0) {

            auto aux = characters.find(v);

            // si esta
            if (aux != characters.end()) {
                throw invalid_argument("Personaje ya existente");
            }
        }

        Villain villain = Villain();
        villain.name = v;
        villain.hp = puntos;
        villain.dead = false;

        Attack a = Attack();
        a.name = "default";
        a.dmg = valor;
        
        villain.attacks.insert({"default", a});
        villain.attack_stack.push(a);

        turns.push_back(villain);
        characters.insert({v, villain});
    }

    // Coste:
    void aparece_heroe(Heroe const& h, int puntos) {

        if (characters.size() > 0) {
            
            auto aux = characters.find(h);

            // si esta
            if (aux != characters.end()) {
                throw invalid_argument("Personaje ya existente");
            }
        }

        Hero hero = Hero();
        hero.name = h;
        hero.hp = puntos;
        hero.dead = false;

        turns.push_back(hero);
        characters.insert({h, hero});

    }

    // Coste:
    void aprende_ataque(Heroe const& h, string const& ataque, int valor) {
        
        if (characters.size() > 0) {

            auto aux = characters.find(h);

            // si esta
            if (aux == characters.end()) {
                throw invalid_argument("Heroe inexistente");
            }
            
            // nombre del heroe
            auto a = *(aux);
            
            characters.find(a.first);
            Character c = characters.at(a.first);

            if (!c.attack_stack.empty()) {

                //// mira si se repite
                //auto attk = c.attacks.find(ataque);
                //if (attk != c.attacks.end()) {
                //    throw invalid_argument("Ataque repetido");
                //}

                if (c.attack_stack.top().name == ataque)
                    throw invalid_argument("Ataque repetido");
            }

            Attack attk = Attack();
            attk.dmg = valor;
            attk.name = ataque;

            // si uso c no se guarda bien el valor 
            characters.at(a.first).attacks.insert({ ataque, attk });
            characters.at(a.first).attack_stack.push(attk);
        }
    }

    // Coste:
    vector<pair<string, int>> mostrar_ataques(Heroe const& h) {
        vector<pair<string, int>> res;
        if (characters.size() > 0) {

            auto aux = characters.find(h);

            // si no esta 
            if (aux == characters.end()) {
                throw invalid_argument("Heroe inexistente");
            }

            auto a = *(aux);
            unordered_map<string, Attack> attks = a.second.attacks;

            stack<Attack> aux_stack = a.second.attack_stack;

            int n = a.second.attack_stack.size();
            for (int i = 0; i < n; i++) {
                pair<string, int> o = { aux_stack.top().name, aux_stack.top().dmg };
                res.push_back(o);
                aux_stack.pop();
            }
        }
        else
            throw invalid_argument("Heroe inexistente");

        return res;
    }

    // Coste:
    vector<pair<string, int>> mostrar_turnos() {
        vector<pair<string, int>> res;
        deque<Character> aux = turns;

        for (int i = 0; i < turns.size(); i++) {
            auto c = characters.find(aux.front().name);

            res.push_back({c->first, c->second.hp});
            aux.pop_front();
        }

        return res;
    }

    // Coste:
    bool villano_ataca(Villano const& v, Heroe const& h) {
        bool dead = false;
        if (characters.size() > 0) {

            // mira si el villano existe
            auto villain_exists = characters.find(v);
            if (villain_exists == characters.end()) {
                throw invalid_argument("Villano inexistente");
            }

            // mira si el heroe existe
            auto hero_exists = characters.find(h);
            if (hero_exists == characters.end()) {
                throw invalid_argument("Heroe inexistente");
            }
            
            // mira si es su turno
            auto current_turn_holder = turns.front();
            if (current_turn_holder.name != villain_exists->first) {
                throw invalid_argument("No es su turno");
            }

            // gestiona el turno

            // el villano ataca al heroe
            int dmg = villain_exists->second.attack_stack.top().dmg;
            hero_exists->second.hp -= villain_exists->second.attack_stack.top().dmg;

            // pide turno
            turns.pop_front();
            turns.push_back(villain_exists->second);

            // mira muerte
            if (hero_exists->second.hp <= 0) {
                hero_exists->second.dead = true;
                characters.erase(hero_exists);  

                auto hero_dead = turns.begin();
                while (hero_dead != turns.begin() && hero_dead->name != h) {
                    hero_dead++;
                }
                turns.erase(hero_dead);


                dead = true;
            }
        }
        else 
            throw invalid_argument("Villano inexistente");

        return dead;
    }

    // Coste:
    bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {

        bool dead = false;
        if (characters.size() > 0) {

            // mira si el villano existe
            auto villain_exists = characters.find(v);
            if (villain_exists == characters.end()) {
                throw invalid_argument("Villano inexistente");
            }

            // mira si el heroe existe
            auto hero_exists = characters.find(h);
            if (hero_exists == characters.end()) {
                throw invalid_argument("Heroe inexistente");
            }

            // mira si es su turno
            auto current_turn_holder = turns.front();
            if (current_turn_holder.name != hero_exists->first) {
                throw invalid_argument("No es su turno");
            }

            // mira si existe el ataque
            auto attacks = hero_exists->second.attacks;
            if (attacks.size() > 0) {
                auto current_attack = attacks.find(ataque);
                if (current_attack == attacks.end()) {
                    throw invalid_argument("Ataque no aprendido");
                }


                //// el villano ataca al heroe
                villain_exists->second.hp -= current_attack->second.dmg;

                //// pide turno
                turns.pop_front();
                turns.push_back(hero_exists->second);
            }
            // aquiiiiiiii TO DO

            

            //// mira muerte
            if (villain_exists->second.hp <= 0) {

                villain_exists->second.dead = true;
                characters.erase(villain_exists);


                auto villain_dead = turns.begin();
                while (villain_dead != turns.begin() && villain_dead->name != v) {
                    villain_dead++;
                }
                turns.erase(villain_dead);

                dead = true;
            }
        }
        else
            throw invalid_argument("Villano inexistente");

        return dead;

    }

};


bool resuelveCaso() { // No tacar nada de esta función!
    string comando;
    cin >> comando;
    if (!cin) return false;

    SistemaBatallas sistema;
    Villano v; Heroe h;
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
                for (int i = 0; i < ataques.size(); i++) {
                    ataque = ataques[i].first;
                    valor = ataques[i].second;

                    cout << ataque << " " << valor << "\n";
                }
            }
            else if (comando == "mostrar_turnos") {
                cout << "Turno: " << endl;

                // vector<pair<string, int>>
                string pers; int puntos;
                auto turnos = sistema.mostrar_turnos();
                for (int i = 0; i < turnos.size(); i++) {
                    pers = turnos[i].first;
                    puntos = turnos[i].second;

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
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
