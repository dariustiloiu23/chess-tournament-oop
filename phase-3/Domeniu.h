#ifndef DOMENIU_H
#define DOMENIU_H
#include "IObject.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Toate clasele de mai jos folosesc string, eliminand gestionarea memoriei manuale
// (Rule of Three simplificat, fara delete[] si fara new char[])

class Data {
    int zi, luna, an;
public:
    Data(int z=1, int l=1, int a=2000);
    string toString() const;
    friend istream& operator>>(istream& in, Data& d);
};

class Persoana : public IObject {
protected:
    string nume;
public:
    Persoana(string n);
    virtual ~Persoana() noexcept;
    string getNume() const;
    void setNume(string n);
    virtual string getType() const = 0;
    virtual void afiseazaTip() const = 0;
    virtual void citeste(istream& in) = 0;
    friend istream& operator>>(istream& in, Persoana& p);
};

class Jucator : public Persoana {
protected:
    float rating;
    bool activ;
    char categorie;
    int anNastere;
public:
    Jucator(string n="Anonim", float r=1700, bool act=true, char cat='F', int an=2000);
    ~Jucator() noexcept override;

    float getRating() const;
    bool esteJunior() const;
    void setRating(float r);
    string getType() const override;
    void afiseazaTip() const override;

    char operator[](unsigned int index) const;
    Jucator& operator++();
    Jucator operator+(float x) const;
    Jucator operator-(float x) const;
    bool operator>(const Jucator& j) const;

    string toString() const override;
    void citeste(istream& in) override;
};

class JucatorPro : public Jucator {
private:
    string sponsor;
public:
    JucatorPro(string n="Anonim", float r=2500, bool act=true, char cat='M', int an=1995, string sp="Fara");
    ~JucatorPro() noexcept override;

    string getType() const override;
    void afiseazaTip() const override;
    string toString() const override;
    void citeste(istream& in) override;
};

class Arbitru : public Persoana {
    int experienta;
    bool principal;
    char nivel;
    int anLicenta;
public:
    Arbitru(string n="Anonim", int exp=0, bool princ=false, char niv='C', int anL=2020);
    ~Arbitru() noexcept override;

    string getType() const override;
    void afiseazaTip() const override;
    bool poateFiPrincipal() const;

    char operator[](unsigned int index) const;
    Arbitru& operator++();
    Arbitru operator+(int x) const;
    Arbitru operator-(int x) const;
    bool operator<(const Arbitru& a) const;

    string toString() const override;
    void citeste(istream& in) override;
};

class Partida : public IObject {
    int idAlb, idNegru;
    string rezultat;
    float durata;
    bool rated;
    char ritm;
    int nrMaximMutari;
public:
    Partida(int alb=0, int negru=0, string rez="1/2-1/2", float dur=0, bool rtd=true, char rm='C', int maxM=200);
    ~Partida() noexcept override;

    bool esteRemiza() const;
    char operator[](unsigned int index) const;
    Partida& operator++();
    Partida operator+(float x) const;
    Partida operator-(float x) const;
    bool operator>(const Partida& p) const;

    string toString() const override;
    friend istream& operator>>(istream& in, Partida& p);
};

class Turneu : public IObject {
    string nume;
    Data dataInceput;
    int nrRunde;
    float taxa;
    bool international;
    char tip;
    int capacitateMaxima;
    vector<int> idParticipanti;
public:
    Turneu(string n="Turneu", float tx=100);
    ~Turneu() noexcept override;

    bool areLocuriLibere() const;
    char operator[](unsigned int index) const;
    Turneu& operator++();
    Turneu operator+(float x) const;
    Turneu operator-(float x) const;
    bool operator<(const Turneu& t) const;

    string toString() const override;
    friend istream& operator>>(istream& in, Turneu& t);
};
#endif