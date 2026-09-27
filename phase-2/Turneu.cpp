#include "Turneu.h"
#include <iostream>
#include <cstring>
using namespace std;

int Turneu::contor=0;

Turneu::Turneu():id(0),dataInceput(1,1,2024),nrRunde(7),taxa(100),international(false),tip('C'),nrParticipanti(0),capacitateMaxima(100) {
    nume=new char[strlen("Turneu")+1];
    strcpy(nume,"Turneu");
    idParticipanti=nullptr;
    contor++;
    cout<<"[Turneu] Construit\n";
}
Turneu::Turneu(int id,const char* nume,int z,int l,int a,int nrRunde,float taxa,bool international,char tip,int* idParticipanti,int nrParticipanti,int capacitateMaxima)
    :id(id),dataInceput(z,l,a),nrRunde(nrRunde),taxa(taxa),international(international),tip(tip),nrParticipanti(nrParticipanti),capacitateMaxima(capacitateMaxima) {
        this->nume=new char[strlen(nume)+1]; strcpy(this->nume,nume);
    if(this->nrParticipanti>this->capacitateMaxima) this->nrParticipanti=this->capacitateMaxima;
    if(this->nrParticipanti>0 && idParticipanti!=nullptr) {
        this->idParticipanti=new int[this->nrParticipanti];
        for(int i=0;i<this->nrParticipanti;i++) this->idParticipanti[i]=idParticipanti[i];
    } else { this->idParticipanti=nullptr; }
    contor++;
    cout<<"[Turneu] Construit\n";
}
Turneu::Turneu(int id,const char* nume):id(id),dataInceput(1,1,2024),nrRunde(7),taxa(100),international(false),tip('C'),nrParticipanti(0),capacitateMaxima(100) {
        this->nume=new char[strlen(nume)+1]; strcpy(this->nume,nume); idParticipanti=nullptr;
    contor++; cout<<"[Turneu] Construit\n";
}
Turneu::Turneu(const char* nume,float taxa):id(0),dataInceput(1,1,2024),nrRunde(7),taxa(taxa),international(false),tip('C'),nrParticipanti(0),capacitateMaxima(100) {
        this->nume=new char[strlen(nume)+1]; strcpy(this->nume,nume); idParticipanti=nullptr;
    contor++; cout<<"[Turneu] Construit\n";
}
Turneu::Turneu(const Turneu& t):id(t.id),dataInceput(t.dataInceput),nrRunde(t.nrRunde),taxa(t.taxa),international(t.international),tip(t.tip),nrParticipanti(t.nrParticipanti),capacitateMaxima(t.capacitateMaxima) {
    nume=new char[strlen(t.nume)+1]; strcpy(nume,t.nume);
    if(nrParticipanti>0 && t.idParticipanti!=nullptr) {
        idParticipanti=new int[nrParticipanti];
        for(int i=0;i<nrParticipanti;i++) idParticipanti[i]=t.idParticipanti[i];
    } else { idParticipanti=nullptr; }
    contor++;
    cout<<"[Turneu] Construit\n";
}
Turneu::~Turneu() {
    if(nume!=nullptr) { delete[] nume; nume=nullptr; }
    if(idParticipanti!=nullptr) { delete[] idParticipanti; idParticipanti=nullptr; }
    contor--;
    cout<<"[Turneu] Distrus\n";
}
Turneu& Turneu::operator=(const Turneu& t) {
    if(this!=&t) {
        if(nume!=nullptr) { delete[] nume; nume=nullptr; }
        if(idParticipanti!=nullptr) { delete[] idParticipanti; idParticipanti=nullptr; }
        id=t.id; dataInceput=t.dataInceput; nrRunde=t.nrRunde; taxa=t.taxa; international=t.international; tip=t.tip; nrParticipanti=t.nrParticipanti; capacitateMaxima=t.capacitateMaxima;
        nume=new char[strlen(t.nume)+1]; strcpy(nume,t.nume);
        if(nrParticipanti>capacitateMaxima) nrParticipanti=capacitateMaxima;
        if(nrParticipanti>0 && t.idParticipanti!=nullptr) {
            idParticipanti=new int[nrParticipanti];
            for(int i=0;i<nrParticipanti;i++) idParticipanti[i]=t.idParticipanti[i];
        } else { idParticipanti=nullptr; }
    }
    return *this;
}
void Turneu::setNume(const char* numeNou) {
    if(numeNou!=nullptr && strlen(numeNou)>0) {
        if(nume!=nullptr) { delete[] nume; nume=nullptr; }
        nume=new char[strlen(numeNou)+1]; strcpy(nume,numeNou);
    }
}
bool Turneu::areLocuriLibere() const { return nrParticipanti<capacitateMaxima; }
bool Turneu::adaugaParticipant(int idParticipant) {
    if(!areLocuriLibere()) return false;
    int* copie=new int[nrParticipanti+1];
    for(int i=0;i<nrParticipanti;i++) copie[i]=idParticipanti[i];
    copie[nrParticipanti]=idParticipant;
    if(idParticipanti!=nullptr) { delete[] idParticipanti; idParticipanti=nullptr; }
    idParticipanti=copie;
    nrParticipanti++; return true;
}
char Turneu::operator[](unsigned int index) const {
    if(nume!=nullptr && index<strlen(nume)) return nume[index]; return '-';
}
Turneu& Turneu::operator++() { nrRunde++; return *this; }
Turneu Turneu::operator+(float x) const { Turneu copie(*this); copie.taxa+=x; return copie; }
Turneu Turneu::operator-(float x) const { Turneu copie(*this); copie.taxa-=x; if(copie.taxa<0) copie.taxa=0; return copie; }
Turneu operator+(float x,const Turneu& t) { return t+x; }
bool Turneu::operator==(const Turneu& t) const { return id==t.id; }
bool Turneu::operator<(const Turneu& t) const { return taxa<t.taxa; }

