#pragma once
#include <ctime>
#include <string>

namespace util {
	class Date {
	public:
		struct Invalid {
			int day;
			int month;
			int year;
		};

		enum class Order {
			MonthDayYear,
			DayMonthYear,
			YearMonthDay
		};

		Date(); // set date to 1/1/1970 MM/DD/YY
		Date(int d, int m, int y);

		void day(int d);
		int day();

		void month(int m);
		int month();

		void year(int y);
		int year();

		std::string dayName();
		std::string monthName();

		void advance(int move = 1);

		void print(std::ostream&);

		static Date now();

		static Order order; // Order::MonthDayYear
		static std::string separator; // '/'



	private:

		int formatDay(); //Exists for convention, doesn't do anything
		int formatMonth(); // add 1
		int formatYear(); // add 1900


		time_t cTime;
		tm oTime;
	};
}