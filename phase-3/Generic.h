#ifndef GENERIC_H
#define GENERIC_H
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "Exceptii.h"
#include "Patterns.h"
using namespace std;

// Functie template libera 1
template<typename Container, typename Pred>
void printeazaFiltrat(const Container& c, Pred p) {
    for(const auto& elem : c) {
        if(p(elem)) cout<<*elem<<"\n";
    }
}

//  Functie template libera 2
template<typename T>
void logheazaMesajGeneric(T msg) { Logger::getInstance().log("Generic log: " + to_string(msg)); }

//  Specializare totala pentru tipul std::string (pentru functia de mai sus)
template<>
inline void logheazaMesajGeneric<string>(string msg) { Logger::getInstance().log("String log: " + msg); }

//  Clasa template generica cu un parametru non-tip (int MAX_CAPACITY)
template<typename T, int MAX_CAPACITY>
class Depozitar {
    // Vector. Bun pt a gestiona o colectie mare de obiecte (Persoana, Partida) care se parcurg frecvent.
    vector<T*> elemente;
public:
    ~Depozitar() noexcept { for(auto e : elemente) delete e; }

    void adauga(T* elem) {
        if(elemente.size()>=MAX_CAPACITY) throw SahException("Capacitate depasita in Depozitar!");
        elemente.push_back(elem);
    }

    void sterge(int id) {
        // find_if cu Lambda
        auto it = find_if(elemente.begin(), elemente.end(), [id](T* e){ return e->getId()==id; });
        if(it==elemente.end()) throw NotFoundException("ID-ul nu a fost gasit!", id);
        delete *it;
        elemente.erase(it); // Erase-remove idiom pentru std::vector
    }

    T* gaseste(int id) {
        // Folosire find_if si a doua oara
        auto it = find_if(elemente.begin(), elemente.end(), [id](T* e){ return e->getId()==id; });
        if(it==elemente.end()) throw NotFoundException("ID-ul nu a fost gasit!", id);
        return *it;
    }

    const vector<T*>& getElemente() const { return elemente; }

    void sorteaza() {
        //  sort cu Lambda
        sort(elemente.begin(), elemente.end(), [](T* a, T* b){ return a->getId() < b->getId(); });
    }

    // metoda template in interiorul clasei template, cu tip independent U
    template<typename U>
    void transferaInLista(list<U*>& listaDest) const {
        for(auto e : elemente) {
            U* casted = dynamic_cast<U*>(e);
            if(casted) listaDest.push_back(casted);
        }
    }
};
#endif