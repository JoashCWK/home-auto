#include "event_handler.h"
#include "mqtt_message.h"

#include <vector>


EventHandler::EventHandler(MqttClient* mqttClient, MsgProcessor* msgProcessor):
s_mqttClient{mqttClient}, s_msgProcessor{msgProcessor}{}

void EventHandler::run(){
	std::vector<std::string> topics = {"addTopic", "schedule"};
	s_mqttClient->subscribe_topics(topics);

	while(1){
		auto msg = s_mqttClient->read_message();
		s_msgProcessor->process(msg);
	}
}

