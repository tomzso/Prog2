#include "konyvtar.h"

#include <iostream>
#include "memtrace.h"
#include<fstream>
//#include <ctype.h>
#include <locale>

#include "konyvtar.h"
#include "regeny.h"
#include "tankonyv.h"
#include "kivetelosztalyok.h"
#include "gtest_lite.h"



int main() {
	Konyvtar konyvtar;
	
	//betoltes
	konyvtar.load();

	bool exit = false;
	std::string input;
	
	while (!exit) {
		std::cout << "Fomenu:" << std::endl;
			std::cout << "0. Kilepes a fomenubol" << std::endl;
			std::cout << "1. Konyv hozzadasa" << std::endl;
			std::cout << "2. Modositasok mentese" << std::endl;
			std::cout << "3. Listazas" << std::endl;
			std::cout << "4. Torles" << std::endl;
			;
		std::cout << "Kerek egy szamot: ";
		try {
			std::getline(std::cin, input);
			char fomenu = ' ';
			if(input.size()==1)
				fomenu = input[0];
			switch (fomenu) {
			case '0':
				exit = true;
				break;
			case '1': {
				konyvtar.add_by_user();

			}
				  break;
			case '2':
				konyvtar.save();
				std::cout << "Modositasok elmentve" << std::endl;
				std::cout << std::endl;
				break;
			case '3':
				konyvtar.list(std::cout);
				break;
			case '4': {
				konyvtar.list(std::cout);
				std::string inputszam;
				std::cout << std::endl;
				std::cout << "Kerek egy azonositoszamot: ";
				std::getline(std::cin, inputszam);
				for (size_t i = 0;i < inputszam.size();i++) {
					if (!std::isdigit(inputszam[i])) {
						throw Incorrect_input();
					}
				}


				konyvtar.remove(std::stoi(inputszam));
				std::cout << std::endl;
				std::cout << "Az ujra sorszamozott lista:";
				std::cout << std::endl;
				konyvtar.list(std::cout);
			}
				break;
			
			default:
				if(fomenu!=0)
					std::cout << "Nincs ilyen opcio" << std::endl;
				std::cout << std::endl;
				break;
				

			}
		}
		catch (Exception& e) { 
			std::cout << e.hiba_oka() << std::endl;
			std::cout << std::endl;
		}
	}


	/// Teszt

	TEST(Konyvtari_adatatok, ellenorzes) {
		Konyvtar iskolai_taska;
		EXPECT_NO_THROW(iskolai_taska.add(new Tankonyv(2006, "English vocabulary 7", "T. Geza", "Angol nyelv", 7)));
		EXPECT_NO_THROW(iskolai_taska.add(new Regeny(2013, "Harry Potter es a Fonix rendje", "JKR.", "Harry Potter")));
		EXPECT_NO_THROW(iskolai_taska.add(new Regeny(1978, "Pal utcai fiuk", "M. Ferenc", "Nemecsek")));
		EXPECT_NO_THROW(iskolai_taska.add(new Tankonyv(2006, "Tortenelem munkafuzet", "C. Akos", "Tortenelem", 5)));
		EXPECT_NO_THROW(iskolai_taska.add(new Tankonyv(2000, "Atlasz kozepiskolasoknak", "L. Botond", "Foldrajz", 10))); 
		EXPECT_NO_THROW(iskolai_taska.add(new Tankonyv(1989, "Sokszinu matematika", "N. Katalin", "Matek", 8)));
		EXPECT_EQ(iskolai_taska.getdb(), 6);
		EXPECT_NO_THROW(iskolai_taska.remove(4));
		EXPECT_EQ(iskolai_taska.getdb(), 5);
		//iskolai_taska.list(std::cout);
		EXPECT_EQ(iskolai_taska[3]->getkiadasiev(), 2000);
		EXPECT_EQ(iskolai_taska[3]->getcim(), "Atlasz kozepiskolasoknak");
		EXPECT_EQ(iskolai_taska[3]->getszerzo(), "L. Botond");
		EXPECT_EQ(iskolai_taska[3]->getspecadat(), "Foldrajz 10");
		EXPECT_EQ(iskolai_taska[0]->getkiadasiev(), 2006);
		EXPECT_EQ(iskolai_taska[1]->getcim(), "Harry Potter es a Fonix rendje");
		EXPECT_EQ(iskolai_taska[2]->getszerzo(), "M. Ferenc");
		EXPECT_EQ(iskolai_taska[2]->getspecadat(), "Nemecsek");
		EXPECT_ANY_THROW(iskolai_taska[5]);
		iskolai_taska.clear_all();
		iskolai_taska.clear_all();
		EXPECT_EQ(iskolai_taska.getdb(), 0);
		//EXPECT_ANY_THROW(iskolai_taska[1]);
	}END

	TEST(Konyvek_letrehozzasa, hibas_szamok) {
		
		EXPECT_ANY_THROW(Tankonyv(1996, "Matekzsenikonyv kicsiknek", "K. Miklos", "Matematika", 0));
		EXPECT_ANY_THROW(Tankonyv(0, "A Biblia", "Lukacs", "Latin nyelv", 10));
		EXPECT_ANY_THROW(Regeny(2300, "The three god heroes", "Best Mark", "Thomas"));
		EXPECT_ANY_THROW(Regeny(250, "Athen", "James", "Spartacus"));

	}END
		
	TEST(Konyvtar, kivetelek) {
		Konyvtar polc;
		polc.add(new Tankonyv(2014, "Enekeskonyv", "Krisz", "Enek", 9));
		EXPECT_ANY_THROW(polc.remove(0));
		EXPECT_NO_THROW(polc.remove(1));
		EXPECT_ANY_THROW(polc.list(std::cout));
		EXPECT_ANY_THROW(polc.remove(1));
		EXPECT_ANY_THROW(polc.remove(0));
		EXPECT_ANY_THROW(polc.add_konyv_inputline("         2016          ,Kemia munkafuzet, D. Norbert,kemia,8"));
		EXPECT_ANY_THROW(polc.add_konyv_inputline("2016,Kemia munkafuzet, D. Norbert,kemia,8."));
		EXPECT_ANY_THROW(polc.add_konyv_inputline("2016,Kemia munkafuzet"));
		EXPECT_ANY_THROW(polc.add_konyv_inputline("Kemai munkafuzet"));
		EXPECT_ANY_THROW(polc.add_konyv_inputline("Ketezertizenhat,Kemia munkafuzet, D. Norbert,kemia,8"));
		EXPECT_ANY_THROW(polc.add_konyv_inputline("2016,Kemia munkafuzet, D. Norbert,kemia,nyolc"));
	}END


	return 0;
};