#include <iostream>
#include <fstream>
#include "changecase.h"

void help() {
	std::cout << "Use\n\tchangecase -key source_file destination_file\n";
	std::cout << "  -L \t to lower case\n";
	std::cout << "  -U \t to upper case\n";
	std::cout << "  -G \t toggle case\n";
	std::cout << "  -T \t Title Case\n";
	std::cout << "  -R \t raNdOM cASe\n";
}

int main(int argc, char* argv[])
{
	if (argc != 4) {
		help();
		return 0;
	}

	const char* inputfilename = argv[2];
	const char* outputfilename = argv[3];

	std::ifstream inFile;
	inFile.open(inputfilename, std::ios_base::binary);
	if (!inFile) {
		std::cout << "Can not open file '" << inputfilename << "'\n";
		return 1;
	}

	std::ofstream outFile;
	outFile.open(outputfilename, std::ios_base::binary);
	if (!outFile) {
		std::cout << "Can not open file '" << outputfilename << "'\n";
		inFile.close();
		return 2;
	}

	if (strcmp(argv[1], "-L") == 0) {
		to_lower_case(inFile, outFile);
	}
	else if (strcmp(argv[1], "-U") == 0) {
		to_upper_case(inFile, outFile);
	}
	else if (strcmp(argv[1], "-G") == 0) {
		toggle_case(inFile, outFile);
	}
	else if (strcmp(argv[1], "-T") == 0) {
		title_case(inFile, outFile);
	}
	else if (strcmp(argv[1], "-R") == 0) {
		random_case(inFile, outFile);
	}
	else {
		help();
	}

	inFile.close();
	outFile.close();
	return 0;
}
