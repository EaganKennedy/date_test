#include "gtest/gtest.h"
#include "date.hpp"

using namespace util;

TEST(DefaultCtor, InitAndBaseGetter) {
	// test constructor = 1/1/1970 MM/DD/YY using getters
}

TEST(Setters, SettingAndGetting) {
	// test setting with the same three dates
}

TEST(ValueCtor, InitWorks) {
	// test using three dates, one on the low, mid and high ends
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

TEST(Advance, Seperator) {
	// Seperator influences all
}


TEST(Now, WorkingStatic) {
	// Static works
}