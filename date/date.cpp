#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include <vector>
#include <ctime>
#include <sstream>
#include <iostream>

using std::string;

namespace util {
	Date::Date() { //Code grade can not have a constructor forward to another constructor, or at least not when I attempted to
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

	Date::Date(int d, int m, int y) {
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


	void Date::day(int d) {
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

		return months.at(oTime.tm_mon);
	}

	void Date::print(std::ostream& out) {
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

	Date::Order Date::order = Date::Order::MonthDayYear;
	string Date::separator = "/";
}