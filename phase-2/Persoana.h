#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
using namespace std;

class Persoana {
    // folosim 'protected' pentru a asigura incapsularea fata de exterior (acces invalid din main)
    // accesul este valid doar din interiorul claselor derivate pt a putea modifica aceste date.
protected:
    int id;
    char* nume;
    static int contor;
public:
    Persoana();
    Persoana(int id, const char* nume);
    Persoana(const Persoana& p);
    virtual ~Persoana();

    Persoana& operator=(const Persoana& p);
    int getId() const { return id; }
    const char* getNume() const { return nume; }
    void setId(int id) { if(id>=0) this->id=id; }
    void setNume(const char* numeNou);

    // prezenta functiilor pur virtuale face clasa abstracta.
    // astfel, clasa nu poate fi instantiata direct .
    virtual void afiseazaTip() const = 0;
    virtual void printeaza(ostream& out) const = 0;
    virtual void citeste(istream& in) = 0;

    friend ostream& operator<<(ostream& out, const Persoana& p);
    friend istream& operator>>(istream& in, Persoana& p);
    static int getContor() { return contor; }
};
#endif