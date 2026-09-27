#include <iostream>
#include <cstring>
using namespace std;
class Jucator {
    int id;
    char* nume;
    float rating;
    bool activ;
    char categorie;
    int anNastere;
    static int contor;
public:
    Jucator():id(0),rating(1700),activ(true),categorie('F'),anNastere(2000) {

        nume=new char[strlen("Anonim")+1];
        strcpy(nume,"Anonim");
        contor++;
    }

    Jucator(int id,const char* nume,float rating,bool activ,char categorie,int anNastere):id(id),rating(rating),activ(activ),categorie(categorie),anNastere(anNastere) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
        contor++;
    }
    Jucator(int id,const char* nume):id(id),rating(1700),activ(true),categorie('F'),anNastere(2000) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
          contor++;
    }

    Jucator(const char* nume,float rating):id(0),rating(rating),activ(true),categorie('F'),anNastere(2000) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
        contor++;
    }
//copy constructor
    Jucator(const Jucator& j):id(j.id),rating(j.rating),activ(j.activ),categorie(j.categorie),anNastere(j.anNastere) {
        nume=new char[strlen(j.nume)+1];
        strcpy(nume,j.nume);
        contor++;
    }

    ~Jucator() {
        if(nume!=nullptr) {
            delete[] nume;
            nume=nullptr;
        }
        contor--;
    }

    Jucator& operator=(const Jucator& j) {
        if(this!=&j) {
            if(nume!=nullptr) {
                delete[] nume;
                nume=nullptr;
            }
            id=j.id;
            rating=j.rating;
            activ=j.activ;
            categorie=j.categorie;
            anNastere=j.anNastere;
            nume=new char[strlen(j.nume)+1];
            strcpy(nume,j.nume);
        }
        return *this;
    }
//getteri si setteri
    int getId() const {
        return id;
    }
    const char* getNume() const {
        return nume;
    }
    float getRating() const {
        return rating;
    }
    bool getActiv() const {
        return activ;
    }
    char getCategorie() const {
        return categorie;
    }
    int getAnNastere() const {
        return anNastere;
    }
    void setId(int id) {
        if(id>=0)
            this->id=id;
    }
    void setNume(const char* numeNou) {
        if(numeNou!=nullptr && strlen(numeNou)>0) {
            if(nume!=nullptr) {
                delete[] nume;
                nume=nullptr;
            }
            nume=new char[strlen(numeNou)+1];
            strcpy(nume,numeNou);
        }
    }
    void setRating(float rating) {
        if(rating>=0)
            this->rating=rating;
    }
    void setActiv(bool activ) {
        this->activ=activ;
    }
    void setCategorie(char categorie) {
        this->categorie=categorie;
    }
    void setAnNastere(int anNastere) {
        if(anNastere>1900)
            this->anNastere=anNastere;
    }
//putem verifica daca jucatorul este junior sau nu
    bool esteJunior() const {
        return anNastere>=2008;
    }
//operator indexare, returneaza un anumit caracter din nume
    char operator[](unsigned int index) const {
        if(nume!=nullptr && index<strlen(nume))
            return nume[index];
        return '-';
    }
    Jucator& operator++() {
        rating++;
        return *this;
    }

    Jucator operator+(float x) const {
        Jucator copie(*this);
        copie.rating+=x;
        return copie;
    }
    Jucator operator-(float x) const {
        Jucator copie(*this);
        copie.rating-=x;
        if(copie.rating<0)
            copie.rating=0;
        return copie;
    }
