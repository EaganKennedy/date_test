#include "gtest/gtest.h"
#include "date.hpp"

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

TEST(Props, CorrectRead) {
	// test Feb, Aug, Nov, Sun, Wed, Fri
}

TEST(Print, Prints) {
	// Prints
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