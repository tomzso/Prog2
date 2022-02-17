// F�jl: fuggvenyeim.cpp
// Ebben val�s�tom meg a gyakran haszn�lt f�ggv�nyeket.

#include "fuggvenyeim.h"

// K�t int adat felcser�l�se
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
