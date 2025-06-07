// Ejercicio 3: Sala de urgencias (4 puntos)
// Tipo: APLICACIONES DE TADs

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <cassert>
#include <utility>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

using paciente = string;
using gravedad = int;

using enfermo = std::pair<paciente, gravedad>;

using listaEspera = list<enfermo>;
using registrados = unordered_map<paciente, gravedad>;

using sanos = map<paciente, gravedad>;

using listas = vector<listaEspera>;

class urgencias {
protected:
    // 3 listas, 1 por gravedad
    listaEspera graves;
    listaEspera medias;
    listaEspera leves;

    // mapa con todos los pacientes en el hospital
    registrados registros;

    // mapa con los pacientes que se han recuperado
    sanos pacientesSanos;

public:
    // registra a un nuevo paciente (un string), que ya ha sido preevaluado por un médico que
    // le ha asignado cierta gravedad(un int) : leve(1), media(2) o grave(3).
    // El paciente pasa a la sala de espera.

    // Si el paciente ya estaba registrado, lanzará una excepción domain_error con mensaje Paciente repetido.
    // Si la gravedad dada no es un número entre 1 y 3, se lanzará una excepción domain_error con el mensaje Gravedad incorrecta.
    // coste: O(n) en caso peor siendo n el tamaño del registros
    void nuevo_paciente(paciente p, gravedad g)
	{
        auto itRegistrado = registros.find(p);
        if (itRegistrado != registros.end())
        {
            throw domain_error("Paciente repetido");
        }

        if (g < 1 || g > 3)
        {
            throw domain_error("Gravedad incorrecta");
        }

        switch (g)
        {
	        case 1: leves.emplace_back(p, g); break;
	        case 2: medias.emplace_back(p, g); break;
	        case 3: graves.emplace_back(p, g); break;
        }

        // lo registra
        registros[p] = g;
    }

    // devuelve el entero que representa la gravedad actual de paciente.

    // Si el paciente no está en la sala de espera, se lanzará una excepción domain_error con mensaje Paciente inexistente
    // coste: O(n) en caso peor siendo n el tamaño del registros
    int gravedad_actual(paciente p) const
	{
        auto itRegistrado = registros.find(p);
        if (itRegistrado == registros.end())
        {
			throw domain_error("Paciente inexistente");
        }

        return itRegistrado->second;
    }

    // Devuelve el nombre del paciente al que le toca ser atendido, que abandona la sala de espera.
    // Los pacientes se atienden teniendo en cuenta su gravedad :
    // primero los graves, luego los de gravedad media y por último los leves.

    // Dentro de la misma gravedad se tiene en cuenta el orden de llegada (el primero que llega es el más prioritario),
    // o el que provoca la operación mejora de cambio de gravedad, explicada a continuación.

    // Si no hay pacientes se lanzará una excepción domain_error con mensaje No hay pacientes
    // coste: O(n) en caso peor siendo n el tamaño del registros
    paciente siguiente()
	{
        if (!graves.empty())
        {
            paciente aux = graves.front().first;
            graves.pop_front();
            registros.erase(aux); // le elimina de registros
	        return aux;
        }

        if (!medias.empty())
        {
            paciente aux = medias.front().first;
            medias.pop_front();
            registros.erase(aux); // le elimina de registros
            return aux;
        }

        if (!leves.empty())
        {
            paciente aux = leves.front().first;
            leves.pop_front();
            registros.erase(aux); // le elimina de registros
            return aux;
        }

		throw domain_error("No hay pacientes");
    }

    // registra el hecho de que un paciente mejora estando en la sala de espera.
    // Si estaba grave pasa a gravedad media y si tenía gravedad media pasa a leve.
    // Para el orden de atención se coloca como el más prioritario de los que tienen la nueva gravedad.
    // Si el paciente estaba leve, entonces se recupera y abandona las urgencias.
    // Si el paciente no existe, se lanzará una excepción domain_error con mensaje Paciente inexistente
    // coste: O(n) en caso peor siendo n el tamaño del registros -> por el find y el erase
    void mejora(paciente p)
	{
        auto itRegistrado = registros.find(p);
        if (itRegistrado == registros.end())
        {
            throw domain_error("Paciente inexistente");
        }

        int g = itRegistrado->second;

        switch (g)
        {
            // si estaba leve -> le dan el alta
        case 1:
	        {
                if (!leves.empty())
                {
		            auto i = leves.begin();
		            while (i != leves.end() && i->first != p) ++i;

                    if (i != leves.end())
                    {
                        i->second = g - 1;
                        leves.erase(i);
                        pacientesSanos[p] = 0; // lo mete al mapa de recuperados
                        registros.erase(p); // le elimina de registros
                    }
                }
	        }
            break;

            // si estaba medio -> pasa a leve
        case 2:
	        {
                if (!medias.empty())
                {
		            auto i = medias.begin();
		            while (i != medias.end() && i->first != p) ++i;

                    if (i != medias.end())
                    {
			            leves.push_front(*i);
			            medias.erase(i);
                        registros[p] = g - 1;
                    }
                }
	        }
            break;

            // si estaba grave -> pasa a medio
        case 3:
	        {
                if (!graves.empty())
                {
					auto i = graves.begin();
			        while (i != graves.end() && i->first != p) ++i;

                    if (i != graves.end())
                    {
                        medias.push_front(*i);
                        graves.erase(i);
                        registros[p] = g - 1;
                    }
                }
	        }
            break;
        }
    }

    // devuelve un tipo de datos lineal ordenado alfabéticamente (y sin repeticiones) con los pacientes que
    // han pasado alguna vez por el servicio de urgencias y se han recuperado del tod mientras esperaban
    // coste: O(n) en caso peor siendo n el tamaño de pacientesSanos
    list<paciente> recuperados() const
	{
        list<paciente> r;

        auto it = pacientesSanos.begin();
        while (it != pacientesSanos.end())
        {
            r.emplace_back(it->first);
            ++it;
        }

        return r;
    }
};

bool resuelveCaso() { // No tocar esta función
    string orden, pac;
    int grav;
    cin >> orden;
    if (!cin) return false;

    urgencias sala;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo_paciente") {
                cin >> pac >> grav;
                sala.nuevo_paciente(pac, grav);
            }
            else if (orden == "gravedad_actual") {
                cin >> pac;
                int g = sala.gravedad_actual(pac);
                cout << "La gravedad de " << pac << " es " << g << '\n';
            }
            else if (orden == "siguiente") {
                string p = sala.siguiente();
                cout << "Siguiente paciente: " << p << '\n';
            }
            else if (orden == "recuperados") {
                auto lista = sala.recuperados();
                cout << "Lista de recuperados:";
                for (auto& p : lista)
                    cout << ' ' << p;
                cout << '\n';
            }
            else if (orden == "mejora") {
                cin >> pac;
                sala.mejora(pac);
            }
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
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
