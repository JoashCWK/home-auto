#ifndef INCLUDED_DATETIME
#define INCLUDED_DATETIME

#include <string>
class Date{
	public:
		Date();
		Date(int year, int month, int day);
		static Date from_string(std::string date);
	private:
		int s_year;
		int s_month;
		int s_day;
};

class Time{
	public:
		Time();
		Time(int hours, int minutes, int seconds);
		static Time from_string(std::string time);
	private:
		int s_hours;
		int s_minutes;
		int s_seconds;
};

#endif
