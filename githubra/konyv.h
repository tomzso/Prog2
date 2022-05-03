
#ifndef KONYV_H_INCLUDED
#define KONYV_H_INCLUDED


//#include "segedfuggvenyek.h"
#include<fstream>
#include <iostream>
#include "segedfuggvenyek.h"


class Konyv {
	int kiadasiev;
	std::string cim;
	std::string szerzo;
	int tipus;
public:
	Konyv();
	Konyv(int kiadasiev, std::string cim, std::string szerzo, int az = 0);
	int getkiadasiev() const;
	std::string getcim()const;
	std::string getszerzo()const;
	int gettipus()const;
	virtual std::string getspecadat()const = 0;
	virtual void print(std::ostream& os, int i = 0)const;
	virtual ~Konyv();

};

#endif