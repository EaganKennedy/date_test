#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include <vector>
#include <ctime>
#include <sstream>

using std::string;

namespace util {
	Date::Date() : Date(1,1,1970){

	}

	Date::Date(int d, int m, int y) {		
		year(y);
		month(m);
		day(d);

		normalizeCTime();
	}


	void Date::day(int d) {
		if (d < 1 || d > 31) {
			throw Invalid{ d, month(), year() };
		}

		int orinM = oTime.tm_mon;
		int orinD = oTime.tm_mday;

		oTime.tm_mday = d;
		mktime(&oTime);

		if (oTime.tm_mon != orinM) {
			oTime.tm_mon = orinM;
			oTime.tm_mday = orinD;
			mktime(&oTime);

			throw Invalid{ d, month(), year() };
		}

		normalizeCTime();
	}

	int Date::day() {
		return oTime.tm_mday;
	}

	void Date::month(int m) {
		if (m < 1 || m > 12) {
			throw Invalid{ (day(), m, year()) };
		}
		oTime.tm_mon = m - 1;
		normalizeCTime();
	}

	int Date::month() {
		return oTime.tm_mon + 1;
	}

	void Date::year(int y) {
		oTime.tm_year = y - 1900;

		normalizeCTime();
	}

	int Date::year() {
		return oTime.tm_year + 1900;
	}

	string Date::dayName() {
		const std::vector<string> weekdays = 
		{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

		return weekdays.at(oTime.tm_wday);
	}

	string Date::monthName() {
		const std::vector<string> months = 
		{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		
		return months.at(oTime.tm_wday);
	}

	void Date::advance(int move) {

	}

	void Date::print(std::ostream& out) {

	}

	 Date Date::now() {
		 //temp
		 Date d;
		 return d;
	}

	 void Date::normalizeCTime() {
		 cTime = mktime(&oTime);
	 }

	Date::Order Date::order = Date::Order::MonthDayYear;
	string Date::separator = "/";
}
