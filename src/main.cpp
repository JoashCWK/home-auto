#include <mqtt/client.h>
#include "mqtt_handler.h"

using namespace std;

int main(){
	MQTT_Handler handler("192.168.5.1:1883", "hub");
	//handler.publish_message("topic2", "Hello from Class Implementation");
	string topics[3] = {"topic1", "topic2", "topic3"};
	handler.subscribe_topics(topics, 3);
	
	while(1){
		struct MQTT_Message msg = handler.read_message();
		if (msg.isValid){
			cout << msg.topic << ": " << msg.payload << endl;
		}
	}
}
