#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class Data {
    int zi;
    int luna;
    int an;
public:
    Data();
    Data(int z, int l, int a);
    ~Data();

    friend ostream& operator<<(ostream& out, const Data& d);
    friend istream& operator>>(istream& in, Data& d);
};
#endif