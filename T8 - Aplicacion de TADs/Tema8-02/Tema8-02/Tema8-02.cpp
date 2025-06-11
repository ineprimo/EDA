// gdv-eda 70
// paula sierra luque

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <map>
#include <unordered_map>

#include <list>

using namespace std;

using medico = string;
using paciente = string;

class fecha {
private:
    int dia, hora, minuto;

public:
    fecha() : dia(0), hora(0), minuto(0) {}; // para medicos sin fecha asignada
    fecha(int d, int h, int m) : dia(d), hora(h), minuto(m) {};

    int getDia() const { return dia; }

    //bool operator==(const fecha& f) const { // const fecha& f -> const para no modificar la referencia, y el metodo tb const porque no modifica el objeto
    //    return dia == f.dia && hora == f.hora && minuto == f.minuto;
    //}

    bool operator<(const fecha& f) const 
    {
        if (dia != f.dia) return dia < f.dia;
        if (hora != f.hora) return hora < f.hora;
        return minuto < f.minuto;
    }

    // imprime HORA del dia f
    friend ostream& operator<<(ostream& o, const fecha& f)
    {        
        if (f.hora < 10) o << "0" << f.hora; // formato 00
        else o << f.hora;

        o << ":";

        if (f.minuto < 10) o << "0" << f.minuto; // formato 00
        else o << f.minuto;

        return o;
    }
};


class Consultorio {
private:

    struct InfoMedico {
        map<fecha, paciente> agenda; // {fecha, paciente}, usamos map porque las fechas se ordenan
    };

    unordered_map<medico, InfoMedico> medicos; // contiene medicos dados de alta {nombre, agenda}


public:
    // O(1)
    void nuevoMedico(const medico& m)
    {
        // insert: Si el medico ya estaba, no hace nada.
        medicos.insert({ m, InfoMedico() }); // le pasamos la agenda vacia
    }
    
    // O(log n) siendo n el numero de consultas del medico (por buscar e insertar en map)
    void pideConsulta(const paciente& p, const medico& m, const fecha& f) 
    {
        //primero vemos si el medico esta dado de alta
        auto it = medicos.find(m); // O(1)

        if (it != medicos.end()) // encontrado
        { 
            // si el medico ya tiene esa fecha excepcion:
            auto itAg = it->second.agenda.find(f); // it->second.agenda -> acceder al map
            
            if (itAg != it->second.agenda.end()) // si encontramos la fecha
            {
                throw invalid_argument("Fecha ocupada");
            }

            // si no la tiene, reservamos:
            it->second.agenda[f] = p; 

            //it->second.agenda.insert({ f,p }); tambien valdria
            
        }
        else // no encontrado
        {
            throw invalid_argument("Medico no existente");
        }
    }

    paciente siguientePaciente(const medico& m) const 
    {
        // miramos si el medico esta dado de alta
        auto it = medicos.find(m); // O(1)

        if (it != medicos.end()) // encontrado
        {
            // comprobamos si tiene pacientes primero:
            if (it->second.agenda.empty())
                throw invalid_argument("No hay pacientes");

            // devolvemos el paciente con fecha menor -> sera el primero en el mapa ya que ha sido ordenado (map) con el operador <
            return it->second.agenda.begin()->second; 
            
            //return medicos[m].agenda.begin()->second;

            /// un poco lioso pero:
            // -  {m, {f, p}} -> .second.second; si queremos mostrar la fecha seria .second.first
            // -  sabemos que es begin porque las fechas estan ordeandas!!
        }
        else // no encontrado
        {
            throw invalid_argument("Medico no existente");
        }
    }

    // O(log n)
    void atiendeConsulta(const medico& m) 
    {
        // primero vemos si el medico esta dado de alta
        auto it = medicos.find(m); // O(1)
        if (it == medicos.end())
            throw invalid_argument("Medico no existente");

        // si existe, eliminamos el siguiente paciente
        if (!it->second.agenda.empty()) {
            it->second.agenda.erase(it->second.agenda.begin()); // O(log n)
        }
        else {
            throw invalid_argument("No hay pacientes");
        }
    }

    map<fecha,paciente> listaPacientes(const medico& m, const fecha& f)
    {
        // primero vemos si el medico esta dado de alta
        auto it = medicos.find(m); // O(1)
        if (it == medicos.end())
            throw invalid_argument("Medico no existente");

        map<fecha, paciente> result;

        // recorremos la agenda
        for (const auto& cita : it->second.agenda)
        {
            // si los dias coinciden
            if (cita.first.getDia() == f.getDia()) 
            {
                // añadimos a la lista
                result.insert({cita.first, cita.second});
            }
        }

        return result;
    }
};


int casos = 0;
bool resuelve() {

    int N;
    cin >> N;
    if (!cin) return false;

    string inst; medico med; paciente pac; int d, h, m; char c;

    Consultorio con;

    for (int i = 0; i < N; ++i) {
        try {
            cin >> inst;
            if (inst == "nuevoMedico") {
                cin >> med;
                con.nuevoMedico(med);
            }
            else if (inst == "pideConsulta") {
                cin >> pac >> med >> d >> h >> c >> m;
                con.pideConsulta(pac, med, fecha(d, h, m));
            }
            else if (inst == "siguientePaciente") {
                cin >> med;
                pac = con.siguientePaciente(med);
                cout << "Siguiente paciente doctor " << med << '\n';
                cout << pac << '\n';
            }
            else if (inst == "atiendeConsulta") {
                cin >> med;
                con.atiendeConsulta(med);
            }
            else if (inst == "listaPacientes") {
                cin >> med >> d;
                auto vec = con.listaPacientes(med, fecha(d, 0, 0));
                cout << "Doctor " << med << " dia " << d << '\n';
                for (auto p : vec) {
                    cout << p.second << " " << p.first << '\n';
                }
            }
            else
                assert(false);
        }
        catch (invalid_argument e) { cout << e.what() << '\n'; }
    }
    cout << "---\n";

    return true;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelve())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
