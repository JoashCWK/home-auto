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
	//handler.publish_message("topic2", "Hello from Class Implementation");
	std::cout << "Entering" << std::endl;
	EventHandler eventHandler("localhost", "hub", "root", "JwKc2000");
	//eventHandler.run();


	while(1);
	std::cout << "Exiting" << std::endl;
}