//comutativitate
    friend Jucator operator+(float x,const Jucator& j) {
        return j+x;
    }
    bool operator==(const Jucator& j) const {
        return id==j.id;
    }
    bool operator>(const Jucator& j) const {
        return rating>j.rating;
    }
    friend ostream& operator<<(ostream& out,const Jucator& j) {
        out<<"ID: "<<j.id<<"\n";
        out<<"Nume: "<<j.nume<<"\n";
        out<<"Rating: "<<j.rating<<"\n";
        out<<"Activ: "<<j.activ<<"\n";
        out<<"Categorie: "<<j.categorie<<"\n";
        out<<"An nastere: "<<j.anNastere<<"\n";
        out<<"Junior: "<<(j.esteJunior()?"Da":"Nu")<<"\n";
        return out;
    }

    friend istream& operator>>(istream& in,Jucator& j) {
        char buffer[100];
        cout<<"ID: ";
        in>>j.id;
        cout<<"Nume: ";
        in>>ws;
        in.getline(buffer,100);
        j.setNume(buffer);
        cout<<"Rating: ";
        in>>j.rating;
        if(j.rating<0)
            j.rating=0;
        cout<<"Activ(1/0): ";
        in>>j.activ;
        cout<<"Categorie(A-Z): ";
        in>>j.categorie;
        cout<<"An nastere: ";
        in>>j.anNastere;
        if(j.anNastere<1900)
            j.anNastere=2000;
        return in;
    }
    static int getContor() {
        return contor;
    }
};
int Jucator::contor=0;

class Arbitru {
    int id;
    char* nume;
    int experienta;
    bool principal;
    char nivel;
    int anLicenta;
    static int contor;

public:
    Arbitru():id(0),experienta(0),principal(false),nivel('C'),anLicenta(2020) {
        nume=new char[strlen("Anonim")+1];
        strcpy(nume,"Anonim");
        contor++;
    }

    Arbitru(int id,const char* nume,int experienta,bool principal,char nivel,int anLicenta):id(id),experienta(experienta),principal(principal),nivel(nivel),anLicenta(anLicenta) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
        contor++;
    }

    Arbitru(int id,const char* nume):id(id),experienta(0),principal(false),nivel('C'),anLicenta(2020) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
            contor++;
    }

    Arbitru(const char* nume,int experienta):id(0),experienta(experienta),principal(false),nivel('C'),anLicenta(2020) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
        contor++;
    }
//copy constructor
    Arbitru(const Arbitru& a):id(a.id),experienta(a.experienta),principal(a.principal),nivel(a.nivel),anLicenta(a.anLicenta) {
        nume=new char[strlen(a.nume)+1];
        strcpy(nume,a.nume);
        contor++;
    }

    ~Arbitru() {
        if(nume!=nullptr) {
            delete[] nume;
            nume=nullptr;
        }
        contor--;
    }

    Arbitru& operator=(const Arbitru& a) {
        if(this!=&a) {
            if(nume!=nullptr) {
                delete[] nume;
                nume=nullptr;
            }
            id=a.id;
            experienta=a.experienta;
            principal=a.principal;
            nivel=a.nivel;
            anLicenta=a.anLicenta;
            nume=new char[strlen(a.nume)+1];
            strcpy(nume,a.nume);
        }
        return *this;
    }
