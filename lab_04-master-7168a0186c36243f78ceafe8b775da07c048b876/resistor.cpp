/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"

double Resistor::defR=126;


Resistor::Resistor(double r){
    R=r;
    Pr("ctor1");
}

Resistor::Resistor(){
    R=defR;
    Pr("ctor0");
}



void Resistor::setDef(double r){
    defR=r;
}


Resistor Resistor::operator+(const Resistor& r) const{
    return Resistor(R+r.R);
}

Resistor Resistor::operator%(const Resistor& r) const{
    return Resistor(1/((1/R)+1/r.R));
}

Resistor operator*(int n, const Resistor& r){
    if(n<=0)
        throw "V6AO9G";

    double sum;
    for(int i=0;i<n;i++){
        sum=sum+r.getR();

    }
    return Resistor(sum);
}

Resistor::Resistor(const Resistor& rhs) :R(rhs.getR()) { /// Itt az adattag másoló konstruktora hívódik!
    Pr("Copy");
}

Resistor::~Resistor(){
    Pr("Dtor");
}

Resistor& Resistor::operator=(const Resistor& rhs){
    R=rhs.R;
    Pr("assign");
    return *this;
}


double Resistor::getI(double u) const{
    return u/R;
}

double Resistor::getU(double i) const{
    return i*R;
}
