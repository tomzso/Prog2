#include <cstring>
#include <cctype>
#include "nem_oo.h"
#include <string>
#include <math.h>


/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

int sajat::atoi(const char *p, int base){
    int osszeg=0;
    int szamjegyek=strlen(p);

    for(int i=0;p[i]!='\0';i++){
        if(isdigit(p[i])){

            char a=p[i];
            int ia = a - '0';
            if (ia<base){
                szamjegyek-=1;
                osszeg+=ia*pow(base,szamjegyek);
            }
            else
                throw "V6AO9G";

        }
        else
            throw "V6AO9G";
    }
    return osszeg;
}


char* sajat::strcat(const char *p1, const char *p2){
    int hossz=strlen(p1)+strlen(p2);
    char *p3= new char[hossz+1];
    strcpy(p3,p1);
    int e=0;
    for(int i=strlen(p1);p2[e]!='\0';i++){
        p3[i]=p2[e];
        e++;
    }
    p3[hossz]='\0';
    return p3;
}

char* sajat::unique(char *first, char *last){
    char *mozgo = first;
    char *eleje = first;
    int i=0;
    int j=0;
    while (mozgo != last){
        if (mozgo[i] == mozgo[i+1]) {
            mozgo++;
        }
        else{
            eleje[j] = mozgo[i];
            j++;
            mozgo++;
        }
    }
    eleje[j] = '\0';
    mozgo= eleje+j;
    return mozgo;
}