//setteri si getteri
    int getId() const {
        return id;
    }

    const char* getNume() const {
        return nume;
    }

    int getExperienta() const {
        return experienta;
    }

    bool getPrincipal() const {
        return principal;
    }
    char getNivel() const {
        return nivel;
    }
    int getAnLicenta() const {
        return anLicenta;
    }
    void setId(int id) {
        if(id>=0)
            this->id=id;
    }
    void setNume(const char* numeNou) {
        if(numeNou!=nullptr && strlen(numeNou)>0) {
            if(nume!=nullptr) {
                delete[] nume;
                nume=nullptr;
            }
            nume=new char[strlen(numeNou)+1];
            strcpy(nume,numeNou);
        }
    }

    void setExperienta(int experienta) {
        if(experienta>=0)
            this->experienta=experienta;
    }
    void setPrincipal(bool principal) {
        this->principal=principal;
    }
    void setNivel(char nivel) {
        this->nivel=nivel;
    }
    void setAnLicenta(int anLicenta) {
        if(anLicenta>1900)
            this->anLicenta=anLicenta;
    }

    bool poateFiPrincipal() const {
        return principal && experienta>=3;
    }

    char operator[](unsigned int index) const {
        if(nume!=nullptr && index<strlen(nume))
            return nume[index];
        return '-';
    }

    Arbitru& operator++() {
        experienta++;
        return *this;
    }

    Arbitru operator+(int x) const {
        Arbitru copie(*this);
        copie.experienta+=x;
        return copie;
    }

    Arbitru operator-(int x) const {
        Arbitru copie(*this);
        copie.experienta-=x;
        if(copie.experienta<0)
            copie.experienta=0;
        return copie;
    }

    friend Arbitru operator+(int x,const Arbitru& a) {
        return a+x;
    }

    bool operator==(const Arbitru& a) const {
        return id==a.id;
    }

    bool operator<(const Arbitru& a) const {
        return experienta<a.experienta;
    }

    friend ostream& operator<<(ostream& out,const Arbitru& a) {
        out<<"ID: "<<a.id<<"\n";
        out<<"Nume: "<<a.nume<<"\n";
        out<<"Experienta: "<<a.experienta<<"\n";
        out<<"Principal: "<<a.principal<<"\n";
        out<<"Nivel: "<<a.nivel<<"\n";
        out<<"An licenta: "<<a.anLicenta<<"\n";
        out<<"Poate fi principal: "<<(a.poateFiPrincipal()?"Da":"Nu")<<"\n";
        return out;
    }

    friend istream& operator>>(istream& in,Arbitru& a) {
        char buffer[100];
        cout<<"ID: ";
        in>>a.id;
        cout<<"Nume: ";
        in>>ws;
        in.getline(buffer,100);
        a.setNume(buffer);
        cout<<"Experienta(ani): ";
        in>>a.experienta;
        if(a.experienta<0)
            a.experienta=0;
        cout<<"Principal(1/0): ";
        in>>a.principal;
        cout<<"Nivel(A-Z): ";
        in>>a.nivel;
        cout<<"An licenta: ";
        in>>a.anLicenta;
        if(a.anLicenta<1950)
            a.anLicenta=2020;
        return in;
    }
    static int getContor() {
        return contor;
    }
};

int Arbitru::contor=0;

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
    Partida():id(0),idAlb(0),idNegru(0),durata(0),rated(true),ritm('C'),nrMaximMutari(200) {
        rezultat=new char[strlen("1-0")+1];
        strcpy(rezultat,"1-0");
        contor++;
    }
    Partida(int id,int idAlb,int idNegru,const char* rezultat,float durata,bool rated,char ritm,int nrMaximMutari):id(id),idAlb(idAlb),idNegru(idNegru),durata(durata),rated(rated),ritm(ritm),nrMaximMutari(nrMaximMutari) {
            this->rezultat=new char[strlen(rezultat)+1];
            strcpy(this->rezultat,rezultat);
        contor++;
    }

    Partida(int id,int idAlb,int idNegru):id(id),idAlb(idAlb),idNegru(idNegru),durata(0),rated(true),ritm('C'),nrMaximMutari(200) {
        rezultat=new char[strlen("1/2-1/2")+1];
        strcpy(rezultat,"1/2-1/2");
        contor++;
    }

    Partida(const char* rezultat,float durata):id(0),idAlb(0),idNegru(0),durata(durata),rated(true),ritm('C'),nrMaximMutari(200) {
            this->rezultat=new char[strlen(rezultat)+1];
            strcpy(this->rezultat,rezultat);
        contor++;
    }

    Partida(const Partida& p):id(p.id),idAlb(p.idAlb),idNegru(p.idNegru),durata(p.durata),rated(p.rated),ritm(p.ritm),nrMaximMutari(p.nrMaximMutari) {
        rezultat=new char[strlen(p.rezultat)+1];
        strcpy(rezultat,p.rezultat);
        contor++;
    }

    ~Partida() {
        if(rezultat!=nullptr) {
            delete[] rezultat;
            rezultat=nullptr;
        }
        contor--;
    }

    Partida& operator=(const Partida& p) {
        if(this!=&p) {
            if(rezultat!=nullptr) {
                delete[] rezultat;
                rezultat=nullptr;
            }
            id=p.id;
            idAlb=p.idAlb;
            idNegru=p.idNegru;
            durata=p.durata;
            rated=p.rated;
            ritm=p.ritm;
            nrMaximMutari=p.nrMaximMutari;
            rezultat=new char[strlen(p.rezultat)+1];
            strcpy(rezultat,p.rezultat);
        }
        return *this;
    }
