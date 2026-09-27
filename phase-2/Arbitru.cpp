#include "Arbitru.h"
#include <iostream>
#include <cstring>
using namespace std;

Arbitru::Arbitru():Persoana(),experienta(0),principal(false),nivel('C'),anLicenta(2020) { cout<<"[Arbitru] Construit\n"; }
Arbitru::Arbitru(int id,const char* nume,int experienta,bool principal,char nivel,int anLicenta):Persoana(id,nume),experienta(experienta),principal(principal),nivel(nivel),anLicenta(anLicenta) { cout<<"[Arbitru] Construit\n"; }
Arbitru::Arbitru(int id,const char* nume):Persoana(id,nume),experienta(0),principal(false),nivel('C'),anLicenta(2020) { cout<<"[Arbitru] Construit\n"; }
Arbitru::Arbitru(const char* nume,int experienta):Persoana(0,nume),experienta(experienta),principal(false),nivel('C'),anLicenta(2020) { cout<<"[Arbitru] Construit\n"; }
Arbitru::Arbitru(const Arbitru& a):Persoana(a),experienta(a.experienta),principal(a.principal),nivel(a.nivel),anLicenta(a.anLicenta) { cout<<"[Arbitru] Construit\n"; }
Arbitru::~Arbitru() { cout<<"[Arbitru] Distrus\n"; }

Arbitru& Arbitru::operator=(const Arbitru& a) {
    if(this!=&a) {
        Persoana::operator=(a);
        experienta=a.experienta; principal=a.principal; nivel=a.nivel; anLicenta=a.anLicenta;
    }
    return *this;
}
char Arbitru::operator[](unsigned int index) const {
    if(nume!=nullptr && index<strlen(nume)) return nume[index]; return '-';
}
Arbitru& Arbitru::operator++() { experienta++; return *this; }
Arbitru Arbitru::operator+(int x) const { Arbitru copie(*this); copie.experienta+=x; return copie; }
Arbitru Arbitru::operator-(int x) const { Arbitru copie(*this); copie.experienta-=x; if(copie.experienta<0) copie.experienta=0; return copie; }
Arbitru operator+(int x,const Arbitru& a) { return a+x; }
bool Arbitru::operator==(const Arbitru& a) const { return id==a.id; }
bool Arbitru::operator<(const Arbitru& a) const { return experienta<a.experienta; }

void Arbitru::afiseazaTip() const { cout<<"[Arbitru]\n"; }
void Arbitru::printeaza(ostream& out) const {
    out<<"ID: "<<id<<"\nNume: "<<nume<<"\nExperienta: "<<experienta<<"\nPrincipal: "<<principal<<"\nNivel: "<<nivel<<"\nAn licenta: "<<anLicenta<<"\nPoate fi principal: "<<(poateFiPrincipal()?"Da":"Nu")<<"\n";
}
void Arbitru::citeste(istream& in) {
    char buffer[100];
    cout<<"ID: "; in>>id;
    cout<<"Nume: "; in>>ws; in.getline(buffer,100); setNume(buffer);
    cout<<"Experienta(ani): "; in>>experienta; if(experienta<0) experienta=0;
    cout<<"Principal(1/0): "; in>>principal;
    cout<<"Nivel(A-Z): "; in>>nivel;
    cout<<"An licenta: "; in>>anLicenta; if(anLicenta<1950) anLicenta=2020;
}