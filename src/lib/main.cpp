#include "msg_processor.h"
#include "db_accessor.h"
#include "event_handler.h"

#include <mqtt/client.h>
#include <mqtt/async_client.h>

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
	//std::unique_ptr<MqttClient> mqttClient{new MqttClient{"localhost", "hub"}};

	std::unique_ptr<DbAccessor> dbAccessor{new DbAccessor{"localhost", "root", "JwKc2000"}};
	std::unique_ptr<MsgProcessor> msgProcessor{new MsgProcessor{std::move(dbAccessor)}};

	std::unique_ptr<mqtt::async_client> asyncClient(new mqtt::async_client("localhost", "hub"));
	//handler.publish_message("topic2", "Hello from Class Implementation");
	std::cout << "Entering" << std::endl;
	EventHandler eventHandler(std::move(msgProcessor), std::move(asyncClient));
	//eventHandler.run();


	while(1);
	std::cout << "Exiting" << std::endl;
}
