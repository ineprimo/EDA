
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <list>

#include <unordered_map>
#include <unordered_set>

using namespace std;

using cancion = std::string;
using artista = std::string;

class iPud {
private:
    struct infoCancion {
        artista artistaCancion;
        int duracionCancion;
    };
    unordered_map<cancion, infoCancion> canciones;

    list<cancion> playList;
    unordered_map<cancion, list<cancion>::iterator> it_playlist;

    list<cancion> recentList;
    unordered_map<cancion, list<cancion>::iterator> it_recentlist;

public:
    void addSong(cancion s, artista a, int d) {
        auto [_, ok] = canciones.insert({ s, infoCancion{a, d} });
        if (!ok) throw invalid_argument("addSong");
    }

    void addToPlaylist(cancion s) {
    auto itS = canciones.find(s);
    if (itS != canciones.end()) {
        if (it_playlist.find(s) == it_playlist.end()) {
            playList.push_back(s);
            it_playlist[s] = prev(playList.end());
        }
    }
    else throw invalid_argument("addToPlayList");
}

    cancion current() {
        if (!playList.empty()) return playList.front();
        else throw invalid_argument("current");
    }

    void play() {
        if (!playList.empty()) {
            cancion c = playList.front();
            // Eliminar de recentList si ya estaba
            auto itr = it_recentlist.find(c);
            if (itr != it_recentlist.end()) {
                recentList.erase(itr->second);
                it_recentlist.erase(itr);
            }
            recentList.push_front(c);
            it_recentlist[c] = recentList.begin();
            playList.pop_front();
            it_playlist.erase(c);
        }
    }

    int totalTime() {
        int duracionTotal = 0;
        for (auto it = playList.begin(); it != playList.end(); ++it) duracionTotal += canciones.at(*it).duracionCancion;
        return duracionTotal;
    }

    list<cancion> recent(int n) {
        list<cancion> auxList;
        unordered_set<cancion> yaIncluidas;

        if (n > recentList.size()) n = recentList.size();

        int count = 0;
        for (auto it = recentList.begin(); it != recentList.end() && count < n; ++it) {
            if (yaIncluidas.find(*it) == yaIncluidas.end()) {
                auxList.push_back(*it);
                yaIncluidas.insert(*it);
                ++count;
            }
        }

        return auxList;
    }

    void deleteSong(cancion s) {
        auto it = canciones.find(s);
        if (it != canciones.end()) {
            // Solo borrar si está en la playlist
            auto itp = it_playlist.find(s);
            if (itp != it_playlist.end()) {
                playList.erase(itp->second);
                it_playlist.erase(itp);
            }
            // Solo borrar si está en recentList
            auto itr = it_recentlist.find(s);
            if (itr != it_recentlist.end()) {
                recentList.erase(itr->second);
                it_recentlist.erase(itr);
            }
            canciones.erase(it);
        }
    }
};

bool resuelve() {
    string operacion;
    cin >> operacion;
    if (!cin)
        return false;
    cancion tit; artista aut; int dur;
    iPud ipud;
    while (operacion != "FIN") {
        try {
            if (operacion == "addSong") {
                cin >> tit >> aut >> dur;
                ipud.addSong(tit, aut, dur);
            }
            else if (operacion == "addToPlaylist") {
                cin >> tit;
                ipud.addToPlaylist(tit);
            }
            else if (operacion == "current") {
                tit = ipud.current(); // aunque no se hace nada, puede producir error
            }
            else if (operacion == "play") {
                try {
                    string tocando = ipud.current(); // para saber si la lista es vacía
                    ipud.play();
                    cout << "Sonando " << tocando << '\n';
                }
                catch (invalid_argument e) {
                    cout << "No hay canciones en la lista\n";
                }
            }
            else if (operacion == "totalTime") {
                cout << "Tiempo total " << ipud.totalTime() << '\n';
            }
            else if (operacion == "recent") {
                int N;
                cin >> N;
                auto lista = ipud.recent(N);
                if (lista.empty())
                    cout << "No hay canciones recientes\n";
                else {
                    cout << "Las " << lista.size() << " mas recientes\n";
                    for (auto const& s : lista)
                        cout << "    " << s << '\n';
                }
            }
            else if (operacion == "deleteSong") {
                cin >> tit;
                ipud.deleteSong(tit);
            }
            else { // operacion desconocida
                assert(false);
            }
        }
        catch (invalid_argument e) {
            cout << "ERROR " << e.what() << '\n';
        }
        cin >> operacion;
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
