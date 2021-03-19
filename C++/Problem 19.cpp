#include <iostream>

#define START_YEAR 1901
#define START_MONTH 1 // January
#define START_MDAY 1 // Month-Day

#define END_YEAR 2000
#define END_MONTH 12 // December
#define END_MDAY 31 // Month-Day

enum class WeekDays {
	Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};
enum class Month {
	January = 1, February, March, April, May, June, July, August, Septermber, October, November, December
};

unsigned short days_In_This_Month(Month month, unsigned int year) {
	switch (month) {
		// Thirty days has September, April, June and November.
		case Month::Septermber:
		case Month::April:
		case Month::June:
		case Month::November:
			return 30;
			break;

		case Month::February: {
			// "A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400."
			if( ((year%4) == 0)   &&   (! (year%100) == 0)   ||   ((year%400) == 0) ) {
				return 29;
			} else {
				return 28;
			}
		}

		// All the rest month have thirty-one days.
		default: {
			return 31;
			break;
		}
	}
}

std::size_t calc() {
	unsigned short year = 1900;
	Month month(Month::January);
	WeekDays weekDay(WeekDays::Monday);

	std::size_t Sundays_since = 0;

	while(year <= END_YEAR) {
		while (month <= Month::December) {
			unsigned short daysInThisMonth = days_In_This_Month(month, year);
			for(unsigned short month_day = 1; month_day < daysInThisMonth; ++month_day) {
				if(weekDay == WeekDays::Sunday && year >= START_YEAR && year <= END_YEAR && month_day == 1) {
					++Sundays_since;
				}
				if(year == END_YEAR && month == static_cast<Month>(END_MONTH) && month_day == END_MDAY || year > END_YEAR) {
					break;
				}

				if(weekDay < WeekDays::Saturday) {
					weekDay = static_cast<WeekDays>( (unsigned short)weekDay + 1);
				} else {
					weekDay = WeekDays::Sunday;
				}
			}
			month = static_cast<Month>( (unsigned short)month + 1);
		}
		month = Month::January;
		++year;
	}
	return Sundays_since;
}

int main() {
	std::cout << calc() << '\n';
	

	return 0;
}