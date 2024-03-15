#include "datetime.h"
#include <vector>

std::vector<int> parse_int_from_string(std::string str, const std::string& delimiter){
	std::vector<int> parsed_int;
	size_t pos = 0;
	while((pos = str.find(delimiter)) != std::string::npos){
		parsed_int.push_back(std::stoi(str.substr(0, pos)));
		str.erase(0, pos + delimiter.length());
	}
	parsed_int.push_back(std::stoi(str));
	return parsed_int;
}

Date::Date(int year, int month, int day):
s_year{year},
s_month{month},
s_day{day}
{}

Date Date::from_string(std::string date){
	std::vector<int> date_vec = parse_int_from_string(date, "-");
	return Date(date_vec[0], date_vec[1], date_vec[2]);
}

Time::Time(int hours, int minutes, int seconds):
s_hours{hours},
s_minutes{minutes},
s_seconds{seconds}
{}

Time Time::from_string(std::string time){
	std::vector<int> time_vec = parse_int_from_string(time, ":");
	return Time(time_vec[0], time_vec[1], time_vec[2]);
}
