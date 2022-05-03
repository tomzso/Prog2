#include "konyvtar.h"

#include <iostream>
#include "memtrace.h"
#include<fstream>
//#include <ctype.h>
#include <locale>

#include "konyvtar.h"
#include "regeny.h"
#include "tankonyv.h"



int main() {
	Konyvtar konyvtar;
	
	//betoltes
	konyvtar.load();

	bool exit = false;
	std::string input;
	
	while (!exit) {
		std::cout << "Fomenu:\n"
			"0. Kilepes a fomenubol\n"
			"1. Konyv hozzadasa\n"
			"2. Modositasok mentese\n"
			"3. Listazas\n"
			"4. Torles\n"
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
				std::cout << "Modositasok elmentve\n" << std::endl;
				break;
			case '3':
				konyvtar.list(std::cout);
				break;
			case '4': {
				konyvtar.list(std::cout);
				std::string inputszam;

				std::cout << "\nKerek egy azonositot: ";
				std::getline(std::cin, inputszam);
				for (size_t i = 0;i < inputszam.size();i++) {
					if (!std::isdigit(inputszam[i])) {
						throw("Ez nem egesz szam!");
					}
				}


				konyvtar.remove(std::stoi(inputszam));
				std::cout << "\nAz ujra sorszamozott lista:\n";
				konyvtar.list(std::cout);
			}
				break;
			
			default:
				if(fomenu!=0)
					std::cout << "Nincs ilyen opcio\n" << std::endl;
				break;
				

			}
		}
		catch (const char* str) { std::cout << str<<"\n\n"; }
	}
	

	return 0;
};