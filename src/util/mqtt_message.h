#ifndef INCLUDED_MQTT_MESSAGE
#define INCLUDED_MQTT_MESSAGE

#include <string>

struct MqttMessage{
	MqttMessage(const std::string& topic, const std::string& payload);
	std::string topic;
	std::string payload;
};

#endif
