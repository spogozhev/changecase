#include "changecase.h"
#include <ctime>
#include <cstdlib>

void toggle_case(std::ifstream & inFile, std::ofstream & outFile) {
	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (ch >= 'a' && ch <= 'z') {
			ch = (ch - 'a') + 'A';
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = (ch - 'A') + 'a';
		}
		outFile.put(ch);
	}
}

void to_lower_case(std::ifstream& inFile, std::ofstream& outFile) {
	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (ch >= 'A' && ch <= 'Z') {
			ch = (ch - 'A') + 'a';
		}
		outFile.put(ch);
	}
}

void to_upper_case(std::ifstream& inFile, std::ofstream& outFile) {
	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (ch >= 'a' && ch <= 'z') {
			ch = (ch - 'a') + 'A';
		}
		outFile.put(ch);
	}
}

bool is_delim(int ch) {
	return  (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
}

void title_case1(std::ifstream& inFile, std::ofstream& outFile) {
	int state = 0; 
	/*
	0 - outside the word
	1 - inside the word
	*/
	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (state == 0) {
			if (!is_delim(ch)) {
				if (ch >= 'a' && ch <= 'z') {
					ch = (ch - 'a') + 'A';
				}
				state = 1;
			}
		}
		else {
			if (!is_delim(ch)) {
				if (ch >= 'A' && ch <= 'Z') {
					ch = (ch - 'A') + 'a';
				}
			}
			else {
				state = 0;
			}
		}
		outFile.put(ch);
	}
}

void title_case(std::ifstream& inFile, std::ofstream& outFile) {
	enum class States {outside, inside};

	States state = States::outside;

	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (state == States::outside) {
			if (!is_delim(ch)) {
				if (ch >= 'a' && ch <= 'z') {
					ch = (ch - 'a') + 'A';
				}
				state = States::inside;
			}
		}
		else {
			if (!is_delim(ch)) {
				if (ch >= 'A' && ch <= 'Z') {
					ch = (ch - 'A') + 'a';
				}
			}
			else {
				state = States::outside;
			}
		}
		outFile.put(ch);
	}
}

void random_case(std::ifstream & inFile, std::ofstream & outFile) {
	int ch;
	std::srand(std::time(0));
	while ((ch = inFile.get()) != EOF) {
		if (ch >= 'a' && ch <= 'z' && rand()%2==1) {
			ch = (ch - 'a') + 'A';
		}
		else if (ch >= 'A' && ch <= 'Z' && rand()%2==1) {
			ch = (ch - 'A') + 'a';
		}
		outFile.put(ch);
	}
}
