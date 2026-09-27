#include "Jucator.h"
#include <iostream>
#include <cstring>
using namespace std;

Jucator::Jucator():Persoana(),rating(1700),activ(true),categorie('F'),anNastere(2000) { cout<<"[Jucator] Construit\n"; }
Jucator::Jucator(int id,const char* nume,float rating,bool activ,char categorie,int anNastere):Persoana(id,nume),rating(rating),activ(activ),categorie(categorie),anNastere(anNastere) { cout<<"[Jucator] Construit\n"; }
Jucator::Jucator(int id,const char* nume):Persoana(id,nume),rating(1700),activ(true),categorie('F'),anNastere(2000) { cout<<"[Jucator] Construit\n"; }
Jucator::Jucator(const char* nume,float rating):Persoana(0,nume),rating(rating),activ(true),categorie('F'),anNastere(2000) { cout<<"[Jucator] Construit\n"; }
Jucator::Jucator(const Jucator& j):Persoana(j),rating(j.rating),activ(j.activ),categorie(j.categorie),anNastere(j.anNastere) { cout<<"[Jucator] Construit\n"; }

Jucator::~Jucator() { cout<<"[Jucator] Distrus\n"; }

Jucator& Jucator::operator=(const Jucator& j) {
    if(this!=&j) {
        Persoana::operator=(j);
        rating=j.rating; activ=j.activ; categorie=j.categorie; anNastere=j.anNastere;
    }
    return *this;
}
char Jucator::operator[](unsigned int index) const {
    if(nume!=nullptr && index<strlen(nume)) return nume[index];
    return '-';
}
Jucator& Jucator::operator++() { rating++; return *this; }

Jucator Jucator::operator+(float x) const { Jucator copie(*this); copie.rating+=x; return copie; }

Jucator Jucator::operator-(float x) const { Jucator copie(*this); copie.rating-=x; if(copie.rating<0) copie.rating=0; return copie; }

Jucator operator+(float x,const Jucator& j) { return j+x; }
bool Jucator::operator==(const Jucator& j) const { return id==j.id; }
bool Jucator::operator>(const Jucator& j) const { return rating>j.rating; }

void Jucator::afiseazaTip() const { cout<<"[Jucator Amator]\n"; }
void Jucator::printeaza(ostream& out) const {
    out<<"ID: "<<id<<"\nNume: "<<nume<<"\nRating: "<<rating<<"\nActiv: "<<activ<<"\nCategorie: "<<categorie<<"\nAn nastere: "<<anNastere<<"\nJunior: "<<(esteJunior()?"Da":"Nu")<<"\n";
}
void Jucator::citeste(istream& in) {
    char buffer[100];
    cout<<"ID: "; in>>id;
    cout<<"Nume: "; in>>ws; in.getline(buffer,100); setNume(buffer);
    cout<<"Rating: "; in>>rating; if(rating<0) rating=0;
    cout<<"Activ(1/0): "; in>>activ;
    cout<<"Categorie(A-Z): "; in>>categorie;
    cout<<"An nastere: "; in>>anNastere; if(anNastere<1900) anNastere=2000;
}