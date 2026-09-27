#ifndef JUCATORPRO_H
#define JUCATORPRO_H
#include "Jucator.h"
#include <iostream>
using namespace std;

class JucatorPro : public Jucator {
    //'sponsor' este private. Accesul este invalid din exterior,
    // dar si invalid din alte posibile clase care ar mosteni din JucatorPro pe viitor.
    char* sponsor;
public:
    JucatorPro();
    JucatorPro(int id,const char* nume,float rating,bool activ,char categorie,int anNastere,const char* sp);
    JucatorPro(const JucatorPro& jp);
    ~JucatorPro() override;

    JucatorPro& operator=(const JucatorPro& jp);
    void afiseazaTip() const override;
    void printeaza(ostream& out) const override;
    void citeste(istream& in) override;
};
#endif