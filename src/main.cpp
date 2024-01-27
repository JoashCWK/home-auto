#include <mqtt/client.h>
#include "mqtt_handler.h"

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>

using namespace std;

string exec_cmd(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main(){
	MQTT_Handler handler("192.168.5.1:1883", "hub");
	//handler.publish_message("topic2", "Hello from Class Implementation");
	std::vector<std::string> topics{"topic1", "topic2", "topic3"};
	handler.subscribe_topics(topics, 3);

	//cout << exec_cmd("bash http/get_mac.sh room-light-1") << endl;
	
	while(1){
		struct MQTT_Message msg = handler.read_message();
		if (msg.isValid){
			cout << msg.topic << ": " << msg.payload << endl;
		}
	}
}