//setteri si getteri
    int getId() const {
        return id;
    }
    int getIdAlb() const {
        return idAlb;
    }
    int getIdNegru() const {
        return idNegru;
    }
    const char* getRezultat() const {
        return rezultat;
    }

    float getDurata() const {
        return durata;
    }

    bool getRated() const {
        return rated;
    }

    char getRitm() const {
        return ritm;
    }

    int getNrMaximMutari() const {
        return nrMaximMutari;
    }
    void setId(int id) {
        if(id>=0)
            this->id=id;
    }
    void setIdAlb(int idAlb) {
        if(idAlb>=0)
            this->idAlb=idAlb;
    }

    void setIdNegru(int idNegru) {
        if(idNegru>=0)
            this->idNegru=idNegru;
    }

    void setRezultat(const char* r) {
        if(r!=nullptr && strlen(r)>0) {
            if(rezultat!=nullptr) {
                delete[] rezultat;
                rezultat=nullptr;
            }
            rezultat=new char[strlen(r)+1];
            strcpy(rezultat,r);
        }
    }

    void setDurata(float durata) {
        if(durata>=0)
            this->durata=durata;
    }

    void setRated(bool rated) {
        this->rated=rated;
    }

    void setRitm(char ritm) {
        this->ritm=ritm;
    }

    void setNrMaximMutari(int nrMaximMutari) {
        if(nrMaximMutari>0)
            this->nrMaximMutari=nrMaximMutari;
    }
    bool esteRemiza() const {
        return strcmp(rezultat,"1/2-1/2")==0;
    }
    //operator indexare, returneaza caracterul de pe pozitia index a din rezultat
    char operator[](unsigned int index) const {
        if(rezultat!=nullptr && index<strlen(rezultat))
            return rezultat[index];
        return '-';
    }

    Partida& operator++() {
        durata++;
        return *this;
    }

    Partida operator+(float x) const {
        Partida copie(*this);
        copie.durata+=x;
        return copie;
    }

    Partida operator-(float x) const {
        Partida copie(*this);
        copie.durata-=x;
        if(copie.durata<0)
            copie.durata=0;
        return copie;
    }

    friend Partida operator+(float x,const Partida& p) {
        return p+x;
    }

    bool operator==(const Partida& p) const {
        return id==p.id;
    }

    bool operator>(const Partida& p) const {
        return durata>p.durata;
    }
    friend ostream& operator<<(ostream& out,const Partida& p) {
        out<<"ID: "<<p.id<<"\n";
        out<<"ID alb: "<<p.idAlb<<"\n";
        out<<"ID negru: "<<p.idNegru<<"\n";
        out<<"Rezultat: "<<p.rezultat<<"\n";
        out<<"Durata: "<<p.durata<<"\n";
        out<<"Rated: "<<p.rated<<"\n";
        out<<"Ritm: "<<p.ritm<<"\n";
        out<<"Nr maxim mutari: "<<p.nrMaximMutari<<"\n";
        out<<"Este remiza: "<<(p.esteRemiza()?"Da":"Nu")<<"\n";
        return out;
    }

    friend istream& operator>>(istream& in,Partida& p) {
        char buffer[50];
        cout<<"ID: ";
        in>>p.id;
        cout<<"ID alb: ";
        in>>p.idAlb;
        cout<<"ID negru: ";
        in>>p.idNegru;
        cout<<"Rezultat(1-0, 1/2-1/2, 0-1): ";
        in>>ws;
        in.getline(buffer,50);
        p.setRezultat(buffer);
        cout<<"Durata(nr ore): ";
        in>>p.durata;
        if(p.durata<0)
            p.durata=0;
        cout<<"Rated(1/0): ";
        in>>p.rated;
        cout<<"Ritm(A-Z): ";
        in>>p.ritm;
        cout<<"Nr maxim mutari: ";
        in>>p.nrMaximMutari;
        if(p.nrMaximMutari<=0)
            p.nrMaximMutari=200;
        return in;
    }

    static int getContor() {
        return contor;
    }
};
int Partida::contor=0;

class Turneu {

