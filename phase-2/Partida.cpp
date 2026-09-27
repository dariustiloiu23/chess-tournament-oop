#include "Partida.h"
#include <cstring>
#include <iostream>
using namespace std;

int Partida::contor=0;

Partida::Partida():id(0),idAlb(0),idNegru(0),durata(0),rated(true),ritm('C'),nrMaximMutari(200) {
    rezultat=new char[strlen("1-0")+1];
    strcpy(rezultat,"1-0");
    contor++;
}
Partida::Partida(int id,int idAlb,int idNegru,const char* rezultat,float durata,bool rated,char ritm,int nrMaximMutari):id(id),idAlb(idAlb),idNegru(idNegru),durata(durata),rated(rated),ritm(ritm),nrMaximMutari(nrMaximMutari) {
    this->rezultat=new char[strlen(rezultat)+1];
    strcpy(this->rezultat,rezultat); contor++;
}
Partida::Partida(int id,int idAlb,int idNegru):id(id),idAlb(idAlb),idNegru(idNegru),durata(0),rated(true),ritm('C'),nrMaximMutari(200) {
    rezultat=new char[strlen("1/2-1/2")+1];
    strcpy(rezultat,"1/2-1/2"); contor++;
}
Partida::Partida(const char* rezultat,float durata):id(0),idAlb(0),idNegru(0),durata(durata),rated(true),ritm('C'),nrMaximMutari(200) {
    this->rezultat=new char[strlen(rezultat)+1];
    strcpy(this->rezultat,rezultat); contor++;
}
Partida::Partida(const Partida& p):id(p.id),idAlb(p.idAlb),idNegru(p.idNegru),durata(p.durata),rated(p.rated),ritm(p.ritm),nrMaximMutari(p.nrMaximMutari) {
    rezultat=new char[strlen(p.rezultat)+1];
    strcpy(rezultat,p.rezultat); contor++;
}
Partida::~Partida() {
    if(rezultat!=nullptr) { delete[] rezultat; rezultat=nullptr; } contor--;
}
Partida& Partida::operator=(const Partida& p) {
    if(this!=&p) {
        if(rezultat!=nullptr) { delete[] rezultat; rezultat=nullptr; }
        id=p.id; idAlb=p.idAlb; idNegru=p.idNegru; durata=p.durata; rated=p.rated; ritm=p.ritm; nrMaximMutari=p.nrMaximMutari;
        rezultat=new char[strlen(p.rezultat)+1]; strcpy(rezultat,p.rezultat);
    }
    return *this;
}
void Partida::setRezultat(const char* r) {
    if(r!=nullptr && strlen(r)>0) {
        if(rezultat!=nullptr) { delete[] rezultat; rezultat=nullptr; }
        rezultat=new char[strlen(r)+1]; strcpy(rezultat,r);
    }
}
bool Partida::esteRemiza() const { return strcmp(rezultat,"1/2-1/2")==0; }
char Partida::operator[](unsigned int index) const {
    if(rezultat!=nullptr && index<strlen(rezultat)) return rezultat[index]; return '-';
}
Partida& Partida::operator++() { durata++; return *this; }
Partida Partida::operator+(float x) const { Partida copie(*this); copie.durata+=x; return copie; }
Partida Partida::operator-(float x) const { Partida copie(*this); copie.durata-=x; if(copie.durata<0) copie.durata=0; return copie; }
Partida operator+(float x,const Partida& p) { return p+x; }
bool Partida::operator==(const Partida& p) const { return id==p.id; }
bool Partida::operator>(const Partida& p) const { return durata>p.durata; }

ostream& operator<<(ostream& out,const Partida& p) {
    out<<"ID: "<<p.id<<"\nID alb: "<<p.idAlb<<"\nID negru: "<<p.idNegru<<"\nRezultat: "<<p.rezultat<<"\nDurata: "<<p.durata<<"\nRated: "<<p.rated<<"\nRitm: "<<p.ritm<<"\nNr maxim mutari: "<<p.nrMaximMutari<<"\nEste remiza: "<<(p.esteRemiza()?"Da":"Nu")<<"\n";
    return out;
}
istream& operator>>(istream& in,Partida& p) {
    char buffer[50];
    cout<<"ID: "; in>>p.id;
    cout<<"ID alb: "; in>>p.idAlb;
    cout<<"ID negru: "; in>>p.idNegru;
    cout<<"Rezultat(1-0, 1/2-1/2, 0-1): "; in>>ws; in.getline(buffer,50); p.setRezultat(buffer);
    cout<<"Durata(nr ore): "; in>>p.durata; if(p.durata<0) p.durata=0;
    cout<<"Rated(1/0): "; in>>p.rated;
    cout<<"Ritm(A-Z): "; in>>p.ritm;
    cout<<"Nr maxim mutari: "; in>>p.nrMaximMutari; if(p.nrMaximMutari<=0) p.nrMaximMutari=200;
    return in;
}