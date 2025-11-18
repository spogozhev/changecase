#include <fstream>
#include <cstring>

void toggle_case(std::ifstream& inFile, std::ofstream& outFile);
void to_lower_case(std::ifstream& inFile, std::ofstream& outFile);
void to_upper_case(std::ifstream& inFile, std::ofstream& outFile);
bool is_delim(int ch);
void title_case(std::ifstream& inFile, std::ofstream& outFile);
void random_case(std::ifstream& inFile, std::ofstream& outFile);
