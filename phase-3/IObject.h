#ifndef IOBJECT_H
#define IOBJECT_H
#include <iostream>
#include <string>
using namespace std;

//Interfata IObject pentru identificatori unici
class IObject {
protected:
    static int contorGlobal; // contor static pt ID-uri unice
    const int id;
public:
    IObject();
    // Destructor virtual marcat noexcept (nu arunca exceptii)
    virtual ~IObject() noexcept;

    int getId() const noexcept;
    virtual string toString() const = 0; // metoda pur virtuala, obliga derivatele sa foloseasca string

    bool operator==(const IObject& alt) const noexcept; // Verificare identitate pe baza de ID
    friend ostream& operator<<(ostream& os, const IObject& obj);
};
#endif