    int id;
    char* nume;
    int nrRunde;
    float taxa;
    bool international;
    char tip;
    int* idParticipanti;
    int nrParticipanti;
    int capacitateMaxima;
    static int contor;

public:
    Turneu():id(0),nrRunde(7),taxa(100),international(false),tip('C'),nrParticipanti(0),capacitateMaxima(100) {
        nume=new char[strlen("Turneu")+1];
        strcpy(nume,"Turneu");
        idParticipanti=nullptr;
        contor++;
    }

    Turneu(int id,const char* nume,int nrRunde,float taxa,bool international,char tip,int* idParticipanti,int nrParticipanti,int capacitateMaxima):id(id),nrRunde(nrRunde),taxa(taxa),international(international),tip(tip),nrParticipanti(nrParticipanti),capacitateMaxima(capacitateMaxima) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
        if(this->nrParticipanti>this->capacitateMaxima)
            this->nrParticipanti=this->capacitateMaxima;
        if(this->nrParticipanti>0 && idParticipanti!=nullptr) {
            this->idParticipanti=new int[this->nrParticipanti];
            for(int i=0;i<this->nrParticipanti;i++)
                this->idParticipanti[i]=idParticipanti[i];
        } else {
            this->idParticipanti=nullptr;
        }
        contor++;
    }

    Turneu(int id,const char* nume):id(id),nrRunde(7),taxa(100),international(false),tip('C'),nrParticipanti(0),capacitateMaxima(100) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
            idParticipanti=nullptr;
        contor++;
    }

    Turneu(const char* nume,float taxa):id(0),nrRunde(7),taxa(taxa),international(false),tip('C'),nrParticipanti(0),capacitateMaxima(100) {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
        idParticipanti=nullptr;
        contor++;
    }

    Turneu(const Turneu& t):id(t.id),nrRunde(t.nrRunde),taxa(t.taxa),international(t.international),tip(t.tip),nrParticipanti(t.nrParticipanti),capacitateMaxima(t.capacitateMaxima) {
        nume=new char[strlen(t.nume)+1];
        strcpy(nume,t.nume);
        if(nrParticipanti>0 && t.idParticipanti!=nullptr) {
            idParticipanti=new int[nrParticipanti];
            for(int i=0;i<nrParticipanti;i++)
                idParticipanti[i]=t.idParticipanti[i];
        } else {
            idParticipanti=nullptr;
        }
        contor++;
    }

    ~Turneu() {
        if(nume!=nullptr) {
            delete[] nume;
            nume=nullptr;
        }
        if(idParticipanti!=nullptr) {
            delete[] idParticipanti;
            idParticipanti=nullptr;
        }
        contor--;
    }

    Turneu& operator=(const Turneu& t) {
        if(this!=&t) {
            if(nume!=nullptr) {
                delete[] nume;
                nume=nullptr;
            }
            if(idParticipanti!=nullptr) {
                delete[] idParticipanti;
                idParticipanti=nullptr;
            }
            id=t.id;
            nrRunde=t.nrRunde;
            taxa=t.taxa;
            international=t.international;
            tip=t.tip;
            nrParticipanti=t.nrParticipanti;
            capacitateMaxima=t.capacitateMaxima;
            nume=new char[strlen(t.nume)+1];
            strcpy(nume,t.nume);
            if(nrParticipanti>capacitateMaxima)
                nrParticipanti=capacitateMaxima;
            if(nrParticipanti>0 && t.idParticipanti!=nullptr) {
                idParticipanti=new int[nrParticipanti];
                for(int i=0;i<nrParticipanti;i++)
                    idParticipanti[i]=t.idParticipanti[i];
            } else {
                idParticipanti=nullptr;
            }
        }
        return *this;
    }
