#include "Data.h"
#include <iostream>
using namespace std;
Data::Data():zi(1),luna(1),an(2000) { cout<<"[Data] Construita\n"; }

Data::Data(int z, int l, int a):zi(z),luna(l),an(a) { cout<<"[Data] Construita\n"; }

Data::~Data() { cout<<"[Data] Distrusa\n"; }

ostream& operator<<(ostream& out, const Data& d) {
    out<<d.zi<<"/"<<d.luna<<"/"<<d.an;
    return out;
}
istream& operator>>(istream& in, Data& d) {
    in>>d.zi>>d.luna>>d.an;
    return in;
}