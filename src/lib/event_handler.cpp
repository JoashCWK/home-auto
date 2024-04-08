#include "event_handler.h"
#include "../util/mqtt_message.h"

#include <vector>
#include <iostream>


EventHandler::EventHandler(std::unique_ptr<MqttClient> mqttClient, std::unique_ptr<MsgProcessor> msgProcessor)
: s_mqttClient{std::move(mqttClient)}
, s_msgProcessor{std::move(msgProcessor)}
{
}

void EventHandler::run(){
	std::vector<std::string> topics = {"setDevice", "schedule"};
	s_mqttClient->subscribe_topics(topics);

	while(1){
		auto msg = s_mqttClient->read_message();
		std::cout << "Read Message (" << msg.topic << ": " << msg.payload << ")" << std::endl;
		MqttMessage response = s_msgProcessor->process(msg);
		s_mqttClient->publish_message(response);
	}
}

