#include "mqtt_client.h"
#include "mqtt_message.h"
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
	MqttClient mqttClient{"127.0.0.1", "hub"};
	DbAccessor dbAccessor("localhost", "root", "JwKc2000");
	MsgProcessor msgProcessor(dbAccessor);
	//handler.publish_message("topic2", "Hello from Class Implementation");
	EventHandler eventHandler(&mqttClient, msgProcessor);
	eventHandler.run();

	std::cout << "Exitting" << std::endl;
}
