#ifndef INCLUDED_MQTT_MESSAGE
#define INCLUDED_MQTT_MESSAGE

#include <string>

struct MqttMessage{
	std::string topic;
	std::string payload;
	bool isValid = false;
};

#endif
