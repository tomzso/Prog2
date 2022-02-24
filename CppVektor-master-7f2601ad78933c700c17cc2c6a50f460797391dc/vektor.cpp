#include "vektor.h"

size_t Vektor::defSize=11;
double Vektor::defValue=51;



/// Másoló konstruktor. Készítse el a vektor.cpp fájlban!
Vektor::Vektor(const Vektor&s){
    pVec=new double[s.nElements];
    nElements=s.nElements;
    for(size_t i=0;i<nElements;i++){
        pVec[i]=s.pVec[i];
    }
}

/// Destruktor. Készítse el a vektor.cpp fájlban!
Vektor::~Vektor(){
    delete[] pVec;
}

/// Értékadó operátor. Készítse el a vektor.cpp fájlban!
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

    /// Indexoperátorok. Készítse el a vektor.cpp fájlban!
    /// Túlcímzés esetén az Ön Neptun-kódját tartalmazó const char* típusú kivételt dob!
    /// @param idx - index értéke
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

/// Szorzás: Valós * Vektor. Készítse el a vektor.cpp fájlban!
/// @param val - valós érték (bal oldali operandus)
/// @param vec - vektor, aminek minden elemét megszorozzuk (jobb oldali operandus)
Vektor operator*(double val, const Vektor& vec){
    Vektor uj=vec;
    for(size_t i=0;i<vec.size();i++){
        uj[i]=vec[i]*val;


    }
    return uj;


}

