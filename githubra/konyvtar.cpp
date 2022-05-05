#include "konyvtar.h"
#include "memtrace.h"

Konyvtar::Konyvtar() :db(0), konyvtar(new Konyv* [0]) {}
int Konyvtar::getdb()const { return db; }
void Konyvtar::add(Konyv* ujkonyv) {
	Konyv** ujkonyvtar = new Konyv * [db + 1];
	for (int i = 0;i < db;i++) {
		ujkonyvtar[i] = konyvtar[i];
	}
	ujkonyvtar[db] = ujkonyv;
	db++;
	delete[] konyvtar;
	konyvtar = ujkonyvtar;
	
}

void Konyvtar::clear_all() {
	for (int i = 0;i < db;i++) {
		delete konyvtar[i];
	}
	delete[] konyvtar;
	konyvtar = new Konyv * [0];
	db = 0;
}
void Konyvtar::list(std::ostream& os, int tipus)const {
	if (db == 0) {
		throw Empty_lista();
	}
	if (tipus == 0) {
		for (int i = 0;i < 115;i++) {

			std::cout << "-";
		}
	}


	for (int i = 0;i < db;i++) {
		if (tipus == 0) {
			std::cout << std::endl;
			std::cout << i + 1 << ".  ";
		}

		konyvtar[i]->print(os, tipus);

	}
	if (tipus == 0) {
		for (int i = 0;i < 115;i++) {

			std::cout << "-";
		}
	}
	std::cout << std::endl;
}
void Konyvtar::remove(int index) {
	if (db == 0) {
		throw Empty_lista();
	}
	int sorszam = index;
	sorszam -= 1;


	if (sorszam < db && sorszam >= 0) {
		Konyv** ujkonyvtar = new Konyv * [db - 1];
		int ujdb = 0;
		for (int i = 0;i < db;i++) {
			if (i == sorszam) {
				delete konyvtar[i];

			}
			else {
				ujkonyvtar[ujdb] = konyvtar[i];
				ujdb++;
			}

		}
		db = db - 1;
		delete[] konyvtar;
		konyvtar = ujkonyvtar;

	}
	else {
		throw OutOfRange_index();
	}

}

void Konyvtar::save() {
	std::fstream konyvtari_adatok;
	konyvtari_adatok.open("konyvtari_adatok.txt", std::ios::out);
	if (konyvtari_adatok.is_open()) {
		konyvtari_adatok << this->getdb() << std::endl;
		this->list(konyvtari_adatok, 1);
	}

}

Konyv* Konyvtar::operator[](int i) const {
	if (i < 0 || i >= db) {
		throw OutOfRange_index();
	}
	return konyvtar[i];
}


Konyvtar::~Konyvtar() {
	this->clear_all();
	delete[] konyvtar;
}

void Konyvtar::load() {
	std::ifstream txt("konyvtari_adatok.txt");
	if (txt.is_open()) {

		int db, konyvtipus;
		txt >> db;
		for (int i = 0;i < db;i++) {
			txt >> konyvtipus;
			if (konyvtipus == 4) {
				int kiadasiev, korosztaly;
				std::string cim, szerzo, targynev;
				txt >> cim >> szerzo >> kiadasiev >> targynev >> korosztaly;

				std::string ujcim = star2whitespace(cim);
				std::string ujszerzo = star2whitespace(szerzo);
				std::string ujtargynev = star2whitespace(targynev);
				
				this->add(new Tankonyv(kiadasiev, ujcim, ujszerzo, ujtargynev, korosztaly));
			}
			if (konyvtipus == 3) {
				int kiadasiev;
				std::string cim, szerzo, fohos;
				txt >> cim >> szerzo >> kiadasiev >> fohos;

				std::string ujcim = star2whitespace(cim);
				std::string ujszerzo = star2whitespace(szerzo);
				std::string ujfohos = star2whitespace(fohos);
				
				this->add(new Regeny(kiadasiev, ujcim, ujszerzo, ujfohos));
			}
		}

	}
}
void Konyvtar::add_konyv_inputline(std::string input_konyv_adatok) {
	//std::string input_konyv_adatok = "hello";
	int i = 0;
	int vesszokszama = 0;
	while (input_konyv_adatok[i] != '\0') {
		if (input_konyv_adatok[i] == ',') {
			vesszokszama++;
		}
		i++;
	}

	if (!(vesszokszama == 3 || vesszokszama == 4)) {

		throw Incorrect_input();
	}
	if (vesszokszama == 3) {

		std::string ev = "";
		std::string cim = "";
		std::string szerzo = "";
		std::string fohos = "";
		int vesszok = 0;
		for (size_t e = 0;e < input_konyv_adatok.size();e++) {
			if (input_konyv_adatok[e] == ',') {
				vesszok += 1;
			}
			else {
				if (vesszok == 0) {
					if (!isdigit(input_konyv_adatok[e])) {
						throw NotNumber_kiadasiev();
					}
					ev += input_konyv_adatok[e];
				}
				if (vesszok == 1) {
					cim += input_konyv_adatok[e];
				}
				if (vesszok == 2) {
					szerzo += input_konyv_adatok[e];
				}
				if (vesszok == 3) {
					fohos += input_konyv_adatok[e];
				}
			}
		}

		this->add(new Regeny(std::stoi(ev), cim, szerzo, fohos));
	}
	if (vesszokszama == 4) {

		std::string ev = "";
		std::string cim = "";
		std::string szerzo = "";
		std::string targy = "";
		std::string evfolyam = "";

		int vesszok = 0;
		for (size_t e = 0;e < input_konyv_adatok.size();e++) {
			if (input_konyv_adatok[e] == ',') {
				vesszok += 1;
			}
			else {
				if (vesszok == 0) {
					if (!isdigit(input_konyv_adatok[e])) {
						throw NotNumber_kiadasiev();
					}
					ev += input_konyv_adatok[e];
				}
				if (vesszok == 1) {
					cim += input_konyv_adatok[e];
				}
				if (vesszok == 2) {
					szerzo += input_konyv_adatok[e];
				}
				if (vesszok == 3) {
					targy += input_konyv_adatok[e];
				}
				if (vesszok == 4) {
					if (!isdigit(input_konyv_adatok[e])) {
						throw NotNumber_evfolyam();
					}

					evfolyam += input_konyv_adatok[e];
				}
			}
		}

		this->add(new Tankonyv(std::stoi(ev), cim, szerzo, targy, std::stoi(evfolyam)));
	}
}

void Konyvtar::add_by_user() {
	
	std::string input_konyv_adatok;

	std::cout << "Tankkonyv eseten (kiadasi ev, cim, szerzo, targy, evfolyam)" << std::endl;
	std::cout << "Regeny eseten (kiadasi ev, cim, szerzo, fohos)" << std::endl;
	std::cout << std::endl;
	std::cout << "Kerem a konyv adatait: ";
	std::getline(std::cin, input_konyv_adatok);
	this->add_konyv_inputline(input_konyv_adatok);
	
}