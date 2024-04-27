#include "event_handler.h"

#include <vector>
#include <iostream>

EventHandler::EventHandler(
	const std::string& IPAddress,
	const std::string& name,
	const std::string& dbUsername,
	const std::string& dbPassword
)
: s_msgProcessor(IPAddress, dbUsername, dbPassword)
, s_mqttAsyncClient(IPAddress, name)
{
	s_mqttAsyncClient.set_callback(*this);
	s_mqttAsyncClient.connect();
}

void EventHandler::connected(const std::string& cause){
	std::cout << "Connected to Mqtt Broker" << std::endl;
	for(const std::string& i: s_topics){
		s_mqttAsyncClient.subscribe(i, 1 /*QOS*/);
	}
}

void EventHandler::message_arrived(mqtt::const_message_ptr msg){
	std::cout << "Received Message (" << msg->get_topic() << ": " << msg->to_string() << ")" << std::endl;
	mqtt::const_message_ptr response = s_msgProcessor.process(msg);
	s_mqttAsyncClient.publish(response);
}

