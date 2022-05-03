#ifndef SEGEDFUGGVENYEK_H_INCLUDED
#define SEGEDFUGGVENYEK_H_INCLUDED
#include <iostream>
#include "memtrace.h"



inline std::string whitespace2star(std::string str) {
	std::string uj = str;
	for (size_t i = 0;i < str.size();i++) {
		if (uj[i] == ' ') {
			uj[i] = '*';
		}
	}
	return uj;
}
inline std::string star2whitespace(std::string str) {
	std::string uj = str;
	for (size_t i = 0;i < str.size();i++) {
		if (uj[i] == '*') {
			uj[i] = ' ';
		}
	}
	return uj;
}

#endif
