#include "konyv.h"
#include "memtrace.h"

Konyv::Konyv() :kiadasiev(0), cim(""), szerzo(""), tipus(0) {}
Konyv::Konyv(int kiadasiev, std::string cim, std::string szerzo, int az) :kiadasiev(kiadasiev), cim(cim), szerzo(szerzo), tipus(az) {}
int Konyv::getkiadasiev() const {
	return kiadasiev;

}
std::string Konyv::getcim()const {
	return cim;
}
std::string Konyv::getszerzo()const {
	return szerzo;
}
int Konyv::gettipus()const { return tipus; }


void Konyv::print(std::ostream& os, int i)const {
	if (i == 0)
		os << "Cim: " << cim << "\t\tSzerzo: " << szerzo << "\t\tKiadasi ev: " << kiadasiev;
	if (i == 1) {
		std::string kovertalt_cim = whitespace2star(cim);
		std::string kovertalt_szerzo = whitespace2star(szerzo);
		os << tipus << " " << kovertalt_cim << " " << kovertalt_szerzo << " " << kiadasiev;
	}

}

Konyv::~Konyv() {}