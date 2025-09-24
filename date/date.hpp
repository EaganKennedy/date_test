#pragma once
#include <ctime>
#include <string>
#include <vector>

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

		Date();
		Date(int d, int m, int y);

		void day(int d);
		int day() const;

		void month(int m);
		int month() const;

		void year(int y);
		int year() const;

		std::string dayName() const;
		std::string monthName() const;

		void advance(int move = 1);

		void print(std::ostream&) const;

		static Date now();

		static Order order; // Order::MonthDayYear
		static std::string separator; // '/'

	private:

		void normalizeCTime();

		time_t cTime = time(nullptr);
		tm oTime;
		const std::vector<std::string> weekdays =
		{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

		const std::vector<std::string> months =
		{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

		//tm oTime = *localtime(&cTime); //Throws exceptions every time for some reason
		//unknown file: error: Unknown C++ exception thrown in the test body.
	};
}