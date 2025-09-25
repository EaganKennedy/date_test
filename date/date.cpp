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
		tm newDate{};

		newDate.tm_mday = d;
		newDate.tm_mon = m - 1;
		newDate.tm_year = y - 1900;
		newDate.tm_isdst = -1;

		validate(newDate);

		oTime = newDate;
		normalizeCTime();
	}

	void Date::day(int d) {
		tm newDate = oTime;
		newDate.tm_mday = d;

		validate(newDate);

		oTime.tm_mday = d;

		normalizeCTime();
	}
	int Date::day() const {
		return oTime.tm_mday;
	}

	void Date::month(int m) {
		tm newDate = oTime;
		newDate.tm_mon = m - 1;

		validate(newDate);
		
		oTime.tm_mon = m - 1;
		normalizeCTime();
	}
	int Date::month() const {
		return oTime.tm_mon + 1;
	}

	void Date::year(int y) {
		tm newDate = oTime;
		newDate.tm_year = y - 1900;

		validate(newDate);

		oTime.tm_year = y - 1900;

		normalizeCTime();
	}
	int Date::year() const {
		return oTime.tm_year + 1900;
	}

	string Date::dayName() const {
		return weekdays.at(oTime.tm_wday);
	}
	string Date::monthName() const {
		return months.at(oTime.tm_mon);
	}

	void Date::print(std::ostream& out) const {
		switch (Date::order) {
		case Order::MonthDayYear:
			out << month() << Date::separator << day() << Date::separator << year();
			break;
		case Order::DayMonthYear:
			out << day() << Date::separator << month() << Date::separator << year();
			break;
		case Order::YearMonthDay:
			out << year() << Date::separator << month() << Date::separator << day();
			break;
		}
	}

	void Date::advance(int move) {
		oTime.tm_mday += move;
		normalizeCTime();
	}

	Date Date::now() {
		Date d;
		time_t curSeconds = time(nullptr);
		tm curTime = *localtime(&curSeconds);
		d.year(curTime.tm_year + 1900);
		d.month(curTime.tm_mon + 1);
		d.day(curTime.tm_mday);
		return d;
	}

	void Date::normalizeCTime() {
		cTime = mktime(&oTime);
	}

	void Date::validate(tm newDate) {
		int year = newDate.tm_year;
		int month = newDate.tm_mon;
		int day = newDate.tm_mday;

		mktime(&newDate);

		if (year != newDate.tm_year ||
			month != newDate.tm_mon ||
			day != newDate.tm_mday) {
			throw Invalid{ day, month, year };
		}
	}

	Date::Order Date::order = Date::Order::MonthDayYear;
	string Date::separator = "/";

	// These are const, that way the user can change the names of days if they want to output in a different language.
	std::vector<string> util::Date::weekdays =
	{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	std::vector<std::string> util::Date::months =
	{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
}