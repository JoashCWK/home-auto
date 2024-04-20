#include "event_handler.h"
#include "../util/mqtt_message.h"

#include <vector>
#include <iostream>


EventHandler::EventHandler(std::unique_ptr<MsgProcessor> msgProcessor, std::unique_ptr<mqtt::async_client> asyncClient)
: s_msgProcessor(std::move(msgProcessor))
, s_mqttAsyncClient(std::move(asyncClient))
{
	s_mqttAsyncClient->set_callback(*this);
	s_mqttAsyncClient->connect();
}

void EventHandler::connected(const std::string& cause){
	std::cout << "Connected to Mqtt Broker" << std::endl;
	for(const std::string& i: s_topics){
		s_mqttAsyncClient->subscribe(i, 1 /*QOS*/);
	}
}

void EventHandler::message_arrived(mqtt::const_message_ptr msg){
	std::cout << "Received Message (" << msg->get_topic() << ": " << msg->to_string() << ")" << std::endl;
	mqtt::const_message_ptr response = s_msgProcessor->process(msg);
	s_mqttAsyncClient->publish(response);
}

