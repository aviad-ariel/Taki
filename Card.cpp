#include "Card.h"
#define RANDOM
#ifdef WINDOWS
//#include <windows.h>
#endif
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

int Card::counter = 0;
using namespace std;
Card Card::generate_card() {
#ifdef RANDOM
	return Card(color(rand() % 4 + 1), sign(rand() % 13 + 1));
#else
	return Card(color(counter % 2 + 1), sign(counter % 5 + 8));
#endif

}
bool Card::is_legal(const Card& other) const {
	bool ret = false;
	ret |= (get_color() == other.get_color());
	ret |= (get_sign() == other.get_sign());
	return ret;
}
ostream& operator << (ostream &os, const Card &c) {
#ifdef WINDOWS
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	switch (c.clr) {
	case color::R:
		SetConsoleTextAttribute(hstdout, 0x7C);
		break;
	case color::G:
		SetConsoleTextAttribute(hstdout, 0x7A);
		break;
	case color::B:
		SetConsoleTextAttribute(hstdout, 0x79);
		break;
	case color::Y:
		SetConsoleTextAttribute(hstdout, 0x7E);
		break;
	default:
		os << static_cast<int>(c.clr) << " error";
	}

	switch (c.s) {
	case sign::PLUS:
		os << "+";
		break;
	case sign::STOP:
		os << "STP";
		break;
	case sign::CD:
		os << "-><-";
		break;
	case sign::TAKI:
		os << "TAKI";
		break;
	default:
		os << static_cast<int>(c.s);
	}

	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
#else
	switch (c.clr) {
	case color::R:
		os << RED;
		break;
	case color::G:
		os << GREEN;
		break;
	case color::B:
		os << BLUE;
		break;
	case color::Y:
		os << YELLOW;
		break;
	default:
		os << static_cast<int>(c.clr) << " error";
	}

	switch (c.s) {
	case sign::PLUS:
		os << "+" << RESET;;
		break;
	case sign::STOP:
		os << "STP" << RESET;
		break;
	case sign::CD:
		os << "-><-" << RESET;
		break;
	case sign::TAKI:
		os << "TAKI" << RESET;
		break;
	default:
		os << static_cast<int>(c.s) << RESET;
	}
#endif
	return os;
}
