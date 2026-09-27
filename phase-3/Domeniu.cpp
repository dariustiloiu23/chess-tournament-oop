#include "Domeniu.h"
#include "Exceptii.h"
#include "Patterns.h"
#include <iostream>
#include <sstream>
using namespace std;

Data::Data(int z, int l, int a):zi(z), luna(l), an(a) {}
string Data::toString() const { return to_string(zi)+"/"+to_string(luna)+"/"+to_string(an); }
istream& operator>>(istream& in, Data& d) { in>>d.zi>>d.luna>>d.an; return in; }

Persoana::Persoana(string n):IObject(), nume(n) {
    Logger::getInstance().log("Persoana adaugata: "+nume); //apel automat la Singleton Logger
}
Persoana::~Persoana() noexcept { Logger::getInstance().log("Persoana stearsa: "+nume); }
string Persoana::getNume() const { return nume; }
void Persoana::setNume(string n) {
    if(n.empty()) throw ValidareException("Numele nu poate fi gol", 0); //  Exceptie custom in setter
    nume=n;
}
istream& operator>>(istream& in, Persoana& p) { p.citeste(in); return in; }

Jucator::Jucator(string n, float r, bool act, char cat, int an)
    :Persoana(n), rating(r), activ(act), categorie(cat), anNastere(an) {
    if(r<0 || r>4000) throw ValidareException("Rating imposibil", r); //  Exceptie custom in constructor
}
Jucator::~Jucator() noexcept {}
float Jucator::getRating() const { return rating; }
bool Jucator::esteJunior() const { return anNastere>=2008; }
void Jucator::setRating(float r) {
    if(r<0 || r>4000) throw ValidareException("Rating invalid", r);
    rating=r;
}
string Jucator::getType() const { return "Jucator"; }
void Jucator::afiseazaTip() const { cout<<"[Tip: Jucator Amator]\n"; }
char Jucator::operator[](unsigned int index) const { if(index<nume.length()) return nume[index]; return '-'; }
Jucator& Jucator::operator++() { rating++; return *this; }
Jucator Jucator::operator+(float x) const { Jucator copie(*this); copie.rating+=x; return copie; }
Jucator Jucator::operator-(float x) const { Jucator copie(*this); copie.rating-=x; if(copie.rating<0) copie.rating=0; return copie; }
bool Jucator::operator>(const Jucator& j) const { return rating>j.rating; }
string Jucator::toString() const {
    ostringstream oss;
    oss<<"ID:"<<id<<" | Nume:"<<nume<<" | Rating:"<<rating<<" | Activ:"<<activ<<" | Cat:"<<categorie<<" | An:"<<anNastere;
    return oss.str();
}
void Jucator::citeste(istream& in) {
    cout<<"Nume: "; in>>ws; getline(in, nume);
    cout<<"Rating: "; in>>rating;
    if(rating<0) throw ValidareException("Rating negativ", rating);
    cout<<"Activ(1/0): "; in>>activ;
    cout<<"Categorie(A-Z): "; in>>categorie;
    cout<<"An nastere: "; in>>anNastere;
    if(anNastere<1900) throw ValidareException("An imposibil", anNastere);
}

JucatorPro::JucatorPro(string n, float r, bool act, char cat, int an, string sp)
    :Jucator(n, r, act, cat, an), sponsor(sp) {}
JucatorPro::~JucatorPro() noexcept {}
string JucatorPro::getType() const { return "Jucator PRO"; }
void JucatorPro::afiseazaTip() const { cout<<"[Tip: Jucator Profesionist]\n"; }
string JucatorPro::toString() const { return Jucator::toString() + " | Sponsor:" + sponsor; }
void JucatorPro::citeste(istream& in) {
    Jucator::citeste(in);
    cout<<"Sponsor: "; in>>ws; getline(in, sponsor);
}

Arbitru::Arbitru(string n, int exp, bool princ, char niv, int anL)
    :Persoana(n), experienta(exp), principal(princ), nivel(niv), anLicenta(anL) {}
Arbitru::~Arbitru() noexcept {}
string Arbitru::getType() const { return "Arbitru"; }
void Arbitru::afiseazaTip() const { cout<<"[Tip: Arbitru]\n"; }
bool Arbitru::poateFiPrincipal() const { return principal && experienta>=3; }
char Arbitru::operator[](unsigned int index) const { if(index<nume.length()) return nume[index]; return '-'; }
Arbitru& Arbitru::operator++() { experienta++; return *this; }
Arbitru Arbitru::operator+(int x) const { Arbitru copie(*this); copie.experienta+=x; return copie; }
Arbitru Arbitru::operator-(int x) const { Arbitru copie(*this); copie.experienta-=x; if(copie.experienta<0) copie.experienta=0; return copie; }
bool Arbitru::operator<(const Arbitru& a) const { return experienta<a.experienta; }
string Arbitru::toString() const {
    ostringstream oss;
    oss<<"ID:"<<id<<" | Arbitru:"<<nume<<" | Exp:"<<experienta<<" | Principal:"<<principal<<" | Nivel:"<<nivel<<" | Licenta:"<<anLicenta;
    return oss.str();
}
void Arbitru::citeste(istream& in) {
    cout<<"Nume: "; in>>ws; getline(in, nume);
    cout<<"Experienta(ani): "; in>>experienta;
    if(experienta<0) throw ValidareException("Experienta negativa", experienta);
    cout<<"Principal(1/0): "; in>>principal;
    cout<<"Nivel(A-Z): "; in>>nivel;
    cout<<"An licenta: "; in>>anLicenta;
    if(anLicenta<1950) throw ValidareException("An licenta invalid", anLicenta);
}

