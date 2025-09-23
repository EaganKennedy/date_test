#define _CRT_SECURE_NO_WARNINGS
#include "gtest/gtest.h"
#include "date.hpp"
#include <string>
#include <sstream>
#include <ctime>

using namespace util;

TEST(DefaultCtor, InitAndBaseGetter) {
	Date d;
	ASSERT_EQ(d.month(), 1);
	ASSERT_EQ(d.day(), 1);
	ASSERT_EQ(d.year(), 1970);
}

TEST(Setters, Setting) {
	Date d;
	ASSERT_NO_THROW(d.month(10));
	ASSERT_THROW(d.month(20), Date::Invalid);

	ASSERT_NO_THROW(d.day(25));
	ASSERT_THROW(d.day(32), Date::Invalid);

	d.month(11);
	ASSERT_NO_THROW(d.day(30));

	ASSERT_NO_THROW(d.year(2000));
}

TEST(Setters, Getting) {
	Date d;

	ASSERT_EQ(d.month(), 1);
	ASSERT_EQ(d.day(), 1);
	ASSERT_EQ(d.year(), 1970);
}

TEST(ValueCtor, InitWorks) {
	Date d(2, 2, 1971);

	ASSERT_EQ(d.month(), 2);
	ASSERT_EQ(d.day(), 2);
	ASSERT_EQ(d.year(), 1971);

	ASSERT_THROW(Date d(1, 40, 1970), Date::Invalid);
}

TEST(Props, CorrectMonthRead) {
	Date d(1,2,1970);
	ASSERT_EQ(d.monthName(), "February");

	d.month(8);
	ASSERT_EQ(d.monthName(), "August");

	d.month(11);
	ASSERT_EQ(d.monthName(), "November");
}

TEST(Props, CorrectDayRead) {
	Date d(21, 9, 2025);
	ASSERT_EQ(d.dayName(), "Sunday");

	Date d2(24, 9, 2025);
	ASSERT_EQ(d2.dayName(), "Wednesday");

	Date d3(26, 9, 2025);
	ASSERT_EQ(d3.dayName(), "Friday");
}

TEST(Print, AccuratePrint) {
	std::ostringstream sout;
	Date d(25,10,2025);

	d.print(sout);

	ASSERT_EQ(sout.str(), "10/25/2025");
}

TEST(Advance, BasicAdvance) {
	Date d;

	d.advance();
	ASSERT_EQ(d.day(), 2);

	d.advance(5);
	ASSERT_EQ(d.day(), 7);
	
	d.advance(-6);
	ASSERT_EQ(d.day(), 1);
}

TEST(Advance, DateOrder) {
	Date d(5,2,1970);
	std::ostringstream sout;
	Date::order = Date::Order::MonthDayYear;

	d.print(sout);
	ASSERT_EQ(sout.str(), "2/5/1970");
	sout.str("");

	Date::order = Date::Order::DayMonthYear;
	d.print(sout);
	ASSERT_EQ(sout.str(), "5/2/1970");
	sout.str("");

	Date::order = Date::Order::YearMonthDay;
	d.print(sout);
	ASSERT_EQ(sout.str(), "1970/2/5");
	sout.str("");
}

TEST(Advance, Separator) {
	Date d(10,5,1970);
	std::ostringstream sout;
	Date::order = Date::Order::MonthDayYear;

	Date::separator = "+";

	d.print(sout);
	ASSERT_EQ(sout.str(), "5+10+1970");
	sout.str("");

	Date d2(2, 11, 1970);
	d2.print(sout);
	ASSERT_EQ(sout.str(), "11+2+1970");
	sout.str("");
}

TEST(Now, WorkingStatic) {
	std::string testCase = "";
	std::ostringstream sout;
	tm testToday;

	Date::order = Date::Order::MonthDayYear;
	Date today = Date::now();

	time_t temp = time(nullptr);
	testToday = *localtime(&temp);

	testCase += std::to_string(testToday.tm_mon + 1);
	testCase += Date::separator;
	
	testCase += std::to_string(testToday.tm_mday);
	testCase += Date::separator;

	testCase += std::to_string(testToday.tm_year + 1900);

	today.print(sout);

	ASSERT_EQ(sout.str(), testCase);
}