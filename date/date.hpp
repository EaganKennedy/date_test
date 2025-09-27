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

		static Order order;
		static std::string separator;

		static std::vector<std::string> weekdays;
		static std::vector<std::string> months;

	private:

		void normalizeCTime();

		void validate(tm newDate);

		tm oTime{};
	};
}