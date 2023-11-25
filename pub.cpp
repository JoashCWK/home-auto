#include <mqtt/client.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class MQTT_Handler{
	private:
		mqtt::client client;
	public:
		MQTT_Handler(string id, string ip){
			client(ip, id, mqtt::create_options(MQTTVERSION_5));
		}

};

int main(){
    string ip = "192.168.5.1:1883";
    string id = "hub";

    mqtt::client client(ip, id, mqtt::create_options(MQTTVERSION_5));

    client.connect();

    mqtt::message_ptr messagePointer = mqtt::make_message("testTopic", "");

    for (int i=0; i<10; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        messagePointer -> set_payload(f"Hello From {id}");
        client.publish(messagePointer);
    }

    messagePointer -> set_payload("quit");
    client.publish(messagePointer);

    return 0;
}
