#ifndef REGENY_H_INCLUDED
#define REGENY_H_INCLUDED
#include<fstream>
#include <iostream>
#include "konyv.h"

class Regeny :public Konyv {
	std::string fohos;
public:
	Regeny(int kiadasiev, std::string cim, std::string szerzo, std::string fohos, int az = 3);
	void print(std::ostream& os, int i = 0) const;
	std::string getspecadat()const;
};

#endif