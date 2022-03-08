/**
 * \file allapotgep.h
 *
 * Ebben a fájlban találja az Allapotgep osztály kezdeti definícióját és két segédfüggvényt.
 *
 * A fájlt tetszés szerint módosíthatja, azzal a megkötéssel, hogy
 * nem hozhat létre globális függvényt és nem változtathatja az Allapotgep osztály
 * publikus interfészét.
 *
 * Új osztályokat, típusokat felvehet.
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#ifndef ALLAPOTGEP_H
#define ALLAPOTGEP_H

#include <locale>
#include <iostream>
#include <exception>
#include <string.h>
#include <fstream>

#include "memtrace.h"

struct String {

    size_t len;
    char * str;

    //public:
    String();
    String(char const * s){
        len=strlen(s);
        str=new char[len+1];
        strcpy(str,s);
    }
    String(char s){
        len=1;
        str=new char[len+1];
        str[0]=s;
        str[1]='\0';
    }
    ~String(){
        delete[] str;
    }
    String(const String& s){
        len=s.len;
        str=new char[len+1];
        strcpy(str,s.str);
    }
    String& operator=(const String& s){
        if(this!=&s){
            delete[] str;
            len=s.len;
            str=new char[len+1];
            strcpy(str,s.str);

        }
        return *this;
    }
    String operator+(String const& rhs) const{

        String uj;
        uj.len=rhs.len+len;
        uj.str=new char[uj.len+1];
        strcpy(uj.str,str);
        strcat(uj.str,rhs.str);
        return uj;

    }
    String& operator+=(String const& rhs){
        String tmp(*this);
        delete[] str;
        len=tmp.len+rhs.len;
        str=new char[len+1];
        strcpy(str,tmp.str);
        strcat(str,rhs.str);
        return *this;

    }
    String& operator+=(char rhs){
        String tmp(*this);
        delete[] str;
        len=tmp.len+1;
        str=new char[len+1];
        strcpy(str,tmp.str);
        str[len+1]=rhs;
        return *this;
    }
    size_t length() const {
        return len;
    }
    char const * c_str() const {
        return str;
    }
    char& operator[](int i) {
        return str[i];

    }
    char operator[](int i) const {
        return str[i];
    }
    char* getstr()const {
        return str;
    }
    bool operator==( const String& s){
        if(len!=s.length()){
            return false;
        }
        for(size_t i=0;i<len;i++){
            if(str[i]!=s.str[i]){
                return false;
            }

        }
        return true;
    }
};




struct Adattomb{
String* ervenyessegtomb;
String* allapottomb;
String* atmenettomb;
int n;
int aktivallapot;

Adattomb(){
    ervenyessegtomb=new String[1];
    allapottomb=new String[1];
    atmenettomb=new String[1];
    n=1;
    aktivallapot=0;

}
Adattomb(const char* text){
    aktivallapot=0;
    std::ifstream file(text);
    int m;
    char ertek;
    char allapotnev[21];
    char atmenet[5];
    int i=0;

    file>>m;
    std::cout << m<< std::endl;
    n=m;

    ervenyessegtomb=new String[n];
    allapottomb=new String[n];
    atmenettomb=new String[n*n];
    while(i<n){
        file>>ertek>>allapotnev;
        //cout <<ertek<<","<<allapotnev<< endl;

        String e(ertek);
        String nev(allapotnev);

        ervenyessegtomb[i]=e;
        allapottomb[i]=nev;
        //cout <<ervenyessegtomb[i].str<<","<<allapottomb[i].str<< endl;

        i++;

    }
    i=0;
    while(file>>atmenet){

        String atmenetnev(atmenet);

        atmenettomb[i]=atmenetnev;
        //cout <<atmenettomb[i].pData<< endl;
        i++;

    }


}
Adattomb(const Adattomb& rhs){
    aktivallapot=rhs.aktivallapot;
    n=rhs.n;
    ervenyessegtomb=new String[n];
    allapottomb=new String[n];
    atmenettomb=new String[n*n];
    for(int i=0;i<n;i++){
        ervenyessegtomb[i]=rhs.ervenyessegtomb[i];
        allapottomb[i]=rhs.allapottomb[i];

    }
    for(int i=0;i<n*n;i++){
        atmenettomb[i]=rhs.atmenettomb[i];
        //cout <<atmenettomb[i].str<< endl;
    }
}
~Adattomb(){
    for(int i=0;i<n;i++){
        delete[] ervenyessegtomb[i].str;
        delete[] allapottomb[i].str;
    }
    for(int i=0;i<n*n;i++){
        delete[] atmenettomb[i].str;
    }


}
Adattomb& operator=(const Adattomb& rhs){
    if(this!=&rhs){
        for(int i=0;i<n;i++){
            delete[] ervenyessegtomb[i].str;
            delete[] allapottomb[i].str;
        }
        for(int i=0;i<n*n;i++){
            delete[] atmenettomb[i].str;
        }
        aktivallapot=rhs.aktivallapot;
        n=rhs.n;
        ervenyessegtomb=new String[n];
        allapottomb=new String[n];
        atmenettomb=new String[n*n];
        for(int i=0;i<n;i++){
            ervenyessegtomb[i]=rhs.ervenyessegtomb[i];
            allapottomb[i]=rhs.allapottomb[i];

        }
        for(int i=0;i<n*n;i++){
            atmenettomb[i]=rhs.atmenettomb[i];
            //cout <<atmenettomb[i].pData<< endl;
        }
    }
    return *this;

    }
};

/**
 * Bázisok
 */
