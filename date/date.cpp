#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include <ctime>
#include <sstream>

using std::string;

namespace util {
	Date::Date() : Date(1,1,1970){

	}

	Date::Date(int d, int m, int y) {		
		oTime.tm_year = y - 1900;
		oTime.tm_mon = m - 1;
		oTime.tm_mday;

		cTime = mktime(&oTime);
	}


	void Date::day(int d) {

	}

	int Date::day() {

	}

	void Date::month(int m) {

	}

	int Date::month() {

	}

	void Date::year(int y) {

	}

	int Date::year() {

	}

	string Date::dayName() {

	}

	string Date::monthName() {

	}

	void Date::advance(int move = 1) {

	}

	void Date::print(std::ostream& out) {

	}


}
