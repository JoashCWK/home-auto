#ifndef INCLUDED_MQTT_HANDLER
#define INCLUDED_MQTT_HANDLER

#include <mqtt/client.h>
#include <vector>


struct MQTT_Message{
	std::string topic;
	std::string payload;
	bool isValid = false;
};

class MQTT_Handler{
	private:
		mqtt::client client;
	public:
		MQTT_Handler(const std::string& ip, const std::string& id);
		void publish_message(const std::string& topic, const std::string& payload);
		void subscribe_topics(const std::vector<std::string>& topics, uint8_t num_topics);
		struct MQTT_Message read_message();
};

#endif