//setteri si getteri
    int getId() const {
        return id;
    }
    const char* getNume() const {
        return nume;
    }
    int getNrRunde() const {
        return nrRunde;
    }
    float getTaxa() const {
        return taxa;
    }
    bool getInternational() const {
        return international;
    }
    char getTip() const {
        return tip;
    }

    int getNrParticipanti() const {
        return nrParticipanti;
    }

    int getCapacitateMaxima() const {
        return capacitateMaxima;
    }

    void setId(int id) {
        if(id>=0)
            this->id=id;
    }

    void setNume(const char* numeNou) {
        if(numeNou!=nullptr && strlen(numeNou)>0) {
            if(nume!=nullptr) {
                delete[] nume;
                nume=nullptr;
            }
            nume=new char[strlen(numeNou)+1];
            strcpy(nume,numeNou);
        }
    }

    void setNrRunde(int nrRunde) {
        if(nrRunde>0)
            this->nrRunde=nrRunde;
    }

    void setTaxa(float taxa) {
        if(taxa>=0)
            this->taxa=taxa;
    }

    void setInternational(bool international) {
        this->international=international;
    }

    void setTip(char tip) {
        this->tip=tip;
    }
    void setCapacitateMaxima(int capacitateMaxima) {
        if(capacitateMaxima>0 && capacitateMaxima>=nrParticipanti)
            this->capacitateMaxima=capacitateMaxima;
    }
    bool areLocuriLibere() const {
        return nrParticipanti<capacitateMaxima;
    }
    bool adaugaParticipant(int idParticipant) {
        if(!areLocuriLibere())
            return false;
        int* copie=new int[nrParticipanti+1];
        for(int i=0;i<nrParticipanti;i++)
            copie[i]=idParticipanti[i];
        copie[nrParticipanti]=idParticipant;
        if(idParticipanti!=nullptr) {
            delete[] idParticipanti;
            idParticipanti=nullptr;
        }
        idParticipanti=copie;
        nrParticipanti++;
        return true;
    }

    char operator[](unsigned int index) const {
        if(nume!=nullptr && index<strlen(nume))
            return nume[index];
        return '-';
    }

    Turneu& operator++() {
        nrRunde++;
        return *this;
    }

    Turneu operator+(float x) const {
        Turneu copie(*this);
        copie.taxa+=x;
        return copie;
    }

    Turneu operator-(float x) const {
        Turneu copie(*this);
        copie.taxa-=x;
        if(copie.taxa<0)
            copie.taxa=0;
        return copie;
    }

    friend Turneu operator+(float x,const Turneu& t) {
        return t+x;
    }

    bool operator==(const Turneu& t) const {
        return id==t.id;
    }

    bool operator<(const Turneu& t) const {
        return taxa<t.taxa;
    }

    friend ostream& operator<<(ostream& out,const Turneu& t) {
        out<<"ID: "<<t.id<<"\n";
        out<<"Nume: "<<t.nume<<"\n";
        out<<"Nr runde: "<<t.nrRunde<<"\n";
        out<<"Taxa: "<<t.taxa<<"\n";
        out<<"International: "<<t.international<<"\n";
        out<<"Tip: "<<t.tip<<"\n";
        out<<"Nr participanti: "<<t.nrParticipanti<<"\n";
        out<<"Capacitate maxima: "<<t.capacitateMaxima<<"\n";
        out<<"Participanti: ";
        for(int i=0;i<t.nrParticipanti;i++)
            out<<t.idParticipanti[i]<<" ";
        out<<"\n";
        return out;
    }

    friend istream& operator>>(istream& in,Turneu& t) {
        char buffer[100];
        int n;
        cout<<"ID: ";
        in>>t.id;
        cout<<"Nume: ";
        in>>ws;
        in.getline(buffer,100);
        t.setNume(buffer);
        cout<<"Nr runde: ";
        in>>t.nrRunde;
        if(t.nrRunde<=0)
            t.nrRunde=1;
        cout<<"Taxa: ";
        in>>t.taxa;
        if(t.taxa<0)
            t.taxa=0;
        cout<<"International(1/0): ";
        in>>t.international;
        cout<<"Tip(A-Z): ";
        in>>t.tip;
        cout<<"Capacitate maxima: ";
        in>>t.capacitateMaxima;
        if(t.capacitateMaxima<=0)
            t.capacitateMaxima=100;
        cout<<"Numar participanti: ";
        in>>n;
        if(n<0)
            n=0;
        if(n>t.capacitateMaxima)
            n=t.capacitateMaxima;
        if(t.idParticipanti!=nullptr) {
            delete[] t.idParticipanti;
            t.idParticipanti=nullptr;
        }
        t.nrParticipanti=n;
        if(n>0) {
            t.idParticipanti=new int[n];
            for(int i=0;i<n;i++) {
                cout<<"ID participant "<<i+1<<": ";
                in>>t.idParticipanti[i];
            }
        } else {
            t.idParticipanti=nullptr;
        }
        return in;
    }

    static int getContor() {
        return contor;
    }
};

