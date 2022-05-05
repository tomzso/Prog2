#include "tankonyv.h"
#include "memtrace.h"
#include "kivetelosztalyok.h"

Tankonyv::Tankonyv(int kiadasiev, std::string cim, std::string szerzo, std::string targynev, int kor, int az) :Konyv(kiadasiev, cim, szerzo, az), targynev(targynev), korosztaly(kor) {
	if (kiadasiev < 1000 || kiadasiev > 2022) {
		throw OutOfRange_kiadasiev();
	}
	if (kor < 1 || kor > 12) {
		throw OutOfRange_evfolyam();
	}
}
void Tankonyv::print(std::ostream& os, int i)const {
	this->Konyv::print(os, i);
	if (i == 0)
		os << "\t\tTantargy: " << targynev << " " << korosztaly << std::endl;
	if (i == 1) {
		std::string kovertalt_targynev = whitespace2star(targynev);
		os << " " << kovertalt_targynev << " " << korosztaly << std::endl;
	}
}
std::string Tankonyv::getspecadat()const {
	return targynev + ' ' + std::to_string(korosztaly);
}