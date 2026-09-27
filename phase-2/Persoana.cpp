#include "Persoana.h"
#include <cstring>
#include <iostream>
using namespace std;

int Persoana::contor=0;

Persoana::Persoana():id(0) {
    nume=new char[strlen("Anonim")+1];
    strcpy(nume,"Anonim");
    contor++;
    cout<<"[Persoana] Construita\n";
}
Persoana::Persoana(int id, const char* nume):id(id) {
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    contor++;
    cout<<"[Persoana] Construita\n";
}
Persoana::Persoana(const Persoana& p):id(p.id) {
    nume=new char[strlen(p.nume)+1];
    strcpy(nume,p.nume);
    contor++;
    cout<<"[Persoana] Construita\n";
}
Persoana::~Persoana() {
    cout<<"[Persoana] Distrusa\n";
    if(nume!=nullptr) { delete[] nume; nume=nullptr; }
    contor--;
}
Persoana& Persoana::operator=(const Persoana& p) {
    if(this!=&p) {
        if(nume!=nullptr) { delete[] nume; nume=nullptr; }
        id=p.id;
        nume=new char[strlen(p.nume)+1];
        strcpy(nume,p.nume);
    }
    return *this;
}
void Persoana::setNume(const char* numeNou) {
    if(numeNou!=nullptr && strlen(numeNou)>0) {
        if(nume!=nullptr) { delete[] nume; nume=nullptr; }
        nume=new char[strlen(numeNou)+1];
        strcpy(nume,numeNou);
    }
}
ostream& operator<<(ostream& out, const Persoana& p) { p.printeaza(out); return out; }
istream& operator>>(istream& in, Persoana& p) { p.citeste(in); return in; }