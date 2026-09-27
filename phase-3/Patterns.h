#ifndef PATTERNS_H
#define PATTERNS_H
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

//Design Pattern: Singleton Meyers
class Logger {
    // Vector. Stocare contigua a sirurilor de caractere (log-uri) si eficienta la adaugare la final (push_back).
    vector<string> loguri;

    Logger(){} // Constructor privat
public:
    Logger(const Logger&) = delete; // Interzicem copierea
    Logger& operator=(const Logger&) = delete; // Interzicem atribuirea

    // Instanta statica locala - varianta Meyers
    static Logger& getInstance();
    void log(const string& msg);
    void afiseazaLoguri() const;
};

// Design Pattern: Abstract Factory (2 familii, 2 produse)
// Produse abstracte
class IPremiu { public: virtual string descriere() const=0; virtual ~IPremiu() noexcept {} };
class IDiploma { public: virtual string text() const=0; virtual ~IDiploma() noexcept {} };

//familia standard
class PremiuStandard : public IPremiu { public: string descriere() const override; };
class DiplomaStandard : public IDiploma { public: string text() const override; };

// familia vip
class PremiuVIP : public IPremiu { public: string descriere() const override; };
class DiplomaVIP : public IDiploma { public: string text() const override; };

// fabrica abstracta
class IFabricaFestivitate {
public:
    virtual IPremiu* crearePremiu() const=0;
    virtual IDiploma* creareDiploma() const=0;
    virtual ~IFabricaFestivitate() noexcept {}
};

// fabrici concrete
class FabricaStandard : public IFabricaFestivitate {
public:
    IPremiu* crearePremiu() const override;
    IDiploma* creareDiploma() const override;
};

class FabricaVIP : public IFabricaFestivitate {
public:
    IPremiu* crearePremiu() const override;
    IDiploma* creareDiploma() const override;
};

// clientul(dependency injection)
class Festivitate {
    IFabricaFestivitate* fabrica; // Lucreaza exclusiv cu interfata

    //Map. Pereche cheie-valoare. Cautarea/inserarea se fac in  O(log n).
    // Optimizeaza contorizarea automata a premiilor unui anumit jucator fara a itera o lista intreaga.
    map<string, int> istoricPremii;
public:
    Festivitate(IFabricaFestivitate* f);
    void setFabrica(IFabricaFestivitate* f); // Schimbarea familiei la runtime
    void premiazaJucator(const string& nume);
};
#endif