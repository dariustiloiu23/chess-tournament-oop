#ifndef TURNEU_H
#define TURNEU_H
#include "Data.h"
#include <iostream>
using namespace std;

class Turneu {
    int id;
    char* nume;
    Data dataInceput; // compunere
    int nrRunde;
    float taxa;
    bool international;
    char tip;
    int* idParticipanti;
    int nrParticipanti;
    int capacitateMaxima;
    static int contor;
public:
    Turneu();
    Turneu(int id,const char* nume,int z,int l,int a,int nrRunde,float taxa,bool international,char tip,int* idParticipanti,int nrParticipanti,int capacitateMaxima);
    Turneu(int id,const char* nume);
    Turneu(const char* nume,float taxa);
    Turneu(const Turneu& t);
    ~Turneu();

    Turneu& operator=(const Turneu& t);

    int getId() const { return id; }
    const char* getNume() const { return nume; }
    int getNrRunde() const { return nrRunde; }
    float getTaxa() const { return taxa; }
    bool getInternational() const { return international; }
    char getTip() const { return tip; }
    int getNrParticipanti() const { return nrParticipanti; }
    int getCapacitateMaxima() const { return capacitateMaxima; }

    void setId(int id) { if(id>=0) this->id=id; }
    void setNume(const char* numeNou);
    void setNrRunde(int nrRunde) { if(nrRunde>0) this->nrRunde=nrRunde; }
    void setTaxa(float taxa) { if(taxa>=0) this->taxa=taxa; }
    void setInternational(bool international) { this->international=international; }
    void setTip(char tip) { this->tip=tip; }
    void setCapacitateMaxima(int capacitateMaxima) { if(capacitateMaxima>0 && capacitateMaxima>=nrParticipanti) this->capacitateMaxima=capacitateMaxima; }

    bool areLocuriLibere() const;
    bool adaugaParticipant(int idParticipant);
    char operator[](unsigned int index) const;

    Turneu& operator++();
    Turneu operator+(float x) const;
    Turneu operator-(float x) const;
    friend Turneu operator+(float x,const Turneu& t);
    bool operator==(const Turneu& t) const;
    bool operator<(const Turneu& t) const;

    friend ostream& operator<<(ostream& out,const Turneu& t);
    friend istream& operator>>(istream& in,Turneu& t);

    static int getContor() { return contor; }
};
#endif