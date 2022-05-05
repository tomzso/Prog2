#ifndef KONYVTAR_H_INCLUDED
#define KONYVTAR_H_INCLUDED
#include<fstream>
#include <iostream>
#include "memtrace.h"

#include "konyv.h"
#include "regeny.h"
#include "tankonyv.h"
#include "kivetelosztalyok.h"

//#include "segedfuggvenyek.h"




class Konyvtar {
	int db;
	Konyv** konyvtar;
public:
	Konyvtar();
	int getdb()const;
	void add(Konyv* ujkonyv);
	void clear_all();
	void list(std::ostream& os, int tipus = 0)const;
	void remove(int index);
	void save();
	Konyv* operator[](int i) const;
	~Konyvtar();
	void load();
	void add_konyv_inputline(std::string input_konyv_adatok);
	void add_by_user();

};

#endif