int Turneu::contor=0;

int cautaJucator(Jucator v[],int n,int id) {
    for(int i=0;i<n;i++)
        if(v[i].getId()==id)
            return i;
    return -1;
}
int cautaArbitru(Arbitru v[],int n,int id) {
    for(int i=0;i<n;i++)
        if(v[i].getId()==id)
            return i;
    return -1;
}

int cautaPartida(Partida v[],int n,int id) {
    for(int i=0;i<n;i++)
        if(v[i].getId()==id)
            return i;
    return -1;
}
int cautaTurneu(Turneu v[],int n,int id) {
    for(int i=0;i<n;i++)
        if(v[i].getId()==id)
            return i;
    return -1;
}

void meniu() {
    cout<<"\n========== MENIU ==========\n";
    cout<<"1.Adauga jucator\n";
    cout<<"2.Afiseaza jucatori\n";
    cout<<"3.Modifica jucator\n";
    cout<<"4.Sterge jucator\n";
    cout<<"5.Adauga arbitru\n";
    cout<<"6.Afiseaza arbitri\n";
    cout<<"7.Modifica arbitru\n";
    cout<<"8.Sterge arbitru\n";
    cout<<"9.Adauga partida\n";
    cout<<"10.Afiseaza partide\n";
    cout<<"11.Modifica partida\n";
    cout<<"12.Sterge partida\n";
    cout<<"13.Adauga turneu\n";
    cout<<"14.Afiseaza turnee\n";
    cout<<"15.Modifica turneu\n";
    cout<<"16.Sterge turneu\n";
    cout<<"17.Demo\n";
    cout<<"0.Iesire\n";
    cout<<"Optiune: ";
}

