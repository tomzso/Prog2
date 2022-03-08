#include <iostream>
#include <string.h>
#include <fstream>
#include "gtest_lite.h"
#include "memtrace.h"
#include <locale>

#include <exception>

using namespace std;

enum Bazis {
    Adenin, Citozin, Guanin, Timin
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


struct String {

    size_t size;
    char * str;
    public:
    String():size(0){
        str=new char[1];
        str[0]='\0';
    }
    String(char const * s){
        size=strlen(s);
        str=new char[size+1];
        strcpy(str,s);
    }
    String(char s){
        size=1;
        str=new char[size+1];
        str[0]=s;
        str[1]='\0';
    }
    ~String(){
        delete[] str;
    }
    String(const String& s){
        size=s.size;
        str=new char[size+1];
        strcpy(str,s.str);
    }
    String& operator=(const String& s){
        if(this!=&s){
            delete[] str;
            size=s.size;
            str=new char[size+1];
            strcpy(str,s.str);

        }
        return *this;
    }
    String operator+(String const& rhs) const{

        String uj;
        uj.size=rhs.size+size;
        uj.str=new char[uj.size+1];
        strcpy(uj.str,str);
        strcat(uj.str,rhs.str);
        return uj;

    }
    String& operator+=(String const& rhs){
        String tmp(*this);
        delete[] str;
        size=tmp.size+rhs.size;
        str=new char[size+1];
        strcpy(str,tmp.str);
        strcat(str,rhs.str);
        return *this;

    }
    String& operator+=(char rhs){
        String tmp(*this);
        delete[] str;
        size=tmp.size+1;
        str=new char[size+1];
        strcpy(str,tmp.str);
        str[size+1]=rhs;
        return *this;
    }
    size_t length() const {
        return size;
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
        if(size!=s.length()){
            return false;
        }
        for(size_t i=0;i<size;i++){
            if(str[i]!=s.str[i]){
                return false;
            }

        }
        return true;
    }
};
std::ostream& operator<<(ostream&os,const String &s){
    os<<s.getstr();
    return os;

}



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
    ifstream file(text);
    int m;
    char ertek;
    char allapotnev[21];
    char atmenet[5];
    int i=0;

    file>>m;
    cout << m<< endl;
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




struct Allapotgep {
    Adattomb t;
public:

    void konfigural(const char* fajlnev){
          ifstream ifs (fajlnev);

          if (ifs.is_open()){
            //cout<<"opened"<<endl;
            Adattomb a=fajlnev;
            t=a;

            //t=Adattomb(fajlnev);

            //cout<<t.atmenettomb[1]<<endl;
          }
          else{
            //cout<<"not opened"<<endl;
            throw "V6AO9G";
          }
        }

    const char* aktualisallapot(){
        //cout<<t.aktivallapot<<endl;
        cout<<t.allapottomb[t.aktivallapot].str[5]<<endl;
        return t.allapottomb[t.aktivallapot].str;
    }
    bool elfogad(){
        if(t.ervenyessegtomb[t.aktivallapot]=="I"){
            //cout<<t.ervenyessegtomb[t.aktivallapot]<<endl;
            //cout<<t.atmenettomb[1].str[1]<<endl;
            return true;
        }

        return false;
    }
    void atmenet(Bazis b){
        char atmenetbetu=cast(b);
        int atmenetindex;

        for(int i=(t.aktivallapot*t.n);i<((t.aktivallapot+1)*t.n);i++){
            for(size_t e=0;e<t.atmenettomb[i].length();e++){
                if (t.atmenettomb[i].str[e]==atmenetbetu){
                    atmenetindex=i;
                }
            }
        }
        int ebbeazallapotbament=atmenetindex%t.n;
        t.aktivallapot=ebbeazallapotbament;

    }
    bool feldolgoz(const Bazis *b, int n){
        for(int i=0;i<n;i++){
            atmenet(b[i]);

        }
        return elfogad();
    }
    void alaphelyzet(){
        t.aktivallapot=0;
    }

};





int main() {
    Allapotgep all;
    all.konfigural("konfiguracio.txt");
    all.elfogad();
    cout<<all.aktualisallapot()<<endl;




/*Enum test

    Bazis a=cast('a');
    Bazis b=Citozin;
    char c=cast(b);
    cout <<c<< endl;
*/

/* Adattomb test

    Adattomb adat("implikacio.txt");
    Adattomb adat2("konfiguracio.txt");
    Adattomb cpy(adat2);
    Adattomb cpy2;
    cpy=adat;


    //cout <<adat.atmenettomb[0].pData<< endl;

    for(int i=0;i<4;i++){
        cout <<cpy.atmenettomb[i].str<< endl;
    }

*/

/*String test

    String s1, s2;
    s1="hello";
    s2="hello";
    //std::cin >> s1 >> s2;
    std::cout << "s1 + s2 = " << s1 + s2 << std::endl;
    //s2 += s1;
    std::cout << "s2 + s1 = " << s2<<"," <<s1<< std::endl;
    std::cout << (s1==s2)<< std::endl;
*/
    return 0;
}
