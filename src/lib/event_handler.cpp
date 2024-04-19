#include "event_handler.h"
#include "../util/mqtt_message.h"

#include <vector>
#include <iostream>


EventHandler::EventHandler(std::unique_ptr<MsgProcessor> msgProcessor, std::unique_ptr<mqtt::async_client> asyncClient)
: s_msgProcessor{std::move(msgProcessor)}
, s_mqttAsyncClient(std::move(asyncClient))
{
	s_mqttAsyncClient->set_callback(*this);
	s_mqttAsyncClient->connect();
}

void EventHandler::connected(const std::string& cause){
	std::cout << "Connected to Mqtt Broker" << std::endl;
	s_mqttAsyncClient->subscribe("setDevice", 1);
}

void EventHandler::message_arrived(mqtt::const_message_ptr msg){
	MqttMessage message(msg->get_topic(), msg->to_string());
	std::cout << "Read Message (" << message.topic << ": " << message.payload << ")" << std::endl;
	MqttMessage response = s_msgProcessor->process(message);
	mqtt::message_ptr res = mqtt::make_message(response.topic, response.payload);
	s_mqttAsyncClient->publish(res);

}

/*
void EventHandler::run(){
	s_mqttClient->subscribe_topics(s_topics);

	while(1){
		auto msg = s_mqttClient->read_message();
		std::cout << "Read Message (" << msg.topic << ": " << msg.payload << ")" << std::endl;
		MqttMessage response = s_msgProcessor->process(msg);
		s_mqttClient->publish_message(response);
	}
}
*/
