#include "mqtt_message.h"

MqttMessage::MqttMessage(const std::string& topic, const std::string& payload)
: topic{topic}
, payload{payload}
{}
