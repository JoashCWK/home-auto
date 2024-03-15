#include "datetime.h"

enum Repetition{
	DAILY,
	WEEKLY,
	MONTHLY,
	NONE
}

struct TaskSchedule{
	Date startDate;
	Date endDate;
	Time time;
	Repetition repetition;
	MqttMessage mqttMessage;
}
