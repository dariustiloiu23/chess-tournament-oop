#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

//Ierarhie custom de minim 3 exceptii, mostenesc std::runtime_error.
class SahException : public runtime_error {
public:
    explicit SahException(const string& msg):runtime_error(msg) {}
    //  Suprascriere what() cu noexcept override
    const char* what() const noexcept override { return runtime_error::what(); }
};

class ValidareException : public SahException {
    double valoareGresita; //valoarea care a cauzat eroarea
public:
    ValidareException(const string& msg, double val):SahException(msg), valoareGresita(val) {}
    const char* what() const noexcept override { return runtime_error::what(); }
    double getValoare() const noexcept { return valoareGresita; }
};

class NotFoundException : public SahException {
    int idCautat; // id cautat, id negasit
public:
    NotFoundException(const string& msg, int id):SahException(msg), idCautat(id) {}
    const char* what() const noexcept override { return runtime_error::what(); }
    int getId() const noexcept { return idCautat; }
};
#endif