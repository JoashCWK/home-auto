#ifndef INCLUDED_MQTT_CLIENT
#define INCLUDED_MQTT_CLIENT

#include "mqtt_message.h"
#include <mqtt/client.h>
#include <vector>

std::string exec_cmd(const std::string& cmd);

class MqttClient{
	private:
		mqtt::client s_client;

	public:
		MqttClient(const std::string& ip, const std::string& id);
		void publish_message(const std::string& topic, const std::string& payload);
		void subscribe_topics(const std::vector<std::string>& topics);
		void subscribe_topic(const std::string& topic);
		struct MqttMessage read_message();
};

#endif
