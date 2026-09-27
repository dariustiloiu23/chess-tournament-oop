#ifndef JUCATOR_H
#define JUCATOR_H
#include "Persoana.h"
#include <iostream>
using namespace std;

class Jucator : public Persoana {
protected:
    float rating;
    bool activ;
    char categorie;
    int anNastere;
public:
    Jucator();
    Jucator(int id,const char* nume,float rating,bool activ,char categorie,int anNastere);
    Jucator(int id,const char* nume);
    Jucator(const char* nume,float rating);
    Jucator(const Jucator& j);
    ~Jucator() override;

    Jucator& operator=(const Jucator& j);

    float getRating() const { return rating; }
    bool getActiv() const { return activ; }
    char getCategorie() const { return categorie; }
    int getAnNastere() const { return anNastere; }

    void setRating(float rating) { if(rating>=0) this->rating=rating; }
    void setActiv(bool activ) { this->activ=activ; }
    void setCategorie(char categorie) { this->categorie=categorie; }
    void setAnNastere(int anNastere) { if(anNastere>1900) this->anNastere=anNastere; }

    bool esteJunior() const { return anNastere>=2008; }

    char operator[](unsigned int index) const;
    Jucator& operator++();
    Jucator operator+(float x) const;
    Jucator operator-(float x) const;
    friend Jucator operator+(float x,const Jucator& j);
    bool operator==(const Jucator& j) const;
    bool operator>(const Jucator& j) const;

    void afiseazaTip() const override;
    void printeaza(ostream& out) const override;
    void citeste(istream& in) override;
};
#endif