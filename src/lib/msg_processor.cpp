#include "msg_processor.h"

#include <iostream>

MsgProcessor::MsgProcessor(MqttClient* mqttClient, DbAccessor* dbAccessor)
: s_mqttClient{mqttClient}, s_dbAccessor{dbAccessor}{}

void MsgProcessor::process(const MqttMessage& msg){
	if(msg.topic == "setDevice")
	{
		s_mqttClient->publish_message("addTopicResponse", "waiting");
		std::string mac_address = exec_cmd("bash http/get_mac.sh " + msg.payload);
		
		std::cout << "To add to database and publish success response: " << mac_address << std::endl;

		s_mqttClient->publish_message("addTopicResponse", "success");
	}
	else if(msg.topic == "getDevices")
	{

	}
	else if(msg.topic == "setSchedule")
	{
		
	}

	else if(msg.topic == "getSchedules")
	{

	}

}