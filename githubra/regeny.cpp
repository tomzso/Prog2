#include "regeny.h"
#include "memtrace.h"
#include "kivetelosztalyok.h"

Regeny::Regeny(int kiadasiev, std::string cim, std::string szerzo, std::string fohos, int az) :Konyv(kiadasiev, cim, szerzo, az), fohos(fohos) {
	if (kiadasiev < 1000 || kiadasiev > 2022) {
		throw OutOfRange_kiadasiev();
	}
}
void Regeny::print(std::ostream& os, int i) const {
	Konyv::print(os, i);
	if (i == 0)
		os << "\t\tFohos: " << fohos << std::endl;
	if (i == 1) {
		std::string kovertalt_fohos = whitespace2star(fohos);
		os << " " << kovertalt_fohos << std::endl;
	}
}
std::string Regeny::getspecadat()const {
	return fohos;
}