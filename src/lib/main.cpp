#include "mqtt_client.h"
#include "msg_processor.h"
#include "db_accessor.h"
#include "event_handler.h"

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
	std::unique_ptr<MqttClient> mqttClient{new MqttClient{"localhost", "hub"}};

	std::unique_ptr<DbAccessor> dbAccessor{new DbAccessor{"localhost", "root", "JwKc2000"}};
	std::unique_ptr<MsgProcessor> msgProcessor{new MsgProcessor{std::move(dbAccessor)}};
	//handler.publish_message("topic2", "Hello from Class Implementation");
	std::cout << "Entering" << std::endl;
	EventHandler eventHandler(std::move(mqttClient), std::move(msgProcessor));
	eventHandler.run();

	std::cout << "Exiting" << std::endl;
}
