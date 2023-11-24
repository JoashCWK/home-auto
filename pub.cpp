#include <mqtt/client.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main(){
    string ip = "localhost:1883";
    string id = "publisher";

    mqtt::client client(ip, id, mqtt::create_options(MQTTVERSION_5));

    client.connect();

    mqtt::message_ptr messagePointer = mqtt::make_message("testTopic", "");

    for (int i=0; i<10; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        messagePointer -> set_payload("Hello From C++");
        client.publish(messagePointer);
    }

    messagePointer -> set_payload("quit");
    client.publish(messagePointer);

    return 0;
}
