#include "vektor.h"

size_t Vektor::defSize=11;
double Vektor::defValue=51;



/// M�sol� konstruktor. K�sz�tse el a vektor.cpp f�jlban!
Vektor::Vektor(const Vektor&s){
    pVec=new double[s.nElements];
    nElements=s.nElements;
    for(size_t i=0;i<nElements;i++){
        pVec[i]=s.pVec[i];
    }
}

/// Destruktor. K�sz�tse el a vektor.cpp f�jlban!
Vektor::~Vektor(){
    delete[] pVec;
}

/// �rt�kad� oper�tor. K�sz�tse el a vektor.cpp f�jlban!
Vektor& Vektor::operator=(const Vektor&v){
    if(this!=&v){
        delete [] pVec;
        pVec=new double[v.nElements];
        nElements=v.nElements;
        for(size_t i=0;i<nElements;i++){
            pVec[i]=v.pVec[i];
        }
    }
    return *this;
}

    /// Indexoper�torok. K�sz�tse el a vektor.cpp f�jlban!
    /// T�lc�mz�s eset�n az �n Neptun-k�dj�t tartalmaz� const char* t�pus� kiv�telt dob!
    /// @param idx - index �rt�ke
    /// @return    - referencia az adott elemre
double& Vektor::operator[](size_t idx){
    if(nElements>idx&& idx>=0)
        return pVec[idx];

    else{
        throw  "V6AO9G";
    }
}

const double& Vektor::operator[](size_t idx) const{
    if(nElements>idx&& idx>=0)
        return pVec[idx];

    else{
        throw  "V6AO9G";
    }
}

/// Szorz�s: Val�s * Vektor. K�sz�tse el a vektor.cpp f�jlban!
/// @param val - val�s �rt�k (bal oldali operandus)
/// @param vec - vektor, aminek minden elem�t megszorozzuk (jobb oldali operandus)
Vektor operator*(double val, const Vektor& vec){
    Vektor uj=vec;
    for(size_t i=0;i<vec.size();i++){
        uj[i]=vec[i]*val;


    }
    return uj;


}

