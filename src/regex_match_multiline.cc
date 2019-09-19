#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

int main(int argc, char **argv) {
	using std::cout;
	using std::string;
	using std::ifstream;
	using std::stringstream;

	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <regex> <file>\n";
		return 1;
	}

	//read file
	stringstream buf;
	buf << ifstream(argv[2]).rdbuf();
	string tomatch = buf.str();

	std::regex r(argv[1]);
	for(std::sregex_iterator it(std::begin(tomatch),std::end(tomatch),r); it != std::sregex_iterator(); ++it)
		cout << it->str() << "\n";
}