Partida::Partida(int alb, int negru, string rez, float dur, bool rtd, char rm, int maxM)
    :IObject(), idAlb(alb), idNegru(negru), rezultat(rez), durata(dur), rated(rtd), ritm(rm), nrMaximMutari(maxM) {
    Logger::getInstance().log("Partida creata");
}
Partida::~Partida() noexcept {}
bool Partida::esteRemiza() const { return rezultat == "1/2-1/2"; }
char Partida::operator[](unsigned int index) const { if(index<rezultat.length()) return rezultat[index]; return '-'; }
Partida& Partida::operator++() { durata++; return *this; }
Partida Partida::operator+(float x) const { Partida copie(*this); copie.durata+=x; return copie; }
Partida Partida::operator-(float x) const { Partida copie(*this); copie.durata-=x; if(copie.durata<0) copie.durata=0; return copie; }
bool Partida::operator>(const Partida& p) const { return durata>p.durata; }
string Partida::toString() const {
    ostringstream oss;
    oss<<"Partida ID:"<<id<<" | Alb:"<<idAlb<<" Negru:"<<idNegru<<" | Rez:"<<rezultat<<" | Durata:"<<durata<<"h | Rated:"<<rated<<" | Ritm:"<<ritm<<" | MaxMutari:"<<nrMaximMutari;
    return oss.str();
}
istream& operator>>(istream& in, Partida& p) {
    cout<<"ID Alb: "; in>>p.idAlb; cout<<"ID Negru: "; in>>p.idNegru;
    cout<<"Rezultat(1-0, 1/2-1/2, 0-1): "; in>>ws; getline(in, p.rezultat);
    cout<<"Durata(ore): "; in>>p.durata;
    if(p.durata<0) throw ValidareException("Durata negativa", p.durata);
    cout<<"Rated(1/0): "; in>>p.rated;
    cout<<"Ritm(A-Z): "; in>>p.ritm;
    cout<<"Nr maxim mutari: "; in>>p.nrMaximMutari;
    return in;
}

Turneu::Turneu(string n, float tx)
    :IObject(), nume(n), dataInceput(1,1,2024), nrRunde(7), taxa(tx), international(false), tip('C'), capacitateMaxima(100) {
    Logger::getInstance().log("Turneu creat");
}
Turneu::~Turneu() noexcept {}
bool Turneu::areLocuriLibere() const { return idParticipanti.size() < (size_t)capacitateMaxima; }
char Turneu::operator[](unsigned int index) const { if(index<nume.length()) return nume[index]; return '-'; }
Turneu& Turneu::operator++() { nrRunde++; return *this; }
Turneu Turneu::operator+(float x) const { Turneu copie(*this); copie.taxa+=x; return copie; }
Turneu Turneu::operator-(float x) const { Turneu copie(*this); copie.taxa-=x; if(copie.taxa<0) copie.taxa=0; return copie; }
bool Turneu::operator<(const Turneu& t) const { return taxa<t.taxa; }
string Turneu::toString() const {
    ostringstream oss;
    oss<<"Turneu ID:"<<id<<" | Nume:"<<nume<<" | Start:"<<dataInceput.toString()<<" | Runde:"<<nrRunde<<" | Taxa:"<<taxa<<" | Intl:"<<international<<" | Tip:"<<tip<<" | Participanti: "<<idParticipanti.size()<<"/"<<capacitateMaxima;
    return oss.str();
}
istream& operator>>(istream& in, Turneu& t) {
    cout<<"Nume: "; in>>ws; getline(in, t.nume);
    cout<<"Data Inceput(zi luna an || ex: 01 01 2020): "; in>>t.dataInceput;
    cout<<"Nr runde: "; in>>t.nrRunde;
    cout<<"Taxa: "; in>>t.taxa;
    if(t.taxa<0) throw ValidareException("Taxa invalida", t.taxa);
    cout<<"International(1/0): "; in>>t.international;
    cout<<"Tip(A-Z): "; in>>t.tip;
    cout<<"Capacitate maxima: "; in>>t.capacitateMaxima;
    if(t.capacitateMaxima<=0) throw ValidareException("Capacitate invalida", t.capacitateMaxima);

    int nrP; cout<<"Cati participanti introduceti acum? "; in>>nrP;
    if(nrP>t.capacitateMaxima) throw ValidareException("Depaseste capacitatea", nrP);
    t.idParticipanti.clear();
    for(int i=0; i<nrP; i++) {
        int idp; cout<<"ID participant "<<i+1<<": "; in>>idp;
        t.idParticipanti.push_back(idp);
    }
    return in;
}