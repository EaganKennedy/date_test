#include "gtest/gtest.h"
#include "date.hpp"
#include <string>
#include <sstream>

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
}

TEST(Props, CorrectMonthRead) {
	Date d(1,2,1970);
	ASSERT_EQ(d.monthName(), "February");

	d.month(8);
	ASSERT_EQ(d.monthName(), "August");

	d.month(11);
	ASSERT_EQ(d.monthName(), "November");

	// test Feb, Aug, Nov, Sun, Wed, Fri
}

TEST(Props, CorrectDayRead) {
	Date d(21, 9, 2025);
	ASSERT_EQ(d.dayName(), "Sunday");

	Date d2(24, 9, 2025);
	ASSERT_EQ(d.dayName(), "Wednesday");

	Date d3(26, 9, 2025);
	ASSERT_EQ(d.dayName(), "Friday");
}

TEST(Print, AccuratePrint) {
	std::ostringstream sout;
	Date d(25,10,2025);

	d.print(sout);

	ASSERT_EQ(sout, "10/25/2025");
}


TEST(Advance, BasicAdvance) {
	// no input, five input, negative
}

TEST(Advance, DateOrder) {
	// Date works in each order ad changes across multiple
}

TEST(Advance, Separator) {
	// Separator influences all
}


TEST(Now, WorkingStatic) {
	// Static works
}