#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include <vector>
#include <ctime>
#include <sstream>
#include <iostream>

using std::string;

//So for some reason adding and deleting a line of code changes the test results on CodeGrade, all of them work on my end


	util::Date::Date() { //Code grade can not have a constructor forward to another constructor, or at least not when I attempted to
		year(1970);
		month(1);
		day(1);

		oTime.tm_sec = 0;
		oTime.tm_min = 0;
		oTime.tm_hour = 0;
		oTime.tm_wday = 0;
		oTime.tm_isdst = -1;

		normalizeCTime();
	}
	util::Date::Date(int d, int m, int y) {
		year(y);
		month(m);
		day(d);

		oTime.tm_sec = 0;
		oTime.tm_min = 0;
		oTime.tm_hour = 0;
		oTime.tm_wday = 0;
		oTime.tm_isdst = -1;

		normalizeCTime();
	}

	void util::Date::day(int d) {
		if (d < 1 || d > 31) {
			throw Invalid{ d, month(), year() };
		}

		tm newDay = oTime;
		newDay.tm_mday = d;
		mktime(&newDay);
		mktime(&oTime);

		if (newDay.tm_mon != oTime.tm_mon) {
			throw Invalid{ d, month(), year() };
		}

		oTime.tm_mday = d;

		normalizeCTime();
	}
	int util::Date::day() const {
		return oTime.tm_mday;
	}

	void util::Date::month(int m) {
		if (m < 1 || m > 12) {
			throw Invalid{ (day(), m, year()) };
		}
		oTime.tm_mon = m - 1;
		normalizeCTime();
	}
	int util::Date::month() const {
		return oTime.tm_mon + 1;
	}

	void util::Date::year(int y) {
		oTime.tm_year = y - 1900;

		normalizeCTime();
	}
	int util::Date::year() const {
		return oTime.tm_year + 1900;
	}

	string util::Date::dayName() const {
		return weekdays.at(oTime.tm_wday);
	}
	string util::Date::monthName() const {
		return months.at(oTime.tm_mon);
	}

	void util::Date::print(std::ostream& out) const {
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

	void util::Date::advance(int move) {
		oTime.tm_mday += move;
		normalizeCTime();
	}

	util::Date util::Date::now() {
		Date d;
		time_t curSeconds = time(nullptr);
		tm curTime = *localtime(&curSeconds);
		d.year(curTime.tm_year + 1900);
		d.month(curTime.tm_mon + 1);
		d.day(curTime.tm_mday);
		return d;
	}

	void util::Date::normalizeCTime() {
		cTime = mktime(&oTime);
	}

	util::Date::Order util::Date::order = util::Date::Order::MonthDayYear;
	string util::Date::separator = "/";
