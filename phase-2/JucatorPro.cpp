#include "JucatorPro.h"
#include <iostream>
#include <cstring>
using namespace std;

JucatorPro::JucatorPro() {
    sponsor=new char[strlen("Fara sponsor")+1];
    strcpy(sponsor,"Fara sponsor");
    cout<<"[JucatorPro] Construit\n";
}
JucatorPro::JucatorPro(int id,const char* nume,float rating,bool activ,char categorie,int anNastere,const char* sp)
    :Jucator(id,nume,rating,activ,categorie,anNastere) {
    this->sponsor=new char[strlen(sp)+1];
    strcpy(this->sponsor,sp);
    cout<<"[JucatorPro] Construit\n";
}
JucatorPro::JucatorPro(const JucatorPro& jp):Jucator(jp) {
    sponsor=new char[strlen(jp.sponsor)+1];
    strcpy(sponsor,jp.sponsor);
    cout<<"[JucatorPro] Construit\n";
}
JucatorPro::~JucatorPro() {
    cout<<"[JucatorPro] Distrus\n";
    if(sponsor!=nullptr) { delete[] sponsor; sponsor=nullptr; }
}
JucatorPro& JucatorPro::operator=(const JucatorPro& jp) {
    if(this!=&jp) {
        Jucator::operator=(jp);
        if(sponsor!=nullptr) { delete[] sponsor; sponsor=nullptr; }
        sponsor=new char[strlen(jp.sponsor)+1];
        strcpy(sponsor,jp.sponsor);
    }
    return *this;
}
void JucatorPro::afiseazaTip() const { cout<<"[Jucator Profesionist]\n"; }
void JucatorPro::printeaza(ostream& out) const {
    Jucator::printeaza(out);
    out<<"Sponsor: "<<sponsor<<"\n";
} // Cerinta 1: Baza::metoda()

void JucatorPro::citeste(istream& in) {
    Jucator::citeste(in);
    char buffer[100];
    cout<<"Sponsor: "; in>>ws; in.getline(buffer,100);
    if (sponsor!=nullptr) { delete[] sponsor; }
    sponsor=new char[strlen(buffer)+1];
    strcpy(sponsor,buffer);
}