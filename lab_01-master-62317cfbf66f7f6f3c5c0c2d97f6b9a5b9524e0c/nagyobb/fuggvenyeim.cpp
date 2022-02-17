// Fájl: fuggvenyeim.cpp
// Ebben valósítom meg a gyakran használt függvényeket.

#include "fuggvenyeim.h"

// Két int adat felcserélése
void csere(int& a, int& b) {
   int tmp =  a;
   a =  b;
   b = tmp;


}

double polinom(double x, double const *a, int n) {
    double y = 0;
    for (int i = n ; i >= 0; i--) {
        y = y * x + a[i];
    }
    return y;
}

// ....
