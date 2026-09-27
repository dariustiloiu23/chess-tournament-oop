#ifndef PARTIDA_H
#define PARTIDA_H
#include <iostream>
using namespace std;

class Partida {
    int id;
    int idAlb;
    int idNegru;
    char* rezultat;
    float durata;
    bool rated;
    char ritm;
    int nrMaximMutari;
    static int contor;
public:
    Partida();
    Partida(int id,int idAlb,int idNegru,const char* rezultat,float durata,bool rated,char ritm,int nrMaximMutari);
    Partida(int id,int idAlb,int idNegru);
    Partida(const char* rezultat,float durata);
    Partida(const Partida& p);
    ~Partida();

    Partida& operator=(const Partida& p);
    int getId() const { return id; }
    int getIdAlb() const { return idAlb; }
    int getIdNegru() const { return idNegru; }
    const char* getRezultat() const { return rezultat; }
    float getDurata() const { return durata; }
    bool getRated() const { return rated; }
    char getRitm() const { return ritm; }
    int getNrMaximMutari() const { return nrMaximMutari; }
    void setId(int id) { if(id>=0) this->id=id; }
    void setIdAlb(int idAlb) { if(idAlb>=0) this->idAlb=idAlb; }
    void setIdNegru(int idNegru) { if(idNegru>=0) this->idNegru=idNegru; }
    void setRezultat(const char* r);
    void setDurata(float durata) { if(durata>=0) this->durata=durata; }
    void setRated(bool rated) { this->rated=rated; }
    void setRitm(char ritm) { this->ritm=ritm; }
    void setNrMaximMutari(int nrMaximMutari) { if(nrMaximMutari>0) this->nrMaximMutari=nrMaximMutari; }

    bool esteRemiza() const;
    char operator[](unsigned int index) const;
    Partida& operator++();
    Partida operator+(float x) const;
    Partida operator-(float x) const;
    friend Partida operator+(float x,const Partida& p);
    bool operator==(const Partida& p) const;
    bool operator>(const Partida& p) const;
    friend ostream& operator<<(ostream& out,const Partida& p);
    friend istream& operator>>(istream& in,Partida& p);

    static int getContor() { return contor; }
};
#endif