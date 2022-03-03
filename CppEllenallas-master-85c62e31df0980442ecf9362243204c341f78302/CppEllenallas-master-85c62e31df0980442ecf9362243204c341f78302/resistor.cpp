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
}

Resistor::Resistor(){
    R=defR;
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




