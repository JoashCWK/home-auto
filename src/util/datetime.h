class DateTime{
	public:	
		DateTime();
		DateTime(int year, int month, int day, int hour, int minute, int second);
		DateTime(int year, int month, int day);
		DateTime(std::string string_dt);

		void setYear(int year);
		void setMonth(int month);
		void setDay(int day);
		void setHour(int hour);
		void setMinute(int minute);
		void setSecond(int second);

	private:
		s_year;
		s_month;
		s_day;
		s_hour;
		s_minute;
		s_second;
}
