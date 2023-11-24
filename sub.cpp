#include <mqtt/client.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string ip = "localhost";
    string id = "hub";
    mqtt::client client(ip, id, mqtt::create_options(MQTTVERSION_5));
    client.connect();
    client.subscribe("testTopic");
    client.start_consuming();

    bool running = true;
    while (running){
        mqtt::const_message_ptr messagePointer;

        if (client.try_consume_message(&messagePointer)){
            string messageString = messagePointer -> get_payload_str();
            cout << messageString << endl;

            if (messageString == "quit"){
                running = false;
            }
        }
    }
    return 0;
}