enum Bazis {
    Adenin, Citozin, Guanin, Timin
};

/**
 * Állapotgép publikus interfésze.
 * A privát részt szabadon változtathatja, de a publikus részt ne változtassa, ne bővítse!
 */
class Allapotgep {
    Adattomb t;
public:
    /**
     * Konfig fájl beolvasása. Ha a fájl nem létezik/nem lehet megnyitni eldobja a NEPTUN-kódot.
     * Újra felépíti az állapotgépet, a korábbit törli ha volt. Kezdő állapotba áll.
     * @param  fajlnév - fájl neve
     * @return -
     * @exception fájl megnyitási hiba esetén NEPTUN_KÓD
    */
    void konfigural(const char* fajlnev);

    /** Visszaadja melyik állapot aktív.
     * @return pointer az aktív állapot nevére
     */
    const char* aktualisallapot();

    /**
     * Elfogadó állapotban van-e az állapotgép.
     * @return true, ha elfogadó állapotban van
     */
    bool elfogad();

    /**
     * Az aktuális állapotnak és inputnak megfelelő következő állapotba léptet.
     * @param b - beérkező bázis, mint input
     */
    void atmenet(Bazis b);

    /**
     * Feldolgozza a paraméterként kapott bázissorozatot.
     * Visszaadja, hogy elfogadó állapotba került-e. (Nem áll vissza kezdő állapotba.)
     * @param b - input sorozatra mutató pointer
     * @param n - a sorozat hossza
     * @return tru, ha elfogadó állapotba került
    */
    bool feldolgoz(const Bazis *b, int n);

    /**
     * Kezdő állapotba visz.
     */
    void alaphelyzet();

    ~Allapotgep();
};

/**
 * Segédfüggvény, karakterből enummá konvertál.
 * @param  b - bázis 1 betűs jele
 * @return Bazis enum kontans
 */
inline Bazis cast(char b) {
    std::locale loc;
    char k = std::tolower(b, loc);
    Bazis ret;
    switch(k) {
        case 'a': ret = Adenin; break;
        case 'c': ret = Citozin; break;
        case 'g': ret = Guanin; break;
        case 't': ret = Timin; break;
        default: throw "Format!!"; break;
    }
    return ret;
}

/**
 * Segédfüggvény, Bazis konstansból karakterré konvertál.
 * @param b - bazis enum konstansa
 * @param upper - nagybetűs legyen-e
 * @return bázis 1 betűs jele
 */
inline char cast(Bazis b, bool upper = true) {
    char ret = '0';
    switch (b)
    {
        case Adenin: ret = 'a'; break;
        case Citozin: ret = 'c'; break;
        case Guanin: ret = 'g'; break;
        case Timin: ret = 't'; break;
    }
    if(upper) {
        std::locale loc;
        ret = std::toupper(ret, loc);
    }
    return ret;
}

#endif
