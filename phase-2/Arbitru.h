#ifndef ARBITRU_H
#define ARBITRU_H
#include "Persoana.h"
#include <iostream>
using namespace std;

class Arbitru : public Persoana {
    int experienta;
    bool principal;
    char nivel;
    int anLicenta;

public:
    Arbitru();
    Arbitru(int id,const char* nume,int experienta,bool principal,char nivel,int anLicenta);
    Arbitru(int id,const char* nume);
    Arbitru(const char* nume,int experienta);
    Arbitru(const Arbitru& a);
    ~Arbitru() override;

    Arbitru& operator=(const Arbitru& a);
    int getExperienta() const { return experienta; }
    bool getPrincipal() const { return principal; }
    char getNivel() const { return nivel; }
    int getAnLicenta() const { return anLicenta; }
    void setExperienta(int experienta) { if(experienta>=0) this->experienta=experienta; }
    void setPrincipal(bool principal) { this->principal=principal; }
    void setNivel(char nivel) { this->nivel=nivel; }
    void setAnLicenta(int anLicenta) { if(anLicenta>1900) this->anLicenta=anLicenta; }
    bool poateFiPrincipal() const { return principal && experienta>=3; }
    char operator[](unsigned int index) const;

    Arbitru& operator++();
    Arbitru operator+(int x) const;
    Arbitru operator-(int x) const;
    friend Arbitru operator+(int x,const Arbitru& a);
    bool operator==(const Arbitru& a) const;
    bool operator<(const Arbitru& a) const;
    void afiseazaTip() const override;
    void printeaza(ostream& out) const override;
    void citeste(istream& in) override;
};
#endif