int main() {
    const int MAX_JUCATORI=67;
    const int MAX_ARBITRI=50;
    const int MAX_PARTIDE=100;
    const int MAX_TURNEE=50;
    Jucator jucatori[MAX_JUCATORI];
    Arbitru arbitri[MAX_ARBITRI];
    Partida partide[MAX_PARTIDE];
    Turneu turnee[MAX_TURNEE];
    int nrJucatori=0;
    int nrArbitri=0;
    int nrPartide=0;
    int nrTurnee=0;
    int op;

    do {
        meniu();
        cin>>op;
        if(op==1) {
            if(nrJucatori<MAX_JUCATORI) {
                cin>>jucatori[nrJucatori];
                nrJucatori++;
            } else {
                cout<<"Nu mai este loc pentru jucatori\n";
            }
        }
        else if(op==2) {
            if(nrJucatori==0)
                cout<<"Nu exista jucatori\n";
            for(int i=0;i<nrJucatori;i++) {
                cout<<"\nJucatorul "<<i+1<<":\n";
                cout<<jucatori[i];
            }
        }
        else if(op==3) {
            int id,p;
            cout<<"ID jucator: ";
            cin>>id;
            p=cautaJucator(jucatori,nrJucatori,id);
            if(p!=-1)
                cin>>jucatori[p];
            else
                cout<<"Nu exista\n";
        }
        else if(op==4) {
            int id,p;
            cout<<"ID jucator: ";
            cin>>id;
            p=cautaJucator(jucatori,nrJucatori,id);
            if(p!=-1) {
                for(int i=p;i<nrJucatori-1;i++)
                    jucatori[i]=jucatori[i+1];
                nrJucatori--;
            } else {
                cout<<"Nu exista\n";
            }
        }
        else if(op==5) {
            if(nrArbitri<MAX_ARBITRI) {
                cin>>arbitri[nrArbitri];
                nrArbitri++;
            } else {
                cout<<"Nu mai este loc pentru arbitri\n";
            }
        }
        else if(op==6) {
            if(nrArbitri==0)
                cout<<"Nu exista arbitri.\n";
            for(int i=0;i<nrArbitri;i++) {
                cout<<"\nArbitrul "<<i+1<<":\n";
                cout<<arbitri[i];
            }
        }
        else if(op==7) {
            int id,p;
            cout<<"ID arbitru: ";
            cin>>id;
            p=cautaArbitru(arbitri,nrArbitri,id);
            if(p!=-1)
                cin>>arbitri[p];
            else
                cout<<"Nu exista.\n";
        }
        else if(op==8) {
            int id,p;
            cout<<"ID arbitru: ";
            cin>>id;
            p=cautaArbitru(arbitri,nrArbitri,id);
            if(p!=-1) {
                for(int i=p;i<nrArbitri-1;i++)
                    arbitri[i]=arbitri[i+1];
                nrArbitri--;
            } else {
                cout<<"Nu exista\n";
            }
        }
        else if(op==9) {
            if(nrPartide<MAX_PARTIDE) {
                cin>>partide[nrPartide];
                nrPartide++;
            } else {
                cout<<"Nu mai este loc pentru partide\n";
            }
        }
        else if(op==10) {
            if(nrPartide==0)
                cout<<"Nu exista partide.\n";
            for(int i=0;i<nrPartide;i++) {
                cout<<"\nPartida "<<i+1<<":\n";
                cout<<partide[i];
            }
        }
        else if(op==11) {
            int id,p;
            cout<<"ID partida: ";
            cin>>id;
            p=cautaPartida(partide,nrPartide,id);
            if(p!=-1)
                cin>>partide[p];
            else
                cout<<"Nu exista\n";
        }
        else if(op==12) {
            int id,p;
            cout<<"ID partida: ";
            cin>>id;
            p=cautaPartida(partide,nrPartide,id);
            if(p!=-1) {
                for(int i=p;i<nrPartide-1;i++)
                    partide[i]=partide[i+1];
                nrPartide--;
            } else {
                cout<<"Nu exista.\n";
            }
        }
        else if(op==13) {
            if(nrTurnee<MAX_TURNEE) {
                cin>>turnee[nrTurnee];
                nrTurnee++;
            } else {
                cout<<"Nu mai este loc pentru turnee.\n";
            }
        }
        else if(op==14) {
            if(nrTurnee==0)
                cout<<"Nu exista turnee\n";
            for(int i=0;i<nrTurnee;i++) {
                cout<<"\nTurneul "<<i+1<<":\n";
                cout<<turnee[i];
            }
        }
        else if(op==15) {
            int id,p;
            cout<<"ID turneu: ";
            cin>>id;
            p=cautaTurneu(turnee,nrTurnee,id);
            if(p!=-1)
                cin>>turnee[p];
            else
                cout<<"Nu exista.\n";
        }
        else if(op==16) {
            int id,p;
            cout<<"ID turneu: ";
            cin>>id;
            p=cautaTurneu(turnee,nrTurnee,id);
            if(p!=-1) {
                for(int i=p;i<nrTurnee-1;i++)
                    turnee[i]=turnee[i+1];
                nrTurnee--;
            } else {
                cout<<"Nu exista.\n";
            }
        }
        else if(op==17) {
            Jucator j1(1,"Darius",1700,true,'X',2006);
            Jucator j2("Magnus",2800);
            Jucator j3=j1+50;
            Arbitru a1(1,"Ionescu",5,true,'A',2018);
            Partida p1(1,10,20,"1/2-1/2",4.5,true,'C',200);
            Turneu t1;
            t1.setId(1);
            t1.setNume("Open Bucuresti");
            t1.adaugaParticipant(10);
            t1.adaugaParticipant(20);
            cout<<"\n=== DEMO ===\n";
            cout<<"j1:\n"<<j1;
            cout<<"j2:\n"<<j2;
            cout<<"j3=j1+50:\n"<<j3;
            ++j1;
            cout<<"Dupa ++j1:\n"<<j1;
            cout<<"j1[0]="<<j1[0]<<"\n";
            cout<<"(j1==j2)="<<(j1==j2)<<"\n";
            cout<<"(j2>j1)="<<(j2>j1)<<"\n\n";
            cout<<"Arbitru demo:\n"<<a1;
            cout<<"Partida demo:\n"<<p1;
            cout<<"Turneu demo:\n"<<t1;
        }
        else if(op!=0) {
            cout<<"Optiune invalida.\n";
        }
    } while(op!=0);

    return 0;
}