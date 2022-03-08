/**
 * \file allapotgep.cpp
 *
 * Ebben a fájlban kell megvalósítania az Allapotgep osztály
 * metódusait, valamint mindazon további osztályokat, melyek szükségesek
 * a feladat megvalósításához.
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include <iostream>
#include <fstream>

#include "allapotgep.h"
#include "memtrace.h"
    String::String(){
        len=0;
        str=new char[1];
        str[0]='\0';
    }



    void Allapotgep::konfigural(const char* fajlnev){
          std::ifstream ifs (fajlnev);

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

