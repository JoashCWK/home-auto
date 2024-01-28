#ifndef INCLUDED_MQTT_HANDLER
#define INCLUDED_MQTT_HANDLER

#include "mqtt_message.h"
#include <mqtt/client.h>
#include <vector>

std::string exec_cmd(const std::string& cmd);

class MqttHandler{
	private:
		mqtt::client client;
	public:
		MqttHandler(const std::string& ip, const std::string& id);
		void publish_message(const std::string& topic, const std::string& payload);
		void subscribe_topics(const std::vector<std::string>& topics);
		void subscribe_topic(const std::string& topic);
		void process_message(const MqttMessage& msg);
		struct MqttMessage read_message();
};

#endif
