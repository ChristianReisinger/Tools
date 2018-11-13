#include <iostream>
#include <sstream>

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <list>\n"
				"<list> ist a list of ints separated by a single non-number char.\n";
	}
	std::istringstream list_iss(argv[1]);
	std::ostringstream ranges_iss;

	int first, prev, next;
	char sep;
	list_iss >> first;
	ranges_iss << first;
	prev = first;

	while (list_iss >> sep >> next) {
		if (next != prev + 1) {
			if (prev != first)
				ranges_iss << ".." << prev;
			ranges_iss << " " << next;
			first = next;
		}
		prev = next;
	}

	if(prev != first)
		ranges_iss << ".." << prev;

	std::cout << ranges_iss.str();
}
