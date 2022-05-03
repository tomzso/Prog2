#ifndef TANKONYV_H_INCLUDED
#define TANKONYV_H_INCLUDED
#include<fstream>
#include <iostream>
#include "konyv.h"

class Tankonyv :public Konyv {
	std::string targynev;
	int korosztaly;

public:
	Tankonyv(int kiadasiev, std::string cim, std::string szerzo, std::string targynev, int kor, int az = 4);
	void print(std::ostream& os, int i = 0)const;
	std::string getspecadat()const;
};

#endif