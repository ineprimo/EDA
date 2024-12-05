// Plantilla para el ejercicio del Consultorio Médico

#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

#include <set>
#include <map>
#include <unordered_map>
using namespace std;

using medico = string;
using paciente = string;

class fecha {
public:
    int dia = 0;
    int hora = 0;   //Tiene que ser menor a 24 (A las 24 es 1 dia)
    int min = 0;    //Tiene que ser menor a 60 (A los 60 es 1 hora)

    fecha(int d, int h, int m) {    //Nos aseguramos de que siempre sean correctas

        if (m > 60) {
            hora++;
            min = m - 60;
        }
        else min = m;

        if (hora + h > 24) {
            dia++;
            hora = h - 24;
        }
        else hora = h;

        dia += d;
    }

    inline bool operator< (const fecha& f) {

        if (dia > f.dia && hora > f.hora && min > f.min) return false;
        else return true;

    }
};
class consultorio {
private:
    //Vamos a hacer un mapa que ponga por cada medico las horas que tiene pilladas
    unordered_map<medico, map<fecha, paciente, less<fecha>>> medicos;

    //La cosa es que la hora con el medico va con un paciente atachado
    //La clave es la fecha y el dato el paciente porque puede tener el mismo paciente a distintas horas

public:

    void nuevoMedico(medico m) {
        set<fecha, less<fecha>> h;
        medicos.insert({m, h});  //El propio map solo lo añade si no esta
    }

    void pideConsulta(paciente p, medico m, fecha f) {

        if (medicos.count(m) != 0) {

            //Buscamos la fecha para ver si esta ocupada
            if (medicos[m].count(f) == 0) { //La fecha no esta ocupada

                //Le ponemos la fecha al medico
                medicos[m].insert({ f });
            }
            else throw exception("Fecha ocupada");
        }
        else throw exception("Medico no existente");
    }

    void siguientePaciente(medico m) {
        //El paciente al que le toca es aquel que tenga la fecha menor
    }

    void atiendeConsulta(medico m) {

    }

    void listaPacientes(medico m, int d) {

    }

};

int casos = 0;
bool resuelve() {

    int N;
    cin >> N;
    if (!cin) return false;

    string inst; medico med; paciente pac; int d, h, m; char c;
    //Consultorio con;

    for (int i = 0; i < N; ++i) {
        try {
            cin >> inst;
            if (inst == "nuevoMedico") {
                cin >> med;
                //con.nuevoMedico(med);
            }
            else if (inst == "pideConsulta") {
                cin >> pac >> med >> d >> h >> c >> m;
               // con.pideConsulta(pac, med, fecha(d, h, m));
            }
            else if (inst == "siguientePaciente") {
                cin >> med;
                //pac = con.siguientePaciente(med);
                cout << "Siguiente paciente doctor " << med << '\n';
                cout << pac << '\n';
            }
            else if (inst == "atiendeConsulta") {
                cin >> med;
                //con.atiendeConsulta(med);
            }
            else if (inst == "listaPacientes") {
                cin >> med >> d;
                //auto vec = con.listaPacientes(med, fecha(d, 0, 0));
                cout << "Doctor " << med << " dia " << d << '\n';
                //for (auto p : vec) {
                    //cout << p.second << ' ' << p.first << '\n';
               // }
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
    while (resuelve());

    return 0;
}
