#include "mqtt_handler.h"
#include "mqtt_message.h"
#include "msg_processor.h"

#include <mqtt/client.h>

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>

using namespace std;


int main(){
	MqttHandler mqttHandler("192.168.5.1:1883", "hub");
	MsgProcessor msgProcessor;

	//handler.publish_message("topic2", "Hello from Class Implementation");
	std::vector<std::string> topics{"addTopic"};
	mqttHandler.subscribe_topics(topics);

	
	while(1){
		struct MqttMessage msg = mqttHandler.read_message();
		mqttHandler.process_message(msg);
	}
}
