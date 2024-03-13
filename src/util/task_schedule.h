struct TaskSchedule{
	Date startDate;
	Date endDate;
	Time time;
	Repetition repetition;
	std::string mqtt_topic;
	std::string mqtt_message;
}
