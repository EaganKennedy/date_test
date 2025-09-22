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
		oTime.tm_mday = d;

		cTime = mktime(&oTime);
	}


	void Date::day(int d) {

	}

	int Date::day() {
		return 1;
	}

	void Date::month(int m) {

	}

	int Date::month() {
		return 1;
	}

	void Date::year(int y) {

	}

	int Date::year() {
		return 1;
	}

	string Date::dayName() {
		return "";
	}

	string Date::monthName() {
		return "";
	}

	void Date::advance(int move) {

	}

	void Date::print(std::ostream& out) {

	}

	Date::Order Date::order = Date::Order::MonthDayYear;
	string Date::separator = "/";
}
