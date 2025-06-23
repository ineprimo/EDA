// Plantilla para el ejercicio del Consultorio Médico

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>

#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

using medico = string;
using paciente = string;

class fecha {
public:
    fecha() {
        dia = 0;
        hora = 0;
        minuto = 0;
    };

    fecha(int d, int h, int m) {
        dia = d;
        hora = h;
        minuto = m;
    }

    bool operator<(const fecha& other) const {
        if (dia != other.dia) return dia < other.dia;
        if (hora != other.hora) return hora < other.hora;
        return minuto < other.minuto;
    }

    friend ostream& operator<<(ostream& o, const fecha& f) {
        if (f.hora < 10) o << "0";
        o << f.hora;

        o << ":";

        if (f.minuto < 10) o << "0";
        o << f.minuto;

        return o;
    }

    int getDia() { return dia; }
    int getHora() { return hora; }
    int getMinuto() { return minuto; }

private:
    int dia, hora, minuto;
};

class Consultorio {
private:   

    struct infoMedico {
        map<fecha, paciente> pacientes;
    };

    unordered_map<medico, infoMedico> medicos;

public:
    void nuevoMedico(medico m) {
        medicos.insert({ m, infoMedico() });
    }

    void pideConsulta(paciente p, medico m, fecha f) {
        auto itM = medicos.find(m);
        if (itM != medicos.end()) {
            auto itF = itM->second.pacientes.find(f);
            if (itF == itM->second.pacientes.end()) {
                //medicos[m].pacientes.insert({f, p});
                itM->second.pacientes[f] = p;
            }
            else throw invalid_argument("Fecha ocupada");
        }
        else throw invalid_argument("Medico no existente");
    }

    paciente siguientePaciente(medico m) {
        auto itM = medicos.find(m);
        if (itM != medicos.end()) {
            if (!itM->second.pacientes.empty()) {
                return itM->second.pacientes.begin()->second;
            }
            else throw invalid_argument("No hay pacientes");
        }
        else throw invalid_argument("Medico no existente");
    }

    void atiendeConsulta(medico m) {
        auto itM = medicos.find(m);
        if (itM != medicos.end()) {
            if (!itM->second.pacientes.empty()) {
                itM->second.pacientes.erase(itM->second.pacientes.begin());
            }
            else throw invalid_argument("No hay pacientes");
        }
        else throw invalid_argument("Medico no existente");
    }

    vector<pair<fecha, paciente>> listaPacientes(medico m, fecha f) {
        vector<pair<fecha, paciente>> lista;

        auto itM = medicos.find(m);
        if (itM != medicos.end()) {
            for (const auto& cita : itM->second.pacientes) {
                fecha fc = cita.first;
                if (fc.getDia() == f.getDia()) {
                    lista.push_back({cita.first , cita.second });
                }
            }
            return lista;
        }
        else throw invalid_argument("Medico no existente");
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
                    cout << p.second << ' ' << p.first << '\n';
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