ostream& operator<<(ostream& out,const Turneu& t) {
    out<<"ID: "<<t.id<<"\nNume: "<<t.nume<<"\nData Start: "<<t.dataInceput<<"\nNr runde: "<<t.nrRunde<<"\nTaxa: "<<t.taxa<<"\nInternational: "<<t.international<<"\nTip: "<<t.tip<<"\nNr participanti: "<<t.nrParticipanti<<"\nCapacitate maxima: "<<t.capacitateMaxima<<"\nParticipanti: ";
    for(int i=0;i<t.nrParticipanti;i++) out<<t.idParticipanti[i]<<" ";
    out<<"\n"; return out;
}
istream& operator>>(istream& in,Turneu& t) {
    char buffer[100]; int n;
    cout<<"ID: "; in>>t.id;
    cout<<"Nume: "; in>>ws; in.getline(buffer,100); t.setNume(buffer);
    cout<<"Data Inceput(zi luna an): "; in>>t.dataInceput;
    cout<<"Nr runde: "; in>>t.nrRunde; if(t.nrRunde<=0) t.nrRunde=1;
    cout<<"Taxa: "; in>>t.taxa; if(t.taxa<0) t.taxa=0;
    cout<<"International(1/0): "; in>>t.international;
    cout<<"Tip(A-Z): "; in>>t.tip;
    cout<<"Capacitate maxima: "; in>>t.capacitateMaxima; if(t.capacitateMaxima<=0) t.capacitateMaxima=100;
    cout<<"Numar participanti: "; in>>n;
    if(n<0) n=0; if(n>t.capacitateMaxima) n=t.capacitateMaxima;
    if(t.idParticipanti!=nullptr) { delete[] t.idParticipanti; t.idParticipanti=nullptr; }
    t.nrParticipanti=n;
    if(n>0) {
        t.idParticipanti=new int[n];
        for(int i=0;i<n;i++) { cout<<"ID participant "<<i+1<<": "; in>>t.idParticipanti[i]; }
    } else { t.idParticipanti=nullptr; }
    return in;
}